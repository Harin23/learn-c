/*
 * Lab 2.4 — Function pointer calculator starter
 * Complete dispatch table using BinOp function pointers.
 */
#include <stdio.h>

typedef int (*BinOp)(int, int);

static int add(int a, int b)
{
	return a + b;
}

static int sub(int a, int b)
{
	return a - b;
}

static int mul(int a, int b)
{
	return a * b;
}

static int safe_div(int a, int b)
{
	if (b == 0)
		return 0;
	return a / b;
}

int main(void)
{
	/* TODO: create ops[] array of BinOp with add, sub, mul, safe_div */
	BinOp ops[] = { NULL, NULL, NULL, NULL };
	const char *labels[] = { "+", "-", "*", "/" };

	int a = 20;
	int b = 4;
	int choice = 2; /* multiply */

	if (choice < 0 || choice >= 4 || ops[choice] == NULL) {
		fprintf(stderr, "invalid op\n");
		return 1;
	}

	printf("%d %s %d = %d\n", a, labels[choice], b, ops[choice](a, b));
	return 0;
}
