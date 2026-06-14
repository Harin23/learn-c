#ifndef DARRAY_H
#define DARRAY_H

#include <stddef.h>

typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} IntArray;

void ia_init(IntArray *a);
void ia_free(IntArray *a);
int ia_append(IntArray *a, int value);
int ia_get(const IntArray *a, size_t index, int *out);
size_t ia_length(const IntArray *a);

#endif /* DARRAY_H */
