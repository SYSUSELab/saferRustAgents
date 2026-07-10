#!/usr/bin/env python3
"""Build an OpenHarmony third-party Rust API knowledge base with LLM help.

Workflow:
1. Read repository URLs from openharmony_rust_repos.json.
2. Clone or update each target repository locally.
3. Use the repository README to produce an initial API KB entry set.
4. Read markdown files under docs/ and ask the LLM to refine the entries.
5. Save a flat JSON array containing the final KB entries.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any

OPENAI_AVAILABLE = True
try:
    from openai import OpenAI
except ImportError:  # pragma: no cover - dependency presence varies by environment
    OPENAI_AVAILABLE = False
    OpenAI = Any  # type: ignore[misc,assignment]


DEFAULT_MODEL = "deepseek-chat"
DEFAULT_BASE_URL = "https://api.deepseek.com"
DEFAULT_DOC_CHUNK_CHARS = 18000
DEFAULT_LLM_RETRIES = 3

SYSTEM_PROMPT = """You are building a high-quality OpenHarmony Rust API knowledge base.

Your job:
- extract practical, reusable Rust API entries from repository docs;
- focus on public-facing APIs, important types, modules, traits, functions, and builder patterns;
- prefer APIs that are explicitly shown or explained in README/docs;
- preserve example code as valid Rust snippets whenever possible;
- keep summaries precise and engineering-oriented;
- infer cautiously and never fabricate APIs that do not appear in the material.

Output rules:
- return JSON only;
- top-level object must be {"api_entries": [...]};
- each entry must contain:
  - "api_name": string
  - "function_summary": string
  - "example_code": array of strings
  - "cargo_dependency": {
      "dependencies_toml": string,
      "rust_version_requirement": string
    }
- deduplicate APIs by api_name;
- if the material is insufficient, return {"api_entries": []}.
"""


@dataclass
class RepoRecord:
    name: str
    url: str


def parse_args() -> argparse.Namespace:
    script_dir = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(
        description="Build an OpenHarmony third-party Rust API knowledge base."
    )
    parser.add_argument(
        "--repos-json",
        default=str(script_dir / "openharmony_rust_repos.json"),
        help="Input JSON file containing OpenHarmony repository URLs.",
    )
    parser.add_argument(
        "--output",
        default=str(script_dir / "openharmony_third_party_rust_api_kb.json"),
        help="Output JSON path for the final flat knowledge base.",
    )
    parser.add_argument(
        "--repo-cache-dir",
        default=str(script_dir / "openharmony_repo_cache"),
        help="Directory used to clone or update repositories.",
    )
    parser.add_argument(
        "--repo-prefix",
        default="",
        help="Only process repositories whose name starts with this prefix. Default: process all repositories.",
    )
    parser.add_argument(
        "--repo-limit",
        type=int,
        default=0,
        help="Optional max number of repositories to process. 0 means no limit.",
    )
    parser.add_argument(
        "--model",
        default=DEFAULT_MODEL,
        help=f"LLM model name. Default: {DEFAULT_MODEL}",
    )
    parser.add_argument(
        "--base-url",
        default=DEFAULT_BASE_URL,
        help=f"LLM API base URL. Default: {DEFAULT_BASE_URL}",
    )
    parser.add_argument(
        "--api-key",
        default=os.environ.get("DEEPSEEK_API_KEY", ""),
        help="DeepSeek API key. Defaults to DEEPSEEK_API_KEY env var.",
    )
    parser.add_argument(
        "--doc-chunk-chars",
        type=int,
        default=DEFAULT_DOC_CHUNK_CHARS,
        help="Approximate maximum characters per docs chunk sent to the LLM.",
    )
    parser.add_argument(
        "--sleep-seconds",
        type=float,
        default=1.0,
        help="Delay between repository-level LLM runs.",
    )
    parser.add_argument(
        "--llm-retries",
        type=int,
        default=DEFAULT_LLM_RETRIES,
        help="Retry count for each LLM call.",
    )
    parser.add_argument(
        "--force-reclone",
        action="store_true",
        help="Delete and reclone repositories if they already exist locally.",
    )
    parser.add_argument(
        "--keep-cloned-repos",
        action="store_true",
        help="Keep cloned repositories on disk after processing. Default behavior is to delete them.",
    )
    return parser.parse_args()


def load_repo_records(repos_json_path: Path, repo_prefix: str, repo_limit: int) -> list[RepoRecord]:
    payload = json.loads(repos_json_path.read_text(encoding="utf-8"))
    repositories = payload.get("repositories", [])
    if repo_prefix:
        records = [
            RepoRecord(name=item["name"], url=item["url"])
            for item in repositories
            if item.get("name", "").startswith(repo_prefix)
        ]
    else:
        records = [RepoRecord(name=item["name"], url=item["url"]) for item in repositories]
    if repo_limit > 0:
        records = records[:repo_limit]
    return records


def run_git_command(args: list[str], cwd: Path | None = None) -> None:
    subprocess.run(args, cwd=cwd, check=True)


def log(message: str) -> None:
    print(message, file=sys.stderr, flush=True)


def clone_or_update_repo(repo: RepoRecord, repo_cache_dir: Path, force_reclone: bool) -> Path:
    repo_dir = repo_cache_dir / repo.name
    if force_reclone and repo_dir.exists():
        log(f"  - removing existing clone before reclone: {repo_dir}")
        shutil.rmtree(repo_dir)

    if (repo_dir / ".git").is_dir():
        log(f"  - updating existing repository: {repo.url}")
        run_git_command(["git", "-C", str(repo_dir), "fetch", "--all", "--tags"])
        run_git_command(["git", "-C", str(repo_dir), "pull", "--ff-only"])
        return repo_dir

    if repo_dir.exists():
        raise RuntimeError(f"Path exists but is not a git repo: {repo_dir}")

    log(f"  - cloning repository: {repo.url}")
    run_git_command(["git", "clone", repo.url, str(repo_dir)])
    return repo_dir


def cleanup_repo_dir(repo_dir: Path) -> None:
    if repo_dir.exists():
        log(f"  - deleting local clone: {repo_dir}")
        shutil.rmtree(repo_dir)


def find_first_existing(repo_dir: Path, candidates: list[str]) -> Path | None:
    for relative_path in candidates:
        path = repo_dir / relative_path
        if path.is_file():
            return path
    return None


def read_text_file(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="ignore")


def read_readme(repo_dir: Path) -> tuple[Path | None, str]:
    readme_path = find_first_existing(
        repo_dir,
        [
            "README.md",
            "README.MD",
            "readme.md",
            "Readme.md",
            "README.rst",
            "README.txt",
        ],
    )
    if readme_path is None:
        return None, ""
    return readme_path, read_text_file(readme_path)


def is_english_docs_markdown(path: Path) -> bool:
    if path.suffix.lower() not in {".md", ".markdown"}:
        return False

    normalized_name = path.name.casefold()
    non_english_markers = (
        ".zh.",
        "_zh.",
        "-zh.",
        ".zh-cn.",
        "_zh-cn.",
        "-zh-cn.",
        ".cn.",
        "_cn.",
        "-cn.",
    )
    return not any(marker in normalized_name for marker in non_english_markers)


def collect_docs_markdown(repo_dir: Path) -> list[Path]:
    docs_dir = repo_dir / "docs"
    if not docs_dir.is_dir():
        return []
    return sorted(
        path
        for path in docs_dir.rglob("*")
        if path.is_file() and is_english_docs_markdown(path)
    )


def group_docs_into_chunks(doc_paths: list[Path], repo_dir: Path, chunk_chars: int) -> list[str]:
    if not doc_paths:
        return []

    chunks: list[str] = []
    current_parts: list[str] = []
    current_size = 0

    for path in doc_paths:
        rel_path = path.relative_to(repo_dir)
        text = read_text_file(path).strip()
        if not text:
            continue

        file_block = f"# File: {rel_path}\n\n{text}\n"
        if current_parts and current_size + len(file_block) > chunk_chars:
            chunks.append("\n\n".join(current_parts))
            current_parts = []
            current_size = 0

        current_parts.append(file_block)
        current_size += len(file_block)

    if current_parts:
        chunks.append("\n\n".join(current_parts))

    return chunks


def extract_rust_version_requirement(repo_dir: Path) -> str:
    cargo_toml = repo_dir / "Cargo.toml"
    if not cargo_toml.is_file():
        return "Unknown"

    text = read_text_file(cargo_toml)
    rust_version_match = re.search(r'^\s*rust-version\s*=\s*"([^"]+)"', text, re.MULTILINE)
    if rust_version_match:
        return rust_version_match.group(1)

    edition_match = re.search(r'^\s*edition\s*=\s*"([^"]+)"', text, re.MULTILINE)
    if edition_match:
        return f"Rust toolchain compatible with edition {edition_match.group(1)}"

    return "Unknown"


def extract_crate_name(repo: RepoRecord, repo_dir: Path) -> str:
    cargo_toml = repo_dir / "Cargo.toml"
    if cargo_toml.is_file():
        text = read_text_file(cargo_toml)
        package_name_match = re.search(r'^\s*name\s*=\s*"([^"]+)"', text, re.MULTILINE)
        if package_name_match:
            return package_name_match.group(1)

    crate_guess = repo.name
    for prefix in ("third_party_rust_", "commonlibrary_rust_"):
        if crate_guess.startswith(prefix):
            crate_guess = crate_guess[len(prefix):]
            break
    return crate_guess.replace("-", "_")


def extract_default_dependency_snippet(repo: RepoRecord, repo_dir: Path) -> str:
    crate_guess = extract_crate_name(repo, repo_dir)
    git_url = repo.url
    return f'[dependencies]\n{crate_guess} = {{ git = "{git_url}.git" }}'


def build_initial_prompt(
    repo: RepoRecord,
    rust_requirement: str,
    dependency_hint: str,
    readme_path: Path | None,
    readme_text: str,
) -> str:
    readme_label = str(readme_path) if readme_path else "README not found"
    return f"""Repository name: {repo.name}
Repository URL: {repo.url}
Known Rust version hint: {rust_requirement}
Suggested Cargo dependency snippet:
{dependency_hint}

Task:
1. Read the README content and identify the main public Rust APIs worth adding to an OpenHarmony-focused third-party Rust API knowledge base.
2. For each API, produce:
   - api_name
   - function_summary
   - example_code: extract every relevant usage example you can find from the README as separate array items
   - cargo_dependency
3. Prefer API names with module/type/function paths, such as crate::Type, crate::module::function, or crate::Trait.
4. If the README contains Cargo usage instructions, preserve them in dependencies_toml.
5. If the README does not contain dependency instructions, use the suggested Cargo dependency snippet.
6. Do not invent example code. Only use README-backed or very lightly normalized snippets.

README source: {readme_label}

README content:
{readme_text}
"""


def build_refinement_prompt(
    repo: RepoRecord,
    rust_requirement: str,
    existing_entries: list[dict[str, Any]],
    docs_chunk: str,
) -> str:
    return f"""Repository name: {repo.name}
Repository URL: {repo.url}
Known Rust version hint: {rust_requirement}

Your task is to refine an existing API knowledge base using repository docs.

Rules:
1. Update existing entries when the docs provide more accurate API names, summaries, Cargo usage, or example code.
2. Add new entries only when the docs clearly describe additional useful APIs.
3. Keep all example_code values as arrays of Rust snippets.
4. Deduplicate example snippets that are near-identical.
5. Return the complete merged result, not only the diff.

Existing KB JSON:
{json.dumps({"api_entries": existing_entries}, ensure_ascii=False, indent=2)}

Docs markdown content:
{docs_chunk}
"""


def strip_code_fences(text: str) -> str:
    stripped = text.strip()
    fence_match = re.match(r"^```(?:json)?\s*(.*?)\s*```$", stripped, re.DOTALL)
    if fence_match:
        return fence_match.group(1).strip()
    return stripped


def parse_llm_json(text: str) -> dict[str, Any]:
    cleaned = strip_code_fences(text)
    try:
        payload = json.loads(cleaned)
    except json.JSONDecodeError as exc:
        raise ValueError(f"Failed to parse LLM JSON response: {exc}\n{text}") from exc

    if not isinstance(payload, dict):
        raise ValueError("LLM response JSON must be an object")

    api_entries = payload.get("api_entries")
    if not isinstance(api_entries, list):
        raise ValueError('LLM response JSON must contain an "api_entries" list')

    return payload


def normalize_entry(
    entry: dict[str, Any],
    repo: RepoRecord,
    rust_requirement: str,
    dependency_hint: str,
) -> dict[str, Any] | None:
    api_name = str(entry.get("api_name", "")).strip()
    if not api_name:
        return None

    function_summary = str(entry.get("function_summary", "")).strip()
    example_code_raw = entry.get("example_code", [])
    if isinstance(example_code_raw, str):
        example_code = [example_code_raw.strip()] if example_code_raw.strip() else []
    elif isinstance(example_code_raw, list):
        example_code = []
        for item in example_code_raw:
            snippet = str(item).strip()
            if snippet and snippet not in example_code:
                example_code.append(snippet)
    else:
        example_code = []

    cargo_dependency_raw = entry.get("cargo_dependency", {})
    dependencies_toml = dependency_hint
    rust_version_requirement = rust_requirement
    if isinstance(cargo_dependency_raw, dict):
        dep_text = str(cargo_dependency_raw.get("dependencies_toml", "")).strip()
        rust_req_text = str(cargo_dependency_raw.get("rust_version_requirement", "")).strip()
        if dep_text:
            dependencies_toml = dep_text
        if rust_req_text:
            rust_version_requirement = rust_req_text

    return {
        "api_name": api_name,
        "function_summary": function_summary,
        "example_code": example_code,
        "cargo_dependency": {
            "dependencies_toml": dependencies_toml,
            "rust_version_requirement": rust_version_requirement,
        },
        "source_repository": {
            "name": repo.name,
            "url": repo.url,
        },
    }


def merge_entries(
    entries: list[dict[str, Any]],
    repo: RepoRecord,
    rust_requirement: str,
    dependency_hint: str,
) -> list[dict[str, Any]]:
    merged: dict[str, dict[str, Any]] = {}
    for entry in entries:
        normalized = normalize_entry(entry, repo, rust_requirement, dependency_hint)
        if normalized is None:
            continue
        key = normalized["api_name"]
        if key not in merged:
            merged[key] = normalized
            continue

        existing = merged[key]
        if len(normalized["function_summary"]) > len(existing["function_summary"]):
            existing["function_summary"] = normalized["function_summary"]

        existing_examples = existing["example_code"]
        for snippet in normalized["example_code"]:
            if snippet not in existing_examples:
                existing_examples.append(snippet)

        dep = normalized["cargo_dependency"]["dependencies_toml"]
        if dep and dep != existing["cargo_dependency"]["dependencies_toml"]:
            existing["cargo_dependency"]["dependencies_toml"] = dep

        rust_req = normalized["cargo_dependency"]["rust_version_requirement"]
        if rust_req and rust_req != "Unknown":
            existing["cargo_dependency"]["rust_version_requirement"] = rust_req

    return sorted(merged.values(), key=lambda item: item["api_name"].casefold())


def create_client(api_key: str, base_url: str) -> OpenAI:
    if not OPENAI_AVAILABLE:
        raise ValueError(
            'Missing dependency "openai". Please install it with: pip3 install openai'
        )
    if not api_key:
        raise ValueError(
            "Missing API key. Please pass --api-key or set DEEPSEEK_API_KEY."
        )
    return OpenAI(api_key=api_key, base_url=base_url)


def call_llm_json(
    client: OpenAI,
    model: str,
    prompt: str,
    retries: int,
    stage_label: str,
) -> dict[str, Any]:
    last_error: Exception | None = None
    for attempt in range(1, retries + 1):
        try:
            log(f"    * LLM request: {stage_label} (attempt {attempt}/{retries})")
            response = client.chat.completions.create(
                model=model,
                messages=[
                    {"role": "system", "content": SYSTEM_PROMPT},
                    {"role": "user", "content": prompt},
                ],
                stream=False,
            )
            content = response.choices[0].message.content or ""
            log(f"    * LLM response received: {stage_label}")
            return parse_llm_json(content)
        except Exception as exc:  # noqa: BLE001
            last_error = exc
            log(f"    * LLM request failed: {stage_label}: {exc}")
            if attempt == retries:
                break
            time.sleep(min(2 * attempt, 8))

    assert last_error is not None
    raise last_error


def build_repo_entries(
    client: OpenAI,
    model: str,
    repo: RepoRecord,
    repo_dir: Path,
    doc_chunk_chars: int,
    llm_retries: int,
) -> list[dict[str, Any]]:
    rust_requirement = extract_rust_version_requirement(repo_dir)
    dependency_hint = extract_default_dependency_snippet(repo, repo_dir)
    readme_path, readme_text = read_readme(repo_dir)
    if readme_path is not None:
        log(f"  - README found: {readme_path.relative_to(repo_dir)} ({len(readme_text)} chars)")
    else:
        log("  - README not found")
    docs_markdown = collect_docs_markdown(repo_dir)
    log(f"  - docs markdown files found: {len(docs_markdown)}")
    if docs_markdown:
        for doc_path in docs_markdown:
            log(f"    * using docs file: {doc_path.relative_to(repo_dir)}")
    docs_chunks = group_docs_into_chunks(
        docs_markdown,
        repo_dir=repo_dir,
        chunk_chars=doc_chunk_chars,
    )
    log(f"  - docs chunks to process: {len(docs_chunks)}")
    log(f"  - rust version hint: {rust_requirement}")
    log(f"  - dependency hint crate snippet prepared for repo: {repo.name}")

    initial_prompt = build_initial_prompt(
        repo=repo,
        rust_requirement=rust_requirement,
        dependency_hint=dependency_hint,
        readme_path=readme_path,
        readme_text=readme_text or "README not found or empty.",
    )
    initial_payload = call_llm_json(
        client,
        model,
        initial_prompt,
        llm_retries,
        stage_label=f"{repo.name} README initial extraction",
    )
    entries = merge_entries(
        initial_payload.get("api_entries", []),
        repo=repo,
        rust_requirement=rust_requirement,
        dependency_hint=dependency_hint,
    )
    log(f"  - entries after README extraction: {len(entries)}")

    for docs_index, docs_chunk in enumerate(docs_chunks, start=1):
        log(
            f"  - refining with docs chunk {docs_index}/{len(docs_chunks)} "
            f"({len(docs_chunk)} chars)"
        )
        refined_payload = call_llm_json(
            client,
            model,
            build_refinement_prompt(
                repo=repo,
                rust_requirement=rust_requirement,
                existing_entries=entries,
                docs_chunk=docs_chunk,
            ),
            llm_retries,
            stage_label=f"{repo.name} docs refinement chunk {docs_index}/{len(docs_chunks)}",
        )
        entries = merge_entries(
            refined_payload.get("api_entries", []),
            repo=repo,
            rust_requirement=rust_requirement,
            dependency_hint=dependency_hint,
        )
        log(f"  - entries after docs chunk {docs_index}: {len(entries)}")

    return entries


def save_output(output_path: Path, entries: list[dict[str, Any]]) -> None:
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(
        json.dumps(entries, ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8",
    )


def main() -> int:
    args = parse_args()
    repos_json_path = Path(args.repos_json).resolve()
    output_path = Path(args.output).resolve()
    repo_cache_dir = Path(args.repo_cache_dir).resolve()
    repo_cache_dir.mkdir(parents=True, exist_ok=True)

    try:
        client = create_client(api_key=args.api_key, base_url=args.base_url)
    except ValueError as exc:
        log(str(exc))
        return 1

    records = load_repo_records(
        repos_json_path=repos_json_path,
        repo_prefix=args.repo_prefix,
        repo_limit=args.repo_limit,
    )
    if not records:
        log("No repositories matched the given prefix.")
        return 1
    log(f"Loaded {len(records)} repositories from {repos_json_path}")
    log(f"Output JSON will be written to: {output_path}")
    log(f"Temporary clone directory: {repo_cache_dir}")
    log(f"Cloned repositories will {'be kept' if args.keep_cloned_repos else 'be deleted after each repo'}")

    all_entries: list[dict[str, Any]] = []
    failures: list[dict[str, str]] = []

    for index, repo in enumerate(records, start=1):
        log(f"[{index}/{len(records)}] Processing {repo.name} ...")
        repo_dir = repo_cache_dir / repo.name
        try:
            repo_dir = clone_or_update_repo(repo, repo_cache_dir, args.force_reclone)
            repo_entries = build_repo_entries(
                client=client,
                model=args.model,
                repo=repo,
                repo_dir=repo_dir,
                doc_chunk_chars=args.doc_chunk_chars,
                llm_retries=args.llm_retries,
            )
            all_entries.extend(repo_entries)
            log(f"[{index}/{len(records)}] Collected {len(repo_entries)} entries from {repo.name}")
        except Exception as exc:  # noqa: BLE001
            failures.append({"repo_name": repo.name, "repo_url": repo.url, "error": str(exc)})
            log(f"[{index}/{len(records)}] Failed for {repo.name}: {exc}")
        finally:
            if not args.keep_cloned_repos:
                cleanup_repo_dir(repo_dir)
        time.sleep(args.sleep_seconds)

    deduped_entries: dict[str, dict[str, Any]] = {}
    for entry in all_entries:
        api_name = entry["api_name"]
        if api_name not in deduped_entries:
            deduped_entries[api_name] = entry
            continue

        existing = deduped_entries[api_name]
        if len(entry["function_summary"]) > len(existing["function_summary"]):
            existing["function_summary"] = entry["function_summary"]
        for snippet in entry["example_code"]:
            if snippet not in existing["example_code"]:
                existing["example_code"].append(snippet)

    final_entries = sorted(deduped_entries.values(), key=lambda item: item["api_name"].casefold())
    save_output(output_path, final_entries)

    log(f"Saved {len(final_entries)} API entries to {output_path}")
    if failures:
        failure_path = output_path.with_suffix(".failures.json")
        save_output(failure_path, failures)
        log(f"Saved {len(failures)} failures to {failure_path}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
