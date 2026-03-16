# Testing Contract

## Goal
Keep Calliope easy to evolve with AI assistance by making behavior changes prove themselves through tests.

## Rules
- New behavior should start with a failing test when practical.
- Bug fixes should include a regression test unless the bug is purely cosmetic or tooling-only.
- Prefer tests that exercise behavior through public APIs.
- Prefer deterministic tests with no dependency on wall-clock time, network access, or machine-local state.
- Keep widget tests focused on UI behavior and signal/slot wiring.
- Move non-UI logic into plain classes when widget tests start carrying too much setup.

## Test Layers
- `unit`: domain or application classes with minimal Qt UI coupling
- `ui`: widget and window behavior, signal/slot wiring, view state
- `smoke`: startup and composition sanity checks

## Done Criteria
- Tests fail before the implementation change when practical.
- Tests pass after the implementation.
- The new test would catch the same regression in the future.
