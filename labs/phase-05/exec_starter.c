/*
 * Lab 5.2 — exec starter
 * Usage: ./exec_demo [args...]
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return 1;
	}

	if (pid == 0) {
		/* TODO: execvp first arg or default "ls" */
		char *default_argv[] = { "ls", "-l", NULL };

		execvp(default_argv[0], default_argv);
		perror("execvp");
		_exit(127);
	}

	int status;

	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
		printf("child exited with %d\n", WEXITSTATUS(status));

	(void)argc;
	(void)argv;
	return 0;
}
