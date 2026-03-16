# Change Contract

Before making non-trivial edits, confirm the change follows these rules:

1. The change has a single main purpose.
2. New behavior has a test plan.
3. UI code stays thin unless the task is explicitly UI-only.
4. New abstractions are justified by behavior or testability, not by speculation.
5. Docs and contracts are updated when the development workflow changes.

## Preferred Delivery Order
1. Add or update the test.
2. Implement the smallest working change.
3. Refactor for naming, structure, or Qt idioms.
4. Update docs if the workflow or architecture changed.
