/*
 * Lab 1.4 — Reverse string starter
 * Implement reverse_string() using index-based swapping only.
 *
 * Compile: gcc -Wall -Wextra -std=c11 -o reverse reverse_string_starter.c
 */
#include <stdio.h>
#include <string.h>

/* TODO: reverse s in place */
void reverse_string(char *s)
{
	(void)s;
}

int main(void)
{
	char buf[] = "hello";

	reverse_string(buf);
	printf("expected olleh, got: %s\n", buf);

	char buf2[] = "abcd";
	reverse_string(buf2);
	printf("expected dcba, got: %s\n", buf2);

	return 0;
}
