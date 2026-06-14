# Module 4.3 — Threads

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Create threads with POSIX `pthread`
- Pass data to thread entry functions safely
- Protect shared variables with `pthread_mutex`
- Join threads and collect return values
- Identify basic race conditions and fix them with locking
- Build a simple multi-threaded terminal application

## Prerequisites

- Completed [Module 4.2](../module-04-02-processes-signals/README.md) exit criteria

## Concepts to Study

1. **Thread vs process** — shared address space; lighter weight
2. **`pthread_create`, `pthread_join`, `pthread_exit`** — lifecycle
3. **Race condition** — undefined behavior from unsynchronized access
4. **`pthread_mutex_t`** — mutual exclusion; lock/unlock pairing
5. **Deadlock preview** — lock ordering; avoid holding locks long
6. **Thread-local data preview** — `__thread` / `pthread_key_t` mention
7. **Compile flag** — link with `-pthread`
8. **Signal and threads** — complexity preview; defer deep dive

## Hands-On Labs

### Lab 1: Hello from Two Threads

Create two threads printing distinct messages; join both before exit.

Starter: [labs/part-04/pthread_hello_starter.c](../../labs/part-04/pthread_hello_starter.c)

### Lab 2: Race Condition Demo

Increment shared counter from multiple threads without mutex — observe wrong total. Fix with mutex.

Starter: [labs/part-04/pthread_counter_starter.c](../../labs/part-04/pthread_counter_starter.c)

### Lab 3: Producer Thread + Consumer Thread (in-process)

Use a bounded buffer with mutex/condition variable preview, or simple mutex + sleep for Module 4.4 prep.

### Lab 4: Thread Argument Passing

Pass struct pointer to thread; ensure struct lives until join (heap or main stack).

## Mini-Project

**Mini Text Editor** — [projects/part-04/24-mini-text-editor.md](../../projects/part-04/24-mini-text-editor.md)

Uses raw terminal mode (`termios`) for single-buffer editing; optional background save thread.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 3 pthread_create`, `man 3 pthread_mutex_lock` | Primary |
| APUE Ch. 11 | Threads |
| `man 3 termios` | Terminal I/O for editor project |

## Exit Criteria

Before advancing to Module 4.4, confirm:

- [ ] Counter lab correct with mutex; wrong without
- [ ] All threads joined before process exit
- [ ] Mini editor loads file, accepts basic keys, saves on quit
- [ ] Compiled with `-pthread` where required
- [ ] You can explain a race condition in your own words

## Next Module

[Module 4.4 — Inter-Process Communication](../module-04-04-ipc/README.md)
