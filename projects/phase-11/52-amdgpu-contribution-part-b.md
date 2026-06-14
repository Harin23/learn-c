# Project 52 Part B: AMDGPU Upstream Contribution

**Module:** 11.3 — Upstream Development and Git Workflows  
**Curriculum project:** 52 (Part B of 2 — completes curriculum)  
**Estimated time:** 12–18 hours

## Description

Execute the contribution planned in Phase 10's preview and Module 11.2. Submit (Path A) or dry-run export (Path B) a small documentation or comment fix in the graphics stack, informed by your `AMDGPU_TRACE.md`.

## Prerequisites

- `AMDGPU_TRACE.md` (Project 52 Part A) with Phase 11 preview section
- `UPSTREAM_SUBMISSION_PLAN.md` (Module 11.2)
- Worksheet [11.3-contribution-execution.md](../../labs/phase-11/worksheets/11.3-contribution-execution.md)

## Choose one contribution option

| Option | Target | Testing |
|--------|--------|---------|
| **A (recommended)** | `Documentation/gpu/` clarity fix tied to traced path | Build docs if applicable; no VM required |
| **B** | Kernel comment / kerneldoc improvement in traced amdgpu/DRM file | `checkpatch.pl --strict`; no behavior change |
| **C (advanced)** | Mesa documentation MR if trace included Mesa boundary | MR or dry-run; Mesa CI not required |

## Hard constraints

- Must reference traced files from `AMDGPU_TRACE.md`
- **No functional amdgpu driver logic changes**
- 1–3 commits; `Signed-off-by` on each
- `checkpatch.pl --strict` clean or exceptions documented in report
- Links back to Part A trace table (which step the patch illuminates)

## Deliverables

### 1. Patch series

Export with:

```bash
git format-patch -N HEAD~N
```

Files: `0001-*.patch`, …

### 2. `CONTRIBUTION_REPORT.md`

Sections:

1. **Environment** — kernel tag, Path A/B, tools used
2. **Problem** — what was unclear or wrong (tie to trace step)
3. **Solution** — what your patch changes (1–2 paragraphs)
4. **Trace alignment** — quote trace step; explain how patch helps readers follow that path
5. **checkpatch summary** — pass or documented exceptions
6. **Submission evidence**
   - Path A: lore.kernel.org link or Mesa MR URL
   - Path B: dry-run rationale + "would-send" steps (list, cover letter, cc lines)
7. **Revision log** — v1 only is fine; note any self-review iterations

### 3. Completed checklist

[labs/phase-11/checklists/upstream-submission-checklist.md](../../labs/phase-11/checklists/upstream-submission-checklist.md)

## Submission paths

| Path | Requirement |
|------|-------------|
| **A** | Actually post to list or open Mesa GitLab MR (mentor approval encouraged) |
| **B** | Full artifact package locally; cover letter + series; explicitly **not** sent — valid for curriculum completion |

## Rubric

| Criterion | Points |
|-----------|--------|
| Trace alignment (file + step referenced) | 25 |
| Patch quality / checkpatch | 25 |
| Commit messages + Signed-off-by | 15 |
| Submission evidence or credible Path B dry-run | 20 |
| CONTRIBUTION_REPORT + checklist complete | 15 |
| **Total** | **100** |

## Example commit message (Option A)

```
docs/gpu: clarify GEM handle role in introduction

Readers tracing DRM open → GEM create paths (see amdgpu trace)
confused GEM handles with CPU pointers. Clarify handle indirection
and ioctl boundary without changing technical scope.

Signed-off-by: Your Name <email@example.com>
```

## Example cover letter snippet

```
Subject: [PATCH v1] docs/gpu: clarify GEM handle role in introduction

Hi,

This small documentation fix supports understanding the GEM create
path in the amdgpu driver. While tracing open → ioctl → amdgpu_gem_*
I found the introduction.rst GEM paragraph easy to misread.

No code changes. Applies on v6.12.

Thanks,
Your Name
```

## Curriculum completion

Project 52 Part B completes the **52-project curriculum**. Complete [curriculum-completion-checklist.md](../../labs/phase-11/checklists/curriculum-completion-checklist.md) after submission.

## Part A reference

[Project 52 Part A — AMDGPU Trace](../phase-10/52-amdgpu-trace-part-a.md)

## Note

Maintainer acceptance is not required for curriculum completion. Path B is first-class.

Do not submit invasive amdgpu production patches.
