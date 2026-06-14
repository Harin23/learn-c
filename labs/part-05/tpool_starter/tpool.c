#include "tpool.h"

#include <stdlib.h>

struct TPool {
	/* TODO: workers, queue, mutex, cond, shutdown flag */
	size_t num_workers;
};

TPool *tpool_create(size_t num_workers)
{
	TPool *pool = calloc(1, sizeof(*pool));

	if (!pool)
		return NULL;

	pool->num_workers = num_workers;
	/* TODO: spawn worker threads */
	return pool;
}

void tpool_destroy(TPool *pool)
{
	free(pool);
}

int tpool_submit(TPool *pool, JobFn fn, void *arg)
{
	(void)pool;
	(void)fn;
	(void)arg;
	return -1;
}

void tpool_shutdown(TPool *pool)
{
	(void)pool;
}
