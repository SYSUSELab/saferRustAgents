#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
from pathlib import Path
from typing import Any, Callable, Dict, List, Optional, Sequence

from .agentic_rag_agent import AgenticRAGAgent


COMPILE_FIX_STRATEGY_GUIDANCE = """
Additional compile-fix strategy guidance:

- Treat compile errors as feedback for refining the safer rewrite, not as a reason to immediately fall back to the original C-style API usage.
- If the previous rewrite was already trying to use a safer Rust/OpenHarmony API from the knowledge base, prefer preserving that API direction and fixing the concrete misuse exposed by the compiler.
- Use compiler feedback as an API-discovery tool: missing trait imports, wrong method names, wrong indexing style, wrong enum variant matching, wrong parse entrypoints, and caller signature mismatches are all normal signals for the next retry.
- Be proactive about bold but grounded retries based on compiler evidence: fix missing imports, trait imports, method names, type conversions, indexing style, iteration APIs, ownership mismatches, caller updates, and signature adjustments before abandoning the safer API path.
- When a knowledge-base API appears semantically compatible, try multiple compile-driven corrections across rounds instead of reverting to the original function body after the first failure.
- Before the final round, prefer another targeted safer-API attempt over reverting to the original unsafe/C-style implementation.
- Only in the final round, or when the history already shows that the selected safer API is unavailable or semantically incompatible after multiple distinct targeted attempts, may you move noticeably closer to the original implementation.
- Only fall back to the old cJSON/libc/compat-heavy implementation when the compile evidence strongly suggests the safer API is unavailable or would materially change semantics after several targeted attempts.
- If caller update targets are available, you are encouraged to change call sites together with the callee when that helps preserve the safer API design.
- Prefer salvaging and correcting the previous safer rewrite over replacing it wholesale with the original implementation.
- Read the previous compile-fix history carefully and do not repeat the same syntax or API-shape mistake in a later round.
""".strip()


class CompileFixAgent:
    def __init__(
        self,
        *,
        model: str,
        client,
        logger: Callable[[str], None],
        prompt_template: str,
        chat: Callable[[str, Optional[str]], str],
        knowledge_base_path,
    ) -> None:
        self.model = model
        self.client = client
        self.logger = logger
        self.prompt_template = prompt_template
        self.chat = chat
        self.knowledge_base_path = knowledge_base_path

    def run(
        self,
        *,
        function: Dict[str, Any],
        symbol_contexts: Sequence[Dict[str, Any]],
        caller_contexts: Sequence[Dict[str, Any]],
        previous_rag_result: Dict[str, Any],
        previous_rewrite: Dict[str, Any],
        compile_check: Dict[str, Any],
        fix_history: Sequence[Dict[str, Any]],
        round_index: int,
        max_rounds: int,
        format_symbol_contexts: Callable[[Sequence[Dict[str, Any]]], str],
        format_caller_contexts: Callable[[Sequence[Dict[str, Any]]], str],
        format_api_knowledge: Callable[[Dict[str, Any]], str],
        flatten_caller_call_sites: Callable[[Sequence[Dict[str, Any]]], List[Dict[str, Any]]],
        build_caller_fixes: Callable[[Sequence[Dict[str, Any]], Sequence[str]], List[Dict[str, Any]]],
        extract_tag_blocks: Callable[[str, str], List[str]],
        extract_func_block: Callable[[str], Optional[str]],
        strip_code_fence: Callable[[str], str],
        normalize_use_statement: Callable[[str], str],
        is_valid_dependency_line: Callable[[str], bool],
    ) -> Dict[str, Any]:
        caller_fix_targets = flatten_caller_call_sites(caller_contexts)
        compile_errors = self._extract_compile_errors((compile_check or {}).get("stderr") or "")
        previous_prompt = previous_rewrite.get("rewrite_prompt") or ""

        diagnosis = self._diagnose_compile_failure(function, compile_errors, previous_prompt)
        llm_calls = 1 if diagnosis.get("used_llm") else 0

        rag_trace = {
            "diagnosis": {k: v for k, v in diagnosis.items() if k != "messages"},
            "example_code_search": None,
            "selection": None,
            "selected_api_entries": [],
        }

        selected_api_entries = list(previous_rag_result.get("selected_api_entries") or [])
        if diagnosis.get("should_run_example_code_search"):
            rag_agent = AgenticRAGAgent(
                knowledge_base_path=self.knowledge_base_path,
                model=self.model,
                client=self.client,
                logger=self.logger,
            )
            search_result = rag_agent.search_example_code_entries(diagnosis.get("example_code_queries") or [], top_n=3)
            rag_trace["example_code_search"] = search_result
            selection = rag_agent.select_example_code_entries_for_fix(
                function=function,
                compile_errors=compile_errors,
                queries=search_result.get("queries") or [],
                aggregated_matches=search_result.get("aggregated_matches") or [],
                max_selected=3,
            )
            rag_trace["selection"] = selection
            if selection.get("used_llm"):
                llm_calls += 1
            selected_api_entries.extend(selection.get("selected_entries") or [])
            rag_trace["selected_api_entries"] = selected_api_entries

        fix_rag_result = {"selected_api_entries": self._dedupe_api_entries(selected_api_entries)}
        round_strategy_guidance = self._build_round_strategy_guidance(round_index, max_rounds)
        history_avoidance_summary = self._build_history_avoidance_summary(fix_history)
        fix_prompt = self.prompt_template.format(
            round_index=round_index,
            max_rounds=max_rounds,
            is_final_round="yes" if round_index >= max_rounds else "no",
            round_strategy_guidance=round_strategy_guidance,
            history_avoidance_summary=history_avoidance_summary,
            original_source=function["source"],
            symbol_context=format_symbol_contexts(symbol_contexts),
            caller_context=format_caller_contexts(caller_contexts),
            previous_api_knowledge=format_api_knowledge(previous_rag_result),
            fix_api_knowledge=format_api_knowledge(fix_rag_result),
            compile_errors=json.dumps(compile_errors, ensure_ascii=False, indent=2),
            fix_history=json.dumps(list(fix_history), ensure_ascii=False, indent=2),
            previous_rewrite_prompt=previous_prompt,
            previous_rewritten_function=previous_rewrite.get("rewritten_function") or "",
            diagnosis=json.dumps({k: v for k, v in diagnosis.items() if k not in {"messages", "raw_response"}}, ensure_ascii=False, indent=2),
        )
        fix_prompt = f"{fix_prompt}\n\n{COMPILE_FIX_STRATEGY_GUIDANCE}\n"

        if self.client is None:
            return {
                "used_llm": False,
                "valid_output": False,
                "analysis": "LLM unavailable; compile-fix stage skipped.",
                "raw_response": None,
                "rewrite_prompt": fix_prompt,
                "rewritten_function": None,
                "func": None,
                "add_use_statements": [],
                "remove_use_statements": [],
                "caller_fixes": [],
                "add_cargo_dependencies": [],
                "remove_cargo_dependencies": [],
                "function_tags": [],
                "compile_errors": compile_errors,
                "round_index": round_index,
                "max_rounds": max_rounds,
                "fix_history": list(fix_history),
                "diagnosis": diagnosis,
                "agentic_rag": rag_trace,
                "model": self.model,
                "llm_calls": llm_calls,
            }

        response_text = self.chat(fix_prompt, self.model)
        func_block = extract_func_block(response_text)
        add_use_statements = self._extract_use_like_tags(response_text, "ADD_USE", extract_tag_blocks, normalize_use_statement)
        remove_use_statements = self._extract_use_like_tags(response_text, "DELETE_USE", extract_tag_blocks, normalize_use_statement)
        add_cargo_dependencies = self._extract_dependency_like_tags(response_text, "ADD_CARGO_DEPENDENCY", extract_tag_blocks, strip_code_fence, is_valid_dependency_line)
        remove_cargo_dependencies = self._extract_dependency_like_tags(response_text, "DELETE_CARGO_DEPENDENCY", extract_tag_blocks, strip_code_fence, lambda _: True)
        fix_caller_lines = self._extract_simple_blocks(response_text, "fix_caller", extract_tag_blocks, strip_code_fence)
        valid_output = func_block is not None
        return {
            "used_llm": True,
            "valid_output": valid_output,
            "analysis": "missing valid <FUNC> block in compile-fix output" if not valid_output else "",
            "raw_response": response_text,
            "rewrite_prompt": fix_prompt,
            "rewritten_function": func_block,
            "func": func_block,
            "add_use_statements": add_use_statements,
            "remove_use_statements": remove_use_statements,
            "caller_fixes": build_caller_fixes(caller_fix_targets, fix_caller_lines),
            "add_cargo_dependencies": add_cargo_dependencies,
            "remove_cargo_dependencies": remove_cargo_dependencies,
            "function_tags": extract_tag_blocks(response_text, "FUNCTION_TAG"),
            "compile_errors": compile_errors,
            "round_index": round_index,
            "max_rounds": max_rounds,
            "fix_history": list(fix_history),
            "diagnosis": diagnosis,
            "agentic_rag": rag_trace,
            "model": self.model,
            "llm_calls": llm_calls + 1,
        }

    def _diagnose_compile_failure(self, function: Dict[str, Any], compile_errors: Sequence[str], previous_prompt: str) -> Dict[str, Any]:
        system_prompt = (
            "You are diagnosing compile errors from a previous safer-rewrite stage. "
            "Return valid JSON only. "
            "Use the top-level shape "
            "{\"likely_api_knowledge_gap\": bool, \"should_run_agentic_rag\": bool, \"should_run_example_code_search\": bool, "
            "\"example_code_queries\": [\"string\"], \"reason\": \"string\"}. "
            "Prefer enabling AgenticRAG when API usage knowledge would help salvage the safer rewrite instead of abandoning the Rust API direction. "
            "If compile failures look like incorrect use of a safer Rust/OpenHarmony API, bias toward more compile-driven retries and example-code retrieval instead of reverting to the original unsafe/C-style implementation."
        )
        user_payload = {
            "function_name": function.get("name", ""),
            "function_source": function.get("source", ""),
            "compile_errors": list(compile_errors),
            "previous_rewrite_prompt_excerpt": previous_prompt[:6000],
        }
        if self.client is None:
            return {
                "used_llm": False,
                "likely_api_knowledge_gap": False,
                "should_run_agentic_rag": False,
                "should_run_example_code_search": False,
                "example_code_queries": [],
                "reason": "LLM unavailable; compile-fix diagnosis skipped",
            }
        response_text = self.chat(
            "\n\n".join(
                [
                    system_prompt,
                    json.dumps(user_payload, ensure_ascii=False, indent=2),
                ]
            ),
            self.model,
        )
        payload = self._extract_json(response_text) or {}
        queries: List[str] = []
        for item in payload.get("example_code_queries", []) if isinstance(payload, dict) else []:
            candidate = (item or "").strip()
            if candidate and candidate not in queries:
                queries.append(candidate)
        return {
            "used_llm": True,
            "raw_response": response_text,
            "likely_api_knowledge_gap": bool(payload.get("likely_api_knowledge_gap")),
            "should_run_agentic_rag": bool(payload.get("should_run_agentic_rag")),
            "should_run_example_code_search": bool(payload.get("should_run_example_code_search")) or bool(queries),
            "example_code_queries": queries[:5],
            "reason": payload.get("reason", "") if isinstance(payload, dict) else "",
        }

    def _build_round_strategy_guidance(self, round_index: int, max_rounds: int) -> str:
        if round_index >= max_rounds:
            return (
                "This is the final allowed compile-fix round. You should still prefer a semantically compatible "
                "safer/OpenHarmony API repair if one looks viable, but if repeated targeted attempts have already "
                "failed and the safer API direction still does not compile, you may choose a minimal fallback toward "
                "the original implementation to get a correct build."
            )
        return (
            "This is not the final compile-fix round. Prioritize preserving the safer/OpenHarmony API direction and "
            "use the compiler as feedback to explore the actual API shape. Do not revert to the original cJSON/libc/"
            "compat-heavy implementation merely because the current attempt used the wrong method name, trait import, "
            "signature, indexing style, or conversion path."
        )

    def _build_history_avoidance_summary(self, fix_history: Sequence[Dict[str, Any]]) -> str:
        patterns: List[str] = []
        seen = set()
        for item in fix_history or []:
            for field in ("compile_errors_before", "compile_errors_after"):
                for err in item.get(field) or []:
                    first_line = ""
                    for line in str(err).splitlines():
                        stripped = line.strip()
                        if stripped:
                            first_line = stripped
                            break
                    if not first_line or first_line in seen:
                        continue
                    seen.add(first_line)
                    patterns.append(first_line)
                    if len(patterns) >= 8:
                        break
                if len(patterns) >= 8:
                    break
            if len(patterns) >= 8:
                break
        if not patterns:
            return "No previous compile-fix mistakes are recorded yet."
        return "\n".join(f"- Avoid repeating: {pattern}" for pattern in patterns)

    def _extract_compile_errors(self, stderr: str) -> List[str]:
        errors: List[str] = []
        current: List[str] = []
        for raw_line in (stderr or "").splitlines():
            line = raw_line.rstrip()
            stripped = line.strip()
            if stripped.startswith("warning:"):
                if current:
                    errors.append("\n".join(current).strip())
                    current = []
                continue
            if stripped.startswith("error[") or stripped.startswith("error:"):
                if current:
                    errors.append("\n".join(current).strip())
                current = [line]
                continue
            if not current:
                continue
            if stripped.startswith("Some errors have detailed explanations"):
                errors.append("\n".join(current).strip())
                current = []
                continue
            if stripped.startswith("For more information about this error"):
                continue
            current.append(line)
        if current:
            errors.append("\n".join(current).strip())
        return [item for item in errors if item]

    def _extract_use_like_tags(
        self,
        text: str,
        tag: str,
        extract_tag_blocks: Callable[[str, str], List[str]],
        normalize_use_statement: Callable[[str], str],
    ) -> List[str]:
        statements: List[str] = []
        seen = set()
        for block in extract_tag_blocks(text, tag):
            for line in block.splitlines():
                candidate = normalize_use_statement(line)
                if candidate and candidate not in seen:
                    seen.add(candidate)
                    statements.append(candidate)
        return statements

    def _extract_dependency_like_tags(
        self,
        text: str,
        tag: str,
        extract_tag_blocks: Callable[[str, str], List[str]],
        strip_code_fence: Callable[[str], str],
        validator: Callable[[str], bool],
    ) -> List[str]:
        lines: List[str] = []
        seen = set()
        for block in extract_tag_blocks(text, tag):
            for raw_line in block.splitlines():
                candidate = strip_code_fence(raw_line).strip()
                if not candidate or candidate in seen:
                    continue
                if validator(candidate):
                    seen.add(candidate)
                    lines.append(candidate)
        return lines

    def _extract_simple_blocks(
        self,
        text: str,
        tag: str,
        extract_tag_blocks: Callable[[str, str], List[str]],
        strip_code_fence: Callable[[str], str],
    ) -> List[str]:
        blocks: List[str] = []
        for block in extract_tag_blocks(text, tag):
            candidate = strip_code_fence(block).strip()
            if candidate:
                blocks.append(candidate)
        return blocks

    def _extract_json(self, text: str) -> Optional[Dict[str, Any]]:
        candidate = (text or "").strip()
        if not candidate:
            return None
        if candidate.startswith("```"):
            lines = candidate.splitlines()
            if len(lines) >= 3 and lines[-1].strip() == "```":
                candidate = "\n".join(lines[1:-1]).strip()
        try:
            payload = json.loads(candidate)
        except Exception:
            match = re.search(r"\{.*\}", candidate, re.DOTALL)
            if not match:
                return None
            try:
                payload = json.loads(match.group(0))
            except Exception:
                return None
        return payload if isinstance(payload, dict) else None

    def _dedupe_api_entries(self, entries: Sequence[Dict[str, Any]]) -> List[Dict[str, Any]]:
        deduped: List[Dict[str, Any]] = []
        seen = set()
        for item in entries:
            kb_id = item.get("kb_id")
            key = (kb_id, item.get("api_name", ""))
            if key in seen:
                continue
            seen.add(key)
            deduped.append(dict(item))
        return deduped


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Offline iterative compile-fix runner for saferAgent result directories")
    parser.add_argument("results_dir", type=Path, help="Existing saferAgent results/<project>/<timestamp> directory")
    parser.add_argument("--target-function", help="Only repair one function directory under results_dir/functions/")
    parser.add_argument("--max-rounds", type=int, default=5, help="Maximum compile-fix rounds per function")
    parser.add_argument("--model", help="Default LLM model")
    parser.add_argument("--context-model", help="Model for context_agent stage")
    parser.add_argument("--rag-model", help="Model for agentic_rag stage")
    parser.add_argument("--rewrite-model", help="Model for final rewrite stage")
    parser.add_argument("--compile-fix-model", help="Model for compile_fix stage")
    parser.add_argument("--workspace-edit-model", help="Model for workspace edit stage")
    parser.add_argument("--api-key", help="LLM API key; defaults to SAFER_AGENT_API_KEY or apiyiTestkey.py")
    parser.add_argument("--base-url", help="LLM base URL; defaults to SAFER_AGENT_BASE_URL or apiyiTestkey.py")
    parser.add_argument("--knowledge-base-path", type=Path, help="OpenHarmony Rust API knowledge base JSON path")
    parser.add_argument("--dry-run", action="store_true", help="Disable LLM calls and only execute the offline control flow")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    results_dir = args.results_dir.resolve()
    baseline_project = results_dir / "workspaces" / "_baseline_project"
    if not baseline_project.exists():
        raise FileNotFoundError(f"baseline workspace not found: {baseline_project}")

    from .safer_agent import SaferAgent

    agent = SaferAgent(
        project_path=baseline_project,
        output_dir=results_dir,
        model=args.model,
        context_model=args.context_model,
        rag_model=args.rag_model,
        rewrite_model=args.rewrite_model,
        compile_fix_model=args.compile_fix_model,
        workspace_edit_model=args.workspace_edit_model,
        api_key=args.api_key or os.environ.get("SAFER_AGENT_API_KEY"),
        base_url=args.base_url or os.environ.get("SAFER_AGENT_BASE_URL"),
        dry_run=args.dry_run,
        knowledge_base_path=args.knowledge_base_path,
        allow_missing_tree_sitter=True,
    )
    summary = agent.repair_existing_results_dir(
        results_dir,
        max_rounds=max(1, args.max_rounds),
        target_function=args.target_function,
    )
    print(json.dumps(summary, ensure_ascii=False, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
