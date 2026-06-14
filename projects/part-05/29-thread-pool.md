# Project 29: Thread Pool

**Module:** 5.4 — pthreads (Advanced)  
**Estimated time:** 7–9 hours

## Description

Implement a reusable thread pool that executes submitted jobs on worker threads.

## API (tpool.h)

```c
typedef struct TPool TPool;
typedef void (*JobFn)(void *arg);

TPool *tpool_create(size_t num_workers);
void   tpool_destroy(TPool *pool);
int    tpool_submit(TPool *pool, JobFn fn, void *arg);
      /* 0 ok, -1 if shutting down or queue full (if bounded) */
void   tpool_shutdown(TPool *pool);
      /* stop accepting; drain queue; join workers */
```

## Requirements

- Fixed worker count (default 4, configurable at create)
- Unbounded or large bounded queue of `{JobFn, void *arg}` pairs
- Mutex + condition variable for queue
- `tpool_shutdown` blocks until all workers exit after queue drained
- Jobs may allocate; document that args must remain valid until job runs (caller copies if needed)

## Demo (main.c)

Submit 20 jobs printing thread id and job number; shutdown cleanly.

## Rubric

| Criterion | Points |
|-----------|--------|
| Jobs run concurrently | 25 |
| Submit/shutdown thread-safe | 25 |
| No deadlocks on shutdown | 20 |
| All workers joined | 10 |
| Valgrind-clean | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Starter

[labs/part-05/tpool_starter/](../../labs/part-05/tpool_starter/)

## Extension (Optional)

Use pool in HTTP server (Project 30) for connection handling.
