__all__ = ["SaferAgent", "SymbolContextAgent", "AgenticRAGAgent", "CompileFixAgent", "WorkspaceEditAgent"]


def __getattr__(name):
    if name == "SaferAgent":
        from .safer_agent import SaferAgent
        return SaferAgent
    if name == "SymbolContextAgent":
        from .symbol_context_agent import SymbolContextAgent
        return SymbolContextAgent
    if name == "AgenticRAGAgent":
        from .agentic_rag_agent import AgenticRAGAgent
        return AgenticRAGAgent
    if name == "CompileFixAgent":
        from .compile_fix_agent import CompileFixAgent
        return CompileFixAgent
    if name == "WorkspaceEditAgent":
        from .workspace_edit_agent import WorkspaceEditAgent
        return WorkspaceEditAgent
    raise AttributeError(name)
