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
	int lines = 0;
	char c, last = '\n';

	if (fd < 0) {
		perror(argv[1]);
		return 1;
	}

	while (read(fd, &c, 1) == 1) {
		if (c == '\n')
			lines++;
		last = c;
	}

	if (last != '\n')
		lines++;

	close(fd);
	printf("%d\n", lines);
	return 0;
}
