# Module 5.6 — Event-Driven Programming

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Write event loops with `select`, `poll`, or `epoll` (intro)
- Monitor filesystem changes with `inotify`
- Combine signal handling with event loops safely
- Build non-blocking or multiplexed I/O applications
- Manage child processes from an interactive tool

## Prerequisites

- Completed [Module 5.5](../module-05-05-networking-tcpip/README.md) exit criteria

## Concepts to Study

1. **Event loop** — wait for events → dispatch handlers → repeat
2. **`select(2)` / `poll(2)`** — watch multiple fds; timeout support
3. **`epoll(7)` preview** — scalable Linux multiplexing; Phase 5 optional extension
4. **`inotify(7)`** — file create/modify/delete events
5. **`INOTIFY_INIT`, `inotify_add_watch`** — watch directories recursively (careful with limits)
6. **Self-pipe trick** — signal handler writes byte to pipe; loop reads it (async-signal-safe)
7. **Process management** — kill, waitpid, `/proc` refresh in UI loop
8. **Integration** — chat server could use poll instead of threads (refactor exercise)

## Hands-On Labs

### Lab 1: select on stdin + timeout

Wait for input with 5-second timeout; print whether data arrived or timeout.

Starter: [labs/phase-05/select_starter.c](../../labs/phase-05/select_starter.c)

### Lab 2: inotify Directory Watch

Print events when files created/modified in a directory.

Starter: [labs/phase-05/inotify_starter.c](../../labs/phase-05/inotify_starter.c)

### Lab 3: poll Multiplex

Watch listen socket + client fds in one loop (HTTP server refactor).

### Lab 4: Signal + Event Loop

Use self-pipe or signalfd preview to exit loop on SIGINT cleanly.

## Mini-Projects

1. **File Watcher** — [projects/phase-05/32-file-watcher.md](../../projects/phase-05/32-file-watcher.md)
2. **Process Manager** — [projects/phase-05/33-process-manager.md](../../projects/phase-05/33-process-manager.md)

## Phase 5 Oral Checklist (Self-Assessment)

Answer without notes:

1. What does `fork` return in parent and child?
2. Why close unused pipe ends?
3. Thread pool vs thread-per-connection for HTTP?
4. Steps to accept a TCP connection?
5. What does `inotify` report?
6. How does `strace` help debugging?

## Exit Criteria

Before advancing to Phase 6, confirm:

- [ ] File watcher prints inotify events correctly
- [ ] Process manager lists, signals, and reaps children
- [ ] All Projects 27–33 complete with zero warnings
- [ ] Phase 5 oral checklist completed confidently
- [ ] [Phase 5 exit gate](../README.md#phase-exit-gate) fully satisfied

## Next Phase

[Phase 6 — Computer Architecture and OS](../../phase-06-computer-architecture-os/) (coming soon)
