/*
 * Lab 2.2 — Grow-on-demand array starter
 * Read integers until EOF; double capacity with realloc when full.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t capacity = 4;
	size_t size = 0;
	int *data = malloc(capacity * sizeof(*data));

	if (!data) {
		perror("malloc");
		return 1;
	}

	int value;

	while (scanf("%d", &value) == 1) {
		if (size >= capacity) {
			/* TODO: double capacity with realloc; handle failure */
			(void)capacity;
		}

		data[size++] = value;
	}

	printf("count=%zu sum=", size);
	int sum = 0;

	for (size_t i = 0; i < size; i++) {
		sum += data[i];
		printf("%d ", data[i]);
	}

	printf("\nsum=%d\n", sum);

	/* TODO: free data */
	(void)data;

	return 0;
}
