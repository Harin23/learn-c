/*
 * Lab 4.2 — Parse /proc/[pid]/stat fields
 * Usage: ./proc_stat [pid]
 * Field reference: man 5 proc
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid = argc > 1 ? atoi(argv[1]) : getpid();
	char path[64];
	char buf[4096];

	snprintf(path, sizeof(path), "/proc/%d/stat", pid);

	FILE *fp = fopen(path, "r");

	if (!fp) {
		perror("fopen");
		return 1;
	}

	if (!fgets(buf, sizeof(buf), fp)) {
		fprintf(stderr, "read failed\n");
		return 1;
	}

	fclose(fp);

	/* TODO: parse comm (in parens), state char, ppid, utime, stime */
	printf("raw (truncated): %.80s...\n", buf);

	return 0;
}
