#!/usr/bin/env python3
"""
统计 RQ1 中 Claude 五个项目在 safer rewrite 前后的 unsafe 率。

核心口径：
1. before: 使用 data/rq1/claude/rust_code/final_projects/<project>/translate_by_qwen3_coder/src
2. after: 以原项目为基线，按 SaferAgent 日志中“workspace_apply: ok 且 compile_check: passed”的函数，
   将对应函数级 workspace 里的改写函数合并回项目，形成一个“项目级合成快照”后再统计。
3. skip / workspace_apply failed / compile_check failed 的函数，保持原始版本不变。

这个口径比“对所有函数 workspace 直接平均”更合理，因为每个 workspace 只是单函数试验沙箱，
并不是同一个最终项目版本。
"""

from __future__ import annotations

import argparse
import importlib.util
import json
import re
import sys
from dataclasses import asdict
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple


REPO_ROOT = Path(__file__).resolve().parents[2]
RQ1_ROOT = REPO_ROOT / "data" / "rq1" / "claude"
CLAUDE_FINAL_ROOT = RQ1_ROOT / "rust_code" / "final_projects"
SAFER_RESULTS_ROOT = REPO_ROOT / "saferAgent" / "results"
LOGS_ROOT = REPO_ROOT / "logs"
HELPER_SCRIPT = REPO_ROOT / "scripts" / "analyze_c2r_compilation_rate.py"


DEFAULT_PROJECTS = [
    "appverify_lite__e5ebe91a98b9",
    "host__25c1898e1626",
    "osal__0bc4f21396ad",
    "shared__12e38ea922f7",
    "shared__541f4e547bdb",
]


def load_helper_module():
    spec = importlib.util.spec_from_file_location("unsafe_helper", HELPER_SCRIPT)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"cannot load helper script: {HELPER_SCRIPT}")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


HELPER = load_helper_module()
UnsafeAnalysis = HELPER.UnsafeAnalysis
analyze_unsafe_global_in_content = HELPER.analyze_unsafe_global_in_content
count_unsafe_lines_precise = HELPER.count_unsafe_lines_precise


HEADER_RE = re.compile(
    r"^\[(?P<idx>\d+)/(?P<total>\d+)\]\s+"
    r"(?P<file>[^:]+):(?P<name>[^\s]+)\s+lines\s+(?P<start>\d+)-(?P<end>\d+)\s*$"
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="统计 Claude 五个项目 safer rewrite 前后的 unsafe 率"
    )
    parser.add_argument(
        "--projects",
        nargs="*",
        default=DEFAULT_PROJECTS,
        help="要分析的项目名，默认五个 Claude 项目",
    )
    parser.add_argument(
        "--json-output",
        type=Path,
        help="将结果写入 JSON 文件",
    )
    parser.add_argument(
        "--keep-merged-src",
        action="store_true",
        help="将合成后的 src 快照写到 saferAgent/results/<project>/<timestamp>/merged_src_snapshot",
    )
    return parser.parse_args()


def round_metrics(obj: Dict) -> Dict:
    rounded = {}
    for key, value in obj.items():
        rounded[key] = round(value, 6) if isinstance(value, float) else value
    return rounded


def format_ratio(value: float) -> str:
    return f"{value:.4%}"


def manifest_path_for(project_name: str) -> Path:
    return (
        RQ1_ROOT
        / "intermediate"
        / project_name
        / "workspace"
        / "extracted"
        / project_name
        / "functions_manifest.json"
    )


def target_files_from_manifest(manifest_path: Path, src_dir: Path) -> List[Path]:
    data = json.loads(manifest_path.read_text(encoding="utf-8"))
    source_files = sorted({item["source_file"] for item in data.get("functions", [])})
    return [
        src_dir / f"{source_file}.rs"
        for source_file in source_files
        if (src_dir / f"{source_file}.rs").exists()
    ]


def target_files_fallback(src_dir: Path) -> List[Path]:
    patterns = (
        re.compile(r"^src_.+\.rs$"),
        re.compile(r"^products_.+\.rs$"),
    )
    files: List[Path] = []
    for path in sorted(src_dir.glob("*.rs")):
        if any(pattern.match(path.name) for pattern in patterns):
            files.append(path)
    return files


def aggregate_unsafe_from_contents(file_contents: Dict[str, str]):
    result = UnsafeAnalysis()
    total_unsafe_block_lines = 0
    total_unsafe_fn_lines = 0

    for content in file_contents.values():
        result.total_lines += content.count("\n") + 1
        global_metrics = analyze_unsafe_global_in_content(content)
        result.code_lines += global_metrics.get("code_lines", 0)
        result.unsafe_keyword_occurrences += global_metrics.get("unsafe_keyword_occurrences", 0)
        result.unsafe_keyword_lines += global_metrics.get("unsafe_keyword_lines", 0)
        result.unsafe_context_lines += global_metrics.get("unsafe_context_lines", 0)
        result.unsafe_total_lines += global_metrics.get("unsafe_total_lines", 0)

        block_lines, fn_lines, block_count, fn_count = count_unsafe_lines_precise(content)
        total_unsafe_block_lines += block_lines
        total_unsafe_fn_lines += fn_lines
        result.unsafe_block_count += block_count
        result.unsafe_fn_count += fn_count
        result.unsafe_impl_count += len(re.findall(r"\bunsafe\s+impl\b", content))
        result.unsafe_trait_count += len(re.findall(r"\bunsafe\s+trait\b", content))

    result.files_analyzed = len(file_contents)
    result.total_unsafe_items = (
        result.unsafe_block_count
        + result.unsafe_fn_count
        + result.unsafe_impl_count
        + result.unsafe_trait_count
    )
    result.unsafe_lines_estimate = total_unsafe_block_lines + total_unsafe_fn_lines

    if result.code_lines > 0:
        result.unsafe_ratio = result.unsafe_lines_estimate / result.code_lines
        result.unsafe_keyword_ratio = result.unsafe_keyword_lines / result.code_lines
        result.unsafe_context_ratio = result.unsafe_context_lines / result.code_lines
        result.unsafe_total_ratio = result.unsafe_total_lines / result.code_lines
        result.unsafe_density_per_kloc = result.total_unsafe_items / result.code_lines * 1000.0

    return result


def discover_latest_result_dir(project_name: str) -> Path:
    project_root = SAFER_RESULTS_ROOT / project_name
    if not project_root.exists():
        raise FileNotFoundError(f"missing safer results dir: {project_root}")

    candidates = sorted(
        p for p in project_root.iterdir()
        if p.is_dir() and (p / "summary.json").exists()
    )
    if not candidates:
        raise FileNotFoundError(f"no summary.json under {project_root}")
    return candidates[-1]


def discover_log_file(project_name: str) -> Path:
    candidates = sorted(LOGS_ROOT.glob(f"safer_agent_{project_name}_*.log*"))
    if not candidates:
        raise FileNotFoundError(f"no safer log found for {project_name} in {LOGS_ROOT}")
    return candidates[-1]


def project_src_dir(project_name: str) -> Path:
    return CLAUDE_FINAL_ROOT / project_name / "translate_by_qwen3_coder" / "src"


def choose_target_files(project_name: str, src_dir: Path) -> Tuple[List[Path], str, Optional[Path]]:
    manifest_path = manifest_path_for(project_name)
    if manifest_path.exists():
        return target_files_from_manifest(manifest_path, src_dir), "manifest", manifest_path
    return target_files_fallback(src_dir), "fallback_by_filename", None


def build_key(file_name: str, func_name: str, start_line: int) -> str:
    return f"{file_name}:{func_name}:{start_line}"


def parse_log_statuses(log_path: Path) -> Dict[str, str]:
    results: Dict[str, str] = {}
    current_key: Optional[str] = None
    skip_fallback = False
    skip_no_unsafe = False
    workspace_ok = False
    workspace_failed = False
    compile_passed = False
    compile_failed = False

    def flush() -> None:
        nonlocal current_key, skip_fallback, skip_no_unsafe
        nonlocal workspace_ok, workspace_failed, compile_passed, compile_failed
        if current_key is None:
            return

        if skip_fallback:
            status = "skip_fallback"
        elif skip_no_unsafe:
            status = "skip_no_unsafe"
        elif workspace_failed:
            status = "workspace_failed"
        elif workspace_ok and compile_passed:
            status = "accepted"
        elif workspace_ok and compile_failed:
            status = "compile_failed"
        else:
            status = "other"

        results[current_key] = status
        current_key = None
        skip_fallback = False
        skip_no_unsafe = False
        workspace_ok = False
        workspace_failed = False
        compile_passed = False
        compile_failed = False

    for line in log_path.read_text(encoding="utf-8", errors="ignore").splitlines():
        match = HEADER_RE.match(line)
        if match:
            flush()
            current_key = build_key(
                match.group("file"),
                match.group("name"),
                int(match.group("start")),
            )
            continue

        if current_key is None:
            continue
        if "-> skip fallback" in line:
            skip_fallback = True
        elif "-> skip no-unsafe" in line:
            skip_no_unsafe = True
        elif "workspace_apply: ok" in line:
            workspace_ok = True
        elif "workspace_apply: failed" in line:
            workspace_failed = True
        elif "compile_check: passed" in line:
            compile_passed = True
        elif "compile_check: failed" in line:
            compile_failed = True

    flush()
    return results


def is_ident_char(ch: str) -> bool:
    return ch.isalnum() or ch == "_"


def strip_line_comment(line: str) -> str:
    idx = line.find("//")
    return line if idx < 0 else line[:idx]


def find_function_signature(content: str, func_name: str) -> int:
    pattern = re.compile(rf"\bfn\s+{re.escape(func_name)}\b")
    for match in pattern.finditer(content):
        pos = match.start()
        prev = content[pos - 1] if pos > 0 else "\n"
        if is_ident_char(prev):
            continue
        line_start = content.rfind("\n", 0, pos) + 1
        line = content[line_start:content.find("\n", line_start) if "\n" in content[line_start:] else len(content)]
        if strip_line_comment(line).find(f"fn {func_name}") == -1:
            continue
        return pos
    raise ValueError(f"cannot find function signature for {func_name}")


def find_matching_brace(content: str, open_idx: int) -> int:
    depth = 0
    i = open_idx
    in_line_comment = False
    in_block_comment = 0
    in_string: Optional[str] = None
    escape = False

    while i < len(content):
        ch = content[i]
        nxt = content[i + 1] if i + 1 < len(content) else ""

        if in_line_comment:
            if ch == "\n":
                in_line_comment = False
            i += 1
            continue

        if in_block_comment:
            if ch == "/" and nxt == "*":
                in_block_comment += 1
                i += 2
                continue
            if ch == "*" and nxt == "/":
                in_block_comment -= 1
                i += 2
                continue
            i += 1
            continue

        if in_string is not None:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == in_string:
                in_string = None
            i += 1
            continue

        if ch == "/" and nxt == "/":
            in_line_comment = True
            i += 2
            continue
        if ch == "/" and nxt == "*":
            in_block_comment = 1
            i += 2
            continue
        if ch in ("'", '"'):
            in_string = ch
            i += 1
            continue

        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1

    raise ValueError("unmatched brace while scanning function body")


def extract_function_span(content: str, func_name: str) -> Tuple[int, int]:
    sig_idx = find_function_signature(content, func_name)
    start = sig_idx

    line_start = content.rfind("\n", 0, sig_idx) + 1
    while line_start > 0:
        prev_newline = content.rfind("\n", 0, line_start - 1)
        prev_start = prev_newline + 1
        prev_line = content[prev_start:line_start - 1]
        stripped = prev_line.strip()
        if stripped.startswith("#["):
            start = prev_start
            line_start = prev_start
            continue
        break

    open_idx = content.find("{", sig_idx)
    if open_idx < 0:
        raise ValueError(f"cannot find function body start for {func_name}")
    close_idx = find_matching_brace(content, open_idx)

    end = close_idx + 1
    while end < len(content) and content[end] == "\r":
        end += 1
    if end < len(content) and content[end] == "\n":
        end += 1
    return start, end


def extract_function_text(content: str, func_name: str) -> str:
    start, end = extract_function_span(content, func_name)
    return content[start:end]


def replace_function_text(content: str, func_name: str, new_text: str) -> str:
    start, end = extract_function_span(content, func_name)
    return content[:start] + new_text + content[end:]


def parse_uid(uid: str) -> Tuple[str, int, str]:
    stem, start_str, name = uid.split(":", 2)
    return f"{stem}.rs", int(start_str), name


def accepted_rewrites_from_log(summary_data: Dict, log_status: Dict[str, str]) -> List[Dict]:
    rewrites: List[Dict] = []
    seen = set()

    for item in summary_data.get("results", []):
        uid = item["uid"]
        file_name, start_line, func_name = parse_uid(uid)
        key = build_key(file_name, func_name, start_line)
        status = log_status.get(key)
        output_dir = Path(item["output_dir"])
        if status != "accepted":
            continue
        if not output_dir.exists():
            continue
        dedup_key = (file_name, start_line, func_name)
        if dedup_key in seen:
            continue
        rewrites.append(
            {
                "uid": uid,
                "file_name": file_name,
                "start_line": start_line,
                "func_name": func_name,
                "output_dir": output_dir,
            }
        )
        seen.add(dedup_key)

    rewrites.sort(key=lambda item: (item["file_name"], item["start_line"]))
    return rewrites


def merge_project_after_rewrite(
    project_name: str,
    result_dir: Path,
    source_src_dir: Path,
    target_files: Sequence[Path],
    accepted_rewrites: Sequence[Dict],
) -> Tuple[Dict[str, str], Dict[str, int]]:
    file_contents: Dict[str, str] = {
        path.name: path.read_text(encoding="utf-8", errors="ignore")
        for path in target_files
    }

    grouped: Dict[str, List[Dict]] = {}
    for item in accepted_rewrites:
        grouped.setdefault(item["file_name"], []).append(item)

    applied = 0
    skipped_missing_workspace = 0
    skipped_extract_error = 0

    for file_name, items in grouped.items():
        if file_name not in file_contents:
            continue
        merged = file_contents[file_name]
        for item in sorted(items, key=lambda x: x["start_line"], reverse=True):
            workspace_file = item["output_dir"] / "workspace" / "src" / file_name
            if not workspace_file.exists():
                skipped_missing_workspace += 1
                continue
            workspace_content = workspace_file.read_text(encoding="utf-8", errors="ignore")
            try:
                rewritten_func = extract_function_text(workspace_content, item["func_name"])
                merged = replace_function_text(merged, item["func_name"], rewritten_func)
                applied += 1
            except Exception:
                skipped_extract_error += 1
        file_contents[file_name] = merged

    return file_contents, {
        "accepted_rewrite_functions": len(accepted_rewrites),
        "applied_function_replacements": applied,
        "skipped_missing_workspace": skipped_missing_workspace,
        "skipped_extract_error": skipped_extract_error,
    }


def analyze_project(project_name: str, keep_merged_src: bool) -> Dict:
    result_dir = discover_latest_result_dir(project_name)
    summary_path = result_dir / "summary.json"
    summary_data = json.loads(summary_path.read_text(encoding="utf-8"))
    log_path = discover_log_file(project_name)
    src_dir = project_src_dir(project_name)

    if not src_dir.exists():
        raise FileNotFoundError(f"missing original Claude src dir: {src_dir}")

    target_files, selection_mode, manifest_path = choose_target_files(project_name, src_dir)
    if not target_files:
        raise RuntimeError(f"no target files selected for {project_name}")

    before_contents = {
        path.name: path.read_text(encoding="utf-8", errors="ignore")
        for path in target_files
    }
    before_metrics = aggregate_unsafe_from_contents(before_contents)

    log_status = parse_log_statuses(log_path)
    accepted_rewrites = accepted_rewrites_from_log(summary_data, log_status)
    after_contents, merge_stats = merge_project_after_rewrite(
        project_name=project_name,
        result_dir=result_dir,
        source_src_dir=src_dir,
        target_files=target_files,
        accepted_rewrites=accepted_rewrites,
    )
    after_metrics = aggregate_unsafe_from_contents(after_contents)

    if keep_merged_src:
        snapshot_dir = result_dir / "merged_src_snapshot"
        snapshot_dir.mkdir(parents=True, exist_ok=True)
        for file_name, content in after_contents.items():
            (snapshot_dir / file_name).write_text(content, encoding="utf-8")

    accepted = sum(1 for status in log_status.values() if status == "accepted")
    compile_failed = sum(1 for status in log_status.values() if status == "compile_failed")
    workspace_failed = sum(1 for status in log_status.values() if status == "workspace_failed")
    skip_fallback = sum(1 for status in log_status.values() if status == "skip_fallback")
    skip_no_unsafe = sum(1 for status in log_status.values() if status == "skip_no_unsafe")

    return {
        "project": project_name,
        "result_dir": str(result_dir),
        "log_path": str(log_path),
        "selection_mode": selection_mode,
        "manifest_path": str(manifest_path) if manifest_path else None,
        "included_files": [path.name for path in target_files],
        "status_counts_from_log": {
            "accepted": accepted,
            "compile_failed": compile_failed,
            "workspace_failed": workspace_failed,
            "skip_fallback": skip_fallback,
            "skip_no_unsafe": skip_no_unsafe,
        },
        "merge_stats": merge_stats,
        "before_unsafe": round_metrics(asdict(before_metrics)),
        "after_unsafe": round_metrics(asdict(after_metrics)),
        "delta": {
            "unsafe_total_lines": after_metrics.unsafe_total_lines - before_metrics.unsafe_total_lines,
            "unsafe_block_count": after_metrics.unsafe_block_count - before_metrics.unsafe_block_count,
            "unsafe_fn_count": after_metrics.unsafe_fn_count - before_metrics.unsafe_fn_count,
            "unsafe_total_ratio": round(after_metrics.unsafe_total_ratio - before_metrics.unsafe_total_ratio, 6),
            "unsafe_keyword_ratio": round(after_metrics.unsafe_keyword_ratio - before_metrics.unsafe_keyword_ratio, 6),
            "unsafe_context_ratio": round(after_metrics.unsafe_context_ratio - before_metrics.unsafe_context_ratio, 6),
        },
    }


def print_project_report(item: Dict) -> None:
    before = item["before_unsafe"]
    after = item["after_unsafe"]
    counts = item["status_counts_from_log"]

    print(f"\n[{item['project']}]")
    print(
        f"files={len(item['included_files'])}, accepted={counts['accepted']}, "
        f"compile_failed={counts['compile_failed']}, workspace_failed={counts['workspace_failed']}, "
        f"skip_fallback={counts['skip_fallback']}, skip_no_unsafe={counts['skip_no_unsafe']}"
    )
    print(
        f"before: code_lines={before['code_lines']}, unsafe_total_lines={before['unsafe_total_lines']} "
        f"({format_ratio(before['unsafe_total_ratio'])}), unsafe_items={before['total_unsafe_items']}"
    )
    print(
        f"after : code_lines={after['code_lines']}, unsafe_total_lines={after['unsafe_total_lines']} "
        f"({format_ratio(after['unsafe_total_ratio'])}), unsafe_items={after['total_unsafe_items']}"
    )
    print(
        f"delta : unsafe_total_lines={item['delta']['unsafe_total_lines']}, "
        f"unsafe_total_ratio={item['delta']['unsafe_total_ratio']:+.4%}, "
        f"unsafe_block_count={item['delta']['unsafe_block_count']:+d}, "
        f"unsafe_fn_count={item['delta']['unsafe_fn_count']:+d}"
    )


def summarize(results: Sequence[Dict]) -> Dict:
    summary = {
        "projects": len(results),
        "before_code_lines": 0,
        "before_unsafe_total_lines": 0,
        "after_code_lines": 0,
        "after_unsafe_total_lines": 0,
        "before_total_unsafe_items": 0,
        "after_total_unsafe_items": 0,
        "accepted": 0,
        "compile_failed": 0,
        "workspace_failed": 0,
        "skip_fallback": 0,
        "skip_no_unsafe": 0,
    }
    for item in results:
        before = item["before_unsafe"]
        after = item["after_unsafe"]
        counts = item["status_counts_from_log"]
        summary["before_code_lines"] += before["code_lines"]
        summary["before_unsafe_total_lines"] += before["unsafe_total_lines"]
        summary["after_code_lines"] += after["code_lines"]
        summary["after_unsafe_total_lines"] += after["unsafe_total_lines"]
        summary["before_total_unsafe_items"] += before["total_unsafe_items"]
        summary["after_total_unsafe_items"] += after["total_unsafe_items"]
        for key in ("accepted", "compile_failed", "workspace_failed", "skip_fallback", "skip_no_unsafe"):
            summary[key] += counts[key]

    summary["before_unsafe_total_ratio"] = (
        summary["before_unsafe_total_lines"] / summary["before_code_lines"]
        if summary["before_code_lines"] else 0.0
    )
    summary["after_unsafe_total_ratio"] = (
        summary["after_unsafe_total_lines"] / summary["after_code_lines"]
        if summary["after_code_lines"] else 0.0
    )
    summary["delta_unsafe_total_lines"] = (
        summary["after_unsafe_total_lines"] - summary["before_unsafe_total_lines"]
    )
    summary["delta_unsafe_total_ratio"] = round(
        summary["after_unsafe_total_ratio"] - summary["before_unsafe_total_ratio"], 6
    )
    return summary


def main() -> int:
    args = parse_args()

    results: List[Dict] = []
    for project_name in args.projects:
        results.append(analyze_project(project_name, args.keep_merged_src))

    summary = summarize(results)

    print("Claude RQ1 safer rewrite unsafe analysis")
    print(f"projects: {', '.join(args.projects)}")
    print(
        f"overall before: unsafe_total_lines={summary['before_unsafe_total_lines']} "
        f"({format_ratio(summary['before_unsafe_total_ratio'])})"
    )
    print(
        f"overall after : unsafe_total_lines={summary['after_unsafe_total_lines']} "
        f"({format_ratio(summary['after_unsafe_total_ratio'])})"
    )
    print(
        f"overall delta : unsafe_total_lines={summary['delta_unsafe_total_lines']}, "
        f"unsafe_total_ratio={summary['delta_unsafe_total_ratio']:+.4%}"
    )

    for item in results:
        print_project_report(item)

    if args.json_output:
        payload = {
            "projects": args.projects,
            "summary": round_metrics(summary),
            "results": results,
        }
        args.json_output.write_text(
            json.dumps(payload, ensure_ascii=False, indent=2),
            encoding="utf-8",
        )
        print(f"\njson written to: {args.json_output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
