#ifndef TPOOL_H
#define TPOOL_H

#include <stddef.h>

typedef struct TPool TPool;
typedef void (*JobFn)(void *arg);

TPool *tpool_create(size_t num_workers);
void   tpool_destroy(TPool *pool);
int    tpool_submit(TPool *pool, JobFn fn, void *arg);
void   tpool_shutdown(TPool *pool);

#endif /* TPOOL_H */
