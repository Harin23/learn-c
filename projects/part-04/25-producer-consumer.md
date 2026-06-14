# Project 25: Producer-Consumer (IPC)

**Module:** 4.4 — Inter-Process Communication  
**Estimated time:** 6–8 hours

## Description

Classic bounded-buffer producer-consumer using shared memory and semaphores across two processes.

## Architecture

```
producer (process)  --->  [ring buffer in shm]  --->  consumer (process)
         sem_empty / sem_full / sem_mutex
```

## Usage

```bash
# Build produces producer and consumer binaries
make
./producer -n 100 &
./consumer -n 100
# consumer prints 100 messages in order
```

Alternative: single binary `pc_demo --fork` spawning both sides — document if used.

## Shared Memory Layout

```c
#define BUFFER_SIZE 16

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} ShmRing;
```

Use POSIX named semaphores: `/pc_empty`, `/pc_full`, `/pc_mutex` (unlink on startup/shutdown).

## Requirements

- Producer generates integers `0..n-1` in order
- Consumer prints in same order
- No lost or duplicate values under `-n 10000` test
- Cleanup semaphores and shm on normal exit and SIGINT

## Rubric

| Criterion | Points |
|-----------|--------|
| Ordering preserved for n=1000 | 30 |
| No busy-wait spin (uses semaphores) | 25 |
| Shared memory cleaned up | 15 |
| SIGINT cleanup | 10 |
| Two-process design | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Starter

[labs/part-04/shm_starter/](../../labs/part-04/shm_starter/)

## Linking

```makefile
LDLIBS = -pthread -lrt
```

(`-lrt` for `shm_open` on older glibc; often merged on modern Ubuntu)
