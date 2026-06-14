/*
 * Lab 5.3 — dup2 redirect stdout to pipe
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int fds[2];

	pipe(fds);

	pid_t pid = fork();

	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		printf("captured by pipe\n");
		fflush(stdout);
		_exit(0);
	}

	close(fds[1]);
	char buf[128];
	ssize_t n = read(fds[0], buf, sizeof(buf) - 1);

	if (n > 0) {
		buf[n] = '\0';
		printf("parent got: %s", buf);
	}

	close(fds[0]);
	waitpid(pid, NULL, 0);
	return 0;
}
