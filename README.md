# Calliope
Calliope is a cross-platform Qt desktop application in C++ for Windows and Ubuntu 24.04.

## Development Stack
- Qt 6 with C++
- CMake
- Qt Test for the first test layer
- AI-assisted development guided by `AGENTS.md` and the files in `contracts/`

## Workflow
- Prefer TDD for new behavior.
- Keep widgets thin and move business logic into testable classes as features emerge.
- Let generated code produce small, reviewable increments instead of large rewrites.
- Treat contracts as part of the codebase, not side documentation.

## Project Layout
- `main.cpp`, `mainwindow.*`, `mainwindow.ui`: current application scaffold
- `tests/`: automated tests
- `contracts/`: AI and architecture constraints
- `TODO.md`: near-term roadmap

## Build
```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

If CMake cannot find Qt, point it at your Qt installation with `CMAKE_PREFIX_PATH`.

## Next Step
Build the first real feature as a thin vertical slice:

1. Write a failing test.
2. Introduce the smallest non-UI class needed.
3. Wire that class into the Qt UI.
4. Refactor only after the behavior is covered.
