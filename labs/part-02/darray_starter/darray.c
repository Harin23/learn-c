#include "darray.h"

#include <stdlib.h>

void ia_init(IntArray *a)
{
	a->data = NULL;
	a->size = 0;
	a->capacity = 0;
}

void ia_free(IntArray *a)
{
	/* TODO: free and reset fields */
	(void)a;
}

int ia_append(IntArray *a, int value)
{
	/* TODO: grow when full, append value */
	(void)a;
	(void)value;
	return -1;
}

int ia_get(const IntArray *a, size_t index, int *out)
{
	/* TODO: bounds check, copy value to *out */
	(void)a;
	(void)index;
	(void)out;
	return -1;
}

size_t ia_length(const IntArray *a)
{
	return a->size;
}
