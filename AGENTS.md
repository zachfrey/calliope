# Calliope Agent Guide

## Purpose
Calliope is a cross-platform Qt desktop application targeting Windows and Ubuntu 24.04.
The codebase is intentionally optimized for:

- learning Qt concepts directly in C++
- test-driven development
- AI-assisted code generation with explicit contracts
- small, reviewable commits

## Working Style
- Prefer Qt 6 and modern CMake.
- Keep production code in C++.
- Keep optional tooling and helper scripts in Python only when they improve developer workflow without affecting the runtime stack.
- Use TDD for new behavior whenever practical: write or update a failing test, implement the smallest change, then refactor.
- Favor small generated patches over large speculative rewrites.

## Architecture Rules
- Keep UI classes thin.
- Put business logic outside QWidget/QMainWindow types.
- Isolate filesystem, process, network, and clock access behind small interfaces before behavior grows.
- Prefer composition over inheritance except where Qt APIs naturally require inheritance.
- Avoid placing non-trivial application logic directly in `main.cpp` or widget constructors.

## Testing Rules
- Add or update tests for behavior changes.
- Prefer fast unit tests over slower UI tests.
- Use Qt Test for Qt-facing behavior unless there is a strong reason to introduce another framework.
- UI tests should verify wiring and visible behavior, not internal implementation details.
- When a feature is hard to test, treat that as a design signal and create a seam.

## AI Generation Rules
- Read the relevant contract files in `contracts/` before making structural changes.
- Preserve manual edits unless the task explicitly replaces them.
- Do not leave parked reference code in `#if 0` blocks after a feature is complete; move enduring reference material into docs instead.
- Generate the smallest useful abstraction first, then let tests justify further decomposition.
- When introducing a new module, also introduce the first test for it.

## Commit Guidance
- Prefer concise commits with one clear purpose.
- Use `feat:` for user-visible capability, `fix:` for defects, `test:` for tests, `docs:` for documentation, and `chore:` for scaffolding or maintenance.
- If a commit mixes behavior and scaffolding, split it unless the scaffolding only exists to support that behavior.

## Near-Term Layout
The current repo is still small. Grow toward this shape as features appear:

- `src/app/` for application services and startup coordination
- `src/ui/` for Qt widgets and windows
- `src/domain/` for core logic with minimal Qt coupling
- `tests/` for unit and UI-facing tests
- `contracts/` for AI-editing and architecture constraints
- `docs/` for decisions and workflow notes
