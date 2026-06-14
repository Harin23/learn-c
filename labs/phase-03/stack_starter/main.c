#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int apply_op(int a, int b, char op)
{
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			return 0;
		return a / b;
	default:
		return 0;
	}
}

int main(void)
{
	Stack *s = stack_create();
	char line[256];

	if (!s)
		return 1;

	while (fgets(line, sizeof(line), stdin)) {
		if (line[0] == '\n')
			break;

		if (strchr("+-*/", line[0]) && strlen(line) <= 2) {
			int b, a;

			if (stack_pop(s, &b) != 0 || stack_pop(s, &a) != 0) {
				fprintf(stderr, "stack underflow\n");
				stack_destroy(s);
				return 1;
			}
			stack_push(s, apply_op(a, b, line[0]));
		} else {
			stack_push(s, atoi(line));
		}
	}

	int result;

	if (stack_pop(s, &result) == 0)
		printf("%d\n", result);

	stack_destroy(s);
	return 0;
}
