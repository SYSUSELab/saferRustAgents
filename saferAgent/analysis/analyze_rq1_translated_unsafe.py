#!/usr/bin/env python3
"""
仅统计 RQ1 最终 Rust 项目中“真实翻译目标文件”的 unsafe 率。

默认优先使用:
  data/rq1/<run>/intermediate/<project>/workspace/extracted/<project>/functions_manifest.json

从 manifest 中提取 source_file，再映射到:
  data/rq1/<run>/rust_code/final_projects/<project>/translate_by_qwen3_coder/src/<source_file>.rs

这样会自动排除:
  compat.rs / compatibility.rs / globals.rs / types.rs / main.rs / __c2r_generated/*
等骨架、补全、生成文件。
"""

from __future__ import annotations

import argparse
import importlib.util
import json
import re
import sys
from dataclasses import asdict
from pathlib import Path
from typing import Dict, Iterable, List, Sequence


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_RQ1_ROOT = REPO_ROOT / "data" / "rq1"
HELPER_SCRIPT = REPO_ROOT / "scripts" / "analyze_c2r_compilation_rate.py"


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


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="分析 RQ1 中仅翻译目标 Rust 文件的 unsafe 率"
    )
    parser.add_argument(
        "--rq1-root",
        type=Path,
        default=DEFAULT_RQ1_ROOT,
        help=f"RQ1 根目录，默认: {DEFAULT_RQ1_ROOT}",
    )
    parser.add_argument(
        "--runs",
        nargs="*",
        help="只分析指定 run，例如: claude k1 k3",
    )
    parser.add_argument(
        "--project",
        help="只分析指定项目名，例如: appverify_lite__e5ebe91a98b9",
    )
    parser.add_argument(
        "--compare-full",
        action="store_true",
        help="额外输出全项目扫描结果，便于对比过滤前后的差异",
    )
    parser.add_argument(
        "--json-output",
        type=Path,
        help="将结果写入 JSON 文件",
    )
    parser.add_argument(
        "--show-file-metrics",
        action="store_true",
        help="输出每个纳入文件的 code_lines 和 unsafe 指标",
    )
    return parser.parse_args()


def discover_runs(rq1_root: Path, requested_runs: Sequence[str] | None) -> List[Path]:
    if requested_runs:
        return [rq1_root / run for run in requested_runs]
    return sorted(
        p for p in rq1_root.iterdir()
        if p.is_dir() and (p / "rust_code" / "final_projects").exists()
    )


def discover_project_dirs(run_dir: Path, project: str | None) -> List[Path]:
    final_root = run_dir / "rust_code" / "final_projects"
    if project:
        candidate = final_root / project / "translate_by_qwen3_coder"
        return [candidate] if candidate.exists() else []
    return sorted(
        p for p in final_root.glob("*/translate_by_qwen3_coder")
        if p.is_dir()
    )


def manifest_path_for(run_dir: Path, project_name: str) -> Path:
    return (
        run_dir
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
    return [src_dir / f"{source_file}.rs" for source_file in source_files if (src_dir / f"{source_file}.rs").exists()]


def target_files_fallback(src_dir: Path) -> List[Path]:
    # 兜底规则: 仅保留明显来自 C 源文件的翻译模块。
    patterns = (
        re.compile(r"^src_.+\.rs$"),
        re.compile(r"^products_.+\.rs$"),
    )
    files = []
    for path in sorted(src_dir.glob("*.rs")):
        if any(pattern.match(path.name) for pattern in patterns):
            files.append(path)
    return files


def aggregate_unsafe(files: Iterable[Path]):
    result = UnsafeAnalysis()
    total_unsafe_block_lines = 0
    total_unsafe_fn_lines = 0
    used_files: List[str] = []

    for rs_file in files:
        content = rs_file.read_text(encoding="utf-8", errors="ignore")
        used_files.append(rs_file.name)

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

    result.files_analyzed = len(used_files)
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

    return result, used_files


def round_metrics(obj: Dict) -> Dict:
    rounded = {}
    for key, value in obj.items():
        if isinstance(value, float):
            rounded[key] = round(value, 6)
        else:
            rounded[key] = value
    return rounded


def format_ratio(value: float) -> str:
    return f"{value:.4%}"


def analyze_project(project_dir: Path, run_dir: Path, compare_full: bool) -> Dict:
    project_name = project_dir.parent.name
    src_dir = project_dir / "src"
    manifest_path = manifest_path_for(run_dir, project_name)

    if manifest_path.exists():
        selected_files = target_files_from_manifest(manifest_path, src_dir)
        selection_mode = "manifest"
    else:
        selected_files = target_files_fallback(src_dir)
        selection_mode = "fallback_by_filename"

    all_rs_files = sorted(
        p for p in src_dir.rglob("*.rs")
        if "__c2r_generated" not in p.parts and "c2rust_fallback" not in p.parts
    )
    excluded_files = sorted(
        p.name for p in all_rs_files if p not in selected_files
    )

    filtered_metrics, included_files = aggregate_unsafe(selected_files)
    file_details = []
    for rs_file in selected_files:
        file_metrics, _ = aggregate_unsafe([rs_file])
        file_details.append(
            {
                "file": rs_file.name,
                "unsafe": round_metrics(asdict(file_metrics)),
            }
        )
    result = {
        "project": project_name,
        "run": run_dir.name,
        "selection_mode": selection_mode,
        "manifest_path": str(manifest_path) if manifest_path.exists() else None,
        "included_files": included_files,
        "excluded_files": excluded_files,
        "included_file_details": file_details,
        "filtered_unsafe": round_metrics(asdict(filtered_metrics)),
    }

    if compare_full:
        full_metrics, full_files = aggregate_unsafe(all_rs_files)
        result["full_project_files"] = [p.name for p in all_rs_files]
        result["full_project_unsafe"] = round_metrics(asdict(full_metrics))
        result["comparison"] = {
            "filtered_file_count": len(included_files),
            "full_file_count": len(full_files),
            "filtered_code_lines": filtered_metrics.code_lines,
            "full_code_lines": full_metrics.code_lines,
            "filtered_unsafe_total_ratio": round(filtered_metrics.unsafe_total_ratio, 6),
            "full_unsafe_total_ratio": round(full_metrics.unsafe_total_ratio, 6),
        }

    return result


def print_analysis_header(args: argparse.Namespace, results: List[Dict]) -> None:
    run_names = ", ".join(sorted({item["run"] for item in results}))
    print("RQ1 translated-target unsafe analysis")
    print(f"rq1_root: {args.rq1_root.resolve()}")
    print(f"runs: {run_names}")
    print(f"project_filter: {args.project or 'ALL'}")
    print(f"compare_full: {args.compare_full}")
    print(f"show_file_metrics: {args.show_file_metrics}")


def summarize_run_items(run_items: List[Dict]) -> Dict:
    summary = {
        "projects": len(run_items),
        "files_analyzed": 0,
        "code_lines": 0,
        "unsafe_keyword_lines": 0,
        "unsafe_context_lines": 0,
        "unsafe_total_lines": 0,
        "unsafe_block_count": 0,
        "unsafe_fn_count": 0,
        "unsafe_impl_count": 0,
        "unsafe_trait_count": 0,
        "total_unsafe_items": 0,
    }
    for item in run_items:
        metrics = item["filtered_unsafe"]
        for key in summary:
            if key == "projects":
                continue
            summary[key] += metrics.get(key, 0)
    if summary["code_lines"] > 0:
        summary["unsafe_keyword_ratio"] = summary["unsafe_keyword_lines"] / summary["code_lines"]
        summary["unsafe_context_ratio"] = summary["unsafe_context_lines"] / summary["code_lines"]
        summary["unsafe_total_ratio"] = summary["unsafe_total_lines"] / summary["code_lines"]
    else:
        summary["unsafe_keyword_ratio"] = 0.0
        summary["unsafe_context_ratio"] = 0.0
        summary["unsafe_total_ratio"] = 0.0
    return summary


def print_project_details(item: Dict, compare_full: bool, show_file_metrics: bool) -> None:
    current_run = None
    metrics = item["filtered_unsafe"]
    print(f"\n[{item['project']}]")
    print(
        f"selection={item['selection_mode']}, files={metrics['files_analyzed']}, "
        f"code_lines={metrics['code_lines']}, total_lines={metrics['total_lines']}"
    )
    print(
        f"unsafe_total_lines={metrics['unsafe_total_lines']} ({format_ratio(metrics['unsafe_total_ratio'])}), "
        f"unsafe_keyword_lines={metrics['unsafe_keyword_lines']} ({format_ratio(metrics['unsafe_keyword_ratio'])}), "
        f"unsafe_context_lines={metrics['unsafe_context_lines']} ({format_ratio(metrics['unsafe_context_ratio'])})"
    )
    print(
        f"unsafe_items={metrics['total_unsafe_items']} "
        f"(block={metrics['unsafe_block_count']}, fn={metrics['unsafe_fn_count']}, "
        f"impl={metrics['unsafe_impl_count']}, trait={metrics['unsafe_trait_count']}), "
        f"unsafe_keyword_occurrences={metrics['unsafe_keyword_occurrences']}"
    )
    print(f"included_files[{len(item['included_files'])}]: {', '.join(item['included_files'])}")
    if item["excluded_files"]:
        print(f"excluded_files[{len(item['excluded_files'])}]: {', '.join(item['excluded_files'])}")
    if item["manifest_path"]:
        print(f"manifest: {item['manifest_path']}")
    if compare_full and "comparison" in item:
        comp = item["comparison"]
        print(
            "compare_full: "
            f"files {comp['filtered_file_count']} vs {comp['full_file_count']}, "
            f"code_lines {comp['filtered_code_lines']} vs {comp['full_code_lines']}, "
            f"unsafe_total_ratio {format_ratio(comp['filtered_unsafe_total_ratio'])} "
            f"vs {format_ratio(comp['full_unsafe_total_ratio'])}"
        )
    if show_file_metrics:
        print("included_file_metrics:")
        for detail in item["included_file_details"]:
            file_metrics = detail["unsafe"]
            print(
                f"  - {detail['file']}: code_lines={file_metrics['code_lines']}, "
                f"unsafe_total_lines={file_metrics['unsafe_total_lines']} "
                f"({format_ratio(file_metrics['unsafe_total_ratio'])}), "
                f"unsafe_items={file_metrics['total_unsafe_items']}"
            )


def print_text_report(results: List[Dict], compare_full: bool, show_file_metrics: bool) -> None:
    grouped: Dict[str, List[Dict]] = {}
    for item in results:
        grouped.setdefault(item["run"], []).append(item)

    for run_name, run_items in grouped.items():
        print(f"\n== {run_name} ==")
        summary = summarize_run_items(run_items)
        print(
            f"summary: projects={summary['projects']}, files={summary['files_analyzed']}, "
            f"code_lines={summary['code_lines']}, unsafe_total_lines={summary['unsafe_total_lines']} "
            f"({format_ratio(summary['unsafe_total_ratio'])})"
        )
        print(
            f"         unsafe_keyword_lines={summary['unsafe_keyword_lines']} "
            f"({format_ratio(summary['unsafe_keyword_ratio'])}), "
            f"unsafe_context_lines={summary['unsafe_context_lines']} "
            f"({format_ratio(summary['unsafe_context_ratio'])}), "
            f"unsafe_items={summary['total_unsafe_items']}"
        )
        for item in run_items:
            print_project_details(item, compare_full, show_file_metrics)


def main() -> int:
    args = parse_args()
    rq1_root = args.rq1_root.resolve()

    if not rq1_root.exists():
        print(f"rq1 root not found: {rq1_root}", file=sys.stderr)
        return 1

    results: List[Dict] = []
    for run_dir in discover_runs(rq1_root, args.runs):
        if not run_dir.exists():
            print(f"skip missing run dir: {run_dir}", file=sys.stderr)
            continue
        for project_dir in discover_project_dirs(run_dir, args.project):
            results.append(analyze_project(project_dir, run_dir, args.compare_full))

    if not results:
        print("no projects matched", file=sys.stderr)
        return 1

    print_analysis_header(args, results)
    print_text_report(results, args.compare_full, args.show_file_metrics)

    if args.json_output:
        payload = {
            "rq1_root": str(rq1_root),
            "runs": sorted({item["run"] for item in results}),
            "project_filter": args.project,
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
