# Patch Self-Review Checklist

Use before submitting [Project 41](../../../projects/part-07/41-small-patch-submission.md).

## Scope

- [ ] Patch does one logical thing (or test+fix pair clearly linked)
- [ ] No unrelated formatting or drive-by changes
- [ ] Commit message explains **why**, not only what

## Correctness

- [ ] Bug is reproduced before fix (test or manual steps)
- [ ] All tests pass (`make test` or project equivalent)
- [ ] Edge cases considered (empty input, errors)

## Style

- [ ] Matches surrounding code style (indent, naming)
- [ ] No new compiler warnings
- [ ] Comments only where non-obvious

## Patch format

- [ ] `git diff` or `format-patch` output is clean unified diff
- [ ] Subject line ≤ 72 characters, imperative mood
- [ ] Body wraps at ~72 columns (kernel convention)

## Documentation

- [ ] README or ISSUES updated if behavior changed
- [ ] PATCH_NOTES.md explains problem and verification

## Optional (kernel/upstream)

- [ ] `Signed-off-by: Name <email>` line present
- [ ] DCO understood if submitting to kernel lists
