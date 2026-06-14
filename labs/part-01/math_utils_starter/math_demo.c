/*
 * Lab 1.3 — Math utils starter (single file to split)
 * Refactor into math_utils.c, math_utils.h, and main.c
 */
#include <stdio.h>

/* Move to math_utils.h / math_utils.c */
int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

double divide(int a, int b)
{
	return (double)a / (double)b;
}

int main(void)
{
	printf("5 + 3 = %d\n", add(5, 3));
	printf("5 - 3 = %d\n", subtract(5, 3));
	printf("5 * 3 = %d\n", multiply(5, 3));
	printf("5 / 3 = %.2f\n", divide(5, 3));
	return 0;
}
