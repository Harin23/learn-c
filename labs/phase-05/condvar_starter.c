/*
 * Lab 5.4 — condition variable starter
 * Compile: gcc -Wall -Wextra -std=c11 -pthread -o condvar condvar_starter.c
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
static int ready;

static void *worker(void *arg)
{
	(void)arg;

	pthread_mutex_lock(&mtx);

	while (!ready)
		pthread_cond_wait(&cv, &mtx);

	puts("worker: got signal");
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(void)
{
	pthread_t t;

	pthread_create(&t, NULL, worker, NULL);
	sleep(1);

	pthread_mutex_lock(&mtx);
	ready = 1;
	pthread_cond_signal(&cv);
	pthread_mutex_unlock(&mtx);

	pthread_join(t, NULL);
	return 0;
}
