/*
 * Lab 5.3 — pipe between parent and child
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int fds[2];

	if (pipe(fds) != 0) {
		perror("pipe");
		return 1;
	}

	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return 1;
	}

	if (pid == 0) {
		close(fds[1]);
		char buf[64];
		ssize_t n = read(fds[0], buf, sizeof(buf) - 1);

		if (n > 0) {
			buf[n] = '\0';
			printf("child read: %s\n", buf);
		}
		close(fds[0]);
		return 0;
	}

	close(fds[0]);
	const char *msg = "hello pipe";

	write(fds[1], msg, strlen(msg));
	close(fds[1]);
	waitpid(pid, NULL, 0);
	return 0;
}
