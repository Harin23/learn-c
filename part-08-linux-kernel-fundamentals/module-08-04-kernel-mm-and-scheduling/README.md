# Module 8.4 — Kernel Memory Management and Scheduling

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Connect Part 6 virtual memory concepts to `mm/` implementation
- Describe page allocator and SLUB at a conceptual level
- Relate Part 6 scheduler simulation to CFS in `kernel/sched/`
- Use ftrace (or trace-cmd) to capture live scheduling or MM-related events
- Cite kernel source functions with file paths in a trace report

## Prerequisites

- Completed [Module 8.3](../module-08-03-kernel-subsystems-and-apis/README.md) exit criteria
- Part 6 [Module 6.2](../../part-06-computer-architecture-os/module-06-02-virtual-memory/README.md) and [Module 6.3](../../part-06-computer-architecture-os/module-06-03-scheduling/README.md) review recommended

## Concepts to Study

1. **`mm/` overview** — VMAs, page tables, fault handling (high level)
2. **Page allocator** — buddy system; `alloc_pages` mention
3. **SLUB** — kernel object cache; contrast with user `malloc`
4. **`vm_area_struct`** — maps to `/proc/pid/maps` regions
5. **CFS** — `task_struct`, vruntime, `kernel/sched/fair.c`
6. **Context switch** — `context_switch`, `sched_switch` tracepoint
7. **ftrace** — `trace_events`, `/sys/kernel/debug/tracing/`
8. **User vs kernel observation** — `/proc`, `ftrace`, Part 6 simulators

## Hands-On Labs

### Lab 1: MM and Sched Source Tour

Worksheet: [labs/part-08/worksheets/8.4-mm-sched-kernel-tour.md](../../labs/part-08/worksheets/8.4-mm-sched-kernel-tour.md)

Locate functions related to Part 6 Projects 35 and 36 in the kernel tree.

### Lab 2: ftrace sched_switch Capture

In VM with debugfs mounted:

```bash
sudo mount -t debugfs none /sys/kernel/debug
echo 1 | sudo tee /sys/kernel/debug/tracing/events/sched/sched_switch/enable
# run busy loop or Part 5 thread-pool workload in another terminal
sudo cat /sys/kernel/debug/tracing/trace | head -40
echo 0 | sudo tee /sys/kernel/debug/tracing/events/sched/sched_switch/enable
```

Save output for Project 45.

### Lab 3: maps vs Kernel Code

Read `/proc/self/maps` for a user program; find `show_map_vma` or `/proc` seq_file handler in source (read-only trace).

### Lab 4: Simulator vs CFS (Written)

Two paragraphs: what Part 6 round-robin simulator captures that CFS does differently (qualitative; no formula proof required).

## Mini-Project

**MM or Scheduler Live Trace Report** — [projects/part-08/45-mm-or-sched-trace.md](../../projects/part-08/45-mm-or-sched-trace.md)

Choose **one** track: memory management **or** scheduling.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| *Linux Kernel Development* (Love) Ch. 4–6 | mm and sched overview |
| `Documentation/trace/ftrace.rst` | ftrace guide |
| Part 6 [Project 35](../../projects/part-06/35-vm-map-explorer.md), [Project 36](../../projects/part-06/36-scheduler-simulator.md) | User-space baseline |

## Exit Criteria

Before advancing to Module 8.5, confirm:

- [ ] Worksheet 8.4 completed
- [ ] ftrace capture saved and explained (≥20 events or equivalent MM trace)
- [ ] ≥6 kernel functions cited with paths in notes or Project 45
- [ ] Explicit connection to Part 6 concepts in written comparison
- [ ] Project 45 `TRACE_REPORT.md` complete

## Next Module

[Module 8.5 — Kernel Synchronization](../module-08-05-kernel-synchronization/README.md)
