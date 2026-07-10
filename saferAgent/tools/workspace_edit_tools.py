from __future__ import annotations

import subprocess
from pathlib import Path
from typing import Callable, Dict, List, Optional, Sequence


class WorkspaceEditTools:
    MAX_FULL_READ_LINES = 400
    MAX_FULL_READ_CHARS = 20000

    def __init__(
        self,
        project_root: Path,
        workspace_root: Path,
        search_bin_dir: Path,
        parser,
        extract_function_name: Callable,
        log: Callable[[str], None],
    ) -> None:
        self.project_root = project_root
        self.workspace_root = workspace_root
        self.search_bin_dir = search_bin_dir
        self.parser = parser
        self.extract_function_name = extract_function_name
        self.log = log

    def _map_to_workspace(self, path: Path) -> Optional[Path]:
        path = path.expanduser()
        if path.is_absolute():
            try:
                path.relative_to(self.workspace_root)
                return path
            except ValueError:
                pass
            try:
                rel = path.relative_to(self.project_root)
                return self.workspace_root / rel
            except ValueError:
                return None
        return self.workspace_root / path

    def specs(self) -> List[Dict]:
        return [
            {
                "name": "search_dir",
                "signature": "search_dir(query, target)",
                "description": "Search a term in files under a directory. Prefer this when you do not yet know the exact file.",
            },
            {
                "name": "search_file",
                "signature": "search_file(query, file_path)",
                "description": "Search a term inside one file when the candidate file is already known.",
            },
            {
                "name": "find_file",
                "signature": "find_file(query, target)",
                "description": "Find files by name pattern under a directory.",
            },
            {
                "name": "open_line_window",
                "signature": "open_line_window(file_path, line_number)",
                "description": "Open 50 lines starting from the provided line number.",
            },
            {
                "name": "read_file",
                "signature": "read_file(file_path)",
                "description": (
                    "Read the full file content only for small files. "
                    "Do not use this for large generated files; prefer search_file/search_dir plus open_line_window."
                ),
            },
            {
                "name": "replace_function",
                "signature": "replace_function(file_path, function_name, approx_start_line, new_text)",
                "description": "Replace a Rust function item using tree-sitter, matching by function name and nearest start line.",
            },
            {
                "name": "replace_line_range",
                "signature": "replace_line_range(file_path, start_line, end_line, new_text)",
                "description": "Replace a specific inclusive line range with new text.",
            },
            {
                "name": "insert_use_statements",
                "signature": "insert_use_statements(file_path, use_statements)",
                "description": "Insert missing Rust use statements near the top of a file.",
            },
            {
                "name": "remove_use_statements",
                "signature": "remove_use_statements(file_path, use_statements)",
                "description": "Remove exact Rust use statements from a file when they are no longer needed.",
            },
            {
                "name": "write_file",
                "signature": "write_file(file_path, content)",
                "description": "Overwrite an entire file when a full-file replacement is the safest choice.",
            },
            {
                "name": "create_file",
                "signature": "create_file(file_path, content)",
                "description": "Create a new file. Fails if the file already exists.",
            },
            {
                "name": "delete_file",
                "signature": "delete_file(file_path)",
                "description": "Delete a file under the writable workspace root.",
            },
        ]

    def run(self, tool_name: str, arguments: Dict) -> str:
        if tool_name == "search_dir":
            return self._run_shell_tool("search_dir", arguments.get("query"), arguments.get("target"))
        if tool_name == "search_file":
            return self._run_shell_tool("search_file", arguments.get("query"), arguments.get("file_path") or arguments.get("target"))
        if tool_name == "find_file":
            return self._run_shell_tool("find_file", arguments.get("query"), arguments.get("target"))
        if tool_name == "open_line_window":
            return self._open_line_window(arguments.get("file_path"), arguments.get("line_number"))
        if tool_name == "read_file":
            return self._read_file(arguments.get("file_path"))
        if tool_name == "replace_function":
            return self._replace_function(
                arguments.get("file_path"),
                arguments.get("function_name"),
                arguments.get("approx_start_line"),
                arguments.get("new_text"),
            )
        if tool_name == "replace_line_range":
            return self._replace_line_range(
                arguments.get("file_path"),
                arguments.get("start_line"),
                arguments.get("end_line"),
                arguments.get("new_text"),
            )
        if tool_name == "insert_use_statements":
            return self._insert_use_statements(arguments.get("file_path"), arguments.get("use_statements"))
        if tool_name == "remove_use_statements":
            return self._remove_use_statements(arguments.get("file_path"), arguments.get("use_statements"))
        if tool_name == "write_file":
            return self._write_file(arguments.get("file_path"), arguments.get("content"))
        if tool_name == "create_file":
            return self._create_file(arguments.get("file_path"), arguments.get("content"))
        if tool_name == "delete_file":
            return self._delete_file(arguments.get("file_path"))
        return f"unsupported tool: {tool_name}"

    def _resolve_path(self, file_path: Optional[str]) -> Optional[Path]:
        if not file_path:
            return None
        return self._map_to_workspace(Path(file_path))

    def _run_shell_tool(self, tool_name: str, query: Optional[str], target: Optional[str]) -> str:
        if not query:
            return "missing query"
        script_path = self.search_bin_dir / tool_name
        if not script_path.exists():
            return f"tool missing: {script_path}"

        target_path = self._resolve_path(target) if target else self.workspace_root
        if target and target_path is None:
            return f"target outside workspace: {target}"
        if target_path and not target_path.exists():
            target_path = self.workspace_root

        cmd = ["bash", str(script_path), query]
        if target_path:
            cmd.append(str(target_path))
        try:
            completed = subprocess.run(
                cmd,
                check=False,
                capture_output=True,
                text=True,
                cwd=self.workspace_root,
            )
        except Exception as exc:
            return f"tool execution failed: {exc}"
        output = (completed.stdout or "") + (completed.stderr or "")
        return output.strip()

    def _open_line_window(self, file_path: Optional[str], line_number) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists() or not path.is_file():
            return f"invalid file_path: {path}"
        try:
            line_no = int(line_number)
        except Exception as exc:
            return f"invalid line_number: {exc}"

        lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
        start = max(1, line_no)
        end = min(len(lines), line_no + 49)
        rendered = [f"{idx}: {lines[idx - 1]}" for idx in range(start, end + 1)]
        return f"Opened {path} lines {start}-{end}:\n" + "\n".join(rendered)

    def _read_file(self, file_path: Optional[str]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists() or not path.is_file():
            return f"invalid file_path: {path}"
        text = path.read_text(encoding="utf-8", errors="ignore")
        line_count = text.count("\n") + (0 if not text or text.endswith("\n") else 1)
        char_count = len(text)
        if line_count > self.MAX_FULL_READ_LINES or char_count > self.MAX_FULL_READ_CHARS:
            return (
                f"read_file refused: {path} is too large for full-file context "
                f"({line_count} lines, {char_count} chars). "
                "Use search_file/search_dir to locate the symbol, then use open_line_window for the relevant lines."
            )
        return text

    def _replace_function(
        self,
        file_path: Optional[str],
        function_name: Optional[str],
        approx_start_line,
        new_text: Optional[str],
    ) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists() or not path.is_file():
            return f"invalid file_path: {path}"
        if not function_name:
            return "missing function_name"
        if not new_text:
            return "missing new_text"
        if self.parser is None:
            return "tree-sitter parser unavailable"

        source_bytes = path.read_bytes()
        tree = self.parser.parse(source_bytes)
        candidates = []

        def visit(node) -> None:
            if node.type == "function_item":
                candidate_name = self.extract_function_name(node, source_bytes)
                if candidate_name == function_name:
                    candidates.append(node)
                return
            for child in node.children:
                visit(child)

        visit(tree.root_node)
        if not candidates:
            return f"function not found: {function_name} in {path}"

        try:
            target_line = int(approx_start_line) if approx_start_line is not None else None
        except Exception:
            target_line = None

        if target_line is None:
            chosen = candidates[0]
        else:
            chosen = min(candidates, key=lambda node: abs((node.start_point[0] + 1) - target_line))

        updated = (
            source_bytes[:chosen.start_byte]
            + new_text.encode("utf-8")
            + source_bytes[chosen.end_byte:]
        )
        path.write_bytes(updated)
        return (
            f"replace_function applied: {path} "
            f"{function_name} lines {chosen.start_point[0] + 1}-{chosen.end_point[0] + 1}"
        )

    def _replace_line_range(self, file_path: Optional[str], start_line, end_line, new_text: Optional[str]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists() or not path.is_file():
            return f"invalid file_path: {path}"
        if new_text is None:
            return "missing new_text"
        try:
            start = int(start_line)
            end = int(end_line)
        except Exception as exc:
            return f"invalid line range: {exc}"
        if start <= 0 or end < start:
            return f"invalid line range: {start_line}-{end_line}"

        lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
        if end > len(lines):
            return f"line range out of bounds: {path}:{start}-{end}"

        replacement_lines = new_text.splitlines()
        lines[start - 1:end] = replacement_lines
        path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        return f"replace_line_range applied: {path}:{start}-{end}"

    def _insert_use_statements(self, file_path: Optional[str], use_statements: Optional[Sequence[str]]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists() or not path.is_file():
            return f"invalid file_path: {path}"
        if not use_statements:
            return "no use statements provided"

        if isinstance(use_statements, str):
            use_items: List[str] = [use_statements]
        else:
            use_items = list(use_statements)

        text = path.read_text(encoding="utf-8", errors="ignore")
        lines = text.splitlines()
        normalized: List[str] = []
        for item in use_items:
            candidate = (item or "").strip()
            if not candidate:
                continue
            if not candidate.startswith("use "):
                candidate = f"use {candidate.rstrip(';')};"
            elif not candidate.endswith(";"):
                candidate = candidate + ";"
            if candidate not in normalized:
                normalized.append(candidate)

        missing = [item for item in normalized if item not in text]
        if not missing:
            return f"insert_use_statements noop: {path}"

        insert_at = 0
        while insert_at < len(lines) and (
            not lines[insert_at].strip()
            or lines[insert_at].startswith("#![")
            or lines[insert_at].startswith("//")
        ):
            insert_at += 1
        while insert_at < len(lines) and lines[insert_at].startswith("use "):
            insert_at += 1

        for offset, statement in enumerate(missing):
            lines.insert(insert_at + offset, statement)
        path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        return f"insert_use_statements applied: {path} added={len(missing)}"

    def _write_file(self, file_path: Optional[str], content: Optional[str]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if content is None:
            return "missing content"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding="utf-8")
        return f"write_file applied: {path}"

    def _remove_use_statements(self, file_path: Optional[str], use_statements: Optional[Sequence[str]]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists() or not path.is_file():
            return f"invalid file_path: {path}"
        if not use_statements:
            return "no use statements provided"

        if isinstance(use_statements, str):
            use_items: List[str] = [use_statements]
        else:
            use_items = list(use_statements)

        targets = set()
        for item in use_items:
            candidate = (item or "").strip()
            if not candidate:
                continue
            if not candidate.startswith("use "):
                candidate = f"use {candidate.rstrip(';')};"
            elif not candidate.endswith(";"):
                candidate = candidate + ";"
            targets.add(candidate)
        if not targets:
            return "no valid use statements provided"

        lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
        kept_lines = [line for line in lines if line.strip() not in targets]
        removed = len(lines) - len(kept_lines)
        if removed == 0:
            return f"remove_use_statements noop: {path}"
        path.write_text("\n".join(kept_lines) + "\n", encoding="utf-8")
        return f"remove_use_statements applied: {path} removed={removed}"

    def _create_file(self, file_path: Optional[str], content: Optional[str]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if content is None:
            return "missing content"
        if path.exists():
            return f"create_file refused: already exists: {path}"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding="utf-8")
        return f"create_file applied: {path}"

    def _delete_file(self, file_path: Optional[str]) -> str:
        path = self._resolve_path(file_path)
        if path is None:
            return "missing file_path"
        if not path.exists():
            return f"delete_file noop: missing: {path}"
        if not path.is_file():
            return f"delete_file refused: not a file: {path}"
        path.unlink()
        return f"delete_file applied: {path}"
