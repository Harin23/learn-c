/*
 * Lab 2.5 — Buffer overflow demonstration
 * Compile: gcc -Wall -Wextra -std=c11 -g -O0 -o overflow buffer_overflow_demo.c
 * Debug with GDB watchpoint on 'guard' to catch the overwrite.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
	int guard = 0xBEEF;
	char buf[8];

	printf("guard before: 0x%x (at %p)\n", guard, (void *)&guard);
	printf("Enter short text: ");

	/* BUG: unbounded read — try input longer than 7 chars */
	if (fgets(buf, sizeof(buf), stdin) == NULL)
		return 1;

	buf[strcspn(buf, "\n")] = '\0';
	printf("you entered: %s\n", buf);
	printf("guard after:  0x%x\n", guard);

	if (guard != 0xBEEF)
		printf("guard corrupted — stack buffer overflow occurred\n");

	return 0;
}
