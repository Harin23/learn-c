# Module 7.3 — Documentation-Driven Development and Small Fixes

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Read existing docs and tests before changing code
- Write commit messages and patches acceptable to open-source projects
- Create unified diffs with `git format-patch` or `git diff`
- Fix a beginner-friendly bug or improve documentation with tests
- Self-review patches using a checklist before submission

## Prerequisites

- Completed [Module 7.2](../module-07-02-linux-source-tree/README.md) exit criteria

## Concepts to Study

1. **Documentation-driven development** — docs + tests define expected behavior
2. **Patch format** — unified diff; subject line conventions
3. **Commit message style** — imperative mood; explain why
4. **Signed-off-by** — DCO preview for kernel (`Signed-off-by:` line)
5. **Minimal patches** — one logical change per commit
6. **Regression tests** — add test when fixing bug
7. **Code review mindset** — reviewer questions to anticipate
8. **Sending patches** — email lists preview; GitHub PR as alternative for user-space

## Hands-On Labs

### Lab 1: Fix mini-util Bug

Fix documented issue in [labs/part-07/mini-util/ISSUES.md](../../labs/part-07/mini-util/ISSUES.md). Run test script.

### Lab 2: Write Patch Series

Create two commits: (1) add test exposing bug, (2) fix bug. Export with `git format-patch -2`.

### Lab 3: Documentation Improvement

Add missing API comment or README section to mini-util without behavior change.

### Lab 4: Review Checklist

Apply [labs/part-07/checklists/patch-review-checklist.md](../../labs/part-07/checklists/patch-review-checklist.md) to your patch.

## Mini-Project

**Small Patch Submission** — [projects/part-07/41-small-patch-submission.md](../../projects/part-07/41-small-patch-submission.md)

Fix mini-util issue **or** submit documentation fix to a real project (with mentor approval / low-risk repo).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/process/submitting-patches.rst` (kernel) | Patch workflow |
| [How to GitHub Fork, Branch, Pull Request](https://docs.github.com/en/pull-requests) | PR path |
| [kernel.org patch tips](https://www.kernel.org/doc/html/latest/process/submitting-patches.html) | Part 11 preview |

## Part 7 Oral Checklist (Self-Assessment)

Answer without notes:

1. What tools do you use first in a new repo?
2. Where are Linux scheduler files roughly located?
3. What is MAINTAINERS for?
4. Syscall path: name three layers from user to VFS
5. What belongs in a good commit message?
6. Difference between `git diff` and `git format-patch`?

## Exit Criteria

Before advancing to Part 8, confirm:

- [ ] mini-util tests pass after your fix
- [ ] Patch exported with proper commit message
- [ ] Patch review checklist completed
- [ ] Project 41 deliverables complete
- [ ] Part 7 oral checklist completed confidently
- [ ] [Part 7 exit gate](../README.md#part-exit-gate) fully satisfied

## Next Part

[Part 8 — Linux Kernel Fundamentals](../../part-08-linux-kernel-fundamentals/)

Requires Part 6 + Part 7 complete.
