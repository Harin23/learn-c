# Report: Upstream Submission Plan

**Module:** 11.2 — Linux Contribution Process  
**Estimated time:** 10–12 hours

## Description

Plan your Project 52 Part B contribution: identify MAINTAINERS routing, draft a cover letter, and choose a safe doc/comment target informed by your Part 10 `AMDGPU_TRACE.md`.

## Prerequisites

- Worksheet [11.2-upstream-submission-plan.md](../../labs/part-11/worksheets/11.2-upstream-submission-plan.md)
- Completed `AMDGPU_TRACE.md` (Project 52 Part A) with Part 11 preview section
- `$KERNEL_SRC` with `scripts/get_maintainer.pl`

## Deliverable: `UPSTREAM_SUBMISSION_PLAN.md`

### 1. Trace connection

- Paste Part 11 preview summary from `AMDGPU_TRACE.md` (2–3 sentences)
- Trace step number your Part B patch will illuminate
- Target file path (must appear in trace table or adjacent docs)

### 2. Part B option chosen

| Option | Description |
|--------|-------------|
| **A (recommended)** | `Documentation/gpu/` clarity fix |
| **B** | Kernel comment / kerneldoc in traced amdgpu/DRM file |
| **C (advanced)** | Mesa documentation MR (only if trace included Mesa) |

State option and rationale (why safe for first upstream contribution).

### 3. MAINTAINERS routing

Paste `get_maintainer.pl --no-rolestats` output for target file (or Elixir equivalent).

Primary list or MR destination: _______________

### 4. Lore research

Summarize **two** recent doc patches in `Documentation/gpu/` or your traced subsystem:

| Patch subject | Thread shape (1 sentence) |
|---------------|---------------------------|
| | |
| | |

### 5. Cover letter draft

Full cover letter for `[PATCH v1]` including:

- Subject line (≤72 chars after prefix)
- 3–8 sentence body explaining what and why
- Pointer to trace motivation (1 sentence)

### 6. Submission path

Path A (send upstream) or Path B (dry-run only) — document choice and constraints (email policy, mentor, etc.).

### 7. Practice patch (optional)

If you created a one-line practice doc fix during Lab 3, note commit hash or `format-patch` filename. Not required to send.

## Rubric

| Criterion | Points |
|-----------|--------|
| Trace connection clear (file + step) | 25 |
| MAINTAINERS / list routing documented | 20 |
| Cover letter draft complete | 25 |
| Lore research (2 patches summarized) | 15 |
| Path A/B documented; worksheet 11.2 done | 15 |
| **Total** | **100** |

## Note

Do not send production amdgpu driver logic patches. Doc/comment fixes only for Part B.

## Next

[Module 11.3 — Upstream Development and Git Workflows](../../part-11-open-source-contributions/module-11-03-upstream-development-git-workflows/README.md)
