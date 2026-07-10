__all__ = ["SaferAgent", "SymbolContextAgent", "AgenticRAGAgent", "CompileFixAgent", "WorkspaceEditAgent"]


def __getattr__(name):
    if name in {"SaferAgent", "SymbolContextAgent", "AgenticRAGAgent", "CompileFixAgent", "WorkspaceEditAgent"}:
        from .agents import __getattr__ as _agents_getattr
        return _agents_getattr(name)
    raise AttributeError(name)
