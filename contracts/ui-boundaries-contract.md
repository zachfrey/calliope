# UI Boundaries Contract

## Goal
Learn Qt well without letting widgets absorb the whole application.

## Rules
- `QMainWindow` and `QWidget` subclasses should coordinate presentation, not own core business rules.
- Keep constructors lightweight; avoid hidden work that makes widgets hard to test.
- Prefer explicit methods for loading state over doing everything in `showEvent()` or constructors.
- If a widget starts talking to the filesystem, process layer, or long-running operations directly, introduce an intermediate service or adapter.
- Signals and slots should express intent clearly; avoid catch-all slots with broad side effects.

## Heuristics
- If logic can be tested without a visible widget, it probably belongs outside the widget.
- If a widget test needs elaborate setup, the design likely needs a seam.
- If the same decision logic appears in both UI handlers and tests, extract it.
