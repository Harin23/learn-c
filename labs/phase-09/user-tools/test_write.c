/* User-space write helper for learn-c char devices */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	char buf[4096];
	ssize_t n;
	size_t len;
	int fd;

	if (argc != 2) {
		fprintf(stderr, "usage: %s /dev/device < data\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_WRONLY);
	if (fd < 0) {
		perror("open");
		return 1;
	}

	len = fread(buf, 1, sizeof(buf), stdin);
	if (len == 0 && ferror(stdin)) {
		perror("fread");
		close(fd);
		return 1;
	}

	n = write(fd, buf, len);
	if (n < 0) {
		perror("write");
		close(fd);
		return 1;
	}

	close(fd);
	return 0;
}
