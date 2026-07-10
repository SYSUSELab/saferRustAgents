#!/usr/bin/env python3
"""Fetch OpenHarmony Rust-related repositories from Gitee and save them locally.

The official organization repos API has had stability issues for some org pages,
so this script scrapes the public organization repository listing page as a
fallback-free primary source.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
from dataclasses import asdict, dataclass
from html import unescape
from pathlib import Path
from typing import Iterable
from urllib.error import HTTPError, URLError
from urllib.parse import urlencode, urljoin
from urllib.request import Request, urlopen


BASE_URL = "https://gitee.com/organizations/openharmony/projects"
USER_AGENT = (
    "Mozilla/5.0 (X11; Linux x86_64) "
    "AppleWebKit/537.36 (KHTML, like Gecko) "
    "Chrome/123.0 Safari/537.36"
)
PAGE_SIZE_HINT = 20


@dataclass
class RepoRecord:
    name: str
    url: str


def fetch_html(url: str, timeout: int) -> str:
    request = Request(
        url,
        headers={
            "User-Agent": USER_AGENT,
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
            "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8",
        },
    )
    with urlopen(request, timeout=timeout) as response:
        charset = response.headers.get_content_charset() or "utf-8"
        return response.read().decode(charset, errors="replace")


def build_page_url(search: str, page: int) -> str:
    query = {"search": search}
    if page > 1:
        query["page"] = page
    return f"{BASE_URL}?{urlencode(query)}"


def extract_last_page(html: str) -> int:
    page_matches = re.findall(r"[?&]page=(\d+)[^\"']*[^>]*>(\d+)<", html)
    max_page = 1
    for href_page, label_page in page_matches:
        try:
            max_page = max(max_page, int(href_page), int(label_page))
        except ValueError:
            continue
    return max_page


def extract_repo_records(html: str) -> list[RepoRecord]:
    records: list[RepoRecord] = []
    seen: set[str] = set()

    for match in re.finditer(r'href="(/openharmony/[^"/?#]+)"', html):
        repo_path = unescape(match.group(1))
        repo_name = repo_path.rsplit("/", 1)[-1]

        if not repo_name:
            continue
        if repo_name in seen:
            continue

        seen.add(repo_name)
        records.append(RepoRecord(name=repo_name, url=urljoin("https://gitee.com", repo_path)))

    return records


def filter_rust_records(records: Iterable[RepoRecord], search: str) -> list[RepoRecord]:
    keyword = search.casefold()
    filtered: list[RepoRecord] = []
    for record in records:
        if keyword in record.name.casefold():
            filtered.append(record)
    return filtered


def save_records(records: list[RepoRecord], output_path: Path, search: str) -> None:
    payload = {
        "source": BASE_URL,
        "search": search,
        "generated_count": len(records),
        "repositories": [asdict(record) for record in records],
    }
    output_path.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Fetch OpenHarmony Rust-related repositories from Gitee."
    )
    parser.add_argument(
        "--search",
        default="rust",
        help="Search keyword used on the Gitee organization page. Default: rust",
    )
    parser.add_argument(
        "--output",
        default=str(Path(__file__).with_name("openharmony_rust_repos.json")),
        help="Where to save the repository list JSON.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=20,
        help="HTTP timeout in seconds. Default: 20",
    )
    parser.add_argument(
        "--sleep",
        type=float,
        default=0.2,
        help="Delay between page requests in seconds. Default: 0.2",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    output_path = Path(args.output).resolve()
    output_path.parent.mkdir(parents=True, exist_ok=True)

    first_page_url = build_page_url(args.search, page=1)
    try:
        first_html = fetch_html(first_page_url, timeout=args.timeout)
    except (HTTPError, URLError) as exc:
        print(f"Failed to fetch first page: {exc}", file=sys.stderr)
        return 1

    page_count = extract_last_page(first_html)
    all_records = extract_repo_records(first_html)

    for page in range(2, page_count + 1):
        time.sleep(args.sleep)
        page_url = build_page_url(args.search, page=page)
        try:
            html = fetch_html(page_url, timeout=args.timeout)
        except (HTTPError, URLError) as exc:
            print(f"Failed to fetch page {page}: {exc}", file=sys.stderr)
            return 1
        all_records.extend(extract_repo_records(html))

    deduped: dict[str, RepoRecord] = {}
    for record in all_records:
        deduped.setdefault(record.name, record)

    records = sorted(
        filter_rust_records(deduped.values(), args.search),
        key=lambda item: item.name.casefold(),
    )
    save_records(records, output_path, args.search)

    print(f"Saved {len(records)} repositories to {output_path}")
    if len(records) < PAGE_SIZE_HINT:
        print(
            "Warning: fetched result count is unexpectedly small; "
            "the page structure may have changed.",
            file=sys.stderr,
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
