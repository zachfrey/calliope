# Calliope
Calliope is a cross-platform PySide6 (Qt for Python) desktop application for Windows and Ubuntu 24.04.

## Development Stack
- PySide6 (Qt 6 for Python)
- `uv` for environment and dependency management
- pytest + pytest-qt for the first test layer
- AI-assisted development guided by `AGENTS.md` and the files in `contracts/`

## Workflow
- Prefer TDD for new behavior.
- Keep widgets thin and move business logic into testable classes as features emerge.
- Let generated code produce small, reviewable increments instead of large rewrites.
- Treat contracts as part of the codebase, not side documentation.

## Project Layout
- `src/calliope/`: application scaffold (`app/`, `ui/`, `domain/`)
- `tests/`: automated tests
- `contracts/`: AI and architecture constraints
- `cpp-legacy/`: original C++/Qt scaffold, kept for reference only
- `TODO.md`: near-term roadmap

## Build
```powershell
uv sync
uv run python -m calliope
uv run pytest
```

## Next Step
Build the first real feature as a thin vertical slice:

1. Write a failing test.
2. Introduce the smallest non-UI class needed.
3. Wire that class into the Qt UI.
4. Refactor only after the behavior is covered.
