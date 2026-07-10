#!/usr/bin/env python3
from __future__ import annotations

import json
import re
import subprocess
import time
from pathlib import Path
from typing import Any, Callable, Dict, List, Optional, Sequence


RUST_TYPE_RE = re.compile(r"\b([A-Z][A-Za-z0-9_]*(?:::[A-Z][A-Za-z0-9_]*)*)\b")
FREE_CALL_RE = re.compile(r"(?<![.\w])([A-Za-z_][A-Za-z0-9_:]*)\s*\(")
PATH_LAST_SEGMENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*$")
CALL_KEYWORDS = {
    "if",
    "else",
    "loop",
    "while",
    "for",
    "match",
    "return",
    "Some",
    "None",
    "Ok",
    "Err",
    "Self",
    "self",
    "super",
    "crate",
}


class SymbolContextAgent:
    def __init__(
        self,
        project_root: Path,
        search_bin_dir: Path,
        model: str,
        client=None,
        max_symbols: int = 4,
        max_steps_per_symbol: int = 4,
        logger: Optional[Callable[[str], None]] = None,
        progress_callback: Optional[Callable[[str, Dict[str, Any]], None]] = None,
    ) -> None:
        self.project_root = project_root
        self.search_bin_dir = search_bin_dir
        self.model = model
        self.client = client
        self.max_symbols = max_symbols
        self.max_steps_per_symbol = max_steps_per_symbol
        self.logger = logger
        self.progress_callback = progress_callback

    def _log(self, message: str) -> None:
        if self.logger is not None:
            self.logger(message)

    def _emit_progress(self, stage: str, payload: Dict[str, Any]) -> None:
        if self.progress_callback is not None:
            self.progress_callback(stage, payload)

    def run(self, function: Dict) -> Dict:
        self._log(f"  [context] start function {function['name']}")
        initial_decision = self._judge_unknown_symbols(function)
        base_messages = initial_decision.get("messages", [])
        symbol_runs = []
        all_symbol_contexts = []
        caller_contexts = []
        llm_calls = 1 if initial_decision.get("used_llm") else 0

        result = {
            "model": self.model,
            "initial_symbol_decision": {
                key: value
                for key, value in initial_decision.items()
                if key != "messages"
            },
            "symbol_runs": symbol_runs,
            "symbol_contexts": all_symbol_contexts,
            "caller_contexts": caller_contexts,
            "llm_calls": llm_calls,
        }
        selected_symbols = [item.get("symbol", "") for item in result["initial_symbol_decision"].get("symbols", []) if item.get("symbol")]
        if selected_symbols:
            self._log(f"  [context] selected symbols: {', '.join(selected_symbols)}")
        else:
            self._log("  [context] selected symbols: none")
        self._emit_progress("initial_symbol_decision", result)

        total_symbols = len(initial_decision.get("symbols", [])[: self.max_symbols])
        for index, symbol_item in enumerate(initial_decision.get("symbols", [])[: self.max_symbols], start=1):
            self._log(f"  [context] symbol {index}/{total_symbols}: {symbol_item.get('symbol', '')}")
            symbol_result = self._process_symbol(function, symbol_item, base_messages)
            symbol_runs.append(symbol_result)
            all_symbol_contexts.append(symbol_result.get("extracted_context") or {})
            llm_calls += symbol_result.get("llm_calls", 0)
            result["llm_calls"] = llm_calls
            self._emit_progress("symbol_run", result)

        caller_candidates = function.get("caller_candidates") or []
        total_callers = len(caller_candidates)
        for index, caller_item in enumerate(caller_candidates, start=1):
            self._log(f"  [context] caller {index}/{total_callers}: {caller_item.get('caller_uid', '')}")
            caller_result = self._process_caller(function, caller_item)
            caller_contexts.append(caller_result.get("extracted_context") or {})
            llm_calls += caller_result.get("llm_calls", 0)
            result["llm_calls"] = llm_calls
            self._emit_progress("caller_run", result)

        self._log(f"  [context] completed llm_calls={llm_calls}")
        self._emit_progress("completed", result)
        return result

    def _judge_unknown_symbols(self, function: Dict) -> Dict:
        allowed_symbols = self._collect_allowed_symbols(function)
        system_prompt = (
            "You are a Rust unsafe-context planning agent. "
            "Output format requirement comes first: your reply must be valid JSON, the first non-whitespace character must be '{', "
            "and the top-level JSON value must be an object with exactly this shape: "
            "{\"symbols\": [{\"symbol\": \"string\", \"kind\": \"struct|external_call\", \"reason\": \"string\"}]}. "
            "If there are no important symbols, return {\"symbols\": []}. "
            "Even when there is exactly one symbol, still return it inside the symbols array. "
            "Do not return a bare array. Do not return a bare symbol object. Do not use markdown fences. "
            "From the function source alone, identify the symbols that are genuinely worth investigating for unsafe reduction. "
            "Do not rely on a precomputed candidate list because none is provided. "
            "Repository search is relatively expensive, so be conservative and only choose a symbol when its missing semantics are likely to materially affect the unsafe-optimization decision. "
            "Prefer symbols that are especially important for memory safety, ownership transfer, aliasing, pointer validity, layout, ABI, or callee side effects. "
            "Choose symbols only from these two categories: "
            "1) struct or struct-like type names that appear in the function and whose layout/field semantics may affect unsafe reduction; "
            "2) free-function or path-based call targets that behave like external callees and whose contracts may affect unsafe reduction. "
            "Do not include ordinary local variables, buffers, pointer base variables, field names, temporary values, literals, macros, or method-call receivers. "
            "If the symbol is only mildly helpful, skip it; if no symbol in those two categories is truly important, return {\"symbols\": []}. "
            "Return valid JSON only."
        )
        user_payload = {
            "project_root": str(self.project_root),
            "file_path": function["file_path"],
            "function_name": function["name"],
            "line_range": [function["start_line"], function["end_line"]],
            "function_source": function["source"],
            "allowed_symbol_scope": {
                "struct_type_symbols": allowed_symbols["structs"],
                "external_call_symbols": allowed_symbols["external_calls"],
            },
            "required_schema": {
                "symbols": [
                    {
                        "symbol": "string",
                        "kind": "struct|external_call",
                        "reason": "why this symbol may affect unsafe reduction",
                    }
                ]
            },
        }
        user_prompt = json.dumps(user_payload, ensure_ascii=False, indent=2)

        if self.client is None:
            self._log("  [context] LLM unavailable during unknown-symbol judgement")
            return {
                "used_llm": False,
                "raw_response": None,
                "symbols": [],
                "messages": [],
                "reason": "LLM unavailable; no symbol pre-filter is performed",
            }

        self._log("  [context] judging unknown symbols...")
        request_messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_prompt},
        ]
        response_text = self._chat(request_messages)
        payload, response_text = self._extract_json_with_repair(
            response_text=response_text,
            request_messages=request_messages,
            required_schema=user_payload["required_schema"],
            stage_label="unknown-symbol judgement",
        )
        payload = self._normalize_symbol_selection_payload(payload)
        symbols = []
        seen = set()
        for item in payload.get("symbols", []):
            symbol = (item.get("symbol") or "").strip()
            normalized = self._normalize_allowed_symbol(symbol, allowed_symbols)
            if not normalized or normalized in seen:
                continue
            seen.add(normalized)
            symbols.append({
                "symbol": normalized,
                "kind": item.get("kind", ""),
                "reason": item.get("reason", ""),
            })
        return {
            "used_llm": True,
            "raw_response": response_text,
            "symbols": symbols[: self.max_symbols],
            "messages": [
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": user_prompt},
                {"role": "assistant", "content": response_text},
            ],
        }

    def _collect_allowed_symbols(self, function: Dict) -> Dict[str, List[str]]:
        source = function.get("source", "")
        function_name = function.get("name", "")

        struct_symbols = sorted({match.group(1) for match in RUST_TYPE_RE.finditer(source)})

        external_calls = []
        seen_calls = set()
        for match in FREE_CALL_RE.finditer(source):
            call_name = match.group(1)
            if call_name in CALL_KEYWORDS or call_name == function_name:
                continue
            if "!" in call_name:
                continue
            if call_name not in seen_calls:
                seen_calls.add(call_name)
                external_calls.append(call_name)

        return {
            "structs": struct_symbols,
            "external_calls": external_calls,
        }

    def _normalize_allowed_symbol(self, symbol: str, allowed_symbols: Dict[str, List[str]]) -> str:
        if not symbol:
            return ""

        allowed_pool = allowed_symbols["structs"] + allowed_symbols["external_calls"]
        if symbol in allowed_pool:
            return symbol

        symbol_last = self._last_segment(symbol)
        if not symbol_last:
            return ""

        for candidate in allowed_pool:
            if self._last_segment(candidate) == symbol_last:
                return candidate
        return ""

    def _last_segment(self, symbol: str) -> str:
        match = PATH_LAST_SEGMENT_RE.search(symbol or "")
        return match.group(0) if match else ""

    def _process_symbol(self, function: Dict, symbol_item: Dict, base_messages: Sequence[Dict]) -> Dict:
        symbol = symbol_item["symbol"]
        symbol_reason = symbol_item.get("reason", "")
        required_schema = {
            "action": "tool|done",
            "reason": "short string",
            "tool_name": "optional tool name",
            "arguments": {
                "query": "optional string",
                "target": "optional path",
                "file_path": "optional file path",
                "line_number": "optional integer",
            },
            "extracted_context": {
                "found_definition": "boolean",
                "symbol": "string",
                "definition_kind": "struct|function|type|extern_decl|unknown",
                "file_path": "string",
                "line_number": "integer",
                "definition_snippet": "exact definition code snippet without line numbers; empty when not found",
                "note": "short explanation of what was or was not found",
            },
        }
        messages = list(base_messages)
        messages.append({
            "role": "system",
            "content": self._tool_planner_system_prompt(),
        })
        messages.append({
            "role": "user",
            "content": json.dumps(
                {
                    "current_symbol": symbol,
                    "symbol_reason": symbol_reason,
                    "project_root": str(self.project_root),
                    "function_name": function["name"],
                    "function_source": function["source"],
                    "tools": self._tool_specs(),
                    "instructions": [
                        "Process one symbol at a time.",
                        "Prefer search_dir first to locate candidate definitions/usages in the whole Rust project.",
                        "Then use open_line_window to inspect the likely definition region.",
                        "Use search_file when you already know the file.",
                        "Use find_file only when file-name lookup is more appropriate than symbol search.",
                        "Your goal is to extract the exact definition snippet for the current symbol.",
                        "After using tools, decide whether the definition was actually identified.",
                        "Do not return tool output as final context.",
                        "Return exactly one JSON object. The first non-whitespace character must be '{'.",
                        "Do not return a bare array. Do not return markdown fences.",
                        "Return JSON only.",
                    ],
                    "required_schema": required_schema,
                },
                ensure_ascii=False,
                indent=2,
            ),
        })

        trace = []
        tool_history = []
        llm_calls = 0

        if self.client is None:
            return {
                "symbol": symbol,
                "symbol_reason": symbol_reason,
                "llm_calls": 0,
                "trace": [],
                "tool_history": [],
                "extracted_context": self._default_extracted_context(
                    symbol=symbol,
                    symbol_reason=symbol_reason,
                    note="LLM unavailable; symbol definition was not extracted.",
                ),
            }

        extracted_context = self._default_extracted_context(symbol=symbol, symbol_reason=symbol_reason)
        for step in range(1, self.max_steps_per_symbol + 1):
            self._log(f"    [context] symbol={symbol} llm step {step}")
            request_messages = list(messages)
            response_text = self._chat(request_messages)
            llm_calls += 1
            payload, response_text = self._extract_json_with_repair(
                response_text=response_text,
                request_messages=request_messages,
                required_schema=required_schema,
                stage_label=f"symbol tool planning for {symbol}",
            )
            payload = self._normalize_action_payload(payload)
            step_record = {
                "step": step,
                "llm_raw_response": response_text,
                "parsed": payload,
            }
            trace.append(step_record)
            messages.append({"role": "assistant", "content": response_text})

            action = payload.get("action")
            if action == "done":
                extracted_context = self._normalize_extracted_context(
                    symbol=symbol,
                    symbol_reason=symbol_reason,
                    payload=payload.get("extracted_context"),
                )
                self._log(f"    [context] symbol={symbol} done")
                self._emit_progress("symbol_step", {
                    "symbol": symbol,
                    "step": step,
                    "trace": trace,
                    "tool_history": tool_history,
                    "extracted_context": extracted_context,
                })
                break

            tool_name = payload.get("tool_name")
            arguments = payload.get("arguments", {}) or {}
            self._log(f"    [context] symbol={symbol} tool={tool_name} args={arguments}")
            tool_output = self._run_tool(tool_name, arguments)
            tool_record = {
                "tool": tool_name,
                "arguments": arguments,
                "output": tool_output,
                "symbol": symbol,
                "reason": payload.get("reason", ""),
            }
            trace.append({"step": step, "tool_result": tool_record})
            tool_history.append(tool_record)
            messages.append({
                "role": "user",
                "content": json.dumps(
                    {
                        "tool_result": tool_record,
                        "instruction": "Continue for the same symbol or return action=done if you have enough context.",
                    },
                    ensure_ascii=False,
                    indent=2,
                ),
            })
            self._emit_progress("symbol_step", {
                "symbol": symbol,
                "step": step,
                "trace": trace,
                "tool_history": tool_history,
                "extracted_context": extracted_context,
            })

        return {
            "symbol": symbol,
            "symbol_reason": symbol_reason,
            "llm_calls": llm_calls,
            "trace": trace,
            "tool_history": tool_history,
            "extracted_context": extracted_context,
        }

    def _default_extracted_context(self, symbol: str, symbol_reason: str, note: str = "") -> Dict[str, Any]:
        return {
            "symbol": symbol,
            "symbol_reason": symbol_reason,
            "found_definition": False,
            "definition_kind": "unknown",
            "file_path": "",
            "line_number": None,
            "definition_snippet": "",
            "note": note,
        }

    def _normalize_extracted_context(self, symbol: str, symbol_reason: str, payload: Any) -> Dict[str, Any]:
        result = self._default_extracted_context(symbol=symbol, symbol_reason=symbol_reason)
        if isinstance(payload, str):
            result["definition_snippet"] = payload.strip()
            result["found_definition"] = bool(result["definition_snippet"])
            result["note"] = "Legacy extracted context format."
            return result
        if not isinstance(payload, dict):
            result["note"] = "Invalid extracted_context payload."
            return result

        result["found_definition"] = bool(payload.get("found_definition"))
        result["definition_kind"] = (payload.get("definition_kind") or "unknown").strip() or "unknown"
        result["file_path"] = (payload.get("file_path") or "").strip()
        line_number = payload.get("line_number")
        try:
            result["line_number"] = int(line_number) if line_number is not None else None
        except Exception:
            result["line_number"] = None
        result["definition_snippet"] = (payload.get("definition_snippet") or "").strip()
        result["note"] = (payload.get("note") or "").strip()

        if result["definition_snippet"] and not result["found_definition"]:
            result["found_definition"] = True
        if result["found_definition"] and not result["definition_snippet"]:
            result["found_definition"] = False
            if not result["note"]:
                result["note"] = "Marked found_definition=true but definition_snippet was empty."
        return result

    def _process_caller(self, function: Dict, caller_item: Dict) -> Dict:
        caller_uid = caller_item.get("caller_uid", "")
        caller_name = caller_item.get("caller_name", "")
        required_schema = {
            "action": "tool|done",
            "reason": "short string",
            "tool_name": "optional tool name",
            "arguments": {
                "query": "optional string",
                "target": "optional path",
                "file_path": "optional file path",
                "line_number": "optional integer",
            },
            "extracted_context": {
                "caller_uid": "string",
                "caller_name": "string",
                "callee_name": "string",
                "caller_file_path": "string",
                "found_call_sites": "boolean",
                "call_sites": [
                    {
                        "file_path": "string",
                        "line_number": "integer",
                        "code": "exact call line code without line numbers",
                    }
                ],
                "note": "short explanation of what was or was not verified",
            },
        }
        messages = [
            {"role": "system", "content": self._caller_planner_system_prompt()},
            {
                "role": "user",
                "content": json.dumps(
                    {
                        "current_function": {
                            "uid": function.get("uid", ""),
                            "name": function["name"],
                            "file_path": function["file_path"],
                            "line_range": [function["start_line"], function["end_line"]],
                            "source": function["source"],
                        },
                        "call_graph_candidate": caller_item,
                        "project_root": str(self.project_root),
                        "tools": self._tool_specs(),
                        "instructions": [
                            "This step happens after symbol extraction. Focus only on caller call sites now.",
                            "Use the call graph candidate as a starting point, then verify actual call sites in the caller source.",
                            "Prefer search_file on the caller file using the callee function name.",
                            "Use open_line_window around candidate lines to confirm the call occurs inside the caller function.",
                            "If the same caller invokes the callee multiple times, extract all call lines.",
                            "Return actual call line code without line numbers.",
                            "If no verified call site is found, set found_call_sites to false.",
                            "Return exactly one JSON object. The first non-whitespace character must be '{'.",
                            "Do not return a bare array. Do not return markdown fences.",
                            "Return JSON only.",
                        ],
                        "required_schema": required_schema,
                    },
                    ensure_ascii=False,
                    indent=2,
                ),
            },
        ]

        trace = []
        tool_history = []
        llm_calls = 0

        if self.client is None:
            return {
                "caller_uid": caller_uid,
                "caller_name": caller_name,
                "llm_calls": 0,
                "trace": [],
                "tool_history": [],
                "extracted_context": self._default_caller_context(caller_item, note="LLM unavailable; caller call sites were not extracted."),
            }

        extracted_context = self._default_caller_context(caller_item)
        for step in range(1, self.max_steps_per_symbol + 1):
            self._log(f"    [context] caller={caller_uid} llm step {step}")
            request_messages = list(messages)
            response_text = self._chat(request_messages)
            llm_calls += 1
            payload, response_text = self._extract_json_with_repair(
                response_text=response_text,
                request_messages=request_messages,
                required_schema=required_schema,
                stage_label=f"caller extraction for {caller_uid}",
            )
            payload = self._normalize_action_payload(payload)
            trace.append({"step": step, "llm_raw_response": response_text, "parsed": payload})
            messages.append({"role": "assistant", "content": response_text})

            action = payload.get("action")
            if action == "done":
                extracted_context = self._normalize_caller_context(caller_item, payload.get("extracted_context"))
                self._emit_progress("caller_step", {
                    "caller_uid": caller_uid,
                    "step": step,
                    "trace": trace,
                    "tool_history": tool_history,
                    "extracted_context": extracted_context,
                })
                break

            tool_name = payload.get("tool_name")
            arguments = payload.get("arguments", {}) or {}
            self._log(f"    [context] caller={caller_uid} tool={tool_name} args={arguments}")
            tool_output = self._run_tool(tool_name, arguments)
            tool_record = {
                "tool": tool_name,
                "arguments": arguments,
                "output": tool_output,
                "caller_uid": caller_uid,
                "reason": payload.get("reason", ""),
            }
            trace.append({"step": step, "tool_result": tool_record})
            tool_history.append(tool_record)
            messages.append({
                "role": "user",
                "content": json.dumps(
                    {
                        "tool_result": tool_record,
                        "instruction": "Continue extracting verified call sites for the same caller or return action=done.",
                    },
                    ensure_ascii=False,
                    indent=2,
                ),
            })
            self._emit_progress("caller_step", {
                "caller_uid": caller_uid,
                "step": step,
                "trace": trace,
                "tool_history": tool_history,
                "extracted_context": extracted_context,
            })

        return {
            "caller_uid": caller_uid,
            "caller_name": caller_name,
            "llm_calls": llm_calls,
            "trace": trace,
            "tool_history": tool_history,
            "extracted_context": extracted_context,
        }

    def _default_caller_context(self, caller_item: Dict, note: str = "") -> Dict[str, Any]:
        return {
            "caller_uid": caller_item.get("caller_uid", ""),
            "caller_name": caller_item.get("caller_name", ""),
            "callee_name": caller_item.get("callee_name", ""),
            "caller_file_path": caller_item.get("caller_file_path", ""),
            "found_call_sites": False,
            "call_sites": [],
            "note": note,
        }

    def _normalize_caller_context(self, caller_item: Dict, payload: Any) -> Dict[str, Any]:
        result = self._default_caller_context(caller_item)
        if not isinstance(payload, dict):
            result["note"] = "Invalid caller extracted_context payload."
            return result

        result["caller_uid"] = (payload.get("caller_uid") or result["caller_uid"]).strip()
        result["caller_name"] = (payload.get("caller_name") or result["caller_name"]).strip()
        result["callee_name"] = (payload.get("callee_name") or result["callee_name"]).strip()
        result["caller_file_path"] = (payload.get("caller_file_path") or result["caller_file_path"]).strip()
        result["found_call_sites"] = bool(payload.get("found_call_sites"))
        result["note"] = (payload.get("note") or "").strip()

        call_sites = []
        for item in payload.get("call_sites", []):
            if not isinstance(item, dict):
                continue
            code = (item.get("code") or "").strip()
            file_path = (item.get("file_path") or result["caller_file_path"]).strip()
            line_number = item.get("line_number")
            try:
                line_number = int(line_number) if line_number is not None else None
            except Exception:
                line_number = None
            if not code:
                continue
            call_sites.append(
                {
                    "file_path": file_path,
                    "line_number": line_number,
                    "code": code,
                }
            )
        result["call_sites"] = call_sites
        if call_sites and not result["found_call_sites"]:
            result["found_call_sites"] = True
        if result["found_call_sites"] and not call_sites:
            result["found_call_sites"] = False
            if not result["note"]:
                result["note"] = "Marked found_call_sites=true but no call_sites were returned."
        return result

    def _tool_planner_system_prompt(self) -> str:
        return (
            "You are a Rust symbol-context agent. "
            "Output format requirement comes first: return exactly one JSON object, the first non-whitespace character must be '{', "
            "and the top-level value must not be an array. "
            "You are deciding which repository tool to use next for one symbol. "
            "Prefer search_dir first, then use open_line_window to inspect the likely definition. "
            "Only use tools that are listed. Return valid JSON only."
        )

    def _caller_planner_system_prompt(self) -> str:
        return (
            "You are a Rust caller-site extraction agent. "
            "Output format requirement comes first: return exactly one JSON object, the first non-whitespace character must be '{', "
            "and the top-level value must not be an array. "
            "Decide which repository tool to use next to verify call sites "
            "for a known caller-callee relationship. Prefer search_file in the caller file, then open_line_window to "
            "confirm exact call lines. Return valid JSON only."
        )

    def _tool_specs(self) -> List[Dict]:
        return [
            {
                "name": "search_dir",
                "signature": "search_dir(query, target_dir)",
                "description": "Search a term in all files under a directory and report matching files and first matching lines. Prefer this first.",
            },
            {
                "name": "search_file",
                "signature": "search_file(query, file_path)",
                "description": "Search a term inside one specific file when the file is already known.",
            },
            {
                "name": "find_file",
                "signature": "find_file(file_name_pattern, target_dir)",
                "description": "Find files by file name or glob pattern.",
            },
            {
                "name": "open_line_window",
                "signature": "open_line_window(file_path, line_number)",
                "description": "Open from the given line and include the next 50 lines with line numbers.",
            },
        ]

    def _run_tool(self, tool_name: str, arguments: Dict) -> str:
        if tool_name == "search_dir":
            query = arguments.get("query")
            target = arguments.get("target") or str(self.project_root)
            return self._run_search_dir(query, target)
        if tool_name == "search_file":
            query = arguments.get("query")
            file_path = arguments.get("file_path") or arguments.get("target")
            return self._run_search_file(query, file_path)
        if tool_name == "find_file":
            query = arguments.get("query")
            target = arguments.get("target") or str(self.project_root)
            return self._run_find_file(query, target)
        if tool_name == "open_line_window":
            file_path = arguments.get("file_path") or arguments.get("target")
            line_number = arguments.get("line_number")
            return self._open_line_window(file_path, line_number)
        return f"unsupported tool: {tool_name}"

    def _run_search_dir(self, query: Optional[str], target: Optional[str]) -> str:
        return self._run_shell_tool("search_dir", query, target)

    def _run_search_file(self, query: Optional[str], file_path: Optional[str]) -> str:
        return self._run_shell_tool("search_file", query, file_path)

    def _run_find_file(self, query: Optional[str], target: Optional[str]) -> str:
        return self._run_shell_tool("find_file", query, target)

    def _run_shell_tool(self, tool_name: str, query: Optional[str], target: Optional[str]) -> str:
        if not query:
            return "missing query"
        script_path = self.search_bin_dir / tool_name
        if not script_path.exists():
            return f"tool missing: {script_path}"

        target_path = Path(target).expanduser() if target else None
        if target_path and not target_path.exists():
            target_path = self.project_root

        cmd = ["bash", str(script_path), query]
        if target_path:
            cmd.append(str(target_path))
        try:
            completed = subprocess.run(
                cmd,
                check=False,
                capture_output=True,
                text=True,
                cwd=self.project_root,
            )
        except Exception as exc:
            return f"tool execution failed: {exc}"
        output = (completed.stdout or "") + (completed.stderr or "")
        return output.strip()

    def _open_line_window(self, file_path: Optional[str], line_number) -> str:
        if not file_path:
            return "missing file_path"
        try:
            path = Path(file_path).expanduser()
            if not path.exists() or not path.is_file():
                return f"invalid file_path: {file_path}"
            line_no = int(line_number)
        except Exception as exc:
            return f"invalid arguments: {exc}"

        lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
        start = max(1, line_no)
        end = min(len(lines), line_no + 49)
        rendered = [f"{idx}: {lines[idx - 1]}" for idx in range(start, end + 1)]
        return f"Opened {path} lines {start}-{end}:\n" + "\n".join(rendered)

    def _chat(self, messages: Sequence[Dict]) -> str:
        assert self.client is not None
        request_messages = list(messages)
        max_attempts = 3
        last_error: Optional[Exception] = None
        for attempt in range(1, max_attempts + 1):
            try:
                completion = self.client.chat.completions.create(
                    model=self.model,
                    stream=False,
                    messages=request_messages,
                )
                content = completion.choices[0].message.content
                if isinstance(content, list):
                    text = "\n".join(
                        item.get("text", "")
                        for item in content
                        if isinstance(item, dict)
                    ).strip()
                else:
                    text = (content or "").strip()
                if text:
                    return text
                raise ValueError("empty response content from LLM")
            except Exception as exc:
                last_error = exc
                self._log(
                    f"  [context] LLM request attempt {attempt}/{max_attempts} failed "
                    f"(model={self.model}, error={type(exc).__name__}: {exc})"
                )
                if attempt < max_attempts:
                    time.sleep(attempt)
        prompt_preview = ""
        if request_messages:
            content = request_messages[-1].get("content", "")
            if isinstance(content, str):
                prompt_preview = content.strip().replace("\n", "\\n")[:300]
        self._log(
            f"  [context] LLM request exhausted retries "
            f"(model={self.model}, prompt_preview={prompt_preview})"
        )
        raise RuntimeError(
            f"LLM request failed after {max_attempts} attempts for model {self.model}: "
            f"{type(last_error).__name__}: {last_error}"
        ) from last_error

    def _extract_json_with_repair(
        self,
        response_text: str,
        request_messages: Sequence[Dict],
        required_schema: Dict,
        stage_label: str,
    ) -> tuple[Any, str]:
        try:
            return self._extract_json(response_text), response_text
        except ValueError as exc:
            self._log(
                f"  [context] {stage_label} returned non-JSON content; requesting one-shot JSON-only repair "
                f"({type(exc).__name__}: {exc})"
            )
            repair_messages = list(request_messages) + [
                {"role": "assistant", "content": response_text},
                {
                    "role": "user",
                    "content": (
                        "Your previous reply was not valid JSON for the required output contract. "
                        "Return JSON only with no markdown, no code fences, and no extra explanation. "
                        "The first non-whitespace character must be '{'. "
                        "Follow this schema exactly:\n"
                        f"{json.dumps(required_schema, ensure_ascii=False, indent=2)}"
                    ),
                },
            ]
            repaired_text = self._chat(repair_messages)
            return self._extract_json(repaired_text), repaired_text

    def _normalize_symbol_selection_payload(self, payload: Any) -> Dict[str, List[Dict[str, Any]]]:
        if isinstance(payload, dict):
            symbols = payload.get("symbols")
            if isinstance(symbols, list):
                return {"symbols": [item for item in symbols if isinstance(item, dict)]}
            if "symbol" in payload:
                return {"symbols": [payload]}
            return {"symbols": []}
        if isinstance(payload, list):
            return {"symbols": [item for item in payload if isinstance(item, dict)]}
        return {"symbols": []}

    def _normalize_action_payload(self, payload: Any) -> Dict[str, Any]:
        if isinstance(payload, dict):
            return payload
        if isinstance(payload, list) and len(payload) == 1 and isinstance(payload[0], dict):
            return payload[0]
        return {}

    def _extract_json(self, text: str) -> Any:
        stripped = text.strip()
        decoder = json.JSONDecoder()

        try:
            parsed = json.loads(stripped)
            if isinstance(parsed, (dict, list)):
                return parsed
        except Exception:
            pass

        fenced_candidates = []
        marker = "```json"
        if marker in stripped:
            parts = stripped.split(marker)
            for part in parts[1:]:
                fenced_body = part.split("```", 1)[0].strip()
                if fenced_body:
                    fenced_candidates.append(fenced_body)

        candidates = fenced_candidates + [stripped[idx:] for idx, ch in enumerate(stripped) if ch == "{"]
        if "[" in stripped:
            candidates.extend(stripped[idx:] for idx, ch in enumerate(stripped) if ch == "[")
        for candidate in candidates:
            try:
                parsed, _ = decoder.raw_decode(candidate)
                if isinstance(parsed, (dict, list)):
                    return parsed
            except Exception:
                continue

        raise ValueError("no JSON object found in LLM response")
