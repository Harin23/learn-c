/*
 * Lab 4.3 — Raw terminal mode preview
 * Compile: gcc -Wall -Wextra -std=c11 -o termios termios_starter.c
 */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios orig;

static void disable_raw(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
}

static void enable_raw(void)
{
	struct termios raw = orig;

	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(void)
{
	if (tcgetattr(STDIN_FILENO, &orig) != 0)
		return 1;

	atexit(disable_raw);
	enable_raw();

	puts("Raw mode: type characters (q to quit)");

	for (;;) {
		char c;

		if (read(STDIN_FILENO, &c, 1) != 1)
			break;
		if (c == 'q')
			break;
		printf("got %c (%d)\n", c, c);
	}

	return 0;
}
