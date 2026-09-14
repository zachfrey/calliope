# Calliope Agent Guide

## Purpose
Calliope is a cross-platform PySide6 (Qt for Python) desktop application targeting Windows and Ubuntu 24.04 (or 26.04, now that it's out).
The codebase is intentionally optimized for:

- shipping the app quickly, while still absorbing Qt concepts through PySide6's API
- test-driven development
- AI-assisted code generation with explicit contracts
- small, reviewable commits

## Working Style
- Prefer PySide6 (Qt 6) and manage the environment/dependencies with `uv`.
- Keep production code in Python, with type hints on public functions and classes.
- Use TDD for new behavior whenever practical: write or update a failing test, implement the smallest change, then refactor.
- Favor small generated patches over large speculative rewrites.

## Architecture Rules
- Keep UI classes thin.
- Put business logic outside QWidget/QMainWindow types.
- Isolate filesystem, process, network, and clock access behind small interfaces before behavior grows.
- Prefer composition over inheritance except where Qt APIs naturally require inheritance.
- Avoid placing non-trivial application logic directly in the entry-point module or widget constructors.

## Testing Rules
- Add or update tests for behavior changes.
- Prefer fast unit tests over slower UI tests.
- Use pytest with pytest-qt for Qt-facing behavior unless there is a strong reason to introduce another framework.
- UI tests should verify wiring and visible behavior, not internal implementation details.
- When a feature is hard to test, treat that as a design signal and create a seam.

## AI Generation Rules
- Read the relevant contract files in `contracts/` before making structural changes.
- Preserve manual edits unless the task explicitly replaces them.
- Do not leave parked reference code commented out after a feature is complete; move enduring reference material into docs instead.
- Generate the smallest useful abstraction first, then let tests justify further decomposition.
- When introducing a new module, also introduce the first test for it.

## Commit Guidance
- Prefer concise commits with one clear purpose.
- Use `feat:` for user-visible capability, `fix:` for defects, `test:` for tests, `docs:` for documentation, and `chore:` for scaffolding or maintenance.
- If a commit mixes behavior and scaffolding, split it unless the scaffolding only exists to support that behavior.
- Commits are reserved for the user to review and create. An AI agent should stage and describe changes but not run `git commit` unless explicitly asked to commit that specific change.

## Near-Term Layout
The current repo is still small. Grow toward this shape as features appear:

- `src/calliope/app/` for application services and startup coordination
- `src/calliope/ui/` for Qt widgets and windows
- `src/calliope/domain/` for core logic with minimal Qt coupling
- `tests/` for unit and UI-facing tests
- `contracts/` for AI-editing and architecture constraints
- `docs/` for decisions and workflow notes
- `cpp-legacy/` holds the original C++/Qt scaffold, kept for reference only; do not build on it
- `pyproject.toml` and `uv.lock` define the environment and dependencies (managed via `uv`)
- `.devcontainer/` provides a Linux dev/test environment
- `.github/workflows/` builds and tests the app on both Windows and Ubuntu
