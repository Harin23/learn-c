# Module 5.4 — pthreads (Advanced)

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Design a worker thread pool with a shared task queue
- Use condition variables (`pthread_cond`) for producer-consumer threading
- Shut down thread pools gracefully without deadlocks
- Distinguish process-based vs thread-based concurrency for I/O servers
- Avoid common pitfalls mixing fork with threads

## Prerequisites

- Completed [Module 5.3](../module-05-03-pipes-ipc/README.md) exit criteria
- Part 4 pthread basics

## Concepts to Study

1. **Thread pool pattern** — fixed workers; queue of function pointers or jobs
2. **`pthread_cond_wait/signal/broadcast`** — block until work available
3. **Spurious wakeups** — always recheck condition in loop
4. **Shutdown flag** — poison pill or broadcast + join all workers
5. **Work stealing preview** — advanced schedulers mention only
6. **Thread vs process** — shared memory; cheaper creation; less isolation
7. **Async-signal-safe** — limited calls in signal handlers with threads
8. **HTTP server preview** — thread per connection vs pool vs event loop

## Hands-On Labs

### Lab 1: Condition Variable Basics

Main produces jobs; one worker waits on cond; processes and loops.

Starter: [labs/part-05/condvar_starter.c](../../labs/part-05/condvar_starter.c)

### Lab 2: Bounded Queue with Mutex + Cond

Multiple producers/consumers in-process (Part 4 ring buffer + cond vars).

### Lab 3: Thread Pool Skeleton

Complete starter with `tpool_submit` and `tpool_shutdown`.

Starter: [labs/part-05/tpool_starter/](../../labs/part-05/tpool_starter/)

### Lab 4: Benchmark Pool vs Per-Task Thread

Submit 1000 trivial tasks; compare thread-per-task vs pool latency.

## Mini-Project

**Thread Pool** — [projects/part-05/29-thread-pool.md](../../projects/part-05/29-thread-pool.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 3 pthread_cond_wait` | Condition variables |
| APUE Ch. 11 | Threads |
| *Programming with POSIX Threads* (Butenhof) | Optional depth |

## Exit Criteria

Before advancing to Module 5.5, confirm:

- [ ] Thread pool project passes rubric
- [ ] Graceful shutdown joins all workers
- [ ] No deadlocks under concurrent submit from multiple threads
- [ ] You can explain when a thread pool beats spawning threads per task

## Next Module

[Module 5.5 — Networking and TCP/IP](../module-05-05-networking-tcpip/README.md)
