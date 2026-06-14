/*
 * mu-wc — minimal word/line/char counter (practice codebase)
 */
#include "common.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int count_lines(FILE *fp)
{
	int lines = 0;
	int c;
	int last = '\n';

	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n')
			lines++;
		last = c;
	}

	if (last != '\n' && last != EOF)
		lines++;

	return lines;
}

static int count_words(FILE *fp)
{
	int words = 0;
	int c;
	int in_word = 0;

	while ((c = fgetc(fp)) != EOF) {
		if (isspace(c)) {
			in_word = 0;
			/* BUG #1: counts spurious word at trailing whitespace */
			if (c == ' ')
				words++;
		} else if (!in_word) {
			in_word = 1;
			words++;
		}
	}

	return words;
}

static int count_chars(FILE *fp)
{
	int n = 0;
	int c;

	while ((c = fgetc(fp)) != EOF)
		n++;

	return n;
}

int main(int argc, char *argv[])
{
	int show_lines = 0;
	int show_words = 0;
	int show_chars = 0;

	if (argc == 1) {
		show_lines = show_words = show_chars = 1;
	} else {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-l") == 0)
				show_lines = 1;
			else if (strcmp(argv[i], "-w") == 0)
				show_words = 1;
			else if (strcmp(argv[i], "-c") == 0)
				show_chars = 1;
			else {
				fprintf(stderr, "usage: %s [-lwc] [file]\n", argv[0]);
				return 1;
			}
		}
	}

	FILE *fp = stdin;
	const char *name = NULL;

	/* file arg after flags — simplified */
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			name = argv[i];
			fp = fopen(name, "r");
			if (!fp) {
				mu_die_perror(name);
				return 1;
			}
			break;
		}
	}

	if (show_lines)
		printf("%7d", count_lines(fp));
	if (show_words)
		printf("%7d", count_words(fp));
	if (show_chars)
		printf("%7d", count_chars(fp));

	if (name)
		printf(" %s", name);

	printf("\n");

	if (fp != stdin)
		fclose(fp);

	return 0;
}
