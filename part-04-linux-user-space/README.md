# Part 4 — Linux User-Space Development

Build real Linux terminal applications: file I/O, processes, signals, threads, IPC, build systems, and shared libraries. This part prepares you for systems programming in Part 5.

**Estimated time:** 85–100 hours (6 modules × 14–17 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [4.1](module-04-01-filesystem-file-io/README.md) | Linux Filesystem and File I/O | 14–17 |
| [4.2](module-04-02-processes-signals/README.md) | Processes and Signals | 14–17 |
| [4.3](module-04-03-threads/README.md) | Threads | 14–17 |
| [4.4](module-04-04-ipc/README.md) | Inter-Process Communication | 14–17 |
| [4.5](module-04-05-build-systems/README.md) | Build Systems and Makefiles | 14–17 |
| [4.6](module-04-06-libraries/README.md) | Static and Shared Libraries | 14–17 |

## Prerequisites

**Required:** [Part 2 exit gate](../part-02-memory-core-c/README.md#part-exit-gate) (pointers, malloc, GDB, Valgrind)

**Strongly recommended:** [Part 3 exit gate](../part-03-data-structures-algorithms/README.md#part-exit-gate)

Install additional packages:

```bash
sudo apt install -y \
    libpthread-stubs0-dev \
    manpages-posix \
    manpages-posix-dev
```

## Part Exit Gate

Do not start Part 5 until you can independently:

- Read and write files using POSIX I/O (`open`, `read`, `write`, `close`) and directory APIs
- Parse structured text logs and organize files by extension or date
- Read process information from `/proc` and handle `SIGINT`/`SIGTERM` gracefully
- Write multi-threaded programs with `pthread` and protect shared data with mutexes
- Implement producer-consumer communication using pipes or shared memory
- Write multi-target Makefiles with variables, pattern rules, and dependencies
- Build and link static and shared libraries; understand `LD_LIBRARY_PATH`
- Complete all Part 4 projects (19–26) with zero compiler warnings
- Run Valgrind on heap-heavy projects where applicable

## Resources

See [resources/part-04.md](../resources/part-04.md) for the canonical reading list.

## Projects in This Part

| # | Project | Module | Spec |
|---|---------|--------|------|
| 19 | `mycat` — cat clone | 4.1 | [19-mycat.md](../projects/part-04/19-mycat.md) |
| 20 | Log parser | 4.1 | [20-log-parser.md](../projects/part-04/20-log-parser.md) |
| 21 | File organizer | 4.1 | [21-file-organizer.md](../projects/part-04/21-file-organizer.md) |
| 22 | Process viewer | 4.2 | [22-process-viewer.md](../projects/part-04/22-process-viewer.md) |
| 23 | System monitor | 4.2 | [23-system-monitor.md](../projects/part-04/23-system-monitor.md) |
| 24 | Mini text editor | 4.3 | [24-mini-text-editor.md](../projects/part-04/24-mini-text-editor.md) |
| 25 | Producer-consumer (IPC) | 4.4 | [25-producer-consumer.md](../projects/part-04/25-producer-consumer.md) |
| 26 | Static + shared library demo | 4.6 | [26-library-demo.md](../projects/part-04/26-library-demo.md) |

Module 4.5 skills are integrated into all projects via Makefiles and the [multi-target build lab](../labs/part-04/makefile_lab/).
