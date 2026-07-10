#!/usr/bin/env python3
from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Callable, Dict, List, Optional, Sequence

from ..tools.workspace_edit_tools import WorkspaceEditTools


class WorkspaceEditAgent:
    MAX_TOOL_RESULT_CHARS_FOR_CONTEXT = 6000

    def __init__(
        self,
        *,
        project_root: Path,
        workspace_root: Path,
        search_bin_dir: Path,
        parser,
        extract_function_name: Callable,
        chat_messages: Callable[[Sequence[Dict[str, str]], str, Optional[str]], str],
        parse_json_response_with_repair: Callable[[str, Sequence[Dict[str, str]], str, Optional[str]], tuple[Optional[Dict[str, Any]], str]],
        log: Callable[[str], None],
        prompt_template: str,
        model: str,
    ) -> None:
        self.project_root = project_root
        self.workspace_root = workspace_root
        self.search_bin_dir = search_bin_dir
        self.parser = parser
        self.extract_function_name = extract_function_name
        self.chat_messages = chat_messages
        self.parse_json_response_with_repair = parse_json_response_with_repair
        self.log = log
        self.prompt_template = prompt_template
        self.model = model

    def run(
        self,
        *,
        function: Any,
        function_dir: Path,
        edit_memory: Dict[str, Any],
        rewritten_function: str,
        add_use_statements: Sequence[str],
        remove_use_statements: Sequence[str],
        caller_fixes: Sequence[Dict[str, Any]],
        mode_label: str,
        auto_apply_caller_fixes: bool = True,
    ) -> Dict[str, Any]:
        target_path = self.workspace_root / Path(str(function.file_path)).relative_to(self.project_root)
        result = {
            "mode": "llm_workspace_edit_loop",
            "mode_label": mode_label,
            "model": self.model,
            "workspace_root": str(self.workspace_root),
            "workspace_file_path": str(target_path),
            "function_uid": function.uid,
            "use_statements_added": [],
            "use_statements_removed": [],
            "caller_fixes_applied": [],
            "function_replaced": False,
            "applied_edits": [],
            "skipped": [],
            "memory": edit_memory,
            "trace": {
                "messages": [],
                "steps": [],
                "summary": "",
                "completed": False,
            },
        }
        if not target_path.exists():
            result["skipped"].append(f"workspace file missing: {target_path}")
            return result
        if not rewritten_function:
            result["skipped"].append("missing rewritten function candidate")
            return result

        tools = WorkspaceEditTools(
            project_root=self.project_root,
            workspace_root=self.workspace_root,
            search_bin_dir=self.search_bin_dir,
            parser=self.parser,
            extract_function_name=self.extract_function_name,
            log=self.log,
        )
        prompt = self.prompt_template.format(
            workspace_root=str(self.workspace_root),
            function_uid=function.uid,
            function_name=function.name,
            source_file_path=str(function.file_path),
            source_start_line=function.start_line,
            source_end_line=function.end_line,
            edit_mode=mode_label,
            edit_memory=json.dumps(edit_memory, ensure_ascii=False, indent=2),
            rewritten_function=rewritten_function,
            add_use_statements=json.dumps(list(add_use_statements), ensure_ascii=False, indent=2),
            remove_use_statements=json.dumps(list(remove_use_statements), ensure_ascii=False, indent=2),
            caller_fixes=json.dumps(list(caller_fixes), ensure_ascii=False, indent=2),
            tool_specs=json.dumps(tools.specs(), ensure_ascii=False, indent=2),
            caller_fix_rule=(
                "Do not use `replace_line_range` to apply the suggested caller fixes from memory; "
                "those caller fixes are applied automatically after the workspace-edit loop."
                if auto_apply_caller_fixes
                else "You may update caller sites directly when verified."
            ),
        )

        messages: List[Dict[str, str]] = [
            {
                "role": "system",
                "content": "You are a careful Rust workspace editing agent. Use tools deliberately, mutate only verified files, and return valid JSON only.",
            },
            {"role": "user", "content": prompt},
        ]
        result["trace"]["messages"] = list(messages)
        max_steps = 12

        for step in range(1, max_steps + 1):
            self.log(f"  [workspace-edit] {mode_label} llm step {step} model={self.model}")
            request_messages = list(messages)
            response_text = self.chat_messages(request_messages, "[workspace-edit]", self.model)
            messages.append({"role": "assistant", "content": response_text})
            parsed, response_text = self.parse_json_response_with_repair(
                response_text,
                request_messages,
                f"{mode_label} workspace edit planning",
                self.model,
            )
            messages[-1] = {"role": "assistant", "content": response_text}
            result["trace"]["steps"].append(
                {
                    "step": step,
                    "assistant_response": response_text,
                    "parsed": parsed,
                }
            )

            if not isinstance(parsed, dict):
                feedback = "Invalid JSON response. Return exactly one JSON object with action=tool or action=done."
                messages.append({"role": "user", "content": feedback})
                result["trace"]["steps"][-1]["tool_result"] = feedback
                continue

            action = (parsed.get("action") or "").strip()
            if action == "done":
                result["trace"]["summary"] = (parsed.get("summary") or "").strip()
                result["trace"]["completed"] = True
                break
            if action != "tool":
                feedback = "Unsupported action. Return action=tool or action=done."
                messages.append({"role": "user", "content": feedback})
                result["trace"]["steps"][-1]["tool_result"] = feedback
                continue

            tool_name = (parsed.get("tool_name") or "").strip()
            arguments = parsed.get("arguments") or {}
            if auto_apply_caller_fixes and tool_name == "replace_line_range" and self._is_caller_fix_replace(arguments, caller_fixes):
                feedback = (
                    "Do not apply suggested caller fixes with replace_line_range inside the workspace-edit loop. "
                    "Inspect caller files if needed, but caller fixes from memory will be auto-applied after the loop."
                )
                messages.append({"role": "user", "content": feedback})
                result["trace"]["steps"][-1]["tool_name"] = tool_name
                result["trace"]["steps"][-1]["arguments"] = arguments
                result["trace"]["steps"][-1]["tool_result"] = feedback
                continue

            self.log(f"  [workspace-edit] tool={tool_name} args={arguments}")
            tool_result = tools.run(tool_name, arguments)
            result["trace"]["steps"][-1]["tool_name"] = tool_name
            result["trace"]["steps"][-1]["arguments"] = arguments
            result["trace"]["steps"][-1]["tool_result"] = tool_result

            if tool_name == "replace_function" and "applied" in tool_result:
                result["function_replaced"] = True
            if tool_name == "insert_use_statements" and "applied" in tool_result:
                result["use_statements_added"] = list(add_use_statements)
            if tool_name == "remove_use_statements" and "applied" in tool_result:
                result["use_statements_removed"] = list(remove_use_statements)
            if tool_name in {
                "replace_function",
                "replace_line_range",
                "insert_use_statements",
                "remove_use_statements",
                "write_file",
                "create_file",
                "delete_file",
            } and "applied" in tool_result:
                result["applied_edits"].append(
                    {
                        "edit_type": tool_name,
                        "arguments": arguments,
                        "tool_result": tool_result,
                    }
                )

            messages.append(
                {
                    "role": "user",
                    "content": (
                        f"Tool result for {tool_name}:\n{self._tool_result_for_context(tool_name, tool_result)}\n\n"
                        "Continue with the next verified tool action, or return action=done if the workspace edits are complete."
                    ),
                }
            )

        if not result["trace"]["completed"]:
            result["skipped"].append("workspace edit loop exhausted without explicit completion")

        result["trace"]["messages"] = messages
        return result

    def _tool_result_for_context(self, tool_name: str, tool_result: str) -> str:
        if not isinstance(tool_result, str):
            return str(tool_result)
        if len(tool_result) <= self.MAX_TOOL_RESULT_CHARS_FOR_CONTEXT:
            return tool_result

        kept = self.MAX_TOOL_RESULT_CHARS_FOR_CONTEXT
        head = tool_result[: kept // 2]
        tail = tool_result[-(kept // 2) :]
        return (
            f"{head}\n\n"
            f"... [tool result truncated for context: original_length={len(tool_result)} "
            f"tool={tool_name}] ...\n\n"
            f"{tail}"
        )

    def _is_caller_fix_replace(self, arguments: Dict[str, Any], caller_fixes: Sequence[Dict[str, Any]]) -> bool:
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
