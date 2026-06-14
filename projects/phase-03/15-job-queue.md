# Project 15: Job Queue

**Module:** 3.1 — Linked Lists, Stacks, and Queues  
**Estimated time:** 4–5 hours

## Description

Simulate a job scheduler using a FIFO queue. Jobs have an ID and priority label (string). Process jobs in arrival order.

## File Layout

```
jobqueue/
├── Makefile
├── queue.h
├── queue.c
└── main.c
```

## Data Model

```c
typedef struct {
    int id;
    char label[32];
} Job;

typedef struct Queue Queue;
```

## Queue API

```c
Queue *queue_create(void);
void   queue_destroy(Queue *q);
int    queue_enqueue(Queue *q, const Job *job);
int    queue_dequeue(Queue *q, Job *out);  /* 0 ok, -1 empty */
int    queue_is_empty(const Queue *q);
size_t queue_size(const Queue *q);
```

## main.c Behavior

Interactive or scripted mode:

```
enqueue 101 backup
enqueue 102 email
enqueue 103 report
process    # dequeues and prints: Processing job 101: backup
process
status     # prints queue size
```

Commands:
- `enqueue <id> <label>`
- `process` — dequeue and print
- `status` — print size
- `quit`

## Rubric

| Criterion | Points |
|-----------|--------|
| FIFO order preserved | 30 |
| Enqueue/dequeue O(1) amortized | 20 |
| All commands work | 20 |
| Empty dequeue handled | 10 |
| Valgrind-clean | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Test Script

```
enqueue 1 alpha
enqueue 2 beta
process
process
status
# expect: job 1, job 2, size 0
```

## Starter

[labs/phase-03/queue_starter/](../../labs/phase-03/queue_starter/)

## Extension (Optional)

Priority queue variant using sorted insert (discuss O(n) vs heap preview).
