# SaferAgents: Multi-Agent Based Optimization Method for Unsafe Rust Code

本仓库是论文 **《基于多智能体的不安全Rust代码优化方法》**（SaferAgents: Multi-Agent Based Optimization Method for Unsafe Rust Code）的源代码。

## 概述

SaferAgents 是一种面向 C-to-Rust 翻译后工程的多智能体协同安全优化方法，目标是在保持工程可编译性的前提下，减少 `unsafe` 代码、裸指针操作和显式内存管理逻辑。该方法通过以下组件形成"上下文分析—知识检索—安全改写—编译反馈修复"的闭环优化流程：

- **Context Agent（上下文智能体）**：补充项目内部的类型定义、辅助函数接口和调用方约束
- **Agentic RAG（检索增强生成模块）**：从领域特定的 Rust API 知识库中检索可复用的安全接口知识
- **Safe Rewriting Agent（安全改写智能体）**：生成新的安全 Rust 实现
- **Workspace-Edit Agent（工作区编辑智能体）**：将修改写入隔离工作区
- **Compile-Repair Agent（编译修复智能体）**：根据编译反馈进行迭代修复

## 仓库结构

```
saferRust/
├── saferAgent/                     # 主方法实现
│   ├── agents/                     # 多智能体（安全改写、上下文、RAG、编译修复、工作区编辑）
│   ├── tools/                      # 工作区编辑工具
│   ├── prompt/                     # LLM 提示词模板
│   ├── search/                     # 项目内搜索工具
│   └── analysis/                   # 实验分析脚本
├── KonwledgebaseConstruct/         # 领域 API 知识库构建模块
├── His2TransData/                  # 实验数据集（5 个 OpenHarmony C-to-Rust 翻译项目）
└── function_level_unsafe_report.md # 函数级 unsafe 变更报告
```

## 方法运行主入口

### 安装依赖

本仓库当前按本地 `HiTrans` 环境中的依赖版本生成了 `requirements.txt`：

```bash
conda activate HiTrans
pip install -r requirements.txt
```

本地 `HiTrans` 环境当前为 Python 3.9.25；建议开源复现时使用 Python 3.10+，以匹配源码中的类型标注语法和 README 的环境要求。

### 配置 API 密钥

不要在源码中写入 API key。运行前通过环境变量传入：

```bash
export SAFER_AGENT_API_KEY=<your_api_key>
export SAFER_AGENT_BASE_URL=https://api.deepseek.com
export SAFER_AGENT_MODEL=deepseek-reasoner
```

也可以参考 `.env.example` 管理本地配置；`.env` 和 `.env.*` 已被 `.gitignore` 忽略，不会进入仓库。

### 运行安全改写流程

```bash
cd saferRust
python -m saferAgent.agents.safer_agent \
    --project_path <Rust项目路径> \
    --output_dir <输出目录> \
    --knowledge-base-path <API知识库JSON路径> \
    --base-url <LLM_BASE_URL>
```

### 主要参数说明

| 参数 | 说明 |
|------|------|
| `--project_path` | 待优化的 Rust 项目路径（His2Trans 翻译结果） |
| `--output_dir` | 输出目录，保存改写结果和日志 |
| `--knowledge-base-path` | Rust API 知识库 JSON 文件路径 |
| `--model` | LLM 模型名称（所有阶段统一使用） |
| `--context-model` | 上下文智能体专用模型 |
| `--rag-model` | Agentic RAG 专用模型 |
| `--rewrite-model` | 安全改写智能体专用模型 |
| `--compile-fix-model` | 编译修复智能体专用模型 |
| `--workspace-edit-model` | 工作区编辑智能体专用模型 |
| `--api-key` | LLM API 密钥（也可通过环境变量 `SAFER_AGENT_API_KEY` 设置） |
| `--base-url` | LLM API 地址（也可通过环境变量 `SAFER_AGENT_BASE_URL` 设置） |
| `--target-file` | 仅处理指定 Rust 源文件中的函数 |
| `--limit-functions N` | 仅处理前 N 个函数（调试用） |
| `--dry-run` | 仅执行分析和上下文收集，不调用 LLM |
| `--resume-from-uid UID` | 从指定函数 UID 断点续跑 |
| `--skip-context-agent` | 跳过上下文智能体阶段 |

### 运行示例

```bash
# 使用统一模型运行
python -m saferAgent.agents.safer_agent \
    --project_path ./His2TransData/osal__0bc4f21396ad \
    --output_dir ./saferAgent/results/osal__0bc4f21396ad \
    --knowledge-base-path ./KonwledgebaseConstruct/openharmony_third_party_rust_api_kb.json \
    --model deepseek-v3

# 使用分阶段模型运行（推荐配置）
python -m saferAgent.agents.safer_agent \
    --project_path ./His2TransData/host__25c1898e1626 \
    --output_dir ./saferAgent/results/host__25c1898e1626 \
    --knowledge-base-path ./KonwledgebaseConstruct/openharmony_third_party_rust_api_kb.json \
    --context-model deepseek-v3 \
    --rag-model deepseek-r1 \
    --rewrite-model deepseek-r1 \
    --compile-fix-model deepseek-r1 \
    --workspace-edit-model deepseek-v3
```

## 领域 API 知识库

### 知识库说明

知识库以 API 功能摘要、依赖配置和示例代码为知识单元，为不安全代码优化提供贴近项目场景的领域知识。其构建流程是**领域无关的**——本文以 OpenHarmony 为实验领域进行构建，但同样的流程可迁移至其他软件生态（如 Linux 内核模块、物联网平台、数据库系统等），只需将输入仓库替换为目标领域的 Rust 仓库即可。

知识库中每个 API 条目包含以下字段：

| 字段 | 说明 |
|------|------|
| `api_name` | API 名称 |
| `summary` | API 功能摘要（自然语言描述该 API 能完成的任务） |
| `example_code` | 示例代码（为该 API 提供用法参考） |
| `cargo_dependency` | Cargo 依赖配置（用于在目标工程中引入该 API） |
| `source` | 来源信息（API 所属仓库和文档路径） |

### 构建知识库

```bash
cd KonwledgebaseConstruct

# Step 1: 获取目标领域的 Rust 仓库列表
python fetch_openharmony_rust_repos.py

# Step 2: 构建 Rust API 知识库
python build_openharmony_third_party_rust_api_kb.py
```

构建知识库时默认从 `DEEPSEEK_API_KEY` 读取密钥，也可以通过 `--api-key` 显式传入：

```bash
export DEEPSEEK_API_KEY=<your_api_key>
python build_openharmony_third_party_rust_api_kb.py
```

构建流程：
1. 从目标领域的 Rust 仓库中提取 `Cargo.toml`（获取依赖、版本信息）、README（获取核心能力描述）和 `docs/` 文档
2. 利用 LLM 从 README 生成初始 API 条目集合
3. 将文档分块后，逐轮精化：对已有条目纠错、补充或合并，并在文档明确介绍新 API 时新增条目
4. 输出结构化的 JSON 知识库

### 更换目标领域

如需将方法应用到其他领域，只需：
1. 修改 `fetch_openharmony_rust_repos.py` 中的仓库来源，指向目标领域的 Rust 仓库
2. 重新运行知识库构建流程
3. 在运行主流程时通过 `--knowledge-base-path` 指定新的知识库路径

## 实验结果分析

```bash
cd saferAgent

# 统计翻译后项目的 unsafe 代码比例
python analysis/analyze_rq1_translated_unsafe.py

# 统计优化后项目的 unsafe 代码比例
python analysis/analyze_rq1_safer_unsafe_claude.py
```

## 依赖环境

- Python 3.10+
- tree-sitter 0.21.3 + tree-sitter-rust 0.21.2
- OpenAI 兼容的 LLM API 接口
- Rust 工具链（用于 `cargo check` 验证）

