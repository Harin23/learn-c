# Project 51: Part 9 Driver Capstone

**Module:** 9.5 — Hardware Interfaces  
**Estimated time:** 14–18 hours

## Description

Integrated loadable module combining character device I/O, sysfs statistics/tunables, and background updates via kernel timer or workqueue. This is the Part 9 capstone.

## Requirements

1. **Char device** — read/write interface (FIFO buffer or counter stream)
2. **Sysfs** — at least two read-only stats + one tunable parameter
3. **Deferred work** — `timer_list` or `workqueue` updating internal state every 1–5 seconds (e.g. `uptime_seconds`, `heartbeat_count`)
4. **Mutex** — protects buffer and/or stats shared between fops, sysfs store, and work handler
5. **Clean teardown** — cancel timer/drain workqueue before unregistering; no oops on `rmmod`
6. **checkpatch.pl** on module `.c` files (host path: `$KERNEL_SRC/scripts/checkpatch.pl`)
7. [lkm-review-checklist.md](../../labs/part-09/checklists/lkm-review-checklist.md) completed

## Suggested name

`learn_monitor.ko` — exposes `/dev/learn_monitor` and sysfs under class device.

## Deliverables

1. Source + Makefile
2. **`CAPSTONE_README.md`**:
   - Architecture diagram (ASCII): user → char dev → mutex → buffer; workqueue → stats → sysfs
   - Build/load/mknod commands
   - Test script or manual steps showing char I/O + sysfs + heartbeat increment
   - checkpatch summary
   - Locking notes (≥5 sentences)
3. **`VM_TEST_LOG.md`**: pasted commands and outputs for load, test, unload
4. Completed lkm-review checklist

## Rubric

| Criterion | Points |
|-----------|--------|
| Char dev read/write works | 20 |
| Sysfs stats + tunable work | 20 |
| Timer/workqueue updates state | 20 |
| Mutex protects shared data | 15 |
| Clean unload (no oops) | 10 |
| checkpatch + checklist | 10 |
| CAPSTONE_README + VM_TEST_LOG | 5 |
| **Total** | **100** |

## Part 9 Completion

Projects 47–51 complete Part 9. Part 10 requires [Part 9 exit gate](../../part-09-kernel-modules-drivers/README.md#part-exit-gate).

## Oral checklist

Complete [Module 9.5 oral checklist](../../part-09-kernel-modules-drivers/module-09-05-hardware-interfaces/README.md#part-9-oral-checklist-self-assessment).

## Worksheet

[9.5-irq-mmio-scavenger.md](../../labs/part-09/worksheets/9.5-irq-mmio-scavenger.md)
