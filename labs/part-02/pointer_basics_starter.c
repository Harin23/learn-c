/*
 * Lab 2.1 — Pointer basics starter
 * Complete the TODOs, then compile:
 *   gcc -Wall -Wextra -std=c11 -g -o pointer_basics pointer_basics_starter.c
 */
#include <stdio.h>

int main(void)
{
	int x = 42;
	int *p = &x;

	/* TODO: print value of x */
	printf("x = \n");

	/* TODO: print address of x with %%p and (void *)&x */
	printf("&x = \n");

	/* TODO: print value of p (address stored in pointer) */
	printf("p = \n");

	/* TODO: print value of *p (value at address) */
	printf("*p = \n");

	/* TODO: change x to 100 through p only */
	/* ... */

	printf("after *p = 100, x = %d\n", x);

	return 0;
}
