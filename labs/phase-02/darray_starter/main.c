#include "darray.h"

#include <stdio.h>

int main(void)
{
	IntArray a;

	ia_init(&a);

	int value;

	while (scanf("%d", &value) == 1) {
		if (ia_append(&a, value) != 0) {
			fprintf(stderr, "append failed\n");
			break;
		}
	}

	printf("count=%zu\n", ia_length(&a));

	for (size_t i = 0; i < ia_length(&a); i++) {
		int v;

		if (ia_get(&a, i, &v) == 0)
			printf("%d ", v);
	}

	printf("\n");
	ia_free(&a);
	return 0;
}
