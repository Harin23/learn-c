#include "util.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		return 1;
	}

	char *buf = NULL;
	size_t len = 0;
	long n = util_read_file(argv[1], &buf, &len);

	if (n < 0) {
		perror("read");
		return 1;
	}

	util_chomp(buf);
	printf("%s\n", buf);
	free(buf);
	return 0;
}
