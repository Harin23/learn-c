#include "util.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd < 0) {
		perror(argv[1]);
		return 1;
	}

	char buf[4096];
	ssize_t n = read(fd, buf, sizeof(buf) - 1);

	close(fd);

	if (n > 0) {
		buf[n] = '\0';
		printf("len=%zu data=%s\n", util_strlen(buf), buf);
	}

	return 0;
}
