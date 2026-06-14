/*
 * Lab 4.3 — pthread hello
 * Compile: gcc -Wall -Wextra -std=c11 -pthread -o hello pthread_hello_starter.c
 */
#include <pthread.h>
#include <stdio.h>

static void *thread_fn(void *arg)
{
	int id = *(int *)arg;

	printf("hello from thread %d\n", id);
	return NULL;
}

int main(void)
{
	pthread_t t1, t2;
	int id1 = 1, id2 = 2;

	/* TODO: pthread_create both threads, join both */
	(void)t1;
	(void)t2;
	(void)thread_fn;
	(void)id1;
	(void)id2;

	return 0;
}
