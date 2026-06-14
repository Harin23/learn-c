/*
 * Lab 1.1 — Hello, toolchain verification
 * Compile: gcc -Wall -Wextra -std=c11 -o hello hello.c
 */
#include <stdio.h>

int main(void)
{
	printf("Hello, C on Linux!\n");
	printf("If you see this, your toolchain works.\n");
	return 0;
}
