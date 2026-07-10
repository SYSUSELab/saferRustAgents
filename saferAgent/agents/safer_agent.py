#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import time
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, List, Optional, Sequence, Tuple

from openai import OpenAI

from .agentic_rag_agent import AgenticRAGAgent
from .compile_fix_agent import CompileFixAgent
from .symbol_context_agent import SymbolContextAgent
from .workspace_edit_agent import WorkspaceEditAgent

try:
    from tree_sitter import Language, Parser
    import tree_sitter_rust
except Exception:
    Language = None
    Parser = None
    tree_sitter_rust = None


THIS_DIR = Path(__file__).resolve().parents[1]
DEFAULT_PROMPT_PATH = THIS_DIR / "prompt" / "unsafeRustToSafeRust.md"
DEFAULT_WORKSPACE_EDIT_PROMPT_PATH = THIS_DIR / "prompt" / "workspaceEditApply.md"
DEFAULT_COMPILE_FIX_PROMPT_PATH = THIS_DIR / "prompt" / "compileFixAfterRewrite.md"
DEFAULT_SEARCH_BIN_DIR = THIS_DIR / "search" / "bin"
DEFAULT_API_EXAMPLE_PATH = THIS_DIR / "apiyiTestkey.py"
DEFAULT_OH_RUST_API_KB_PATH = THIS_DIR.parent / "knowledgeBaseConstruct" / "openharmony_third_party_rust_api_kb.json"


FALLBACK_MARKERS = (
    "C2Rust fallback",
    "C2R MANUAL FIX REQUIRED",
    "__c2rust_fallback",
)

CALL_TARGET_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
DEPENDENCY_NAME_RE = re.compile(r"^\s*([A-Za-z0-9_.-]+)\s*=")

UNSAFE_PATTERNS = (
    re.compile(r"\bunsafe\b"),
    re.compile(r"\bstd::mem::zeroed\s*\("),
    re.compile(r"\bMaybeUninit\b"),
    re.compile(r"\blibc::"),
    re.compile(r"\bcrate::compat::"),
)


@dataclass
class FunctionRecord:
    uid: str
    name: str
    file_path: Path
    start_line: int
    end_line: int
    source: str
    pre_context: str
    contains_unsafe: bool
    is_fallback: bool


class SaferAgent:
    DEFAULT_STAGE_MODELS = {
        "context_agent": "deepseek-chat",
        "agentic_rag": "deepseek-reasoner",
        "final_rewrite": "deepseek-reasoner",
        "compile_fix": "deepseek-reasoner",
        "workspace_edit": "deepseek-chat",
    }
    FUNCTION_RESULT_SUBDIRS = {
        "inputs": "inputs",
        "traces": "traces",
        "rewrite": "rewrite",
        "artifacts": "artifacts",
        "workspace": "workspace",
    }

    def _log(self, message: str) -> None:
        print(message, flush=True)

    def __init__(
        self,
        project_path: Path,
        output_dir: Optional[Path] = None,
        model: Optional[str] = None,
        context_model: Optional[str] = None,
        rag_model: Optional[str] = None,
        rewrite_model: Optional[str] = None,
        compile_fix_model: Optional[str] = None,
        workspace_edit_model: Optional[str] = None,
        api_key: Optional[str] = None,
        base_url: Optional[str] = None,
        dry_run: bool = False,
        limit_functions: Optional[int] = None,
        knowledge_base_path: Optional[Path] = None,
        target_file: Optional[Path] = None,
        stop_before_uid: Optional[str] = None,
        resume_from_uid: Optional[str] = None,
        reset_resume_function_dir: bool = False,
        skip_context_agent: bool = False,
        allow_missing_tree_sitter: bool = False,
    ) -> None:
        self.project_input = project_path.resolve()
        self.source_project_root = self._resolve_project_root(self.project_input)
        self.project_root = self.source_project_root
        self.src_dir = self.project_root / "src"
        self.project_name = self._resolve_project_name()
        self.manifest_path = self._infer_manifest_path()
        self.prompt_template = DEFAULT_PROMPT_PATH.read_text(encoding="utf-8")
        self.workspace_edit_prompt_template = DEFAULT_WORKSPACE_EDIT_PROMPT_PATH.read_text(encoding="utf-8")
        self.compile_fix_prompt_template = DEFAULT_COMPILE_FIX_PROMPT_PATH.read_text(encoding="utf-8")
        self.search_bin_dir = DEFAULT_SEARCH_BIN_DIR
        self.dry_run = dry_run
        self.limit_functions = limit_functions
        self.knowledge_base_path = (knowledge_base_path or DEFAULT_OH_RUST_API_KB_PATH).resolve()
        self.target_file = target_file.resolve() if target_file else None
        self.stop_before_uid = stop_before_uid
        self.resume_from_uid = resume_from_uid
        self.reset_resume_function_dir = reset_resume_function_dir
        self.skip_context_agent = skip_context_agent
        self._ts_parser = self._create_tree_sitter_parser(allow_missing=allow_missing_tree_sitter)
        self.call_graph: Dict = {"nodes": [], "edges": [], "unresolved_calls": {}}
        self.call_graph_node_map: Dict[str, Dict] = {}

        inferred_api_key, inferred_base_url, inferred_model = self._load_llm_defaults_from_example()
        self.api_key = api_key or os.environ.get("SAFER_AGENT_API_KEY") or inferred_api_key
        self.base_url = base_url or os.environ.get("SAFER_AGENT_BASE_URL") or inferred_base_url
        self.model = model or os.environ.get("SAFER_AGENT_MODEL") or inferred_model or "qwen3.5-plus-2026-02-15"
        self.stage_models = self._resolve_stage_models(self.model)
        if context_model:
            self.stage_models["context_agent"] = context_model
        if rag_model:
            self.stage_models["agentic_rag"] = rag_model
        if rewrite_model:
            self.stage_models["final_rewrite"] = rewrite_model
        if compile_fix_model:
            self.stage_models["compile_fix"] = compile_fix_model
        if workspace_edit_model:
            self.stage_models["workspace_edit"] = workspace_edit_model

        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.output_dir = output_dir.resolve() if output_dir else THIS_DIR / "results" / self.project_name / timestamp
        self.functions_dir = self.output_dir / "functions"
        self.workspaces_dir = self.output_dir / "workspaces"
        self.base_workspace_root = self.workspaces_dir / "_baseline_project"
        self.output_dir.mkdir(parents=True, exist_ok=True)
        self.functions_dir.mkdir(parents=True, exist_ok=True)
        self.workspaces_dir.mkdir(parents=True, exist_ok=True)

        self.client: Optional[OpenAI] = None
        if not self.dry_run and self.api_key and self.base_url:
            self.client = OpenAI(api_key=self.api_key, base_url=self.base_url)

    def run(self) -> Dict:
        if not self.source_project_root.exists():
            raise FileNotFoundError(f"project root not found: {self.source_project_root}")
        if not (self.source_project_root / "src").exists():
            raise FileNotFoundError(f"src dir not found: {self.source_project_root / 'src'}")
        if not self.knowledge_base_path.exists():
            raise FileNotFoundError(f"knowledge base not found: {self.knowledge_base_path}")

        self._log("[stage] baseline cargo check...")
        baseline_compile = self._run_baseline_compile_check()
        self._write_json(self.output_dir / "baseline_compile_check.json", baseline_compile)
        if not baseline_compile.get("success"):
            self._log("[stage] baseline cargo check failed; aborting before any workspace copy/edit")
            stderr = (baseline_compile.get("stderr") or "").strip()
            if stderr:
                self._log(stderr)
            raise RuntimeError("baseline project cargo check failed")

        self._log("[stage] creating isolated baseline workspace...")
        self._initialize_base_workspace()
        workspace_info = self._prepare_workspace_layout()

        self._log("[stage] selecting target files...")
        target_files, selection_mode = self._select_target_files()
        self._log(f"[stage] selected {len(target_files)} target files via {selection_mode}")

        self._log("[stage] collecting functions with tree-sitter...")
        all_functions = self._collect_functions(target_files)
        self._log(f"[stage] collected {len(all_functions)} functions")

        self._log("[stage] building call graph...")
        call_graph = self._build_call_graph(all_functions)
        self.call_graph = call_graph
        self.call_graph_node_map = {item["uid"]: item for item in call_graph.get("nodes", [])}
        self._log(
            f"[stage] call graph built: nodes={len(call_graph.get('nodes', []))} "
            f"edges={len(call_graph.get('edges', []))} "
            f"unresolved_call_sites={len(call_graph.get('unresolved_calls', {}))}"
        )

        self._log("[stage] topological sorting...")
        ordered_functions = self._sort_functions_by_call_graph(all_functions, call_graph)
        self._log(f"[stage] topological order ready: {len(ordered_functions)} functions")
        self._write_call_graph(call_graph)
        self._log(f"[stage] call graph written to: {self.output_dir / 'call_graph.json'}")

        self._log("[stage] applying processing filters...")
        selected_functions = self._apply_processing_filters(ordered_functions)
        self._log(f"[stage] filtered run set: {len(selected_functions)} functions")
        if self.limit_functions is not None:
            selected_functions = selected_functions[: self.limit_functions]
            self._log(f"[stage] limit-functions applied: {len(selected_functions)} functions remain")

        self._print_run_configuration(target_files, ordered_functions, selected_functions)
        self._prepare_resume_state(selected_functions)

        summary = {
            "project_root": str(self.project_root),
            "src_dir": str(self.src_dir),
            "project_name": self.project_name,
            "manifest_path": str(self.manifest_path) if self.manifest_path else None,
            "selection_mode": selection_mode,
            "target_files": [str(path) for path in target_files],
            "total_functions_scanned": len(selected_functions),
            "total_functions_in_topological_order": len(ordered_functions),
            "call_graph_path": str(self.output_dir / "call_graph.json"),
            "knowledge_base_path": str(self.knowledge_base_path),
            "target_file": str(self.target_file) if self.target_file else None,
            "stop_before_uid": self.stop_before_uid,
            "resume_from_uid": self.resume_from_uid,
            "reset_resume_function_dir": self.reset_resume_function_dir,
            "skip_context_agent": self.skip_context_agent,
            "fallback_functions_skipped": 0,
            "safe_functions_skipped": 0,
            "unsafe_functions_processed": 0,
            "llm_calls": 0,
            "cargo_dependencies_added": [],
            "workspace_apply_success": 0,
            "workspace_apply_failed": 0,
            "compile_checks_ran": 0,
            "compile_checks_passed": 0,
            "compile_checks_failed": 0,
            "results": [],
            "workspace": workspace_info,
            "baseline_compile_check": baseline_compile,
            "stage_models": dict(self.stage_models),
        }
        cargo_added_set = set()

        for index, function in enumerate(selected_functions, start=1):
            print(
                f"[{index}/{len(ordered_functions)}] {function.file_path.name}:{function.name} "
                f"lines {function.start_line}-{function.end_line}"
            )

            if function.is_fallback:
                print("  -> skip fallback")
                summary["fallback_functions_skipped"] += 1
                output_record = self._write_function_result(
                    function,
                    {
                        "status": "skipped_fallback",
                        "reason": "function marked as C2Rust fallback/manual-fix wrapper",
                    },
                )
                summary["results"].append(output_record)
                print(f"     output: {output_record['output_dir']}")
                continue

            if not function.contains_unsafe:
                print("  -> skip no-unsafe")
                summary["safe_functions_skipped"] += 1
                output_record = self._write_function_result(
                    function,
                    {
                        "status": "skipped_no_unsafe",
                        "reason": "function does not contain unsafe markers",
                    },
                )
                summary["results"].append(output_record)
                print(f"     output: {output_record['output_dir']}")
                continue

            result = self._process_unsafe_function(function)
            output_record = self._write_function_result(function, result)
            summary["results"].append(output_record)
            summary["unsafe_functions_processed"] += 1
            summary["llm_calls"] += result.get("llm_calls", 0)
            for item in result.get("cargo_updates", {}).get("added", []):
                if item not in cargo_added_set:
                    cargo_added_set.add(item)
                    summary["cargo_dependencies_added"].append(item)
            context_symbols = [
                item.get("symbol", "")
                for item in result.get("context_agent", {}).get("initial_symbol_decision", {}).get("symbols", [])
                if item.get("symbol")
            ]
            selected_apis = [
                item.get("api_name", "")
                for item in result.get("agentic_rag", {}).get("selected_api_entries", [])
                if item.get("api_name")
            ]
            cargo_added = result.get("cargo_updates", {}).get("added", [])
            workspace_apply = result.get("workspace_apply") or {}
            compile_check = result.get("compile_check") or {}
            workspace_apply_ok = bool(workspace_apply.get("function_replaced"))
            if workspace_apply_ok:
                summary["workspace_apply_success"] += 1
            else:
                summary["workspace_apply_failed"] += 1
            if compile_check.get("ran"):
                summary["compile_checks_ran"] += 1
                if compile_check.get("success"):
                    summary["compile_checks_passed"] += 1
                else:
                    summary["compile_checks_failed"] += 1
            print(f"  -> {result['status']} llm_calls={result.get('llm_calls', 0)}")
            if context_symbols:
                print(f"     symbols: {', '.join(context_symbols)}")
            if selected_apis:
                print(f"     rag_apis: {', '.join(selected_apis)}")
            if cargo_added:
                print(f"     cargo_added: {', '.join(cargo_added)}")
            print(f"     workspace_apply: {'ok' if workspace_apply_ok else 'failed'}")
            if workspace_apply.get("use_statements_added"):
                print(f"     use_added: {', '.join(workspace_apply['use_statements_added'])}")
            if compile_check.get("ran"):
                compile_status = 'passed' if compile_check.get("success") else f"failed(rc={compile_check.get('returncode')})"
                print(f"     compile_check: {compile_status}")
            else:
                print(f"     compile_check: skipped")
            print(f"     output: {output_record['output_dir']}")

        summary_path = self.output_dir / "summary.json"
        summary_path.write_text(json.dumps(summary, ensure_ascii=False, indent=2), encoding="utf-8")
        self._write_console_report(summary)
        print(f"summary written to: {summary_path}")
        return summary

    def _resolve_project_root(self, project_path: Path) -> Path:
        if (project_path / "Cargo.toml").exists() and (project_path / "src").exists():
            return project_path
        translated = project_path / "translate_by_qwen3_coder"
        if (translated / "Cargo.toml").exists() and (translated / "src").exists():
            return translated
        raise FileNotFoundError(
            "cannot resolve project root; expected Cargo.toml under the provided path "
            "or under translate_by_qwen3_coder/"
        )

    def _resolve_project_name(self) -> str:
        if self.source_project_root.name == "translate_by_qwen3_coder":
            return self.source_project_root.parent.name
        return self.source_project_root.name

    def _infer_manifest_path(self) -> Optional[Path]:
        parts = self.source_project_root.parts
        try:
            rq1_index = parts.index("rq1")
            run_name = parts[rq1_index + 1]
        except (ValueError, IndexError):
            return None

        repo_root = Path(*parts[:rq1_index]) if rq1_index > 0 else Path("/")
        candidate = (
            repo_root
            / "rq1"
            / run_name
            / "intermediate"
            / self.project_name
            / "workspace"
            / "extracted"
            / self.project_name
            / "functions_manifest.json"
        )
        return candidate if candidate.exists() else None

    def _load_llm_defaults_from_example(self) -> Tuple[Optional[str], Optional[str], Optional[str]]:
        if not DEFAULT_API_EXAMPLE_PATH.exists():
            return None, None, None
        content = DEFAULT_API_EXAMPLE_PATH.read_text(encoding="utf-8", errors="ignore")
        api_key_match = re.search(r'(?:api_key|API_KEY)\s*=\s*"([^"]+)"', content)
        base_url_match = re.search(r'(?:base_url|BASE_URL)\s*=\s*"([^"]+)"', content)
        model_match = re.search(r'(?:model|MODEL_NAME|MODEL)\s*=\s*"([^"]+)"', content)
        return (
            api_key_match.group(1) if api_key_match else None,
            base_url_match.group(1) if base_url_match else None,
            model_match.group(1) if model_match else None,
        )

    def _resolve_stage_models(self, fallback_model: str) -> Dict[str, str]:
        stage_models: Dict[str, str] = {}
        for stage, default_model in self.DEFAULT_STAGE_MODELS.items():
            env_name = f"SAFER_AGENT_{stage.upper()}_MODEL"
            stage_models[stage] = os.environ.get(env_name) or default_model or fallback_model
        return stage_models

    def _model_for_stage(self, stage: str) -> str:
        return self.stage_models.get(stage, self.model)

    def _select_target_files(self) -> Tuple[List[Path], str]:
        if self.manifest_path and self.manifest_path.exists():
            data = json.loads(self.manifest_path.read_text(encoding="utf-8"))
            source_files = sorted({item["source_file"] for item in data.get("functions", [])})
            files = [
                self.src_dir / f"{source_file}.rs"
                for source_file in source_files
                if (self.src_dir / f"{source_file}.rs").exists()
            ]
            return files, "manifest"

        patterns = (re.compile(r"^src_.+\.rs$"), re.compile(r"^products_.+\.rs$"))
        files = []
        for path in sorted(self.src_dir.glob("*.rs")):
            if any(pattern.match(path.name) for pattern in patterns):
                files.append(path)
        return files, "fallback_by_filename"

    def _collect_functions(self, target_files: Sequence[Path]) -> List[FunctionRecord]:
        records: List[FunctionRecord] = []
        total_files = len(target_files)
        for index, file_path in enumerate(target_files, start=1):
            file_records = self._collect_functions_with_tree_sitter(file_path)
            records.extend(file_records)
            self._log(
                f"  [functions {index}/{total_files}] {file_path.name} -> {len(file_records)} functions "
                f"(running_total={len(records)})"
            )
        return records

    def _build_call_graph(self, functions: Sequence[FunctionRecord]) -> Dict:
        name_to_uids: Dict[str, List[str]] = {}
        for function in functions:
            name_to_uids.setdefault(function.name, []).append(function.uid)

        edges = []
        unresolved_calls: Dict[str, List[str]] = {}
        unique_files = sorted({function.file_path for function in functions})
        total_files = len(unique_files)
        for index, file_path in enumerate(unique_files, start=1):
            source_bytes = file_path.read_bytes()
            tree = self._ts_parser.parse(source_bytes)
            records = self._collect_function_calls_in_file(file_path, source_bytes, tree.root_node)
            file_edge_count = 0
            file_unresolved_count = 0
            for item in records:
                caller_uid = item["caller_uid"]
                seen_callees = set()
                unresolved = []
                for called_name in item["called_names"]:
                    matched_uids = [uid for uid in name_to_uids.get(called_name, []) if uid != caller_uid]
                    if matched_uids:
                        for callee_uid in matched_uids:
                            edge_key = (caller_uid, callee_uid, called_name)
                            if edge_key in seen_callees:
                                continue
                            seen_callees.add(edge_key)
                            edges.append(
                                {
                                    "caller_uid": caller_uid,
                                    "callee_uid": callee_uid,
                                    "callee_name": called_name,
                                }
                            )
                            file_edge_count += 1
                    else:
                        unresolved.append(called_name)
                if unresolved:
                    unresolved_calls[caller_uid] = sorted(set(unresolved))
                    file_unresolved_count += len(set(unresolved))
            self._log(
                f"  [calls {index}/{total_files}] {file_path.name} -> "
                f"functions={len(records)} edges_added={file_edge_count} unresolved_symbols={file_unresolved_count}"
            )

        return {
            "nodes": [
                {
                    "uid": function.uid,
                    "name": function.name,
                    "file_path": str(function.file_path),
                    "start_line": function.start_line,
                    "end_line": function.end_line,
                    "contains_unsafe": function.contains_unsafe,
                    "is_fallback": function.is_fallback,
                }
                for function in functions
            ],
            "edges": edges,
            "unresolved_calls": unresolved_calls,
        }

    def _collect_function_calls_in_file(self, file_path: Path, source_bytes: bytes, node) -> List[Dict]:
        records: List[Dict] = []
        self._walk_tree_for_call_graph(file_path, source_bytes, node, records)
        return records

    def _walk_tree_for_call_graph(self, file_path: Path, source_bytes: bytes, node, records: List[Dict]) -> None:
        if node.type == "function_item":
            function_name = self._extract_function_name(node, source_bytes)
            if function_name:
                start_line = node.start_point[0] + 1
                caller_uid = f"{file_path.stem}:{start_line}:{function_name}"
                called_names = self._extract_called_function_names(node, source_bytes)
                records.append({"caller_uid": caller_uid, "called_names": called_names})
            return

        for child in node.children:
            self._walk_tree_for_call_graph(file_path, source_bytes, child, records)

    def _extract_called_function_names(self, function_node, source_bytes: bytes) -> List[str]:
        names: List[str] = []

        def visit(node):
            if node.type == "call_expression":
                function_part = node.child_by_field_name("function")
                called_name = self._extract_call_target_name(function_part, source_bytes)
                if called_name:
                    names.append(called_name)
            for child in node.children:
                visit(child)

        visit(function_node)
        return names

    def _extract_call_target_name(self, function_part, source_bytes: bytes) -> Optional[str]:
        if function_part is None:
            return None
        target_text = source_bytes[function_part.start_byte:function_part.end_byte].decode("utf-8", errors="ignore")
        matches = CALL_TARGET_RE.findall(target_text)
        if not matches:
            return None
        return matches[-1]

    def _sort_functions_by_call_graph(self, functions: Sequence[FunctionRecord], call_graph: Dict) -> List[FunctionRecord]:
        function_map = {function.uid: function for function in functions}
        dependency_count = {function.uid: 0 for function in functions}
        reverse_edges: Dict[str, List[str]] = {function.uid: [] for function in functions}

        for edge in call_graph.get("edges", []):
            caller_uid = edge["caller_uid"]
            callee_uid = edge["callee_uid"]
            if caller_uid not in dependency_count or callee_uid not in reverse_edges:
                continue
            dependency_count[caller_uid] += 1
            reverse_edges[callee_uid].append(caller_uid)

        ready = sorted(
            [uid for uid, count in dependency_count.items() if count == 0],
            key=lambda uid: (function_map[uid].file_path.name, function_map[uid].start_line, uid),
        )
        self._log(f"  [toposort] initial ready nodes: {len(ready)}")
        ordered_uids: List[str] = []

        while ready:
            uid = ready.pop(0)
            ordered_uids.append(uid)
            for dependent_uid in sorted(
                reverse_edges.get(uid, []),
                key=lambda item: (function_map[item].file_path.name, function_map[item].start_line, item),
            ):
                dependency_count[dependent_uid] -= 1
                if dependency_count[dependent_uid] == 0:
                    ready.append(dependent_uid)
            ready.sort(key=lambda item: (function_map[item].file_path.name, function_map[item].start_line, item))

        remaining = [uid for uid in function_map if uid not in ordered_uids]
        remaining.sort(key=lambda uid: (function_map[uid].file_path.name, function_map[uid].start_line, uid))
        if remaining:
            self._log(f"  [toposort] cycle_or_unresolved_tail: {len(remaining)}")
        ordered_uids.extend(remaining)
        call_graph["topological_order"] = ordered_uids
        call_graph["cycle_or_unresolved_order_tail"] = remaining
        self._log(f"  [toposort] final ordered nodes: {len(ordered_uids)}")
        return [function_map[uid] for uid in ordered_uids]

    def _write_call_graph(self, call_graph: Dict) -> None:
        path = self.output_dir / "call_graph.json"
        path.write_text(json.dumps(call_graph, ensure_ascii=False, indent=2), encoding="utf-8")


    def _apply_processing_filters(self, ordered_functions: Sequence[FunctionRecord]) -> List[FunctionRecord]:
        selected = list(ordered_functions)
        if self.target_file is not None:
            selected = [function for function in selected if function.file_path.resolve() == self.target_file]
        if self.stop_before_uid:
            for index, function in enumerate(selected):
                if function.uid == self.stop_before_uid:
                    selected = selected[:index]
                    break
        if self.resume_from_uid:
            for index, function in enumerate(selected):
                if function.uid == self.resume_from_uid:
                    selected = selected[index:]
                    break
            else:
                raise ValueError(f"resume_from_uid not found after filters: {self.resume_from_uid}")
        return selected

    def _print_run_configuration(
        self,
        target_files: Sequence[Path],
        ordered_functions: Sequence[FunctionRecord],
        selected_functions: Sequence[FunctionRecord],
    ) -> None:
        self._log('SaferAgent run configuration')
        self._log(f'  default_model: {self.model}')
        self._log(f"  context_agent_model: {self._model_for_stage('context_agent')}")
        self._log(f"  agentic_rag_model: {self._model_for_stage('agentic_rag')}")
        self._log(f"  final_rewrite_model: {self._model_for_stage('final_rewrite')}")
        self._log(f"  compile_fix_model: {self._model_for_stage('compile_fix')}")
        self._log(f"  workspace_edit_model: {self._model_for_stage('workspace_edit')}")
        self._log(f'  project_root: {self.project_root}')
        self._log(f'  output_dir: {self.output_dir}')
        self._log(f'  knowledge_base: {self.knowledge_base_path}')
        self._log(f'  target_files_selected: {len(target_files)}')
        self._log(f'  topological_functions_total: {len(ordered_functions)}')
        self._log(f'  functions_to_process: {len(selected_functions)}')
        self._log(f'  skip_context_agent: {self.skip_context_agent}')
        if self.target_file is not None:
            self._log(f'  target_file_filter: {self.target_file}')
        if self.stop_before_uid:
            self._log(f'  stop_before_uid: {self.stop_before_uid}')
        if self.resume_from_uid:
            self._log(f'  resume_from_uid: {self.resume_from_uid}')
            self._log(f'  reset_resume_function_dir: {self.reset_resume_function_dir}')
        self._log('')

    def _prepare_resume_state(self, selected_functions: Sequence[FunctionRecord]) -> None:
        if not self.resume_from_uid or not self.reset_resume_function_dir:
            return
        if not selected_functions:
            raise ValueError("cannot reset resume function dir: no selected functions remain after filters")
        resume_function = selected_functions[0]
        if resume_function.uid != self.resume_from_uid:
            raise ValueError(
                f"resume state mismatch: expected first selected uid {self.resume_from_uid}, "
                f"got {resume_function.uid}"
            )
        function_dir = self._function_dir_for(resume_function)
        if function_dir.exists():
            self._log(f"[resume] removing interrupted function dir: {function_dir}")
            shutil.rmtree(function_dir)
        else:
            self._log(f"[resume] interrupted function dir not present, nothing to remove: {function_dir}")

    def _create_tree_sitter_parser(self, allow_missing: bool = False):
        if Parser is None or Language is None or tree_sitter_rust is None:
            if allow_missing:
                return None
            raise RuntimeError(
                "tree-sitter dependencies are unavailable; please run saferAgent in an environment with tree_sitter and tree_sitter_rust"
            )
        binding_path = Path(tree_sitter_rust.__file__).with_name("_binding.abi3.so")
        if not binding_path.exists():
            if allow_missing:
                return None
            raise FileNotFoundError(f"tree-sitter-rust binding not found: {binding_path}")
        parser = Parser()
        rust_language = Language(str(binding_path), "rust")
        parser.set_language(rust_language)
        return parser

    def _collect_functions_with_tree_sitter(self, file_path: Path) -> List[FunctionRecord]:
        source_bytes = file_path.read_bytes()
        tree = self._ts_parser.parse(source_bytes)
        records: List[FunctionRecord] = []
        self._walk_tree_for_functions(file_path, source_bytes, tree.root_node, records)
        return records

    def _walk_tree_for_functions(self, file_path: Path, source_bytes: bytes, node, records: List[FunctionRecord]) -> None:
        if node.type == "function_item":
            function_name = self._extract_function_name(node, source_bytes)
            if function_name:
                start_line = node.start_point[0] + 1
                end_line = node.end_point[0] + 1
                uid = f"{file_path.stem}:{start_line}:{function_name}"
                records.append(
                    self._build_function_record(
                        uid=uid,
                        name=function_name,
                        file_path=file_path,
                        start_line=start_line,
                        end_line=end_line,
                    )
                )
            return

        for child in node.children:
            self._walk_tree_for_functions(file_path, source_bytes, child, records)

    def _extract_function_name(self, function_node, source_bytes: bytes) -> Optional[str]:
        name_node = function_node.child_by_field_name("name")
        if name_node is None:
            return None
        return source_bytes[name_node.start_byte:name_node.end_byte].decode("utf-8", errors="ignore")

    def _build_function_record(
        self,
        uid: str,
        name: str,
        file_path: Path,
        start_line: int,
        end_line: int,
    ) -> FunctionRecord:
        lines = file_path.read_text(encoding="utf-8", errors="ignore").splitlines()
        source = "\n".join(lines[start_line - 1:end_line])
        lookback_start = max(0, start_line - 21)
        pre_context = "\n".join(lines[lookback_start:start_line - 1])
        combined_text = f"{pre_context}\n{source}"
        contains_unsafe = any(pattern.search(source) for pattern in UNSAFE_PATTERNS)
        is_fallback = any(marker in combined_text for marker in FALLBACK_MARKERS)
        return FunctionRecord(
            uid=uid,
            name=name,
            file_path=file_path,
            start_line=start_line,
            end_line=end_line,
            source=source,
            pre_context=pre_context,
            contains_unsafe=contains_unsafe,
            is_fallback=is_fallback,
        )


    def _function_dir_for(self, function: FunctionRecord) -> Path:
        return self.functions_dir / self._sanitize_filename(function.uid)

    def _prepare_function_subdirs(self, function_dir: Path) -> None:
        for dirname in self.FUNCTION_RESULT_SUBDIRS.values():
            (function_dir / dirname).mkdir(parents=True, exist_ok=True)

    def _function_file(self, function_dir: Path, group: str, filename: str) -> Path:
        subdir = self.FUNCTION_RESULT_SUBDIRS[group]
        path = function_dir / subdir / filename
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def _prepare_function_dir(self, function: FunctionRecord) -> Path:
        function_dir = self._function_dir_for(function)
        function_dir.mkdir(parents=True, exist_ok=True)
        self._prepare_function_subdirs(function_dir)
        metadata = {
            "uid": function.uid,
            "name": function.name,
            "file_path": str(function.file_path),
            "start_line": function.start_line,
            "end_line": function.end_line,
            "contains_unsafe": function.contains_unsafe,
            "is_fallback": function.is_fallback,
            "models": dict(self.stage_models),
        }
        self._write_json(self._function_file(function_dir, "inputs", "function.json"), metadata)
        self._function_file(function_dir, "inputs", "function.rs").write_text(function.source, encoding="utf-8")
        self._function_file(function_dir, "inputs", "pre_context.txt").write_text(function.pre_context, encoding="utf-8")
        return function_dir

    def _write_json(self, path: Path, payload: Dict) -> None:
        path.write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")

    def _write_live_result(self, function_dir: Path, payload: Dict) -> None:
        self._write_json(self._function_file(function_dir, "traces", "result.json"), payload)

    def _extract_prompt_section_code_block(self, prompt_text: str, heading: str, fence_lang: Optional[str] = None) -> str:
        heading_re = re.escape(heading)
        fence_part = re.escape(fence_lang) if fence_lang else r"[^\n]*"
        pattern = re.compile(
            rf"{heading_re}\s*\n(?:.*?\n)*?```{fence_part}\n(.*?)\n```",
            re.DOTALL,
        )
        match = pattern.search(prompt_text or "")
        return match.group(1).strip() if match else ""

    def _parse_final_rewrite_prompt_file(self, function_dir: Path) -> Dict[str, Any]:
        prompt_path = self._function_file(function_dir, "rewrite", "final_rewrite_prompt.txt")
        if not prompt_path.exists():
            return {}
        prompt_text = prompt_path.read_text(encoding="utf-8")
        source_code = self._extract_prompt_section_code_block(prompt_text, "Here is a function / piece of Rust code:", "rust")
        symbol_context = self._extract_prompt_section_code_block(
            prompt_text,
            "Additional Rust context from the previous symbol/context-search stage, if provided:",
            "rust",
        )
        caller_context = self._extract_prompt_section_code_block(
            prompt_text,
            "Caller update targets, if provided:",
            "rust",
        )
        api_knowledge_raw = self._extract_prompt_section_code_block(
            prompt_text,
            "Potential OpenHarmony Rust API knowledge, if provided:",
            "json",
        )
        try:
            api_knowledge = json.loads(api_knowledge_raw) if api_knowledge_raw else []
        except Exception:
            api_knowledge = []
        return {
            "prompt_text": prompt_text,
            "source_code": source_code,
            "symbol_context": symbol_context,
            "caller_context": caller_context,
            "api_knowledge_raw": api_knowledge_raw,
            "api_knowledge": api_knowledge,
        }

    def _load_existing_function_record(self, function_dir: Path) -> FunctionRecord:
        metadata = json.loads(self._function_file(function_dir, "inputs", "function.json").read_text(encoding="utf-8"))
        source = self._function_file(function_dir, "inputs", "function.rs").read_text(encoding="utf-8")
        pre_context = self._function_file(function_dir, "inputs", "pre_context.txt").read_text(encoding="utf-8")
        return FunctionRecord(
            uid=metadata["uid"],
            name=metadata["name"],
            file_path=Path(metadata["file_path"]),
            start_line=int(metadata["start_line"]),
            end_line=int(metadata["end_line"]),
            source=source,
            pre_context=pre_context,
            contains_unsafe=bool(metadata.get("contains_unsafe", True)),
            is_fallback=bool(metadata.get("is_fallback", False)),
        )

    def repair_existing_results_dir(self, results_dir: Path, *, max_rounds: int = 3, target_function: Optional[str] = None) -> Dict[str, Any]:
        results_dir = results_dir.resolve()
        functions_root = results_dir / "functions"
        if not functions_root.exists():
            raise FileNotFoundError(f"functions dir not found: {functions_root}")
        run_stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        run_dir = results_dir / "offline_compile_fix_runs" / run_stamp
        run_dir.mkdir(parents=True, exist_ok=True)
        repaired: List[Dict[str, Any]] = []
        for function_dir in sorted(path for path in functions_root.iterdir() if path.is_dir()):
            if target_function and function_dir.name != target_function:
                continue
            compile_check_path = function_dir / "artifacts" / "compile_check.json"
            if not compile_check_path.exists():
                self._log(f"[offline-fix] skip {function_dir.name}: missing compile_check.json")
                continue
            compile_check = json.loads(compile_check_path.read_text(encoding="utf-8"))
            if compile_check.get("success"):
                self._log(f"[offline-fix] skip {function_dir.name}: compile_check already passed")
                continue
            self._log(f"[offline-fix] repairing {function_dir.name}")
            result = self._repair_existing_function_dir(function_dir, compile_check, max_rounds=max_rounds)
            record = {
                "function_dir": str(function_dir),
                "success": bool((result.get("compile_check") or {}).get("success")),
                "attempt_count": result.get("attempt_count", 0),
                "compile_check": result.get("compile_check") or {},
            }
            repaired.append(record)
            (run_dir / function_dir.name).mkdir(parents=True, exist_ok=True)
            self._write_json(run_dir / function_dir.name / "summary.json", record)
            self._write_json(run_dir / function_dir.name / "compile_fix.json", result)
        summary = {
            "results_dir": str(results_dir),
            "run_dir": str(run_dir),
            "max_rounds": max_rounds,
            "repaired_functions": repaired,
        }
        self._write_json(results_dir / "offline_compile_fix_summary.json", summary)
        self._write_json(run_dir / "summary.json", summary)
        (run_dir / "summary.txt").write_text(
            "\n".join(
                [
                    f"results_dir: {results_dir}",
                    f"run_dir: {run_dir}",
                    f"max_rounds: {max_rounds}",
                    f"repaired_functions: {len(repaired)}",
                ]
                + [
                    f"{item['function_dir']} | success={item['success']} | attempts={item['attempt_count']}"
                    for item in repaired
                ]
            )
            + "\n",
            encoding="utf-8",
        )
        return summary

    def _repair_existing_function_dir(self, function_dir: Path, compile_check: Dict[str, Any], *, max_rounds: int) -> Dict[str, Any]:
        function = self._load_existing_function_record(function_dir)
        prompt_info = self._parse_final_rewrite_prompt_file(function_dir)
        if prompt_info.get("source_code"):
            function = FunctionRecord(
                uid=function.uid,
                name=function.name,
                file_path=function.file_path,
                start_line=function.start_line,
                end_line=function.end_line,
                source=prompt_info["source_code"],
                pre_context=function.pre_context,
                contains_unsafe=function.contains_unsafe,
                is_fallback=function.is_fallback,
            )
        result_trace_path = self._function_file(function_dir, "traces", "result.json")
        result_trace = json.loads(result_trace_path.read_text(encoding="utf-8")) if result_trace_path.exists() else {}
        context_agent = result_trace.get("context_agent") or {}
        symbol_contexts = prompt_info.get("symbol_context") or result_trace.get("search_results") or context_agent.get("symbol_contexts") or []
        caller_contexts = prompt_info.get("caller_context") or context_agent.get("caller_contexts") or []
        rag_result = result_trace.get("agentic_rag") or {}
        if prompt_info.get("api_knowledge"):
            rag_result = {
                **rag_result,
                "selected_api_entries": prompt_info.get("api_knowledge") or [],
            }
        final_analysis = result_trace.get("final_analysis") or {}
        if prompt_info.get("prompt_text"):
            final_analysis = {
                **final_analysis,
                "rewrite_prompt": prompt_info["prompt_text"],
            }
        workspace_info_path = self._function_file(function_dir, "artifacts", "workspace.json")
        workspace_info = json.loads(workspace_info_path.read_text(encoding="utf-8")) if workspace_info_path.exists() else {}
        workspace_root = Path(workspace_info.get("workspace_root") or (function_dir / "workspace"))

        compile_fix_result = self._run_compile_fix_iterations(
            function=function,
            function_dir=function_dir,
            workspace_root=workspace_root,
            symbol_contexts=symbol_contexts,
            caller_contexts=caller_contexts,
            rag_result=rag_result,
            final_analysis=final_analysis,
            initial_compile_check=compile_check,
            max_rounds=max_rounds,
        )
        result_trace["compile_fix"] = compile_fix_result
        result_trace["compile_check"] = compile_fix_result.get("compile_check") or compile_check
        result_trace["current_stage"] = "completed"
        result_trace["status"] = "processed"
        self._write_live_result(function_dir, result_trace)
        self._write_json(self._function_file(function_dir, "artifacts", "compile_check.json"), result_trace["compile_check"])
        self._write_json(self._function_file(function_dir, "artifacts", "compile_fix.json"), compile_fix_result)
        self._write_json(
            self._function_file(function_dir, "artifacts", "compile_fix_history.json"),
            {
                "history": compile_fix_result.get("history") or [],
                "attempt_count": compile_fix_result.get("attempt_count", 0),
                "success": compile_fix_result.get("success", False),
                "compile_check": compile_fix_result.get("compile_check") or {},
            },
        )
        return compile_fix_result

    def _process_unsafe_function(self, function: FunctionRecord) -> Dict:
        function_dir = self._prepare_function_dir(function)
        function_payload = {
            "uid": function.uid,
            "name": function.name,
            "file_path": str(function.file_path),
            "start_line": function.start_line,
            "end_line": function.end_line,
            "source": function.source,
            "caller_candidates": self._collect_caller_candidates(function),
        }
        partial_result = {
            "status": "processing",
            "current_stage": "context_agent",
            "llm_calls": 0,
            "models": dict(self.stage_models),
            "context_agent": None,
            "search_results": [],
            "agentic_rag": None,
            "final_analysis": None,
            "compile_fix": None,
            "cargo_updates": None,
            "workspace_apply": None,
            "compile_check": None,
            "workspace": None,
        }
        self._write_live_result(function_dir, partial_result)

        def persist_context(stage: str, payload: Dict) -> None:
            self._write_json(self._function_file(function_dir, "traces", "context_agent_trace.json"), payload)
            partial_result["context_agent"] = payload
            partial_result["search_results"] = payload.get("symbol_contexts", [])
            partial_result["llm_calls"] = payload.get("llm_calls", 0)
            partial_result["current_stage"] = f"context_agent:{stage}"
            self._write_live_result(function_dir, partial_result)

        def persist_rag(stage: str, payload: Dict) -> None:
            self._write_json(self._function_file(function_dir, "traces", "agentic_rag_trace.json"), payload)
            partial_result["agentic_rag"] = payload
            partial_result["llm_calls"] = (partial_result.get("context_agent") or {}).get("llm_calls", 0) + payload.get("llm_calls", 0)
            partial_result["current_stage"] = f"agentic_rag:{stage}"
            self._write_live_result(function_dir, partial_result)

        if self.skip_context_agent:
            self._log("  [context] skipped by configuration")
            context_result = {
                "model": self._model_for_stage("context_agent"),
                "initial_symbol_decision": {
                    "used_llm": False,
                    "raw_response": None,
                    "symbols": [],
                    "reason": "context agent skipped by configuration",
                },
                "symbol_runs": [],
                "symbol_contexts": [],
                "caller_contexts": [],
                "llm_calls": 0,
            }
            symbol_contexts = []
            caller_contexts = []
            llm_calls = 0
            partial_result["context_agent"] = context_result
            partial_result["search_results"] = symbol_contexts
            partial_result["llm_calls"] = llm_calls
            partial_result["current_stage"] = "agentic_rag"
            self._write_json(self._function_file(function_dir, "traces", "context_agent_trace.json"), context_result)
            self._write_live_result(function_dir, partial_result)
        else:
            context_model = self._model_for_stage("context_agent")
            self._log(f"  [context] model={context_model}")
            context_agent = SymbolContextAgent(
                project_root=self.project_root,
                search_bin_dir=self.search_bin_dir,
                model=context_model,
                client=self.client,
                logger=self._log,
                progress_callback=persist_context,
            )
            try:
                context_result = context_agent.run(function_payload)
            except Exception as exc:
                self._log(f"  [context] failed, degrading to empty context: {type(exc).__name__}: {exc}")
                context_result = {
                    "model": context_model,
                    "initial_symbol_decision": {
                        "used_llm": False,
                        "raw_response": None,
                        "symbols": [],
                        "reason": f"context agent failed: {exc}",
                    },
                    "symbol_runs": [],
                    "symbol_contexts": [],
                    "caller_contexts": [],
                    "llm_calls": 0,
                }
            symbol_contexts = context_result.get("symbol_contexts", [])
            caller_contexts = context_result.get("caller_contexts", [])
            llm_calls = context_result.get("llm_calls", 0)
            partial_result["context_agent"] = context_result
            partial_result["search_results"] = symbol_contexts
            partial_result["llm_calls"] = llm_calls
            partial_result["current_stage"] = "agentic_rag"
            self._write_live_result(function_dir, partial_result)

        try:
            rag_model = self._model_for_stage("agentic_rag")
            self._log(f"  [rag] model={rag_model}")
            rag_agent = AgenticRAGAgent(
                knowledge_base_path=self.knowledge_base_path,
                model=rag_model,
                client=self.client,
                logger=self._log,
                progress_callback=persist_rag,
            )
            rag_result = rag_agent.run(function_payload, symbol_contexts)
        except Exception as exc:
            self._log(f"  [rag] failed, degrading to empty API knowledge: {type(exc).__name__}: {exc}")
            rag_result = {
                "model": rag_model,
                "knowledge_base_path": str(self.knowledge_base_path),
                "initial_api_judgement": {
                    "used_llm": False,
                    "raw_response": None,
                    "api_candidates": [],
                    "reason": f"agentic RAG failed: {exc}",
                },
                "query_runs": [],
                "aggregated_matches": [],
                "selected_api_entries": [],
                "selection": {
                    "used_llm": False,
                    "raw_response": None,
                    "selected_api_entries": [],
                    "reason": f"agentic RAG failed: {exc}",
                },
                "llm_calls": 0,
            }
        llm_calls += rag_result.get("llm_calls", 0)
        partial_result["agentic_rag"] = rag_result
        partial_result["llm_calls"] = llm_calls
        partial_result["current_stage"] = "final_rewrite"
        self._write_live_result(function_dir, partial_result)

        rewrite_model = self._model_for_stage("final_rewrite")
        self._log(f"  [rewrite] generating final safer rewrite with model={rewrite_model}")
        final_analysis = self._generate_safe_rewrite(function, symbol_contexts, caller_contexts, rag_result)
        if final_analysis.get("used_llm"):
            llm_calls += 1
        partial_result["final_analysis"] = final_analysis
        partial_result["llm_calls"] = llm_calls
        partial_result["current_stage"] = "cargo_updates"
        self._write_live_result(function_dir, partial_result)

        self._log("  [baseline-check] cargo check on isolated baseline workspace before function copy")
        baseline_compile = self._run_workspace_compile_check(self.project_root)
        self._write_json(self._function_file(function_dir, "artifacts", "baseline_workspace_compile_check.json"), baseline_compile)
        partial_result["baseline_workspace_compile_check"] = baseline_compile
        self._write_live_result(function_dir, partial_result)
        if not baseline_compile.get("success"):
            self._log("  [baseline-check] failed; stopping before function workspace copy")
            raise RuntimeError("isolated baseline workspace cargo check failed before function workspace copy")

        function_workspace = self._prepare_function_workspace(function, function_dir)
        workspace_root = Path(function_workspace["workspace_root"])
        partial_result["workspace"] = function_workspace

        cargo_updates = self._apply_cargo_dependency_changes(
            workspace_root,
            add_lines=final_analysis.get("cargo_dependencies", []),
            remove_items=[],
        )
        partial_result["cargo_updates"] = cargo_updates
        partial_result["current_stage"] = "workspace_apply"
        self._write_live_result(function_dir, partial_result)

        workspace_apply = self._apply_workspace_rewrite(workspace_root, function, final_analysis, function_dir)
        partial_result["workspace_apply"] = workspace_apply
        partial_result["current_stage"] = "compile_check"
        self._write_live_result(function_dir, partial_result)

        compile_check = self._run_workspace_compile_check(workspace_root)
        compile_fix_result = None
        if compile_check.get("ran") and not compile_check.get("success"):
            partial_result["current_stage"] = "compile_fix"
            self._write_live_result(function_dir, partial_result)
            self._log(f"  [compile-fix] compile failed after safer rewrite; invoking fix agent model={self._model_for_stage('compile_fix')}")
            compile_fix_result = self._run_compile_fix_iterations(
                function=function,
                function_dir=function_dir,
                workspace_root=workspace_root,
                symbol_contexts=symbol_contexts,
                caller_contexts=caller_contexts,
                rag_result=rag_result,
                final_analysis=final_analysis,
                initial_compile_check=compile_check,
                max_rounds=5,
            )
            llm_calls += compile_fix_result.get("llm_calls", 0)
            partial_result["compile_fix"] = compile_fix_result
            partial_result["llm_calls"] = llm_calls
            partial_result["current_stage"] = "compile_check:after_fix"
            self._write_live_result(function_dir, partial_result)
            compile_check = compile_fix_result.get("compile_check") or compile_check

        partial_result["compile_check"] = compile_check
        partial_result["status"] = "processed"
        partial_result["current_stage"] = "completed"
        self._write_live_result(function_dir, partial_result)

        raw_response = final_analysis.get("raw_response")
        if raw_response:
            self._function_file(function_dir, "rewrite", "final_llm_raw_response.txt").write_text(raw_response, encoding="utf-8")
        self._write_json(self._function_file(function_dir, "artifacts", "llm_models.json"), partial_result.get("models", {}))
        self._function_file(function_dir, "artifacts", "llm_models.txt").write_text(
            "\n".join(f"{key}={value}" for key, value in partial_result.get("models", {}).items()) + "\n",
            encoding="utf-8",
        )
        rewrite_messages = final_analysis.get("messages")
        if rewrite_messages:
            self._write_json(self._function_file(function_dir, "traces", "final_rewrite_messages.json"), rewrite_messages)
        rewrite_prompt = final_analysis.get("rewrite_prompt")
        if rewrite_prompt:
            self._function_file(function_dir, "rewrite", "final_rewrite_prompt.txt").write_text(rewrite_prompt, encoding="utf-8")
        if final_analysis.get("rewritten_function"):
            self._function_file(function_dir, "rewrite", "rewritten_function.txt").write_text(final_analysis["rewritten_function"], encoding="utf-8")
        if final_analysis.get("use_statements"):
            self._write_json(self._function_file(function_dir, "rewrite", "use_statements.json"), final_analysis["use_statements"])
        if final_analysis.get("function_tags"):
            self._write_json(self._function_file(function_dir, "rewrite", "function_tags.json"), final_analysis["function_tags"])
        if final_analysis.get("cargo_dependency_tags"):
            self._write_json(self._function_file(function_dir, "rewrite", "cargo_dependency_tags.json"), final_analysis["cargo_dependency_tags"])
        if cargo_updates is not None:
            self._write_json(self._function_file(function_dir, "artifacts", "cargo_updates.json"), cargo_updates)
        if workspace_apply is not None:
            self._write_json(self._function_file(function_dir, "artifacts", "workspace_apply.json"), workspace_apply)
            self._write_json(
                self._function_file(function_dir, "artifacts", "project_modifications.json"),
                {
                    "workspace_root": str(workspace_root),
                    "cargo_updates": cargo_updates or {},
                    "workspace_apply": workspace_apply,
                },
            )
            if workspace_apply.get("memory") is not None:
                self._write_json(self._function_file(function_dir, "traces", "workspace_edit_memory.json"), workspace_apply["memory"])
            if workspace_apply.get("trace") is not None:
                self._write_json(self._function_file(function_dir, "traces", "workspace_edit_trace.json"), workspace_apply["trace"])
        if compile_check is not None:
            self._write_json(self._function_file(function_dir, "artifacts", "compile_check.json"), compile_check)
        if compile_fix_result is not None:
            self._write_json(self._function_file(function_dir, "artifacts", "compile_fix.json"), compile_fix_result)
            self._write_json(
                self._function_file(function_dir, "artifacts", "compile_fix_history.json"),
                {
                    "history": compile_fix_result.get("history") or [],
                    "attempt_count": compile_fix_result.get("attempt_count", 0),
                    "success": compile_fix_result.get("success", False),
                    "compile_check": compile_fix_result.get("compile_check") or {},
                },
            )
            fix_prompt = compile_fix_result.get("rewrite_prompt")
            if fix_prompt:
                self._function_file(function_dir, "rewrite", "compile_fix_prompt.txt").write_text(fix_prompt, encoding="utf-8")
            fix_raw = compile_fix_result.get("raw_response")
            if fix_raw:
                self._function_file(function_dir, "rewrite", "compile_fix_raw_response.txt").write_text(fix_raw, encoding="utf-8")
            if compile_fix_result.get("rewritten_function"):
                self._function_file(function_dir, "rewrite", "compile_fixed_function.txt").write_text(
                    compile_fix_result["rewritten_function"],
                    encoding="utf-8",
                )
            if compile_fix_result.get("add_use_statements") or compile_fix_result.get("remove_use_statements"):
                self._write_json(
                    self._function_file(function_dir, "rewrite", "compile_fix_use_changes.json"),
                    {
                        "add": compile_fix_result.get("add_use_statements") or [],
                        "remove": compile_fix_result.get("remove_use_statements") or [],
                    },
                )
            if compile_fix_result.get("add_cargo_dependencies") or compile_fix_result.get("remove_cargo_dependencies"):
                self._write_json(
                    self._function_file(function_dir, "rewrite", "compile_fix_cargo_changes.json"),
                    {
                        "add": compile_fix_result.get("add_cargo_dependencies") or [],
                        "remove": compile_fix_result.get("remove_cargo_dependencies") or [],
                    },
                )

        return {
            "status": "processed",
            "llm_calls": llm_calls,
            "models": partial_result.get("models", {}),
            "context_agent": context_result,
            "search_results": symbol_contexts,
            "agentic_rag": rag_result,
            "final_analysis": final_analysis,
            "compile_fix": compile_fix_result,
            "cargo_updates": cargo_updates,
            "workspace": function_workspace,
            "workspace_apply": workspace_apply,
            "compile_check": compile_check,
        }

    def _generate_safe_rewrite(
        self,
        function: FunctionRecord,
        symbol_contexts: Sequence[Dict],
        caller_contexts: Sequence[Dict],
        rag_result: Dict,
    ) -> Dict:
        rewrite_model = self._model_for_stage("final_rewrite")
        caller_fix_targets = self._flatten_caller_call_sites(caller_contexts)
        symbol_context = self._format_symbol_contexts(symbol_contexts)
        caller_context = self._format_caller_contexts(caller_contexts)
        api_knowledge = self._format_api_knowledge(rag_result)
        rewrite_prompt = self.prompt_template.format(
            source_code=function.source,
            symbol_context=symbol_context,
            caller_context=caller_context,
            openharmony_api_knowledge=api_knowledge,
        )
        messages = [{"role": "user", "content": rewrite_prompt}]

        if self.client is None:
            return {
                "used_llm": False,
                "analysis": "LLM unavailable; only context collection and AgenticRAG retrieval were completed.",
                "valid_output": False,
                "func": None,
                "rewritten_function": None,
                "use_statements": [],
                "caller_fixes": [],
                "function_tags": [],
                "cargo_dependency_tags": [],
                "cargo_dependencies": [],
                "api_knowledge_used": [],
                "model": rewrite_model,
                "rewrite_prompt": rewrite_prompt,
                "messages": messages,
            }

        try:
            response_text = self._chat(rewrite_prompt, model=rewrite_model)
            func_block = self._extract_func_block(response_text)
            use_statements = self._extract_use_statements(response_text)
            fix_caller_lines = self._extract_fix_caller_blocks(response_text)
            cargo_dependency_tags = self._extract_cargo_dependency_lines(response_text)
            valid_output = func_block is not None
            return {
                "used_llm": True,
                "valid_output": valid_output,
                "func": func_block,
                "rewritten_function": func_block,
                "raw_response": response_text,
                "use_statements": use_statements,
                "caller_fixes": self._build_caller_fixes(caller_fix_targets, fix_caller_lines),
                "function_tags": self._extract_tag_blocks(response_text, "FUNCTION_TAG"),
                "cargo_dependency_tags": cargo_dependency_tags,
                "cargo_dependencies": cargo_dependency_tags,
                "api_knowledge_used": rag_result.get("selected_api_entries", []),
                "model": rewrite_model,
                "rewrite_prompt": rewrite_prompt,
                "messages": messages,
                "analysis": "missing valid <FUNC> block in LLM output" if not valid_output else "",
            }
        except Exception as exc:
            return {
                "used_llm": False,
                "analysis": f"LLM rewrite failed: {exc}",
                "valid_output": False,
                "func": None,
                "rewritten_function": None,
                "use_statements": [],
                "caller_fixes": [],
                "function_tags": [],
                "cargo_dependency_tags": [],
                "cargo_dependencies": [],
                "api_knowledge_used": rag_result.get("selected_api_entries", []),
                "model": rewrite_model,
                "rewrite_prompt": rewrite_prompt,
                "messages": messages,
            }

    def _format_symbol_contexts(self, symbol_contexts: Sequence[Dict]) -> str:
        if isinstance(symbol_contexts, str):
            return symbol_contexts.strip() or "No additional symbol/search-stage Rust context."
        context_chunks = []
        for item in symbol_contexts:
            if not item.get("found_definition"):
                continue
            snippet = (item.get("definition_snippet") or "").strip()
            if not snippet:
                continue
            metadata = [
                f"// symbol: {item.get('symbol', '')}",
                f"// kind: {item.get('definition_kind', 'unknown')}",
            ]
            file_path = (item.get("file_path") or "").strip()
            line_number = item.get("line_number")
            if file_path:
                location = file_path
                if line_number is not None:
                    location += f":{line_number}"
                metadata.append(f"// location: {location}")
            note = (item.get("note") or "").strip()
            if note:
                metadata.append(f"// note: {note}")
            context_chunks.append("\n".join(metadata + [snippet]))
        return "\n\n".join(context_chunks) if context_chunks else "No additional symbol/search-stage Rust context."

    def _format_caller_contexts(self, caller_contexts: Sequence[Dict]) -> str:
        if isinstance(caller_contexts, str):
            return caller_contexts.strip() or "No verified caller update targets."
        context_chunks = []
        for item in caller_contexts:
            if not item.get("found_call_sites"):
                continue
            call_sites = item.get("call_sites") or []
            rendered_sites = []
            for site in call_sites:
                code = (site.get("code") or "").strip()
                if not code:
                    continue
                location = (site.get("file_path") or "").strip()
                line_number = site.get("line_number")
                if location:
                    if line_number is not None:
                        rendered_sites.append(f"// callsite: {location}:{line_number}")
                    else:
                        rendered_sites.append(f"// callsite: {location}")
                rendered_sites.append(code)
            if not rendered_sites:
                continue
            metadata = [
                f"// caller: {item.get('caller_name', '')}",
                f"// caller_uid: {item.get('caller_uid', '')}",
                f"// callee: {item.get('callee_name', '')}",
            ]
            note = (item.get("note") or "").strip()
            if note:
                metadata.append(f"// note: {note}")
            context_chunks.append("\n".join(metadata + rendered_sites))
        return "\n\n".join(context_chunks) if context_chunks else "No verified caller update targets."

    def _flatten_caller_call_sites(self, caller_contexts: Sequence[Dict]) -> List[Dict]:
        if isinstance(caller_contexts, str):
            return []
        flattened: List[Dict] = []
        for item in caller_contexts:
            if not item.get("found_call_sites"):
                continue
            for site in item.get("call_sites") or []:
                code = (site.get("code") or "").strip()
                if not code:
                    continue
                flattened.append(
                    {
                        "caller_uid": item.get("caller_uid", ""),
                        "caller_name": item.get("caller_name", ""),
                        "callee_name": item.get("callee_name", ""),
                        "file_path": (site.get("file_path") or item.get("caller_file_path") or "").strip(),
                        "line_number": site.get("line_number"),
                        "original_code": code,
                    }
                )
        return flattened

    def _build_caller_fixes(self, caller_fix_targets: Sequence[Dict], fix_caller_lines: Sequence[str]) -> List[Dict]:
        fixes: List[Dict] = []
        for target, replacement in zip(caller_fix_targets, fix_caller_lines):
            replacement_text = self._strip_code_fence(replacement).strip()
            if not replacement_text:
                continue
            fixes.append(
                {
                    "caller_uid": target.get("caller_uid", ""),
                    "caller_name": target.get("caller_name", ""),
                    "callee_name": target.get("callee_name", ""),
                    "file_path": target.get("file_path", ""),
                    "line_number": target.get("line_number"),
                    "original_code": target.get("original_code", ""),
                    "replacement_code": replacement_text,
                }
            )
        return fixes

    def _format_api_knowledge(self, rag_result: Dict) -> str:
        selected = rag_result.get("selected_api_entries", [])
        if not selected:
            return "[]"
        compact = []
        for item in selected:
            compact.append(
                {
                    "api_name": item.get("api_name", ""),
                    "function_summary": item.get("function_summary", ""),
                    "selection_reason": item.get("selection_reason", ""),
                    "usage_hint": item.get("usage_hint", ""),
                    "example_code": item.get("example_code") or [],
                    "cargo_dependency": item.get("cargo_dependency") or {},
                    "source_repository": item.get("source_repository") or {},
                }
            )
        return json.dumps(compact, ensure_ascii=False, indent=2)

    def _collect_caller_candidates(self, function: FunctionRecord) -> List[Dict]:
        candidates: List[Dict] = []
        for edge in self.call_graph.get("edges", []):
            if edge.get("callee_uid") != function.uid:
                continue
            caller_uid = edge.get("caller_uid", "")
            caller_node = self.call_graph_node_map.get(caller_uid, {})
            candidates.append(
                {
                    "caller_uid": caller_uid,
                    "caller_name": caller_node.get("name", ""),
                    "caller_file_path": caller_node.get("file_path", ""),
                    "caller_start_line": caller_node.get("start_line"),
                    "caller_end_line": caller_node.get("end_line"),
                    "callee_uid": edge.get("callee_uid", ""),
                    "callee_name": edge.get("callee_name", function.name),
                }
            )
        return candidates

    def _prepare_workspace_layout(self) -> Dict:
        info = {
            "mode": "per_function_workspace",
            "project_root": str(self.project_root),
            "base_workspace_root": str(self.project_root),
            "workspaces_root": str(self.workspaces_dir),
        }
        self._write_json(self.output_dir / "workspace.json", info)
        self._log(f"[stage] workspace layout prepared: {self.workspaces_dir}")
        return info

    def _prepare_function_workspace(self, function: FunctionRecord, function_dir: Path) -> Dict:
        workspace_dir = self._function_file(function_dir, "workspace", ".keep").parent
        if workspace_dir.exists():
            shutil.rmtree(workspace_dir)
        shutil.copytree(self.project_root, workspace_dir)
        info = {
            "mode": "per_function_workspace",
            "function_uid": function.uid,
            "base_workspace_root": str(self.project_root),
            "workspace_root": str(workspace_dir),
            "cargo_toml": str(workspace_dir / "Cargo.toml"),
        }
        self._write_json(self._function_file(function_dir, "artifacts", "workspace.json"), info)
        return info

    def _apply_workspace_rewrite(
        self,
        workspace_root: Path,
        function: FunctionRecord,
        final_analysis: Dict,
        function_dir: Path,
    ) -> Dict:
        rewrite_memory = self._build_workspace_edit_memory(function, final_analysis, workspace_root)
        result = self._run_workspace_edit_agent(
            workspace_root=workspace_root,
            function=function,
            function_dir=function_dir,
            edit_memory=rewrite_memory,
            rewritten_function=final_analysis.get("rewritten_function") or "",
            add_use_statements=final_analysis.get("use_statements") or [],
            remove_use_statements=[],
            caller_fixes=final_analysis.get("caller_fixes") or [],
            mode_label="rewrite",
        )
        self._write_json(self._function_file(function_dir, "traces", "workspace_edit_memory.json"), rewrite_memory)
        self._write_json(self._function_file(function_dir, "traces", "workspace_edit_trace.json"), result["trace"])
        return result

    def _build_workspace_edit_memory(self, function: FunctionRecord, final_analysis: Dict, workspace_root: Path) -> Dict[str, Any]:
        return {
            "function": {
                "uid": function.uid,
                "name": function.name,
                "file_path": str(function.file_path),
                "start_line": function.start_line,
                "end_line": function.end_line,
            },
            "workspace_root": str(workspace_root),
            "rewrite_prompt": final_analysis.get("rewrite_prompt", ""),
            "rewrite_messages": final_analysis.get("messages") or [],
            "rewrite_raw_response": final_analysis.get("raw_response", ""),
            "rewrite_model": final_analysis.get("model", ""),
            "rewritten_function": final_analysis.get("rewritten_function", ""),
            "use_statements": final_analysis.get("use_statements") or [],
            "remove_use_statements": [],
            "caller_fixes": final_analysis.get("caller_fixes") or [],
            "cargo_dependencies": final_analysis.get("cargo_dependencies") or [],
            "remove_cargo_dependencies": [],
        }

    def _build_compile_fix_memory(
        self,
        function: FunctionRecord,
        compile_fix: Dict,
        workspace_root: Path,
        *,
        fix_history: Sequence[Dict[str, Any]],
        round_index: int,
        max_rounds: int,
    ) -> Dict[str, Any]:
        return {
            "function": {
                "uid": function.uid,
                "name": function.name,
                "file_path": str(function.file_path),
                "start_line": function.start_line,
                "end_line": function.end_line,
            },
            "workspace_root": str(workspace_root),
            "round_index": round_index,
            "max_rounds": max_rounds,
            "compile_errors": compile_fix.get("compile_errors") or [],
            "fix_history": list(fix_history),
            "diagnosis": compile_fix.get("diagnosis") or {},
            "compile_fix_prompt": compile_fix.get("rewrite_prompt", ""),
            "compile_fix_raw_response": compile_fix.get("raw_response", ""),
            "compile_fix_model": compile_fix.get("model", ""),
            "rewritten_function": compile_fix.get("rewritten_function", ""),
            "add_use_statements": compile_fix.get("add_use_statements") or [],
            "remove_use_statements": compile_fix.get("remove_use_statements") or [],
            "caller_fixes": compile_fix.get("caller_fixes") or [],
            "add_cargo_dependencies": compile_fix.get("add_cargo_dependencies") or [],
            "remove_cargo_dependencies": compile_fix.get("remove_cargo_dependencies") or [],
            "agentic_rag": compile_fix.get("agentic_rag") or {},
        }

    def _run_compile_fix_iterations(
        self,
        *,
        function: FunctionRecord,
        function_dir: Path,
        workspace_root: Path,
        symbol_contexts: Sequence[Dict],
        caller_contexts: Sequence[Dict],
        rag_result: Dict,
        final_analysis: Dict,
        initial_compile_check: Dict,
        max_rounds: int = 3,
    ) -> Dict[str, Any]:
        fix_history: List[Dict[str, Any]] = []
        attempts: List[Dict[str, Any]] = []
        current_compile_check = dict(initial_compile_check or {})
        current_rewrite = dict(final_analysis or {})
        current_rag_result = dict(rag_result or {})
        total_llm_calls = 0

        for round_index in range(1, max_rounds + 1):
            if current_compile_check.get("success"):
                break
            attempt = self._run_single_compile_fix_attempt(
                function=function,
                function_dir=function_dir,
                workspace_root=workspace_root,
                symbol_contexts=symbol_contexts,
                caller_contexts=caller_contexts,
                rag_result=current_rag_result,
                previous_rewrite=current_rewrite,
                compile_check=current_compile_check,
                fix_history=fix_history,
                round_index=round_index,
                max_rounds=max_rounds,
            )
            attempts.append(attempt)
            total_llm_calls += attempt.get("llm_calls", 0)
            current_compile_check = attempt.get("compile_check") or current_compile_check
            current_rewrite = attempt
            current_rag_result = {
                "selected_api_entries": self._dedupe_kb_entries(
                    list(current_rag_result.get("selected_api_entries") or [])
                    + list((attempt.get("agentic_rag") or {}).get("selected_api_entries") or [])
                )
            }
            fix_history.append(
                {
                    "round_index": round_index,
                    "compile_errors_before": attempt.get("compile_errors") or [],
                    "compile_errors_after": self._extract_compile_errors_from_check(attempt.get("compile_check") or {}),
                    "diagnosis": attempt.get("diagnosis") or {},
                    "analysis": attempt.get("analysis", ""),
                    "function_tags": attempt.get("function_tags") or [],
                    "success_after_round": bool((attempt.get("compile_check") or {}).get("success")),
                }
            )
            if (attempt.get("compile_check") or {}).get("success"):
                break

        final_attempt = attempts[-1] if attempts else None
        final_agentic_rag = (
            (final_attempt.get("agentic_rag") or {}) if final_attempt else {"selected_api_entries": current_rag_result.get("selected_api_entries") or []}
        )
        if final_attempt and not final_agentic_rag.get("selected_api_entries"):
            final_agentic_rag = {"selected_api_entries": current_rag_result.get("selected_api_entries") or []}
        return {
            "mode": "iterative_compile_fix",
            "max_rounds": max_rounds,
            "attempt_count": len(attempts),
            "history": fix_history,
            "attempts": attempts,
            "llm_calls": total_llm_calls,
            "compile_check": current_compile_check,
            "success": bool(current_compile_check.get("success")),
            "final_attempt": final_attempt,
            "rewrite_prompt": final_attempt.get("rewrite_prompt", "") if final_attempt else "",
            "raw_response": final_attempt.get("raw_response", "") if final_attempt else "",
            "rewritten_function": final_attempt.get("rewritten_function") if final_attempt else None,
            "add_use_statements": final_attempt.get("add_use_statements") or [] if final_attempt else [],
            "remove_use_statements": final_attempt.get("remove_use_statements") or [] if final_attempt else [],
            "add_cargo_dependencies": final_attempt.get("add_cargo_dependencies") or [] if final_attempt else [],
            "remove_cargo_dependencies": final_attempt.get("remove_cargo_dependencies") or [] if final_attempt else [],
            "function_tags": final_attempt.get("function_tags") or [] if final_attempt else [],
            "diagnosis": final_attempt.get("diagnosis") or {} if final_attempt else {},
            "agentic_rag": final_agentic_rag,
            "workspace_apply": final_attempt.get("workspace_apply") if final_attempt else None,
            "cargo_updates": final_attempt.get("cargo_updates") if final_attempt else None,
        }

    def _run_single_compile_fix_attempt(
        self,
        *,
        function: FunctionRecord,
        function_dir: Path,
        workspace_root: Path,
        symbol_contexts: Sequence[Dict],
        caller_contexts: Sequence[Dict],
        rag_result: Dict,
        previous_rewrite: Dict,
        compile_check: Dict,
        fix_history: Sequence[Dict[str, Any]],
        round_index: int,
        max_rounds: int,
    ) -> Dict[str, Any]:
        self._log(f"  [compile-fix] round {round_index}/{max_rounds}")
        error_list = self._extract_compile_errors_from_check(compile_check)
        self._log(f"  [compile-fix] compile errors before round: {len(error_list)}")
        for idx, err in enumerate(error_list[:3], start=1):
            preview = err.splitlines()[0].strip()
            self._log(f"    [compile-fix] error {idx}: {preview}")
        fix_agent = CompileFixAgent(
            model=self._model_for_stage("compile_fix"),
            client=self.client,
            logger=self._log,
            prompt_template=self.compile_fix_prompt_template,
            chat=self._chat,
            knowledge_base_path=self.knowledge_base_path,
        )
        compile_fix = fix_agent.run(
            function={
                "uid": function.uid,
                "name": function.name,
                "file_path": str(function.file_path),
                "start_line": function.start_line,
                "end_line": function.end_line,
                "source": function.source,
            },
            symbol_contexts=symbol_contexts,
            caller_contexts=caller_contexts,
            previous_rag_result=rag_result,
            previous_rewrite=previous_rewrite,
            compile_check=compile_check,
            fix_history=fix_history,
            round_index=round_index,
            max_rounds=max_rounds,
            format_symbol_contexts=self._format_symbol_contexts,
            format_caller_contexts=self._format_caller_contexts,
            format_api_knowledge=self._format_api_knowledge,
            flatten_caller_call_sites=self._flatten_caller_call_sites,
            build_caller_fixes=self._build_caller_fixes,
            extract_tag_blocks=self._extract_tag_blocks,
            extract_func_block=self._extract_func_block,
            strip_code_fence=self._strip_code_fence,
            normalize_use_statement=self._normalize_use_statement,
            is_valid_dependency_line=self._is_valid_dependency_line,
        )
        diagnosis = compile_fix.get("diagnosis") or {}
        self._log(
            "  [compile-fix] diagnosis: "
            f"api_gap={diagnosis.get('likely_api_knowledge_gap', False)} "
            f"run_agentic_rag={diagnosis.get('should_run_agentic_rag', False)} "
            f"run_example_code_search={diagnosis.get('should_run_example_code_search', False)}"
        )
        queries = diagnosis.get("example_code_queries") or []
        if queries:
            self._log(f"  [compile-fix] example-code queries: {queries}")
        rag_info = compile_fix.get("agentic_rag") or {}
        example_search = rag_info.get("example_code_search") or {}
        if example_search.get("aggregated_matches") is not None:
            self._log(
                f"  [compile-fix] example-code bm25 matches: {len(example_search.get('aggregated_matches') or [])}"
            )
        selected_entries = rag_info.get("selected_api_entries") or []
        if selected_entries:
            self._log(
                "  [compile-fix] selected knowledge entries: "
                + ", ".join(item.get("api_name", "") or f"kb:{item.get('kb_id')}" for item in selected_entries)
            )
        else:
            self._log("  [compile-fix] selected knowledge entries: none")
        if compile_fix.get("valid_output"):
            self._log("  [compile-fix] generated repaired function candidate")
        else:
            self._log(f"  [compile-fix] invalid output: {compile_fix.get('analysis', '')}")

        dependency_updates = self._apply_cargo_dependency_changes(
            workspace_root,
            add_lines=compile_fix.get("add_cargo_dependencies") or [],
            remove_items=compile_fix.get("remove_cargo_dependencies") or [],
        )
        compile_fix_memory = self._build_compile_fix_memory(
            function,
            compile_fix,
            workspace_root,
            fix_history=fix_history,
            round_index=round_index,
            max_rounds=max_rounds,
        )
        workspace_apply = self._run_workspace_edit_agent(
            workspace_root=workspace_root,
            function=function,
            function_dir=function_dir,
            edit_memory=compile_fix_memory,
            rewritten_function=compile_fix.get("rewritten_function") or "",
            add_use_statements=compile_fix.get("add_use_statements") or [],
            remove_use_statements=compile_fix.get("remove_use_statements") or [],
            caller_fixes=compile_fix.get("caller_fixes") or [],
            mode_label="compile_fix",
        )
        rerun_compile = self._run_workspace_compile_check(workspace_root)
        compile_fix["cargo_updates"] = dependency_updates
        compile_fix["workspace_apply"] = workspace_apply
        compile_fix["compile_check"] = rerun_compile
        self._log(
            "  [compile-fix] compile after round: "
            + ("passed" if rerun_compile.get("success") else f"failed(rc={rerun_compile.get('returncode')})")
        )
        self._write_compile_fix_round_artifacts(function_dir, round_index, compile_check, compile_fix_memory, compile_fix)
        return compile_fix

    def _write_compile_fix_round_artifacts(
        self,
        function_dir: Path,
        round_index: int,
        compile_check_before: Dict[str, Any],
        compile_fix_memory: Dict[str, Any],
        compile_fix: Dict[str, Any],
    ) -> None:
        round_label = f"compile_fix_round_{round_index}"
        self._write_json(self._function_file(function_dir, "artifacts", f"{round_label}_compile_check_before.json"), compile_check_before)
        self._write_json(self._function_file(function_dir, "artifacts", f"{round_label}_compile_check_after.json"), compile_fix.get("compile_check") or {})
        self._write_json(self._function_file(function_dir, "traces", f"{round_label}_memory.json"), compile_fix_memory)
        self._write_json(self._function_file(function_dir, "traces", f"{round_label}_trace.json"), compile_fix)
        prompt = compile_fix.get("rewrite_prompt")
        if prompt:
            self._function_file(function_dir, "rewrite", f"{round_label}_prompt.txt").write_text(prompt, encoding="utf-8")
        raw_response = compile_fix.get("raw_response")
        if raw_response:
            self._function_file(function_dir, "rewrite", f"{round_label}_raw_response.txt").write_text(raw_response, encoding="utf-8")
        rewritten_function = compile_fix.get("rewritten_function")
        if rewritten_function:
            self._function_file(function_dir, "rewrite", f"{round_label}_function.txt").write_text(rewritten_function, encoding="utf-8")
        self._write_json(
            self._function_file(function_dir, "artifacts", "compile_fix_history.json"),
            {
                "history": compile_fix.get("fix_history") or [],
                "latest_round": round_index,
                "latest_compile_check": compile_fix.get("compile_check") or {},
            },
        )

    def _extract_compile_errors_from_check(self, compile_check: Dict[str, Any]) -> List[str]:
        stderr = (compile_check or {}).get("stderr") or ""
        errors: List[str] = []
        current: List[str] = []
        for raw_line in stderr.splitlines():
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

    def _dedupe_kb_entries(self, entries: Sequence[Dict[str, Any]]) -> List[Dict[str, Any]]:
        deduped: List[Dict[str, Any]] = []
        seen = set()
        for item in entries:
            key = (item.get("kb_id"), item.get("api_name", ""))
            if key in seen:
                continue
            seen.add(key)
            deduped.append(dict(item))
        return deduped

    def _run_workspace_edit_agent(
        self,
        *,
        workspace_root: Path,
        function: FunctionRecord,
        function_dir: Path,
        edit_memory: Dict[str, Any],
        rewritten_function: str,
        add_use_statements: Sequence[str],
        remove_use_statements: Sequence[str],
        caller_fixes: Sequence[Dict[str, Any]],
        mode_label: str,
    ) -> Dict[str, Any]:
        target_path = self._workspace_path_for(workspace_root, function.file_path)
        result = {
            "mode": "llm_workspace_edit_loop",
            "mode_label": mode_label,
            "model": self._model_for_stage("workspace_edit"),
            "workspace_root": str(workspace_root),
            "workspace_file_path": str(target_path),
            "function_uid": function.uid,
            "use_statements_added": [],
            "use_statements_removed": [],
            "caller_fixes_applied": [],
            "function_replaced": False,
            "applied_edits": [],
            "skipped": [],
            "memory": edit_memory,
            "trace": {"messages": [], "steps": [], "summary": "", "completed": False},
        }
        if not target_path.exists():
            result["skipped"].append(f"workspace file missing: {target_path}")
            return result
        if not rewritten_function:
            result["skipped"].append("workspace edit loop unavailable: missing rewritten function")
            return result
        if self.client is None:
            result["skipped"].append("workspace edit loop unavailable: no LLM client configured")
            return result

        agent = WorkspaceEditAgent(
            project_root=self.project_root,
            workspace_root=workspace_root,
            search_bin_dir=self.search_bin_dir,
            parser=self._ts_parser,
            extract_function_name=self._extract_function_name,
            chat_messages=self._chat_messages,
            parse_json_response_with_repair=self._parse_json_response_with_repair,
            log=self._log,
            prompt_template=self.workspace_edit_prompt_template,
            model=self._model_for_stage("workspace_edit"),
        )
        result = agent.run(
            function=function,
            function_dir=function_dir,
            edit_memory=edit_memory,
            rewritten_function=rewritten_function,
            add_use_statements=add_use_statements,
            remove_use_statements=remove_use_statements,
            caller_fixes=caller_fixes,
            mode_label=mode_label,
            auto_apply_caller_fixes=True,
        )

        caller_fix_result = self._apply_caller_fixes(workspace_root, caller_fixes)
        result["caller_fixes_applied"] = caller_fix_result.get("applied", [])
        if caller_fix_result.get("edits"):
            result["applied_edits"].extend(caller_fix_result["edits"])
        if caller_fix_result.get("skipped"):
            result["skipped"].extend(caller_fix_result["skipped"])
        result["trace"]["caller_fix_apply"] = caller_fix_result
        return result

    def _workspace_path_for(self, workspace_root: Path, source_path: Path) -> Path:
        return workspace_root / source_path.relative_to(self.project_root)

    def _run_baseline_compile_check(self) -> Dict:
        cargo_toml_path = self.source_project_root / "Cargo.toml"
        if not cargo_toml_path.exists():
            return {
                "ran": False,
                "success": False,
                "workspace_root": str(self.source_project_root),
                "reason": f"missing Cargo.toml: {cargo_toml_path}",
            }

        cmd = ["cargo", "check", "--manifest-path", str(cargo_toml_path)]
        try:
            completed = subprocess.run(
                cmd,
                check=False,
                capture_output=True,
                text=True,
                cwd=self.source_project_root,
            )
        except Exception as exc:
            return {
                "ran": False,
                "success": False,
                "workspace_root": str(self.source_project_root),
                "reason": str(exc),
            }

        return {
            "ran": True,
            "success": completed.returncode == 0,
            "returncode": completed.returncode,
            "workspace_root": str(self.source_project_root),
            "command": cmd,
            "stdout": completed.stdout,
            "stderr": completed.stderr,
        }

    def _initialize_base_workspace(self) -> None:
        if self.base_workspace_root.exists():
            shutil.rmtree(self.base_workspace_root)
        shutil.copytree(self.source_project_root, self.base_workspace_root)
        self.project_root = self.base_workspace_root
        self.src_dir = self.project_root / "src"
        if self.target_file is not None:
            self.target_file = self._map_path_to_workspace(self.target_file, self.project_root)

    def _map_path_to_workspace(self, path: Path, workspace_root: Path) -> Path:
        if path.is_absolute():
            try:
                path.relative_to(workspace_root)
                return path
            except ValueError:
                pass
            try:
                rel = path.relative_to(self.source_project_root)
                return workspace_root / rel
            except ValueError:
                return path
        return workspace_root / path

    def _strip_code_fence(self, text: str) -> str:
        candidate = (text or "").strip()
        if not candidate:
            return ""
        lines = candidate.splitlines()
        if len(lines) >= 2:
            first = lines[0].strip()
            last = lines[-1].strip()
            if first.startswith("```") and last == "```":
                return "\n".join(lines[1:-1]).strip()
            if first.startswith("'''") and last == "'''":
                return "\n".join(lines[1:-1]).strip()
        return candidate

    def _contains_tag_artifact(self, text: str) -> bool:
        candidate = text or ""
        markers = (
            "```",
            "'''",
            "<FUNC>",
            "</FUNC>",
            "<USE>",
            "</USE>",
            "<fix_caller>",
            "</fix_caller>",
            "<FUNCTION_TAG>",
            "</FUNCTION_TAG>",
            "<CARGO_DEPENDENCY>",
            "</CARGO_DEPENDENCY>",
        )
        return any(marker in candidate for marker in markers)

    def _looks_like_rust_code(self, text: str) -> bool:
        candidate = self._strip_code_fence(text)
        if not candidate or self._contains_tag_artifact(candidate):
            return False
        indicators = (
            "fn ",
            "pub fn ",
            'extern "C"',
            "unsafe fn ",
            "impl ",
            "struct ",
            "enum ",
            "type ",
            "const ",
            "static ",
            "let ",
            "match ",
            "return",
            "if ",
            "{",
            ";",
        )
        return any(indicator in candidate for indicator in indicators)

    def _normalize_use_statement(self, statement: str) -> str:
        normalized = self._strip_code_fence(statement)
        if not normalized:
            return ""
        if self._contains_tag_artifact(normalized) or "..." in normalized:
            return ""
        normalized = normalized.strip()
        if not normalized.startswith("use "):
            if normalized.endswith(";"):
                normalized = normalized[:-1].strip()
            normalized = f"use {normalized};" if normalized else ""
        elif not normalized.endswith(";"):
            normalized = normalized + ";"
        if not normalized:
            return ""
        if not re.match(r"^use\s+[A-Za-z_][A-Za-z0-9_:{}*,\s]*;\s*$", normalized):
            return ""
        return normalized

    def _is_valid_dependency_line(self, dependency_line: str) -> bool:
        normalized = self._strip_code_fence(dependency_line).strip()
        if not normalized:
            return False
        if self._contains_tag_artifact(normalized) or "..." in normalized or "\n" in normalized:
            return False
        return DEPENDENCY_NAME_RE.match(normalized) is not None

    def _extract_use_statements(self, text: str) -> List[str]:
        statements: List[str] = []
        seen = set()
        for block in self._extract_tag_blocks(text, "USE"):
            if self._contains_tag_artifact(block):
                continue
            for line in block.splitlines():
                candidate = self._normalize_use_statement(line)
                if candidate and candidate not in seen:
                    seen.add(candidate)
                    statements.append(candidate)
        return statements

    def _extract_fix_caller_blocks(self, text: str) -> List[str]:
        fixes: List[str] = []
        for block in self._extract_tag_blocks(text, "fix_caller"):
            candidate = self._strip_code_fence(block).strip()
            if candidate:
                fixes.append(candidate)
        return fixes

    def _extract_cargo_dependency_lines(self, text: str) -> List[str]:
        dependency_lines: List[str] = []
        seen = set()
        for block in self._extract_tag_blocks(text, "CARGO_DEPENDENCY"):
            for line in block.splitlines():
                candidate = self._strip_code_fence(line).strip()
                if not candidate:
                    continue
                if not self._is_valid_dependency_line(candidate):
                    continue
                if candidate not in seen:
                    seen.add(candidate)
                    dependency_lines.append(candidate)
        return dependency_lines

    def _apply_caller_fixes(self, workspace_root: Path, caller_fixes: Sequence[Dict]) -> Dict:
        grouped: Dict[str, List[Dict]] = {}
        for item in caller_fixes:
            file_path = (item.get("file_path") or "").strip()
            if not file_path:
                continue
            grouped.setdefault(file_path, []).append(item)

        applied: List[Dict] = []
        edits: List[Dict] = []
        skipped: List[str] = []

        for file_path_str, items in grouped.items():
            path = self._map_path_to_workspace(Path(file_path_str), workspace_root)
            try:
                path.relative_to(workspace_root)
            except ValueError:
                skipped.append(f"caller file outside workspace rejected: {file_path_str}")
                continue
            if not path.exists():
                skipped.append(f"caller file missing: {path}")
                continue

            lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
            for item in sorted(items, key=lambda entry: (entry.get("line_number") or 0), reverse=True):
                line_number = item.get("line_number")
                replacement_code = self._strip_code_fence(item.get("replacement_code") or "").strip()
                if line_number is None or not replacement_code:
                    skipped.append(f"invalid caller fix for {item.get('caller_uid', '')}")
                    continue
                try:
                    line_idx = int(line_number) - 1
                except Exception:
                    skipped.append(f"invalid caller line number for {item.get('caller_uid', '')}: {line_number}")
                    continue
                if line_idx < 0 or line_idx >= len(lines):
                    skipped.append(f"caller line out of range: {path}:{line_number}")
                    continue

                old_text = lines[line_idx]
                replacement_lines = replacement_code.splitlines()
                lines[line_idx:line_idx + 1] = replacement_lines
                applied_item = {
                    "caller_uid": item.get("caller_uid", ""),
                    "caller_name": item.get("caller_name", ""),
                    "callee_name": item.get("callee_name", ""),
                    "file_path": str(path),
                    "line_number": int(line_number),
                    "old_text": old_text,
                    "new_text": replacement_code,
                }
                applied.append(applied_item)
                edits.append(
                    {
                        "edit_type": "replace_caller_line",
                        **applied_item,
                    }
                )
            path.write_text("\n".join(lines) + "\n", encoding="utf-8")

        return {"applied": applied, "edits": edits, "skipped": skipped}

    def _is_caller_fix_replace(self, arguments: Dict[str, Any], caller_fixes: Sequence[Dict]) -> bool:
        file_path = (arguments.get("file_path") or "").strip()
        start_line = arguments.get("start_line")
        end_line = arguments.get("end_line")
        try:
            start = int(start_line)
            end = int(end_line)
        except Exception:
            return False
        if start <= 0 or end < start:
            return False

        for item in caller_fixes:
            item_file = (item.get("file_path") or "").strip()
            item_line = item.get("line_number")
            try:
                item_line_int = int(item_line)
            except Exception:
                continue
            if item_file == file_path and start <= item_line_int <= end:
                return True
        return False

    def _run_workspace_compile_check(self, workspace_root: Path) -> Dict:
        cargo_toml_path = workspace_root / "Cargo.toml"
        if not cargo_toml_path.exists():
            return {
                "ran": False,
                "success": False,
                "workspace_root": str(workspace_root),
                "reason": f"missing Cargo.toml: {cargo_toml_path}",
            }

        cmd = ["cargo", "check", "--manifest-path", str(cargo_toml_path)]
        try:
            completed = subprocess.run(
                cmd,
                check=False,
                capture_output=True,
                text=True,
                cwd=workspace_root,
            )
        except Exception as exc:
            return {
                "ran": False,
                "success": False,
                "workspace_root": str(workspace_root),
                "reason": str(exc),
            }

        return {
            "ran": True,
            "success": completed.returncode == 0,
            "returncode": completed.returncode,
            "workspace_root": str(workspace_root),
            "command": cmd,
            "stdout": completed.stdout,
            "stderr": completed.stderr,
        }

    def _chat_messages(self, messages: Sequence[Dict], log_prefix: str = "[llm]", model: Optional[str] = None) -> str:
        assert self.client is not None
        request_model = model or self.model
        request_messages = list(messages)
        max_attempts = 3
        last_error: Optional[Exception] = None
        for attempt in range(1, max_attempts + 1):
            try:
                completion = self.client.chat.completions.create(
                    model=request_model,
                    stream=False,
                    messages=request_messages,
                )
                content = completion.choices[0].message.content
                if isinstance(content, list):
                    text = "\n".join(item.get("text", "") for item in content if isinstance(item, dict)).strip()
                else:
                    text = (content or "").strip()
                if text:
                    return text
                raise ValueError("empty response content from LLM")
            except Exception as exc:
                last_error = exc
                self._log(
                    f"{log_prefix} LLM request attempt {attempt}/{max_attempts} failed "
                    f"(model={request_model}, error={type(exc).__name__}: {exc})"
                )
                if attempt < max_attempts:
                    time.sleep(attempt)
        prompt_preview = ""
        if request_messages:
            content = request_messages[-1].get("content", "")
            if isinstance(content, str):
                prompt_preview = content.strip().replace("\n", "\\n")[:300]
        self._log(
            f"{log_prefix} LLM request exhausted retries "
            f"(model={request_model}, prompt_preview={prompt_preview})"
        )
        raise RuntimeError(
            f"LLM request failed after {max_attempts} attempts for model {request_model}: "
            f"{type(last_error).__name__}: {last_error}"
        ) from last_error

    def _parse_json_response_with_repair(
        self,
        response_text: str,
        request_messages: Sequence[Dict],
        stage_label: str,
        model: Optional[str] = None,
    ) -> Tuple[Optional[Dict[str, Any]], str]:
        payload = self._parse_json_response(response_text)
        if payload is not None:
            return payload, response_text

        self._log(f"[workspace-edit] {stage_label} returned invalid JSON; requesting one-shot JSON-only repair")
        repair_messages = list(request_messages) + [
            {"role": "assistant", "content": response_text},
            {
                "role": "user",
                "content": (
                    "Your previous reply was not valid JSON for the required workspace-edit protocol. "
                    "Return exactly one JSON object only. "
                    "The first non-whitespace character must be '{'. "
                    "The top-level value must not be an array. "
                    "Do not use markdown fences. "
                    "Use action=tool or action=done."
                ),
            },
        ]
        repaired_text = self._chat_messages(repair_messages, log_prefix="[workspace-edit]", model=model)
        return self._parse_json_response(repaired_text), repaired_text

    def _parse_json_response(self, text: str) -> Optional[Dict[str, Any]]:
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
            start = candidate.find("{")
            end = candidate.rfind("}")
            if start == -1 or end == -1 or end <= start:
                start = candidate.find("[")
                end = candidate.rfind("]")
                if start == -1 or end == -1 or end <= start:
                    return None
                try:
                    payload = json.loads(candidate[start:end + 1])
                except Exception:
                    return None
            else:
                try:
                    payload = json.loads(candidate[start:end + 1])
                except Exception:
                    return None
        if isinstance(payload, dict):
            return payload
        if isinstance(payload, list) and len(payload) == 1 and isinstance(payload[0], dict):
            return payload[0]
        return None

    def _apply_cargo_dependency_changes(
        self,
        workspace_root: Path,
        add_lines: Sequence[str],
        remove_items: Sequence[str],
    ) -> Dict:
        cargo_toml_path = workspace_root / "Cargo.toml"
        if not cargo_toml_path.exists():
            return {
                "added": [],
                "removed": [],
                "skipped": list(add_lines) + list(remove_items),
                "path": str(cargo_toml_path),
                "edits": [],
            }

        original_text = cargo_toml_path.read_text(encoding="utf-8")
        lines = original_text.splitlines()
        added: List[str] = []
        removed: List[str] = []
        skipped: List[str] = []
        edits: List[Dict] = []
        clean_lines: List[str] = []
        existing_names = set()

        for raw in lines:
            match = DEPENDENCY_NAME_RE.match(raw)
            if match:
                existing_names.add(match.group(1).strip())

        for item in add_lines:
            dependency_line = item.strip()
            if not dependency_line:
                continue
            name_match = DEPENDENCY_NAME_RE.match(dependency_line)
            if not name_match:
                skipped.append(dependency_line)
                continue
            dep_name = name_match.group(1).strip()
            if dep_name in existing_names or dependency_line in clean_lines:
                skipped.append(dependency_line)
                continue
            clean_lines.append(dependency_line)
            existing_names.add(dep_name)

        removal_targets = {(item or "").strip() for item in remove_items if (item or "").strip()}
        if removal_targets:
            kept_lines: List[str] = []
            for idx, line in enumerate(lines, start=1):
                stripped = line.strip()
                match = DEPENDENCY_NAME_RE.match(line)
                dep_name = match.group(1).strip() if match else None
                if stripped in removal_targets or (dep_name and dep_name in removal_targets):
                    removed.append(line)
                    edits.append(
                        {
                            "edit_type": "delete_cargo_dependency",
                            "file_path": str(cargo_toml_path),
                            "line_number": idx,
                            "old_text": line,
                        }
                    )
                    continue
                kept_lines.append(line)
            lines = kept_lines

        if not clean_lines and not removed:
            return {"added": [], "removed": [], "skipped": skipped, "path": str(cargo_toml_path), "edits": edits}

        dep_section_start = None
        insertion_index = None
        for index, line in enumerate(lines):
            if line.strip() == "[dependencies]":
                dep_section_start = index
                insertion_index = index + 1
                continue
            if dep_section_start is not None and line.startswith("[") and line.strip() != "[dependencies]":
                insertion_index = index
                break

        if dep_section_start is None:
            if lines and lines[-1].strip():
                lines.append("")
            lines.append("[dependencies]")
            insertion_index = len(lines)
        elif insertion_index is None:
            insertion_index = len(lines)

        for offset, dependency_line in enumerate(clean_lines):
            line_number = insertion_index + offset + 1
            lines.insert(insertion_index + offset, dependency_line)
            added.append(dependency_line)
            edits.append(
                {
                    "edit_type": "insert_cargo_dependency",
                    "file_path": str(cargo_toml_path),
                    "line_number": line_number,
                    "new_text": dependency_line,
                }
            )

        updated_text = "\n".join(lines) + "\n"
        if updated_text != original_text:
            cargo_toml_path.write_text(updated_text, encoding="utf-8")
        return {"added": added, "removed": removed, "skipped": skipped, "path": str(cargo_toml_path), "edits": edits}

    def _apply_cargo_dependencies(self, workspace_root: Path, dependency_lines: Sequence[str]) -> Dict:
        return self._apply_cargo_dependency_changes(workspace_root, add_lines=dependency_lines, remove_items=[])

    def _chat(self, user_prompt: str, model: Optional[str] = None) -> str:
        return self._chat_messages([{"role": "user", "content": user_prompt}], log_prefix="[rewrite]", model=model)

    def _extract_func_block(self, text: str) -> Optional[str]:
        for body in self._extract_tag_blocks(text, "FUNC"):
            candidate = self._strip_code_fence(body)
            if not self._looks_like_rust_code(candidate):
                continue
            return "<FUNC>\n" + candidate.strip() + "\n</FUNC>"
        return None

    def _extract_tag_blocks(self, text: str, tag: str) -> List[str]:
        pattern = re.compile(rf"<{re.escape(tag)}>\s*(.*?)\s*</{re.escape(tag)}>", re.DOTALL)
        blocks: List[str] = []
        for match in pattern.finditer(text or ""):
            body = self._strip_code_fence(match.group(1))
            if not body:
                continue
            blocks.append(body)
        return blocks

    def _write_function_result(self, function: FunctionRecord, result: Dict) -> Dict:
        function_dir = self.functions_dir / self._sanitize_filename(function.uid)
        function_dir.mkdir(parents=True, exist_ok=True)
        self._prepare_function_subdirs(function_dir)

        metadata = {
            "uid": function.uid,
            "name": function.name,
            "file_path": str(function.file_path),
            "start_line": function.start_line,
            "end_line": function.end_line,
            "contains_unsafe": function.contains_unsafe,
            "is_fallback": function.is_fallback,
            "models": result.get("models") or {},
        }
        self._function_file(function_dir, "inputs", "function.json").write_text(json.dumps(metadata, ensure_ascii=False, indent=2), encoding="utf-8")
        self._function_file(function_dir, "inputs", "function.rs").write_text(function.source, encoding="utf-8")
        self._function_file(function_dir, "inputs", "pre_context.txt").write_text(function.pre_context, encoding="utf-8")
        self._function_file(function_dir, "traces", "result.json").write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")

        context_trace = result.get("context_agent")
        if context_trace is not None:
            self._function_file(function_dir, "traces", "context_agent_trace.json").write_text(
                json.dumps(context_trace, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        rag_trace = result.get("agentic_rag")
        if rag_trace is not None:
            self._function_file(function_dir, "traces", "agentic_rag_trace.json").write_text(
                json.dumps(rag_trace, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        raw_response = result.get("final_analysis", {}).get("raw_response")
        if raw_response:
            self._function_file(function_dir, "rewrite", "final_llm_raw_response.txt").write_text(raw_response, encoding="utf-8")
        rewritten = result.get("final_analysis", {}).get("rewritten_function")
        if rewritten:
            self._function_file(function_dir, "rewrite", "rewritten_function.txt").write_text(rewritten, encoding="utf-8")
        use_statements = result.get("final_analysis", {}).get("use_statements", [])
        if use_statements:
            self._function_file(function_dir, "rewrite", "use_statements.json").write_text(
                json.dumps(use_statements, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        function_tags = result.get("final_analysis", {}).get("function_tags", [])
        if function_tags:
            self._function_file(function_dir, "rewrite", "function_tags.json").write_text(
                json.dumps(function_tags, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        cargo_dependency_tags = result.get("final_analysis", {}).get("cargo_dependency_tags", [])
        if cargo_dependency_tags:
            self._function_file(function_dir, "rewrite", "cargo_dependency_tags.json").write_text(
                json.dumps(cargo_dependency_tags, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        cargo_updates = result.get("cargo_updates")
        if cargo_updates:
            self._function_file(function_dir, "artifacts", "cargo_updates.json").write_text(
                json.dumps(cargo_updates, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        workspace_apply = result.get("workspace_apply")
        if workspace_apply:
            self._function_file(function_dir, "artifacts", "workspace_apply.json").write_text(
                json.dumps(workspace_apply, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        compile_check = result.get("compile_check")
        if compile_check:
            self._function_file(function_dir, "artifacts", "compile_check.json").write_text(
                json.dumps(compile_check, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )

        return {
            "uid": function.uid,
            "name": function.name,
            "file_path": str(function.file_path),
            "status": result["status"],
            "output_dir": str(function_dir),
        }

    def _write_console_report(self, summary: Dict) -> None:
        lines = [
            "SaferAgent summary",
            f"project: {summary['project_name']}",
            f"project_root: {summary['project_root']}",
            f"workspace_mode: {summary.get('workspace', {}).get('mode')}",
            f"workspaces_root: {summary.get('workspace', {}).get('workspaces_root')}",
            f"default_model: {self.model}",
            f"context_agent_model: {self._model_for_stage('context_agent')}",
            f"agentic_rag_model: {self._model_for_stage('agentic_rag')}",
            f"final_rewrite_model: {self._model_for_stage('final_rewrite')}",
            f"compile_fix_model: {self._model_for_stage('compile_fix')}",
            f"workspace_edit_model: {self._model_for_stage('workspace_edit')}",
            f"selection_mode: {summary['selection_mode']}",
            f"target_files: {len(summary['target_files'])}",
            f"topological_functions_total: {summary['total_functions_in_topological_order']}",
            f"functions_scanned: {summary['total_functions_scanned']}",
            f"fallback_skipped: {summary['fallback_functions_skipped']}",
            f"no_unsafe_skipped: {summary['safe_functions_skipped']}",
            f"unsafe_processed: {summary['unsafe_functions_processed']}",
            f"llm_calls: {summary['llm_calls']}",
            f"cargo_dependencies_added: {len(summary['cargo_dependencies_added'])}",
            f"workspace_apply_success: {summary['workspace_apply_success']}",
            f"workspace_apply_failed: {summary['workspace_apply_failed']}",
            f"compile_checks_ran: {summary['compile_checks_ran']}",
            f"compile_checks_passed: {summary['compile_checks_passed']}",
            f"compile_checks_failed: {summary['compile_checks_failed']}",
            f"target_file: {summary['target_file']}",
            f"stop_before_uid: {summary['stop_before_uid']}",
            f"resume_from_uid: {summary.get('resume_from_uid')}",
            f"reset_resume_function_dir: {summary.get('reset_resume_function_dir')}",
        ]
        report_path = self.output_dir / "console_summary.txt"
        report_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        self._log("\n".join(lines))
        self._log(f"console summary written to: {report_path}")

    def _sanitize_filename(self, value: str) -> str:
        return re.sub(r"[^A-Za-z0-9._-]+", "_", value)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Function-level saferAgent for translated Rust projects")
    parser.add_argument(
        "project_path",
        type=Path,
        help="Rust project root or its parent directory that contains translate_by_qwen3_coder/",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        help="Directory for analysis outputs; default is saferAgent/results/<project>/<timestamp>",
    )
    parser.add_argument("--model", help="LLM model name")
    parser.add_argument("--context-model", help="Model for context_agent stage")
    parser.add_argument("--rag-model", help="Model for agentic_rag stage")
    parser.add_argument("--rewrite-model", help="Model for final safer rewrite stage")
    parser.add_argument("--compile-fix-model", help="Model for compile_fix stage")
    parser.add_argument("--workspace-edit-model", help="Model for workspace edit stage")
    parser.add_argument("--api-key", help="LLM API key; defaults to SAFER_AGENT_API_KEY or apiyiTestkey.py")
    parser.add_argument("--base-url", help="LLM base URL; defaults to SAFER_AGENT_BASE_URL or apiyiTestkey.py")
    parser.add_argument("--dry-run", action="store_true", help="Disable LLM calls and only run file/function/context analysis")
    parser.add_argument("--limit-functions", type=int, help="Only process the first N collected functions, useful for debugging")
    parser.add_argument("--knowledge-base-path", type=Path, help="OpenHarmony Rust API knowledge base JSON path")
    parser.add_argument("--target-file", type=Path, help="Only process functions from this Rust source file after topological ordering")
    parser.add_argument("--stop-before-uid", help="Stop before this function uid after applying other filters")
    parser.add_argument("--resume-from-uid", help="Resume processing from this function uid within an existing or new output dir")
    parser.add_argument(
        "--reset-resume-function-dir",
        action="store_true",
        help="When resuming, delete the existing result directory for the resume function before rerunning it",
    )
    parser.add_argument("--skip-context-agent", action="store_true", help="Skip the slow symbol-context search stage and only run AgenticRAG plus rewrite")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    agent = SaferAgent(
        project_path=args.project_path,
        output_dir=args.output_dir,
        model=args.model,
        context_model=args.context_model,
        rag_model=args.rag_model,
        rewrite_model=args.rewrite_model,
        compile_fix_model=args.compile_fix_model,
        workspace_edit_model=args.workspace_edit_model,
        api_key=args.api_key,
        base_url=args.base_url,
        dry_run=args.dry_run,
        limit_functions=args.limit_functions,
        knowledge_base_path=args.knowledge_base_path,
        target_file=args.target_file,
        stop_before_uid=args.stop_before_uid,
        resume_from_uid=args.resume_from_uid,
        reset_resume_function_dir=args.reset_resume_function_dir,
        skip_context_agent=args.skip_context_agent,
    )
    agent.run()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
