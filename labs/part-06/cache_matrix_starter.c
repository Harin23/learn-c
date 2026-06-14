/*
 * Lab 6.5 / Project 38 — cache matrix traversal
 * Usage: ./cache_matrix row|col N
 */
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static double seconds_between(struct timespec a, struct timespec b)
{
	return (b.tv_sec - a.tv_sec) + (b.tv_nsec - a.tv_nsec) / 1e9;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s row|col N\n", argv[0]);
		return 1;
	}

	int row_major = strcmp(argv[1], "row") == 0;
	int n = atoi(argv[2]);

	if (n <= 0)
		return 1;

	double *m = calloc((size_t)n * (size_t)n, sizeof(double));

	if (!m)
		return 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m[i * n + j] = (double)(i + j);

	struct timespec t0, t1;

	clock_gettime(CLOCK_MONOTONIC, &t0);

	double sum = 0.0;

	if (row_major) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				sum += m[i * n + j];
	} else {
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				sum += m[i * n + j];
	}

	clock_gettime(CLOCK_MONOTONIC, &t1);

	printf("mode=%s n=%d sum=%.1f time=%.3f s\n", argv[1], n, sum,
	       seconds_between(t0, t1));

	free(m);
	return 0;
}
