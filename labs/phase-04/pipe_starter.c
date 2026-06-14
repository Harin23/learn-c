/*
 * Lab 4.4 — Pipe demo (same process)
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int fds[2];

	if (pipe(fds) != 0) {
		perror("pipe");
		return 1;
	}

	const char *msg = "hello through pipe";
	write(fds[1], msg, strlen(msg));
	close(fds[1]);

	char buf[64];
	ssize_t n = read(fds[0], buf, sizeof(buf) - 1);

	if (n > 0) {
		buf[n] = '\0';
		printf("read: %s\n", buf);
	}

	close(fds[0]);
	return 0;
}
