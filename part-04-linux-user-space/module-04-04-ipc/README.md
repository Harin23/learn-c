# Module 4.4 — Inter-Process Communication

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain why processes need IPC mechanisms
- Use anonymous pipes for parent-child communication (preview of Part 5)
- Use POSIX shared memory (`shm_open`, `mmap`) for producer-consumer
- Coordinate access with semaphores or mutex in shared memory
- Choose pipe vs shared memory for a given workload

## Prerequisites

- Completed [Module 4.3](../module-04-03-threads/README.md) exit criteria

## Concepts to Study

1. **IPC motivation** — separate address spaces; need kernel-mediated channels
2. **Pipe** — unidirectional byte stream; `pipe(2)` preview
3. **FIFO/named pipe** — `mkfifo` mention
4. **Shared memory** — `shm_open(3)`, `ftruncate`, `mmap(2)`, `munmap`, `shm_unlink`
5. **Synchronization** — `sem_open`, `sem_wait`, `sem_post` for shared buffer
6. **Producer-consumer** — bounded buffer classic problem
7. **Lifetime** — unlink shm/sem names; cleanup on exit
8. **Part 5 preview** — `fork` + pipe patterns coming next

## Hands-On Labs

### Lab 1: Simple Pipe (Same Process)

Create pipe; write message in main, read from other end (no fork yet — demonstrates fd pair).

Starter: [labs/part-04/pipe_starter.c](../../labs/part-04/pipe_starter.c)

### Lab 2: Shared Memory Counter

Two processes or two threads mapping same shm — increment with semaphore protection.

Starter: [labs/part-04/shm_starter/](../../labs/part-04/shm_starter/)

### Lab 3: Ring Buffer in Shared Memory

Fixed-size buffer with head/tail indices in shm struct.

### Lab 4: Cleanup and Error Paths

Ensure `shm_unlink` and `sem_unlink` on all exit paths including signals (careful with async-signal-safe).

## Mini-Project

**Producer-Consumer (IPC)** — [projects/part-04/25-producer-consumer.md](../../projects/part-04/25-producer-consumer.md)

Uses separate producer and consumer **processes** (via `fork`) with shared memory, or two programs coordinated by named shm — spec allows either documented approach.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 2 pipe`, `man 2 mmap`, `man 3 shm_open` | Primary |
| APUE Ch. 15–16 | IPC |
| `man 7 sem_overview` | Semaphore overview |

## Exit Criteria

Before advancing to Module 4.5, confirm:

- [ ] Producer-consumer project passes rubric
- [ ] No lost items under load test (1000 messages)
- [ ] Shared memory and semaphores cleaned up on exit
- [ ] You can explain pipe vs shared memory trade-offs

## Next Module

[Module 4.5 — Build Systems and Makefiles](../module-04-05-build-systems/README.md)
