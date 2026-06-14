#include "queue.h"

#include <stdio.h>
#include <string.h>

int main(void)
{
	Queue *q = queue_create();
	char cmd[32];

	if (!q)
		return 1;

	while (scanf("%31s", cmd) == 1) {
		if (strcmp(cmd, "quit") == 0)
			break;
		if (strcmp(cmd, "enqueue") == 0) {
			Job job;

			scanf("%d %31s", &job.id, job.label);
			queue_enqueue(q, &job);
		} else if (strcmp(cmd, "process") == 0) {
			Job job;

			if (queue_dequeue(q, &job) == 0)
				printf("Processing job %d: %s\n", job.id, job.label);
			else
				puts("Queue empty");
		} else if (strcmp(cmd, "status") == 0) {
			printf("size=%zu\n", queue_size(q));
		}
	}

	queue_destroy(q);
	return 0;
}
