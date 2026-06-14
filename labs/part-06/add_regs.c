#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int main(void)
{
	printf("add(3,4)=%d\n", add(3, 4));
	printf("factorial(5)=%d\n", factorial(5));
	return 0;
}
