# Module 11.3 — Upstream Development and Git Workflows

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Execute Project 52 Part B — small graphics-stack upstream contribution
- Produce checkpatch-clean, Signed-off-by patch series
- Submit via Path A (list/MR) or complete Path B (dry-run export)
- Document contribution evidence in `CONTRIBUTION_REPORT.md`
- Complete the curriculum with Part 11 oral and completion checklists

## Prerequisites

- Completed [Module 11.2](../module-11-02-linux-contribution-process/README.md) exit criteria
- `UPSTREAM_SUBMISSION_PLAN.md` approved by self-review
- `$KERNEL_SRC` with `scripts/checkpatch.pl`

## Concepts to Study

1. **Implementing Part 10 preview** — scope control, no driver logic changes
2. **Revision workflow** — `[PATCH v2]`, changelog below `---`
3. **Responding to review** — even self-simulated in Path B
4. **Testing expectations** — doc-only vs code comment vs Mesa MR
5. **VM boot** — usually not required for doc-only Part B Option A
6. **Curriculum synthesis** — oral checklist spanning Parts 7–11
7. **After the curriculum** — mentors, larger contributions, live patching preview
8. **Archiving evidence** — lore link, MR URL, or dry-run artifacts

## Hands-On Labs

### Lab 1: Apply and checkpatch

Create Part B patch in kernel tree (or Mesa fork). Run:

```bash
cd "$KERNEL_SRC"
git diff | scripts/checkpatch.pl --strict --no-signoff -
# or on exported patches:
scripts/checkpatch.pl --strict --no-signoff 0001-*.patch
```

Fix issues before export.

### Lab 2: Self-Review

Apply [labs/part-11/checklists/upstream-submission-checklist.md](../../labs/part-11/checklists/upstream-submission-checklist.md).

### Lab 3: Submit or Dry-Run

- **Path A:** send via `b4 send` / `git send-email` or open Mesa GitLab MR
- **Path B:** export series + cover letter; document steps in `CONTRIBUTION_REPORT.md`

### Lab 4: Contribution Worksheet

Worksheet: [labs/part-11/worksheets/11.3-contribution-execution.md](../../labs/part-11/worksheets/11.3-contribution-execution.md)

## Capstone — Project 52 Part B

**AMDGPU Upstream Contribution** — [projects/part-11/52-amdgpu-contribution-part-b.md](../../projects/part-11/52-amdgpu-contribution-part-b.md)

Deliverables: patch series + `CONTRIBUTION_REPORT.md` — **completes curriculum Project 52**

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [resources/part-11.md](../../resources/part-11.md) | Final reading |
| [projects/part-10/52-amdgpu-trace-part-a.md](../../projects/part-10/52-amdgpu-trace-part-a.md) | Part A trace |
| [curriculum-completion-checklist.md](../../labs/part-11/checklists/curriculum-completion-checklist.md) | Final sign-off |

## Part 11 Oral Checklist (Self-Assessment)

Answer without notes:

1. What is the difference between must-fix and nit in a code review?
2. When would you use `git rebase -i` before sending a patch series?
3. How do you find the right mailing list for a kernel patch?
4. What does `Signed-off-by` certify under the DCO?
5. When is Path B (dry-run) acceptable for curriculum completion?
6. What did your Part B patch clarify from your Part 10 trace?
7. When is VM boot required for a kernel patch?
8. Name one graphics stack layer your trace crossed (userspace → kernel).

Cross-check: Part 7, 8, and 10 oral checklists if any answer was uncertain.

## Exit Criteria

Before marking the curriculum complete, confirm:

- [ ] Worksheet 11.3 completed
- [ ] Project 52 Part B patch series exported
- [ ] `CONTRIBUTION_REPORT.md` submitted
- [ ] [upstream-submission-checklist.md](../../labs/part-11/checklists/upstream-submission-checklist.md) completed
- [ ] [curriculum-completion-checklist.md](../../labs/part-11/checklists/curriculum-completion-checklist.md) completed
- [ ] Part 11 oral checklist passed
- [ ] [Part 11 exit gate](../README.md#part-exit-gate) fully satisfied

## Curriculum Complete

Congratulations — you have completed all 11 parts and 52 projects of the learn-c curriculum.

See [Part 11 README](../README.md#curriculum-completion-gate) for continuing after the curriculum.
