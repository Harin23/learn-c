#include "sort.h"

#include <stdio.h>

static void print_arr(const int *arr, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[] = { 5, 2, 4, 1, 3, 8, 0 };

	merge_sort(arr, 7);
	print_arr(arr, 7);
	return 0;
}
