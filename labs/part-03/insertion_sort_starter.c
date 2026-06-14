/*
 * Lab 3.4 — Insertion sort starter
 */
#include <stdio.h>

static void print_arr(const int *arr, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertion_sort(int *arr, size_t n)
{
	/* TODO: in-place insertion sort */
	(void)arr;
	(void)n;
}

int main(void)
{
	int arr[] = { 5, 2, 4, 1, 3 };

	insertion_sort(arr, 5);
	print_arr(arr, 5);
	return 0;
}
