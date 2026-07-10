# Claude Safer Rewrite Unsafe Rate Summary

统计时间：2026-03-29

统计口径：
- `before`：`data/rq1/claude/rust_code/final_projects/<project>/translate_by_qwen3_coder/src`
- `after`：以原 Claude 项目为 baseline，只合并 SaferAgent 日志中 `workspace_apply: ok` 且 `compile_check: passed` 的函数改写
- `skip fallback`、`skip no-unsafe`、`workspace_apply failed`、`compile_check failed` 的函数均保持原始版本
- unsafe 率使用 `unsafe_total_lines / code_lines`

## Overall

| Projects | Before Code Lines | Before Unsafe Lines | Before Unsafe Rate | After Code Lines | After Unsafe Lines | After Unsafe Rate | Delta Unsafe Lines | Delta Unsafe Rate |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| 5 | 9344 | 6465 | 69.1888% | 9585 | 5228 | 54.5436% | -1237 | -14.6452% |

## Per Project

| Project | Files | Accepted | Compile Failed | Workspace Failed | Skip Fallback | Skip No-unsafe | Before Code Lines | Before Unsafe Lines | Before Unsafe Rate | After Code Lines | After Unsafe Lines | After Unsafe Rate | Delta Unsafe Lines | Delta Unsafe Rate |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| appverify_lite__e5ebe91a98b9 | 10 | 140 | 9 | 3 | 4 | 7 | 5634 | 4104 | 72.8435% | 5907 | 3518 | 59.5565% | -586 | -13.2870% |
| host__25c1898e1626 | 14 | 108 | 2 | 1 | 1 | 6 | 2848 | 1844 | 64.7472% | 2766 | 1291 | 46.6739% | -553 | -18.0733% |
| osal__0bc4f21396ad | 1 | 7 | 0 | 0 | 0 | 0 | 265 | 179 | 67.5472% | 245 | 132 | 53.8776% | -47 | -13.6696% |
| shared__12e38ea922f7 | 2 | 4 | 0 | 0 | 3 | 0 | 143 | 91 | 63.6364% | 164 | 75 | 45.7317% | -16 | -17.9047% |
| shared__541f4e547bdb | 7 | 23 | 0 | 0 | 0 | 3 | 454 | 247 | 54.4053% | 503 | 212 | 42.1471% | -35 | -12.2582% |

## Notes

| Metric | Value |
|---|---:|
| Accepted rewrites | 282 |
| Compile failed functions | 11 |
| Workspace failed functions | 4 |
| Skip fallback functions | 8 |
| Skip no-unsafe functions | 16 |
| Before unsafe items | 866 |
| After unsafe items | 875 |

结果来源：
- 统计脚本：`/data/home/Cyw22331009/His2Trans/His2Trans/saferAgent/analysis/analyze_rq1_safer_unsafe_claude.py`
- 中间 JSON：`/tmp/claude_safer_unsafe.json`
