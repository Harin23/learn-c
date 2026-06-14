/*
 * Lab 5.6 — select on stdin with timeout
 */
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main(void)
{
	fd_set rfds;
	struct timeval tv = { .tv_sec = 5, .tv_usec = 0 };

	FD_ZERO(&rfds);
	FD_SET(STDIN_FILENO, &rfds);

	printf("Type something within 5 seconds...\n");

	int ret = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);

	if (ret < 0) {
		perror("select");
		return 1;
	}

	if (ret == 0) {
		puts("timeout");
		return 0;
	}

	char buf[128];

	if (fgets(buf, sizeof(buf), stdin))
		printf("got: %s", buf);

	return 0;
}
