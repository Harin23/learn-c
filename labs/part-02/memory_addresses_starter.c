/*
 * Lab 2.3 — Memory addresses starter
 * Print addresses of global, static, stack, and heap variables.
 */
#include <stdio.h>
#include <stdlib.h>

int global_counter;

static void print_stack_local(int depth)
{
	int stack_var = depth;

	printf("stack depth %d: stack_var at %p\n", depth,
	       (void *)&stack_var);

	if (depth < 3)
		print_stack_local(depth + 1);
}

int main(void)
{
	static int static_var = 1;
	int main_local = 2;
	int *heap_var = malloc(sizeof(*heap_var));

	if (!heap_var) {
		perror("malloc");
		return 1;
	}

	*heap_var = 3;

	/* TODO: print addresses of global_counter, static_var, main_local, heap_var */
	(void)global_counter;
	(void)static_var;
	(void)main_local;

	print_stack_local(0);

	free(heap_var);
	return 0;
}
