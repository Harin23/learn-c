# Project 45: MM or Scheduler Live Trace Report

**Module:** 8.4 — Kernel Memory Management and Scheduling  
**Estimated time:** 12–14 hours

## Description

Capture live kernel behavior with ftrace (or trace-cmd) and write a report connecting observations to Part 6 theory and kernel source. Choose **one** track.

## Track A — Scheduling (recommended if Part 6 Project 36 fresh)

1. Boot your custom kernel VM with debugfs/ftrace enabled ([learn-c-base.config](../../labs/part-08/configs/learn-c-base.config))
2. Enable `sched:sched_switch` tracepoint
3. Run workload: busy loop, `stress-ng --cpu 2`, or Part 5 thread-pool binary
4. Capture ≥20 `sched_switch` events
5. Identify PID/TGID patterns and CPU migrations in prose

**Source tour:** cite ≥6 functions/files in `kernel/sched/` related to context switch.

## Track B — Memory management

1. Run a user program that `mmap`s anonymous memory (Part 6 [mmap_touch_starter.c](../../labs/part-06/mmap_touch_starter.c))
2. Use ftrace function graph or tracepoint on page fault path if available, **or** correlate `/proc/pid/maps` + `/proc/pid/status` VmRSS with read-only source trace of fault handler
3. Document page fault or RSS growth observation

**Source tour:** cite ≥6 functions/files in `mm/` (e.g. fault, mmap, page cache intro).

## Deliverable: `TRACE_REPORT.md`

### 1. Environment

- Kernel `uname -r` in VM
- Track chosen (A or B)
- Tools: ftrace sysfs paths or `trace-cmd` commands

### 2. Method

Exact commands to enable trace, run workload, save trace buffer.

### 3. Observations

- Paste abbreviated trace output (≤40 lines) or summary table
- Explain in your words what happened (≥3 paragraphs)

### 4. Source map

| Concept (Part 6) | Kernel function | File path |
|-------------------|-----------------|-----------|

Minimum **6 rows**.

### 5. Part 6 comparison

Compare to [Project 35](../../projects/part-06/35-vm-map-explorer.md) or [Project 36](../../projects/part-06/36-scheduler-simulator.md): what user-space tools showed vs what kernel trace shows.

### 6. Artifacts

Attach raw trace file or `trace.dat` if using trace-cmd.

## Rubric

| Criterion | Points |
|-----------|--------|
| Valid ftrace capture method documented | 20 |
| Observations explained (≥3 paragraphs) | 25 |
| Source map ≥6 entries, paths verified | 30 |
| Part 6 comparison | 15 |
| Worksheet 8.4 completed | 10 |
| **Total** | **100** |

## Worksheet

[labs/part-08/worksheets/8.4-mm-sched-kernel-tour.md](../../labs/part-08/worksheets/8.4-mm-sched-kernel-tour.md)

## Note

Trace format varies by kernel version. Document version consistently with Projects 43–44.
