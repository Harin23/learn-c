# Module 9.5 — Hardware Interfaces

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Contrast MMIO and port I/O at a conceptual level
- Recognize `ioremap`, `request_irq`, and deferred work patterns in driver code
- Use a kernel timer or workqueue to update module state (VM-safe — no custom hardware required)
- Protect shared data with mutexes in module code
- Deliver an integrated capstone module combining char dev, sysfs, and background work

## Prerequisites

- Completed [Module 9.4](../module-09-04-driver-architecture-pci/README.md) exit criteria
- Projects 48–49 modules available as base for capstone

## Concepts to Study

1. **MMIO** — device registers mapped into kernel address space
2. **`ioremap` / `devm_ioremap`** — map physical MMIO (read in traced drivers)
3. **Interrupts** — top half short; defer work to tasklet/workqueue
4. **`request_irq`** — register handler; `free_irq` on remove
5. **Workqueues / timers** — process context deferred work
6. **Mutex in modules** — protect buffer + stats updated from fops and workqueue
7. **Part 8 locking** — no sleep in atomic context; mutex OK in fops
8. **Integrated driver** — char interface + sysfs + background updater

## Hands-On Labs

### Lab 1: IRQ/MMIO Scavenger Hunt

Worksheet: [labs/part-09/worksheets/9.5-irq-mmio-scavenger.md](../../labs/part-09/worksheets/9.5-irq-mmio-scavenger.md)

Find `request_irq` and `ioremap` in driver traced in Module 9.4.

### Lab 2: Timer or Workqueue Counter

Add delayed work to Project 49 module; increment counter exposed via sysfs every N seconds.

### Lab 3: Mutex Review

Ensure chardev buffer and stats share one mutex; document lock ordering in comments.

### Lab 4: Optional /proc/interrupts

Compare IRQ counts before/after loading pci-skeleton (may show no change — document).

## Mini-Project

**Part 9 Driver Capstone** — [projects/part-09/51-driver-capstone.md](../../projects/part-09/51-driver-capstone.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/core-api/workqueue.rst` | Workqueues |
| Part 8 [Module 8.5](../../part-08-linux-kernel-fundamentals/module-08-05-kernel-synchronization/README.md) | Locking review |

## Part 9 Oral Checklist (Self-Assessment)

Answer without notes:

1. What does `vermagic` mismatch mean when `insmod` fails?
2. Why use `copy_to_user` instead of `*user_ptr = x`?
3. Where do sysfs files for your module appear?
4. What happens in `pci_driver.probe`?
5. Why keep interrupt handlers short?
6. Name three pieces your capstone module combines.

## Exit Criteria

Before advancing to Part 10, confirm:

- [ ] Worksheet 9.5 completed
- [ ] Project 51 capstone loads, runs, unloads cleanly in VM
- [ ] checkpatch run on module sources; lkm checklist complete
- [ ] Part 9 oral checklist completed confidently
- [ ] [Part 9 exit gate](../README.md#part-exit-gate) fully satisfied

## Next Part

[Part 10 — AMD Driver and Graphics Stack](../../part-10-amd-driver-graphics/)

Requires Part 9 exit gate complete.
