/*
 * Lab 4.1 — POSIX file copy starter
 * Usage: ./copy src dst
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s src dst\n", argv[0]);
		return 1;
	}

	/* TODO: open src O_RDONLY, dst O_WRONLY|O_CREAT|O_TRUNC mode 0644 */
	/* TODO: read/write loop, close fds, handle errors with perror */
	(void)BUF_SIZE;

	return 0;
}
