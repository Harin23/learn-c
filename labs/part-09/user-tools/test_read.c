/* User-space read helper for learn-c char devices */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	char buf[4096];
	ssize_t n;
	int fd;

	if (argc != 2) {
		fprintf(stderr, "usage: %s /dev/device\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("open");
		return 1;
	}

	n = read(fd, buf, sizeof(buf) - 1);
	if (n < 0) {
		perror("read");
		close(fd);
		return 1;
	}

	buf[n] = '\0';
	printf("%s", buf);
	close(fd);
	return 0;
}
