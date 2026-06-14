#include "sort.h"

#include <stdlib.h>
#include <string.h>

void insertion_sort(int *arr, size_t n)
{
	for (size_t i = 1; i < n; i++) {
		int key = arr[i];
		size_t j = i;

		while (j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

static void merge(int *arr, int *tmp, size_t lo, size_t mid, size_t hi)
{
	(void)arr;
	(void)tmp;
	(void)lo;
	(void)mid;
	(void)hi;
	/* TODO: merge tmp[lo..mid] and tmp[mid+1..hi] into arr */
}

static void merge_sort_rec(int *arr, int *tmp, size_t lo, size_t hi)
{
	if (lo >= hi)
		return;

	size_t mid = lo + (hi - lo) / 2;

	merge_sort_rec(arr, tmp, lo, mid);
	merge_sort_rec(arr, tmp, mid + 1, hi);
	merge(arr, tmp, lo, mid, hi);
}

void merge_sort(int *arr, size_t n)
{
	if (n == 0)
		return;

	int *tmp = malloc(n * sizeof(*tmp));

	if (!tmp)
		return;

	memcpy(tmp, arr, n * sizeof(*tmp));
	merge_sort_rec(arr, tmp, 0, n - 1);
	free(tmp);
}
