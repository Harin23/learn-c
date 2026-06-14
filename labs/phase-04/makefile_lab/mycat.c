#include "util.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s file...\n", argv[0]);
		return 1;
	}

	char buf[4096];

	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);

		if (fd < 0) {
			perror(argv[i]);
			continue;
		}

		ssize_t n;

		while ((n = read(fd, buf, sizeof(buf))) > 0)
			write(STDOUT_FILENO, buf, (size_t)n);

		close(fd);
	}

	return 0;
}
