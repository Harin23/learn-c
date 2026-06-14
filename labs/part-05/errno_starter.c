/*
 * Lab 5.1 — errno demonstration
 */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int fd = open("/nonexistent_file_xyz", O_RDONLY);

	if (fd < 0) {
		fprintf(stderr, "open failed: errno=%d (%s)\n", errno,
			strerror(errno));
		return 1;
	}

	close(fd);
	return 0;
}
