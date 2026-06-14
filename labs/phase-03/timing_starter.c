/*
 * Lab 3.5 — Timing with clock_gettime
 * Compile: gcc -Wall -Wextra -std=c11 -o timing timing_starter.c
 */
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>

static double seconds_between(struct timespec a, struct timespec b)
{
	return (b.tv_sec - a.tv_sec) + (b.tv_nsec - a.tv_nsec) / 1e9;
}

int main(void)
{
	struct timespec start, end;
	volatile long sum = 0;

	clock_gettime(CLOCK_MONOTONIC, &start);

	/* TODO: replace with insertion_sort on large array for real benchmark */
	for (long i = 0; i < 100000000L; i++)
		sum += i;

	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("elapsed: %.3f seconds (sum=%ld)\n", seconds_between(start, end),
	       sum);
	return 0;
}
