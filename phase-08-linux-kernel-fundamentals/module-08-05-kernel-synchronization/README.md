# Module 8.5 — Kernel Synchronization

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain why kernel locking differs from pthread mutexes
- Distinguish `spinlock_t` vs `mutex` and when each applies
- Describe interrupt context and why sleeping there is forbidden
- Use `lockdep` awareness when reading and reviewing patches
- Deliver a tested in-tree kernel patch as Phase 8 capstone

## Prerequisites

- Completed [Module 8.4](../module-08-04-kernel-mm-and-scheduling/README.md) exit criteria
- Project 44 patch available for locking review

## Concepts to Study

1. **Preemption and atomic context** — `preempt_count`, `in_interrupt()`
2. **Spinlocks** — short critical sections; no sleep; IRQ variants preview
3. **Mutexes** — process context; may sleep waiting
4. **lockdep** — lock ordering validation; `lockdep=1` boot param
5. **`WARN_ON` / `BUG`** — developer assertions vs user crashes
6. **RCU preview** — read-mostly paths; defer free; no deep dive yet
7. **Locking in VFS** — find locks on path from Project 40 trace
8. **Patch review** — does new code hold locks across blocking calls?

## Hands-On Labs

### Lab 1: Locking Scavenger Hunt

Worksheet: [labs/phase-08/worksheets/8.5-locking-scavenger-hunt.md](../../labs/phase-08/worksheets/8.5-locking-scavenger-hunt.md)

Find locks along your Project 40 vfs path.

### Lab 2: lockdep Boot Parameter

Add `lockdep=1` to VM kernel cmdline (QEMU `-append` or GRUB in VM). Boot, note any lockdep lines in dmesg (none is OK — document boot success).

### Lab 3: Review Project 44 Patch

Apply [kernel-patch-review-checklist.md](../../labs/phase-08/checklists/kernel-patch-review-checklist.md) with focus on locking/context questions.

### Lab 4: Documentation Patch (Optional Practice)

Make a one-hunk clarity fix in `Documentation/` under a subsystem you traced — compile not always required for doc-only; still run spellcheck/review.

## Mini-Project

**Phase 8 Capstone — Tested In-Tree Kernel Patch** — [projects/phase-08/46-kernel-patch-capstone.md](../../projects/phase-08/46-kernel-patch-capstone.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| *Linux Kernel Development* (Love) Ch. 7 | Locking overview |
| `Documentation/locking/` | Kernel locking docs |
| `Documentation/process/submitting-patches.rst` | Final patch polish |

## Phase 8 Oral Checklist (Self-Assessment)

Answer without notes:

1. What happens if you sleep while holding a spinlock?
2. Where is your custom kernel config stored and how do you boot it safely?
3. Name three artifacts from a successful kernel build.
4. How do you enable and read a sched tracepoint with ftrace?
5. What belongs in a kernel patch commit message and `Signed-off-by`?
6. Spinlock vs mutex — one sentence each on when to use.

## Exit Criteria

Before advancing to Phase 9, confirm:

- [ ] Worksheet 8.5 completed
- [ ] Project 44 reviewed for locking/context
- [ ] Project 46 capstone patch builds, boots in VM, and is checkpatch-reviewed
- [ ] Phase 8 oral checklist completed confidently
- [ ] [Phase 8 exit gate](../README.md#phase-exit-gate) fully satisfied

## Next Phase

[Phase 9 — Kernel Modules and Drivers](../../phase-09-kernel-modules-drivers/)

Requires Phase 8 exit gate complete.
