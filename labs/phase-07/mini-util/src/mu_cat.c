/*
 * mu-cat — minimal cat (practice codebase)
 */
#include "common.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc > 2) {
		fprintf(stderr, "usage: %s [file]\n", argv[0]);
		return 1;
	}

	FILE *fp = stdin;

	if (argc == 2) {
		fp = fopen(argv[1], "r");
		if (!fp) {
			mu_die_perror(argv[1]);
			return 1;
		}
	}

	/* BUG #2: fgets truncates lines longer than MU_BUF_SIZE-1 */
	char buf[MU_BUF_SIZE];

	while (fgets(buf, sizeof(buf), fp) != NULL)
		fputs(buf, stdout);

	if (fp != stdin)
		fclose(fp);

	return 0;
}
