/*
 * Lab 4.3 — Race condition counter
 * Compile: gcc -Wall -Wextra -std=c11 -pthread -o counter pthread_counter_starter.c
 */
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 4
#define INCREMENTS 100000

static long counter;
/* TODO: add pthread_mutex_t */

static void *worker(void *arg)
{
	(void)arg;

	for (int i = 0; i < INCREMENTS; i++)
		counter++;

	return NULL;
}

int main(void)
{
	pthread_t threads[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_create(&threads[i], NULL, worker, NULL);

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	printf("counter=%ld (expected %d)\n", counter,
	       NUM_THREADS * INCREMENTS);
	return 0;
}
