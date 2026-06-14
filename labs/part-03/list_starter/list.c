#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct List {
	/* TODO: add head pointer (and optionally tail) */
	int placeholder;
};

List *list_create(void)
{
	List *list = malloc(sizeof(*list));

	if (!list)
		return NULL;

	/* TODO: initialize empty list */
	return list;
}

void list_destroy(List *list)
{
	/* TODO: free all nodes and list */
	free(list);
}

int list_prepend(List *list, int value)
{
	(void)list;
	(void)value;
	return -1;
}

int list_append(List *list, int value)
{
	(void)list;
	(void)value;
	return -1;
}

int list_remove(List *list, int value)
{
	(void)list;
	(void)value;
	return -1;
}

int list_contains(const List *list, int value)
{
	(void)list;
	(void)value;
	return 0;
}

size_t list_length(const List *list)
{
	(void)list;
	return 0;
}

void list_print(const List *list)
{
	(void)list;
	printf("[]\n");
}
