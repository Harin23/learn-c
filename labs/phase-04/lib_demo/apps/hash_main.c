#include "util.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s string\n", argv[0]);
		return 1;
	}

	printf("hash=%lu\n", util_hash_string(argv[1]));
	return 0;
}
