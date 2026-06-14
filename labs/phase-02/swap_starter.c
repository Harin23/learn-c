/*
 * Lab 2.1 — Swap starter (pass-by-value version fails)
 * Fix swap so caller variables are exchanged.
 */
#include <stdio.h>

/* TODO: rewrite to void swap_int(int *a, int *b) */
void swap_int(int a, int b)
{
	int tmp = a;

	a = b;
	b = tmp;
}

int main(void)
{
	int x = 10;
	int y = 20;

	printf("before: x=%d y=%d\n", x, y);
	swap_int(x, y);
	printf("after:  x=%d y=%d (should be 20, 10)\n", x, y);

	return 0;
}
