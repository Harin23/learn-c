/*
 * Lab 4.2 — Read /proc/self/status
 */
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	FILE *fp = fopen("/proc/self/status", "r");

	if (!fp) {
		perror("fopen");
		return 1;
	}

	char line[256];
	int count = 0;

	while (fgets(line, sizeof(line), fp) && count < 10) {
		printf("%s", line);
		count++;
	}

	fclose(fp);
	printf("PID=%d PPID=%d (verify from lines above)\n", getpid(), getppid());
	return 0;
}
