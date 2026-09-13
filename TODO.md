# Calliope TODO

## Foundation
- [x] Choose PySide6 (Qt for Python) as the primary application stack, replacing the original C++/Qt plan.
- [ ] Add a starter stack for TDD and AI-assisted development in Python (`pyproject.toml`, `uv.lock`, pytest + pytest-qt).
- [ ] Archive the original C++/Qt scaffold to `cpp-legacy/` as a distinct step, once the Python scaffold lands.
- [ ] Split UI code from application/domain code as soon as the first real feature lands.

## Tooling
- [ ] Set up `uv` for environment and dependency management, with a pinned `.python-version`.
- [ ] Add a first pytest-qt smoke test.
- [ ] Add a devcontainer for the Linux dev/test loop (PySide6 apt packages, headless Qt via `QT_QPA_PLATFORM=offscreen` or Xvfb).
- [ ] Add a GitHub Actions matrix (`windows-latest`, `ubuntu-24.04`) that installs deps with `uv`, runs tests, and builds a PyInstaller binary per OS as a build artifact.
- [ ] Decide whether to add formatting and linting tooling (e.g. `ruff`, `mypy`).

## Product
- [ ] Define the first user-facing feature slice to build with TDD.
- [ ] Decide what belongs in the main window versus a dedicated application service.
- [ ] Write the first behavior contract before implementing the first real feature.
