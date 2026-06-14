/*
 * Lab 3.4 — Binary search starter
 * Return index of target or -1.
 */
#include <stdio.h>

int binary_search(const int *arr, size_t n, int target)
{
	/* TODO: iterative binary search */
	(void)arr;
	(void)n;
	(void)target;
	return -1;
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9, 11 };

	printf("search 7 -> %d (expect 3)\n",
	       binary_search(arr, 6, 7));
	printf("search 4 -> %d (expect -1)\n",
	       binary_search(arr, 6, 4));
	return 0;
}
