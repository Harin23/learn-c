# Module 11.2 — Linux Contribution Process

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Route patches using `MAINTAINERS` and `scripts/get_maintainer.pl`
- Draft cover letters and understand mailing-list submission workflow
- Read real contribution threads on lore.kernel.org / Patchwork
- Choose a safe first contribution target in the graphics stack
- Document Path A (send) vs Path B (dry-run) submission strategy

## Prerequisites

- Completed [Module 11.1](../module-11-01-patch-workflow-code-reviews/README.md) exit criteria
- `AMDGPU_TRACE.md` (Project 52 Part A) with Part 11 preview section
- `$KERNEL_SRC` with `scripts/get_maintainer.pl`

## Concepts to Study

1. **`MAINTAINERS`** and `get_maintainer.pl --no-rolestats`
2. **`Documentation/process/submitting-patches.rst`** — cover letter, `--cc`, version tags
3. **DCO / Signed-off-by** — when `Co-developed-by` applies
4. **Patchwork and lore.kernel.org** — reading real threads
5. **Submission tools** — `git send-email`, **b4**, manual attach (document all three)
6. **Safe first contributions** — doc/clarity/comment in traced subsystem
7. **Mesa upstream** — GitLab MR path if trace included Mesa hop
8. **What not to submit** — invasive amdgpu logic, untested driver behavior

## Hands-On Labs

### Lab 1: get_maintainer.pl

Run on a file from your `AMDGPU_TRACE.md`:

```bash
cd "$KERNEL_SRC"
scripts/get_maintainer.pl --no-rolestats path/to/traced/file.c
```

Record list addresses and names.

### Lab 2: Lore Research

Find two recent doc patches in `Documentation/gpu/` on [lore.kernel.org](https://lore.kernel.org). Summarize thread shape (cover letter → ack → merge or revision request).

### Lab 3: Cover Letter Draft

Draft cover letter + export a **practice** one-line doc fix series with `git format-patch -1` (do not send yet).

### Lab 4: Submission Plan Worksheet

Worksheet: [labs/part-11/worksheets/11.2-upstream-submission-plan.md](../../labs/part-11/worksheets/11.2-upstream-submission-plan.md)

## Module Report

**Upstream Submission Plan** — [projects/part-11/upstream-submission-plan.md](../../projects/part-11/upstream-submission-plan.md)

Deliverable: `UPSTREAM_SUBMISSION_PLAN.md`

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [resources/part-11.md](../../resources/part-11.md) | Submission tools and lists |
| `Documentation/process/submitting-patches.rst` | Canonical kernel guide |
| [resources/part-10.md](../../resources/part-10.md) | Trace context |

## Exit Criteria

Before advancing to Module 11.3, confirm:

- [ ] Worksheet 11.2 completed
- [ ] MAINTAINERS entry identified for Part B target file
- [ ] Cover letter draft complete in plan
- [ ] Part B option (A/B/C) chosen with rationale
- [ ] Path A or Path B documented
- [ ] `UPSTREAM_SUBMISSION_PLAN.md` submitted

## Next Module

[Module 11.3 — Upstream Development and Git Workflows](../module-11-03-upstream-development-git-workflows/README.md)
