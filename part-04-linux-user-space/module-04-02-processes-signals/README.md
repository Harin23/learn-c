# Module 4.2 — Processes and Signals

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain process ID, parent PID, and process state at a high level
- Read process information from `/proc/[pid]/`
- Use `getpid`, `getppid`, and basic process listing
- Install signal handlers with `signal` or `sigaction`
- Handle `SIGINT` and `SIGTERM` for graceful shutdown
- Build tools similar to simplified `ps` and system monitors

## Prerequisites

- Completed [Module 4.1](../module-04-01-filesystem-file-io/README.md) exit criteria

## Concepts to Study

1. **Process** — running program instance; PID uniquely identifies
2. **`/proc` filesystem** — virtual files exposing kernel process data
3. **Key files** — `/proc/[pid]/status`, `/proc/[pid]/cmdline`, `/proc/stat` (system)
4. **`getpid(2)`, `getppid(2)`** — current process IDs
5. **Signals** — async notifications; `SIGINT`, `SIGTERM`, `SIGCHLD`, `SIGKILL`
6. **Signal handlers** — `sigaction` preferred over `signal`; async-signal-safe functions only
7. **Polling `/proc`** — re-read files for monitor-style tools
8. **Preview** — `fork`/`exec` deferred to Part 5

## Hands-On Labs

### Lab 1: Print Self PID and Parent

Write a program printing PID, PPID, and uid from `/proc/self/status`.

Starter: [labs/part-04/proc_self_starter.c](../../labs/part-04/proc_self_starter.c)

### Lab 2: Parse `/proc/[pid]/stat`

Extract process state character and utime/stime fields (man `proc(5)` field order).

Starter: [labs/part-04/proc_stat_starter.c](../../labs/part-04/proc_stat_starter.c)

### Lab 3: SIGINT Handler

Count Ctrl+C presses; quit on third SIGINT. Use `sigaction` with `SA_RESTART` discussion.

Starter: [labs/part-04/signal_starter.c](../../labs/part-04/signal_starter.c)

### Lab 4: List PIDs in `/proc`

Scan `/proc` for numeric directories; print PID and comm from `status`.

## Mini-Projects

1. **Process viewer** — [projects/part-04/22-process-viewer.md](../../projects/part-04/22-process-viewer.md)
2. **System monitor** — [projects/part-04/23-system-monitor.md](../../projects/part-04/23-system-monitor.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 5 proc` | /proc layout |
| `man 2 sigaction` | Signal handling |
| APUE Ch. 8, 10 | Process control, signals |

## Exit Criteria

Before advancing to Module 4.3, confirm:

- [ ] Process viewer lists running processes with PID and command name
- [ ] System monitor handles SIGINT and exits cleanly
- [ ] Signal handler uses only async-signal-safe calls
- [ ] You can explain what `/proc` is and why it exists

## Next Module

[Module 4.3 — Threads](../module-04-03-threads/README.md)
