#include "stack.h"

#include <stdlib.h>

struct Stack {
	/* TODO: linked-list or array backend */
	int placeholder;
};

Stack *stack_create(void)
{
	Stack *s = malloc(sizeof(*s));

	if (!s)
		return NULL;
	return s;
}

void stack_destroy(Stack *s)
{
	free(s);
}

int stack_push(Stack *s, int value)
{
	(void)s;
	(void)value;
	return -1;
}

int stack_pop(Stack *s, int *out)
{
	(void)s;
	(void)out;
	return -1;
}

int stack_peek(const Stack *s, int *out)
{
	(void)s;
	(void)out;
	return -1;
}

int stack_is_empty(const Stack *s)
{
	(void)s;
	return 1;
}
