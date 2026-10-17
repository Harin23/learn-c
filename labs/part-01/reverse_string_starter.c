/*
 * Lab 1.4 — Reverse string starter
 * Implement reverse_string() using index-based swapping only.
 *
 * Compile: gcc -Wall -Wextra -std=c11 -o reverse reverse_string_starter.c
 */
#include <stdio.h>
#include <string.h>

void reverse_string(char *s)
{
	int len = strlen(s);
	char reversed[strlen(s)];
	for (int i=0; i<len; i++) {
		// printf("%c\n", s[len-1-i]);
		reversed[i] = s[len-1-i];
		// printf("%c\n", reversed[i]);
	}
	for (int i=0; i<len; i++) {
		s[i] = reversed[i];
	}
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
