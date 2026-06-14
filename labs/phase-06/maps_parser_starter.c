/*
 * Lab 6.2 — Parse /proc/pid/maps
 * Usage: ./maps_parser [pid]
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid = getpid();

	if (argc > 1)
		pid = atoi(argv[1]);

	char path[64];

	snprintf(path, sizeof(path), "/proc/%d/maps", pid);

	FILE *fp = fopen(path, "r");

	if (!fp) {
		perror("fopen maps");
		return 1;
	}

	char line[512];

	while (fgets(line, sizeof(line), fp)) {
		/* TODO: parse and print categorized region */
		printf("%s", line);
	}

	fclose(fp);
	return 0;
}
