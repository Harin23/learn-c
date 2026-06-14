#include "queue.h"

#include <stdlib.h>

struct Queue {
	/* TODO: ring buffer or linked queue with tail */
	size_t size;
};

Queue *queue_create(void)
{
	Queue *q = malloc(sizeof(*q));

	if (!q)
		return NULL;
	q->size = 0;
	return q;
}

void queue_destroy(Queue *q)
{
	free(q);
}

int queue_enqueue(Queue *q, const Job *job)
{
	(void)q;
	(void)job;
	return -1;
}

int queue_dequeue(Queue *q, Job *out)
{
	(void)q;
	(void)out;
	return -1;
}

int queue_is_empty(const Queue *q)
{
	return q->size == 0;
}

size_t queue_size(const Queue *q)
{
	return q->size;
}
