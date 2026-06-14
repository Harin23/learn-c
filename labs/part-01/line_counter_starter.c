/*
 * Lab 1.2 — Line counter starter
 * Complete count_lines() and file handling in main().
 *
 * Compile: gcc -Wall -Wextra -std=c11 -o line_counter line_counter_starter.c
 * Usage:   ./line_counter filename
 */
#include <stdio.h>
#include <stdlib.h>

/* TODO: implement — return number of newline characters in file */
int count_lines(FILE *fp)
{
	(void)fp;
	return -1; /* replace with real implementation */
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	if (!fp) {
		perror(argv[1]);
		return 1;
	}

	int lines = count_lines(fp);
	fclose(fp);

	if (lines < 0) {
		fprintf(stderr, "count_lines not implemented yet\n");
		return 1;
	}

	printf("%d %s\n", lines, argv[1]);
	return 0;
}
