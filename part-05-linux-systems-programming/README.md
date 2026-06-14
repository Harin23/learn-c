# Part 5 — Linux Systems Programming

Deep dive into system calls, process creation, pipes, advanced threading, TCP/IP networking, and event-driven I/O. This part bridges user-space applications to kernel interaction patterns used throughout Linux.

**Estimated time:** 90–105 hours (6 modules × 15–18 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [5.1](module-05-01-syscalls/README.md) | System Calls | 15–18 |
| [5.2](module-05-02-fork-exec/README.md) | fork() and exec() | 15–18 |
| [5.3](module-05-03-pipes-ipc/README.md) | pipe() and IPC Patterns | 15–18 |
| [5.4](module-05-04-pthreads-advanced/README.md) | pthreads (Advanced) | 15–18 |
| [5.5](module-05-05-networking-tcpip/README.md) | Networking and TCP/IP | 15–18 |
| [5.6](module-05-06-event-driven/README.md) | Event-Driven Programming | 15–18 |

## Prerequisites

Complete the [Part 4 exit gate](../part-04-linux-user-space/README.md#part-exit-gate) before starting.

Additional packages:

```bash
sudo apt install -y strace net-tools
```

## Part Exit Gate

Do not start Part 6 or Part 7 until you can independently:

- Explain user space vs kernel space and how system calls transition between them
- Create processes with `fork`, replace images with `execve`, and `wait` for children
- Connect processes with pipes and shell-style pipelines (`dup2` redirection)
- Implement a worker thread pool with a task queue and graceful shutdown
- Write a minimal TCP HTTP server that handles concurrent clients
- Build a multi-client chat server using `select` or `poll`
- Monitor filesystem events with `inotify` in an event loop
- Manage processes (list, signal, reap) in a mini process manager
- Complete all Part 5 projects (27–33) with zero compiler warnings

## Resources

See [resources/part-05.md](../resources/part-05.md) for the canonical reading list.

## Projects in This Part

| # | Project | Module | Spec |
|---|---------|--------|------|
| 27 | Custom shell | 5.2 | [27-custom-shell.md](../projects/part-05/27-custom-shell.md) |
| 28 | Pipe filter pipeline | 5.3 | [28-pipe-pipeline.md](../projects/part-05/28-pipe-pipeline.md) |
| 29 | Thread pool | 5.4 | [29-thread-pool.md](../projects/part-05/29-thread-pool.md) |
| 30 | HTTP server | 5.5 | [30-http-server.md](../projects/part-05/30-http-server.md) |
| 31 | Chat server | 5.5 | [31-chat-server.md](../projects/part-05/31-chat-server.md) |
| 32 | File watcher (inotify) | 5.6 | [32-file-watcher.md](../projects/part-05/32-file-watcher.md) |
| 33 | Process manager | 5.6 | [33-process-manager.md](../projects/part-05/33-process-manager.md) |

Module 5.1 skills are integrated via labs and syscall tracing exercises used throughout later modules.
