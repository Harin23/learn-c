#include "tpool.h"

#include <stdio.h>
#include <unistd.h>

static void job(void *arg)
{
	int n = *(int *)arg;

	printf("job %d on thread\n", n);
}

int main(void)
{
	TPool *pool = tpool_create(4);

	if (!pool)
		return 1;

	for (int i = 0; i < 10; i++)
		tpool_submit(pool, job, &i);

	tpool_shutdown(pool);
	tpool_destroy(pool);
	return 0;
}
