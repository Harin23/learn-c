#include "list.h"

#include <stdio.h>

int main(void)
{
	List *list = list_create();

	if (!list)
		return 1;

	list_prepend(list, 3);
	list_prepend(list, 1);
	list_append(list, 5);
	list_print(list);
	printf("length=%zu contains 3=%d\n", list_length(list),
	       list_contains(list, 3));
	list_remove(list, 3);
	list_print(list);

	list_destroy(list);
	return 0;
}
