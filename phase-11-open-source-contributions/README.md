# Phase 11 — Open Source Contributions

Upstream contribution workflow and curriculum capstone. Review patches, plan submission, and complete **Project 52 Part B** — a small graphics-stack doc or comment fix informed by your Phase 10 trace.

**Estimated time:** 35–45 hours (3 modules × 12–15 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [11.1](module-11-01-patch-workflow-code-reviews/README.md) | Patch Workflow and Code Reviews | 12–15 |
| [11.2](module-11-02-linux-contribution-process/README.md) | Linux Contribution Process | 12–15 |
| [11.3](module-11-03-upstream-development-git-workflows/README.md) | Upstream Development and Git Workflows | 12–15 |

## Prerequisites

**Required:** [Phase 10 exit gate](../phase-10-amd-driver-graphics/README.md#phase-exit-gate)

- All Phase 10 module reports (`GRAPHICS_STACK.md`, `DRM_AMDGPU_WALK.md`, `MESA_GPU_PATH.md`, `GEM_TTM_ANALYSIS.md`)
- **Project 52 Part A** — [`AMDGPU_TRACE.md`](../projects/phase-10/52-amdgpu-trace-part-a.md) complete

**Required:** Phases 7 and 9 (patch literacy and driver fundamentals)

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-phase-11.sh
```

## Scope

| In prior phases | In this phase |
|-----------------|---------------|
| Phase 7: local patch format | Review others' patches |
| Phase 8: in-tree capstone (local) | Upstream submission workflow |
| Phase 10: read-only trace | Execute Phase 11 preview as Part B |
| No mailing lists | Cover letter + MAINTAINERS routing |
| Project 52 Part A | **Project 52 Part B** — curriculum complete |

## Submission Paths

| Path | Description |
|------|-------------|
| **A** | Send patch to mailing list or open Mesa GitLab MR (mentor approval encouraged) |
| **B** | Full dry-run export (series + cover letter + report); explicitly not sent — **valid for curriculum completion** |

Document Path A or B in every deliverable.

## Phase Exit Gate

Do not mark curriculum complete until you can independently:

- Review a stranger's patch with constructive, prioritized feedback
- Route a patch using `MAINTAINERS` / `get_maintainer.pl` and draft a cover letter
- Produce a checkpatch-clean, Signed-off-by series for a doc/comment fix in the graphics stack
- Complete **Project 52 Part B** with `CONTRIBUTION_REPORT.md`
- Explain mailing-list vs GitLab MR paths and when VM testing is required

**Not required:** Maintainer merge acceptance (Path B is valid); AMD hardware; Mesa build.

## Curriculum Completion Gate

After Module 11.3 and Project 52 Part B:

1. Complete [curriculum-completion-checklist.md](../labs/phase-11/checklists/curriculum-completion-checklist.md)
2. Pass Phase 11 oral checklist in [Module 11.3](module-11-03-upstream-development-git-workflows/README.md#phase-11-oral-checklist-self-assessment)
3. Spot-check prior phase skills (Phases 7–10 oral checklists if uncertain)

You have then completed **all 11 phases** and **52 projects** of the learn-c curriculum.

### Continuing after the curriculum

- Find subsystem mentors via MAINTAINERS and list archives
- Expand from doc fixes to tested driver changes with VM validation
- Follow dri-devel and amd-gfx lists for graphics stack work
- Consider GSoC, Outreachy, or employer open-source time for sustained contribution

## Resources

See [resources/phase-11.md](../resources/phase-11.md) for the canonical reading list.

## Projects and Reports in This Phase

| Deliverable | Module | Spec | Output |
|-------------|--------|------|--------|
| Patch review practice | 11.1 | [patch-review-practice.md](../projects/phase-11/patch-review-practice.md) | `PATCH_REVIEW_NOTES.md` |
| Upstream submission plan | 11.2 | [upstream-submission-plan.md](../projects/phase-11/upstream-submission-plan.md) | `UPSTREAM_SUBMISSION_PLAN.md` |
| **Project 52 Part B** | 11.3 | [52-amdgpu-contribution-part-b.md](../projects/phase-11/52-amdgpu-contribution-part-b.md) | patch series + `CONTRIBUTION_REPORT.md` |

Project 52 Part A was completed in [Phase 10](../phase-10-amd-driver-graphics/).
