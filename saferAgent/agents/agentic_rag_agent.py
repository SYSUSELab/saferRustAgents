#!/usr/bin/env python3
from __future__ import annotations

import json
import math
import re
import time
from pathlib import Path
from typing import Any, Callable, Dict, List, Optional, Sequence

TOKEN_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_:+.-]*")


class AgenticRAGAgent:
    def __init__(
        self,
        knowledge_base_path: Path,
        model: str,
        client=None,
        bm25_top_n: int = 12,
        max_candidate_apis: int = 5,
        max_queries_per_api: int = 3,
        max_selected_apis: int = 5,
        logger: Optional[Callable[[str], None]] = None,
        progress_callback: Optional[Callable[[str, Dict[str, Any]], None]] = None,
    ) -> None:
        self.knowledge_base_path = knowledge_base_path
        self.model = model
        self.client = client
        self.bm25_top_n = bm25_top_n
        self.max_candidate_apis = max_candidate_apis
        self.max_queries_per_api = max_queries_per_api
        self.max_selected_apis = max_selected_apis
        self.logger = logger
        self.progress_callback = progress_callback
        self.entries = self._load_entries()
        self._build_bm25_index()

    def _log(self, message: str) -> None:
        if self.logger is not None:
            self.logger(message)

    def _emit_progress(self, stage: str, payload: Dict[str, Any]) -> None:
        if self.progress_callback is not None:
            self.progress_callback(stage, payload)

    def run(self, function: Dict, search_results: Sequence[Dict]) -> Dict:
        self._log(f"  [rag] start function {function['name']}")
        try:
            initial = self._identify_candidate_apis(function, search_results)
        except Exception as exc:
            self._log(f"  [rag] candidate API judgement failed, degrading to empty result: {type(exc).__name__}: {exc}")
            initial = {
                "used_llm": False,
                "raw_response": None,
                "api_candidates": [],
                "messages": [],
                "reason": f"candidate API judgement failed: {exc}",
            }
        llm_calls = 1 if initial.get("used_llm") else 0

        query_runs: List[Dict] = []
        result = {
            "model": self.model,
            "knowledge_base_path": str(self.knowledge_base_path),
            "initial_api_judgement": {k: v for k, v in initial.items() if k != "messages"},
            "query_runs": query_runs,
            "aggregated_matches": [],
            "selected_api_entries": [],
            "selection": {},
            "llm_calls": llm_calls,
        }
        candidates = [item.get("unsafe_api", "") for item in result["initial_api_judgement"].get("api_candidates", []) if item.get("unsafe_api")]
        if candidates:
            self._log(f"  [rag] candidate apis: {', '.join(candidates)}")
        else:
            self._log("  [rag] candidate apis: none")
        self._emit_progress("initial_api_judgement", result)

        if initial.get("api_candidates"):
            for api_item in initial["api_candidates"][: self.max_candidate_apis]:
                unsafe_api = api_item.get("unsafe_api", "")
                for query in api_item.get("query_descriptions", [])[: self.max_queries_per_api]:
                    self._log(f"  [rag] bm25 query for {unsafe_api}: {query}")
                    matches = self._bm25_search(query, self.bm25_top_n)
                    query_runs.append(
                        {
                            "unsafe_api": unsafe_api,
                            "reason": api_item.get("reason", ""),
                            "query": query,
                            "matches": matches,
                        }
                    )
                    self._log(f"  [rag] bm25 hits: {len(matches)}")
                    self._emit_progress("query_run", result)

        aggregated_matches = self._aggregate_matches(query_runs)
        result["aggregated_matches"] = aggregated_matches
        self._log(f"  [rag] aggregated matches: {len(aggregated_matches)}")
        self._emit_progress("aggregated_matches", result)

        try:
            selection = self._select_top_matches(function, initial, aggregated_matches)
        except Exception as exc:
            self._log(f"  [rag] top API selection failed, degrading to empty selection: {type(exc).__name__}: {exc}")
            selection = {
                "used_llm": False,
                "raw_response": None,
                "selected_api_entries": [],
                "reason": f"top API selection failed: {exc}",
            }
        if selection.get("used_llm"):
            llm_calls += 1
        result["selected_api_entries"] = selection.get("selected_api_entries", [])
        result["selection"] = {k: v for k, v in selection.items() if k != "messages"}
        result["llm_calls"] = llm_calls
        selected_names = [item.get("api_name", "") for item in result["selected_api_entries"] if item.get("api_name")]
        if selected_names:
            self._log(f"  [rag] selected apis: {', '.join(selected_names)}")
        else:
            self._log("  [rag] selected apis: none")
        self._emit_progress("completed", result)
        return result

    def _load_entries(self) -> List[Dict]:
        raw_entries = json.loads(self.knowledge_base_path.read_text(encoding="utf-8"))
        if not isinstance(raw_entries, list):
            raise ValueError(f"knowledge base must be a list: {self.knowledge_base_path}")
        entries: List[Dict] = []
        for index, item in enumerate(raw_entries):
            if not isinstance(item, dict):
                continue
            entries.append(
                {
                    "kb_id": index,
                    "api_name": item.get("api_name", ""),
                    "function_summary": item.get("function_summary", ""),
                    "example_code": item.get("example_code", []),
                    "cargo_dependency": item.get("cargo_dependency") or {},
                    "source_repository": item.get("source_repository") or {},
                }
            )
        return entries

    def _build_bm25_index(self) -> None:
        self.doc_tokens: List[List[str]] = []
        self.doc_freq: Dict[str, int] = {}
        self.avg_doc_len = 0.0
        total_len = 0

        for entry in self.entries:
            tokens = self._tokenize(entry.get("function_summary", ""))
            self.doc_tokens.append(tokens)
            total_len += len(tokens)
            for token in set(tokens):
                self.doc_freq[token] = self.doc_freq.get(token, 0) + 1

        if self.entries:
            self.avg_doc_len = total_len / len(self.entries)
        self._build_example_code_bm25_index()

    def _build_example_code_bm25_index(self) -> None:
        self.example_doc_tokens: List[List[str]] = []
        self.example_doc_freq: Dict[str, int] = {}
        self.example_avg_doc_len = 0.0
        total_len = 0

        for entry in self.entries:
            snippets = entry.get("example_code") or []
            text = "\n\n".join(snippet for snippet in snippets if isinstance(snippet, str))
            tokens = self._tokenize(text)
            self.example_doc_tokens.append(tokens)
            total_len += len(tokens)
            for token in set(tokens):
                self.example_doc_freq[token] = self.example_doc_freq.get(token, 0) + 1

        if self.entries:
            self.example_avg_doc_len = total_len / len(self.entries)

    def _tokenize(self, text: str) -> List[str]:
        return [token.lower() for token in TOKEN_RE.findall(text)]

    def _identify_candidate_apis(self, function: Dict, search_results: Sequence[Dict]) -> Dict:
        system_prompt = (
            "You are an OpenHarmony Rust API migration planner. "
            "Output format requirement comes first: return valid JSON only, and prefer the top-level shape "
            "{\"api_candidates\": [{\"unsafe_api\": \"string\", \"reason\": \"string\", \"query_descriptions\": [\"string\"]}]}. "
            "If there are no good candidates, return {\"api_candidates\": []}. "
            "Even if there is only one candidate, still return it inside the api_candidates array. "
            "The top-level JSON value must be an object/dict, never a bare array/list. "
            "Do not return a bare array. Do not return a bare object with a different schema. Do not use markdown fences. "
            "Given a translated Rust function that still uses unsafe operations and possibly C-style APIs, "
            "identify only the called APIs inside or directly causing unsafe logic that might have OpenHarmony Rust replacements or close Rust-library substitutes. "
            "Be selective: it is normal that no reusable Rust API is a good fit for the current function. "
            "Focus on APIs whose functionality might be replaced by a Rust/OpenHarmony API, not just low-level helper calls. "
            "For example, if a function uses C-style JSON access such as cJSON object lookups, a Rust JSON value API may be a better migration candidate than only picking strlen/malloc/strcpy-style helpers. "
            "This is only an example of the kind of functional replacement to consider, not a mandatory choice. "
            "Do not force a JSON-library candidate unless the function's semantics actually suggest one. "
            "For each chosen API, generate short functional BM25 queries that describe what the API does, not just the API name. "
            "Return valid JSON only."
        )
        user_payload = {
            "function_name": function["name"],
            "file_path": function["file_path"],
            "line_range": [function["start_line"], function["end_line"]],
            "function_source": function["source"],
            "context_search_results": list(search_results),
            "required_schema": {
                "api_candidates": [
                    {
                        "unsafe_api": "string",
                        "reason": "why this API might have a Rust replacement",
                        "query_descriptions": ["short functionality search query"],
                    }
                ]
            },
        }
        user_prompt = json.dumps(user_payload, ensure_ascii=False, indent=2)

        if self.client is None:
            self._log("  [rag] LLM unavailable during candidate API judgement")
            return {
                "used_llm": False,
                "raw_response": None,
                "api_candidates": [],
                "messages": [],
                "reason": "LLM unavailable; AgenticRAG candidate API judgement skipped",
            }

        self._log("  [rag] judging replacement API candidates...")
        self._log("  [rag] selecting top OpenHarmony API entries...")
        request_messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_prompt},
        ]
        response_text = self._chat(request_messages)
        payload, response_text = self._extract_json_with_repair(
            response_text=response_text,
            request_messages=request_messages,
            required_schema=user_payload["required_schema"],
            stage_label="candidate API judgement",
        )
        payload = self._normalize_candidate_payload(payload)
        candidates = []
        seen = set()
        for item in payload.get("api_candidates", []):
            unsafe_api = (item.get("unsafe_api") or "").strip()
            if not unsafe_api or unsafe_api in seen:
                continue
            seen.add(unsafe_api)
            queries: List[str] = []
            for query in item.get("query_descriptions", []):
                query = (query or "").strip()
                if query and query not in queries:
                    queries.append(query)
            if not queries:
                continue
            candidates.append(
                {
                    "unsafe_api": unsafe_api,
                    "reason": item.get("reason", ""),
                    "query_descriptions": queries,
                }
            )
        return {
            "used_llm": True,
            "raw_response": response_text,
            "api_candidates": candidates[: self.max_candidate_apis],
            "messages": [
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": user_prompt},
                {"role": "assistant", "content": response_text},
            ],
        }

    def _bm25_search(self, query: str, top_n: int) -> List[Dict]:
        query_tokens = self._tokenize(query)
        if not query_tokens or not self.entries:
            return []

        n_docs = len(self.entries)
        k1 = 1.5
        b = 0.75
        scores: List[tuple[float, int]] = []

        for index, tokens in enumerate(self.doc_tokens):
            if not tokens:
                continue
            token_counts: Dict[str, int] = {}
            for token in tokens:
                token_counts[token] = token_counts.get(token, 0) + 1

            score = 0.0
            doc_len = len(tokens)
            for token in query_tokens:
                freq = token_counts.get(token, 0)
                if freq == 0:
                    continue
                df = self.doc_freq.get(token, 0)
                idf = math.log(1 + (n_docs - df + 0.5) / (df + 0.5))
                denom = freq + k1 * (1 - b + b * doc_len / max(self.avg_doc_len, 1.0))
                score += idf * (freq * (k1 + 1)) / denom
            if score > 0:
                scores.append((score, index))

        scores.sort(key=lambda item: item[0], reverse=True)
        results: List[Dict] = []
        for score, index in scores[:top_n]:
            entry = self.entries[index]
            results.append(
                {
                    "kb_id": entry["kb_id"],
                    "api_name": entry["api_name"],
                    "function_summary": entry["function_summary"],
                    "cargo_dependency": entry.get("cargo_dependency") or {},
                    "source_repository": entry.get("source_repository") or {},
                    "example_code": entry.get("example_code") or [],
                    "score": score,
                }
            )
        return results

    def _bm25_search_example_code(self, query: str, top_n: int) -> List[Dict]:
        query_tokens = self._tokenize(query)
        if not query_tokens or not self.entries:
            return []

        n_docs = len(self.entries)
        k1 = 1.5
        b = 0.75
        scores: List[tuple[float, int]] = []

        for index, tokens in enumerate(self.example_doc_tokens):
            if not tokens:
                continue
            token_counts: Dict[str, int] = {}
            for token in tokens:
                token_counts[token] = token_counts.get(token, 0) + 1

            score = 0.0
            doc_len = len(tokens)
            for token in query_tokens:
                freq = token_counts.get(token, 0)
                if freq == 0:
                    continue
                df = self.example_doc_freq.get(token, 0)
                idf = math.log(1 + (n_docs - df + 0.5) / (df + 0.5))
                denom = freq + k1 * (1 - b + b * doc_len / max(self.example_avg_doc_len, 1.0))
                score += idf * (freq * (k1 + 1)) / denom
            if score > 0:
                scores.append((score, index))

        scores.sort(key=lambda item: item[0], reverse=True)
        results: List[Dict] = []
        for score, index in scores[:top_n]:
            entry = self.entries[index]
            results.append(
                {
                    "kb_id": entry["kb_id"],
                    "api_name": entry["api_name"],
                    "function_summary": entry["function_summary"],
                    "cargo_dependency": entry.get("cargo_dependency") or {},
                    "source_repository": entry.get("source_repository") or {},
                    "example_code": entry.get("example_code") or [],
                    "score": score,
                }
            )
        return results

    def search_example_code_entries(self, queries: Sequence[str], top_n: int = 3) -> Dict[str, Any]:
        query_runs: List[Dict[str, Any]] = []
        for query in queries:
            normalized = (query or "").strip()
            if not normalized:
                continue
            matches = self._bm25_search_example_code(normalized, top_n)
            query_runs.append({"query": normalized, "matches": matches})
        aggregated_matches = self._aggregate_matches(query_runs)
        return {
            "queries": [item["query"] for item in query_runs],
            "query_runs": query_runs,
            "aggregated_matches": aggregated_matches[:top_n],
        }

    def select_example_code_entries_for_fix(
        self,
        *,
        function: Dict[str, Any],
        compile_errors: Sequence[str],
        queries: Sequence[str],
        aggregated_matches: Sequence[Dict[str, Any]],
        max_selected: int = 3,
    ) -> Dict[str, Any]:
        if self.client is None:
            return {
                "used_llm": False,
                "raw_response": None,
                "selected_entries": [],
                "reason": "LLM unavailable; fix-stage example-code selection skipped",
            }
        if not aggregated_matches:
            return {
                "used_llm": False,
                "raw_response": None,
                "selected_entries": [],
                "reason": "no example-code BM25 matches; fix-stage selection skipped",
            }

        condensed_matches = []
        for item in aggregated_matches[:max_selected]:
            condensed_matches.append(
                {
                    "kb_id": item["kb_id"],
                    "api_name": item["api_name"],
                    "function_summary": item["function_summary"],
                    "example_code": item.get("example_code") or [],
                    "cargo_dependency": item.get("cargo_dependency") or {},
                    "source_repository": item.get("source_repository") or {},
                    "matched_queries": item.get("matched_queries", []),
                    "score": item["score"],
                }
            )

        system_prompt = (
            "You are selecting OpenHarmony Rust knowledge-base entries to help repair compile errors in a rewritten Rust function. "
            "The candidates were retrieved by BM25 over example_code snippets. "
            "Keep only entries whose example code is concretely useful for fixing the current compile errors or API usage confusion. "
            "It is acceptable to keep none. "
            "Return valid JSON only with top-level key \"selected_entries\"."
        )
        user_payload = {
            "function_name": function.get("name", ""),
            "function_source": function.get("source", ""),
            "compile_errors": list(compile_errors),
            "code_queries": list(queries),
            "example_code_candidates": condensed_matches,
            "required_schema": {
                "selected_entries": [
                    {
                        "kb_id": "integer from example_code_candidates",
                        "reason": "why this entry should be kept",
                        "usage_hint": "how it helps fix the compile errors",
                    }
                ]
            },
        }
        request_messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": json.dumps(user_payload, ensure_ascii=False, indent=2)},
        ]
        response_text = self._chat(request_messages)
        payload, response_text = self._extract_json_with_repair(
            response_text=response_text,
            request_messages=request_messages,
            required_schema=user_payload["required_schema"],
            stage_label="fix-stage example code selection",
        )
        candidate_map = {item["kb_id"]: item for item in condensed_matches}
        selected_entries: List[Dict[str, Any]] = []
        seen = set()
        for item in (payload or {}).get("selected_entries", []):
            kb_id = item.get("kb_id")
            if kb_id in seen or kb_id not in candidate_map:
                continue
            seen.add(kb_id)
            selected = dict(candidate_map[kb_id])
            selected["selection_reason"] = item.get("reason", "")
            selected["usage_hint"] = item.get("usage_hint", "")
            selected_entries.append(selected)
        return {
            "used_llm": True,
            "raw_response": response_text,
            "selected_entries": selected_entries[:max_selected],
        }

    def _aggregate_matches(self, query_runs: Sequence[Dict]) -> List[Dict]:
        merged: Dict[int, Dict] = {}
        for run in query_runs:
            unsafe_api = run.get("unsafe_api", "")
            query = run.get("query", "")
            for match in run.get("matches", []):
                kb_id = match["kb_id"]
                existing = merged.get(kb_id)
                if existing is None:
                    merged[kb_id] = {
                        **match,
                        "matched_queries": [query] if query else [],
                        "unsafe_apis": [unsafe_api] if unsafe_api else [],
                    }
                    continue
                existing["score"] = max(existing["score"], match["score"])
                if query and query not in existing["matched_queries"]:
                    existing["matched_queries"].append(query)
                if unsafe_api and unsafe_api not in existing["unsafe_apis"]:
                    existing["unsafe_apis"].append(unsafe_api)
        aggregated = list(merged.values())
        aggregated.sort(key=lambda item: item["score"], reverse=True)
        return aggregated

    def _select_top_matches(self, function: Dict, initial: Dict, aggregated_matches: Sequence[Dict]) -> Dict:
        if self.client is None:
            self._log("  [rag] LLM unavailable during top API selection")
            return {
                "used_llm": False,
                "raw_response": None,
                "selected_api_entries": [],
                "reason": "LLM unavailable; top OpenHarmony API selection skipped",
            }

        if not aggregated_matches:
            self._log("  [rag] no aggregated matches; skipping top API selection LLM call")
            return {
                "used_llm": False,
                "raw_response": None,
                "selected_api_entries": [],
                "reason": "no aggregated BM25 matches; top API selection skipped",
            }

        condensed_matches = []
        for item in aggregated_matches[:20]:
            condensed_matches.append(
                {
                    "kb_id": item["kb_id"],
                    "api_name": item["api_name"],
                    "function_summary": item["function_summary"],
                    "example_code": item.get("example_code") or [],
                    "cargo_dependency": item.get("cargo_dependency") or {},
                    "source_repository": item.get("source_repository") or {},
                    "matched_queries": item.get("matched_queries", []),
                    "unsafe_apis": item.get("unsafe_apis", []),
                    "score": item["score"],
                }
            )

        system_prompt = (
            "You are selecting OpenHarmony Rust API candidates for replacing or reducing unsafe usage. "
            "Choose at most 5 API entries from the provided BM25 results, and it is completely acceptable to choose none. "
            "Only choose entries that have a plausible and reusable functional relationship to the original unsafe or C-style APIs. "
            "You do not need to diversify across different aspects; if multiple strong entries are all relevant in similar ways, you may keep them. "
            "If the matches are weak, indirect, or not actually reusable for this function, return an empty list. "
            "Return valid JSON only. "
            "The top-level JSON value must be an object/dict with key \"selected_api_entries\"; never return a bare array/list."
        )
        user_payload = {
            "function_name": function["name"],
            "file_path": function["file_path"],
            "function_source": function["source"],
            "initial_api_judgement": {k: v for k, v in initial.items() if k != "messages"},
            "bm25_candidates": condensed_matches,
            "required_schema": {
                "selected_api_entries": [
                    {
                        "kb_id": "integer from bm25_candidates",
                        "reason": "why this API is a plausible replacement or helper",
                        "usage_hint": "how the rewritten function could use it",
                    }
                ]
            },
        }
        user_prompt = json.dumps(user_payload, ensure_ascii=False, indent=2)
        request_messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_prompt},
        ]
        response_text = self._chat(request_messages)
        payload, response_text = self._extract_json_with_repair(
            response_text=response_text,
            request_messages=request_messages,
            required_schema=user_payload["required_schema"],
            stage_label="top API selection",
        )

        selection: List[Dict] = []
        seen = set()
        candidate_map = {item["kb_id"]: item for item in condensed_matches}
        normalized_payload = self._normalize_selection_payload(payload)
        for item in normalized_payload.get("selected_api_entries", []):
            kb_id = item.get("kb_id")
            if kb_id in seen or kb_id not in candidate_map:
                continue
            seen.add(kb_id)
            selected = dict(candidate_map[kb_id])
            selected["selection_reason"] = item.get("reason", "")
            selected["usage_hint"] = item.get("usage_hint", "")
            selection.append(selected)
        return {
            "used_llm": True,
            "raw_response": response_text,
            "selected_api_entries": selection[: self.max_selected_apis],
        }

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
                    text = "\n".join(item.get("text", "") for item in content if isinstance(item, dict)).strip()
                else:
                    text = (content or "").strip()
                if text:
                    return text
                raise ValueError("empty response content from LLM")
            except Exception as exc:
                last_error = exc
                self._log(
                    f"  [rag] LLM request attempt {attempt}/{max_attempts} failed "
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
            f"  [rag] LLM request exhausted retries "
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
                f"  [rag] {stage_label} returned non-JSON content; requesting one-shot JSON-only repair "
                f"({type(exc).__name__}: {exc})"
            )
            repair_messages = list(request_messages) + [
                {"role": "assistant", "content": response_text},
                {
                    "role": "user",
                    "content": (
                        "Your previous reply was not valid JSON. "
                        "Return JSON only with no markdown, no code fences, and no extra explanation. "
                        "The top-level JSON value must be an object/dict, never a bare array/list. "
                        "Follow this schema exactly:\n"
                        f"{json.dumps(required_schema, ensure_ascii=False, indent=2)}"
                    ),
                },
            ]
            repaired_text = self._chat(repair_messages)
            return self._extract_json(repaired_text), repaired_text

    def _normalize_candidate_payload(self, payload: Any) -> Dict[str, List[Dict[str, Any]]]:
        if isinstance(payload, dict):
            candidates = payload.get("api_candidates")
            if isinstance(candidates, list):
                return {"api_candidates": [item for item in candidates if isinstance(item, dict)]}
            if "unsafe_api" in payload:
                return {"api_candidates": [payload]}
            return {"api_candidates": []}
        if isinstance(payload, list):
            return {"api_candidates": [item for item in payload if isinstance(item, dict)]}
        return {"api_candidates": []}

    def _normalize_selection_payload(self, payload: Any) -> Dict[str, List[Dict[str, Any]]]:
        if isinstance(payload, dict):
            selected = payload.get("selected_api_entries")
            if isinstance(selected, list):
                return {"selected_api_entries": [item for item in selected if isinstance(item, dict)]}
            if "kb_id" in payload:
                return {"selected_api_entries": [payload]}
            return {"selected_api_entries": []}
        if isinstance(payload, list):
            return {"selected_api_entries": [item for item in payload if isinstance(item, dict)]}
        return {"selected_api_entries": []}

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
