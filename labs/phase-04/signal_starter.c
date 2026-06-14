/*
 * Lab 4.2 — SIGINT handler
 */
#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static volatile sig_atomic_t sigint_count;

static void on_sigint(int sig)
{
	(void)sig;
	sigint_count++;
}

int main(void)
{
	struct sigaction sa = { 0 };

	sa.sa_handler = on_sigint;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);

	puts("Press Ctrl+C three times to quit");

	while (sigint_count < 3) {
		printf("count=%d\n", sigint_count);
		sleep(1);
	}

	puts("bye");
	return 0;
}
