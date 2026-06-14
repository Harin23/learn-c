# Project 46: Phase 8 Capstone — Tested In-Tree Kernel Patch

**Module:** 8.5 — Kernel Synchronization  
**Estimated time:** 14–18 hours

## Description

Deliver a polished, boot-tested in-tree kernel patch series that demonstrates Phase 8 skills: build system, coding style, locking awareness, and VM validation. This is the Phase 8 capstone.

## Choose one option

### Option A — Documentation improvement (safest)

Clarity fix in `Documentation/` for a subsystem you traced (boot, mm, sched, or vfs). No behavior change. Still run `make` if docs build target exists; always boot-test kernel if you touched build scripts (usually not needed for pure `.rst`).

### Option B — Cleaned-up Project 44 debug patch

Refine Project 44: remove noise, ensure guard/`pr_debug`, checkpatch-clean, single purpose. Must still build and boot.

### Option C — ftrace/tracepoint documentation + sample script

Add a short doc under `Documentation/trace/` or extend existing ftrace doc with learn-c capture example; include sample shell commands (no invasive core kernel logic change).

## Requirements (all options)

1. **1–3 commits**, one logical change each
2. **`Signed-off-by`** on every commit
3. **`checkpatch.pl --strict`** on full series; fix or justify
4. **Locking review** — confirm patch does not sleep in atomic context or hold spinlocks across blocking calls
5. **Build + VM boot** after final patch state (required for Options B; recommended for A/C)
6. [kernel-patch-review-checklist.md](../../labs/phase-08/checklists/kernel-patch-review-checklist.md) completed
7. [vm-safety-checklist.md](../../labs/phase-08/checklists/vm-safety-checklist.md) if booting new image

## Deliverables

1. **Patch series:** `git format-patch -N HEAD~N` → `0001-*.patch`, ...
2. **`CAPSTONE_NOTES.md`** containing:
   - Option chosen and rationale
   - Summary of each commit
   - checkpatch summary
   - Locking/context review (≥5 sentences)
   - Build command + VM `uname -a` after patch
   - What you would ask a reviewer to focus on

3. Completed checklists (paste or attach)

## Rubric

| Criterion | Points |
|-----------|--------|
| Patch series applies cleanly | 20 |
| checkpatch reviewed; style acceptable | 20 |
| Locking/context review in CAPSTONE_NOTES | 15 |
| Build + VM boot verified (Options B/C mandatory; A if applicable) | 25 |
| Commit messages + Signed-off-by | 10 |
| CAPSTONE_NOTES + checklists complete | 10 |
| **Total** | **100** |

## Phase 8 Completion

Projects 42–46 complete Phase 8. Phase 9 requires [Phase 8 exit gate](../../phase-08-linux-kernel-fundamentals/README.md#phase-exit-gate).

## Worksheet

[labs/phase-08/worksheets/8.5-locking-scavenger-hunt.md](../../labs/phase-08/worksheets/8.5-locking-scavenger-hunt.md)

## Oral checklist

Complete [Module 8.5 oral checklist](../../phase-08-linux-kernel-fundamentals/module-08-05-kernel-synchronization/README.md#phase-8-oral-checklist-self-assessment) before advancing.
