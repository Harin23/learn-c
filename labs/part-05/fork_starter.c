/*
 * Lab 5.2 — fork starter
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return 1;
	}

	if (pid == 0) {
		/* TODO: child code */
		printf("child pid=%d\n", getpid());
		return 0;
	}

	printf("parent pid=%d child pid=%d\n", getpid(), pid);
	waitpid(pid, NULL, 0);
	return 0;
}
