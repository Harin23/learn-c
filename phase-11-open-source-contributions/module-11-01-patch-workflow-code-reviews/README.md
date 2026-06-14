# Module 11.1 — Patch Workflow and Code Reviews

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Review patches with constructive, prioritized feedback (must-fix vs nit vs question)
- Read unified diffs and identify common submission failures before sending
- Clean a patch series with interactive rebase (`git rebase -i`, fixup/squash)
- Compare series revisions with `git range-diff` (optional)
- Extend Phase 7/8 self-review checklists from a reviewer perspective

## Prerequisites

- [Phase 10 exit gate](../../phase-10-amd-driver-graphics/README.md#phase-exit-gate) — all reports + `AMDGPU_TRACE.md`
- Phase 7 Project 41 (patch format) and Phase 8 Project 46 (checkpatch, Signed-off-by) completed
- `$KERNEL_SRC` recommended for context; not required for this module's labs

## Concepts to Study

1. **Review vocabulary** — must-fix vs nit vs question vs praise
2. **Reading diffs** — `git show`, hunk context, spotting drive-by changes
3. **Interactive rebase** — squash, fixup, reorder commits before send
4. **`git range-diff`** — comparing v1 vs v2 patch series
5. **Extending prior checklists** — [Phase 7 patch-review-checklist](../../labs/phase-07/checklists/patch-review-checklist.md), [Phase 8 kernel-patch-review-checklist](../../labs/phase-08/checklists/kernel-patch-review-checklist.md)
6. **Patch series structure** — test-first commits, logical dependency order
7. **Common failures** — vague subjects, missing Signed-off-by, scope creep
8. **Review ethics** — constructive tone, no bikeshedding

## Hands-On Labs

### Lab 1: Review Sample Patch A

Review [labs/phase-11/sample-patches/01-mini-util-style-bug.patch](../../labs/phase-11/sample-patches/01-mini-util-style-bug.patch) — user-space style patch with intentional flaws. Write ≥3 actionable comments.

### Lab 2: Review Sample Patch B

Review [labs/phase-11/sample-patches/02-kernel-doc-nits.patch](../../labs/phase-11/sample-patches/02-kernel-doc-nits.patch) — kernel doc patch with intentional style issues. Write ≥3 actionable comments.

### Lab 3: Interactive Rebase Practice

Run [labs/phase-11/rebase-practice/setup.sh](../../labs/phase-11/rebase-practice/setup.sh) and reduce three commits to two using `git rebase -i`.

### Lab 4: Review Worksheet

Worksheet: [labs/phase-11/worksheets/11.1-patch-review-practice.md](../../labs/phase-11/worksheets/11.1-patch-review-practice.md)

## Module Report

**Patch Review Practice** — [projects/phase-11/patch-review-practice.md](../../projects/phase-11/patch-review-practice.md)

Deliverable: `PATCH_REVIEW_NOTES.md`

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [resources/phase-11.md](../../resources/phase-11.md) | Reading map |
| Phase 7 [Module 7.3](../../phase-07-reading-large-codebases/module-07-03-docs-and-small-fixes/README.md) | Patch format baseline |
| Phase 8 [Module 8.3](../../phase-08-linux-kernel-fundamentals/module-08-03-kernel-subsystems-and-apis/README.md) | checkpatch introduction |

## Exit Criteria

Before advancing to Module 11.2, confirm:

- [ ] Worksheet 11.1 completed
- [ ] Reviewed both sample patches with ≥3 actionable comments each
- [ ] Rebase practice documented (3 commits → 2)
- [ ] `PATCH_REVIEW_NOTES.md` submitted
- [ ] Can explain when rebase is preferred over merge for patch cleanup

## Next Module

[Module 11.2 — Linux Contribution Process](../module-11-02-linux-contribution-process/README.md)
