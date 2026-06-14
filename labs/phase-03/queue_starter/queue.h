#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct {
	int id;
	char label[32];
} Job;

typedef struct Queue Queue;

Queue *queue_create(void);
void   queue_destroy(Queue *q);
int    queue_enqueue(Queue *q, const Job *job);
int    queue_dequeue(Queue *q, Job *out);
int    queue_is_empty(const Queue *q);
size_t queue_size(const Queue *q);

#endif /* QUEUE_H */
