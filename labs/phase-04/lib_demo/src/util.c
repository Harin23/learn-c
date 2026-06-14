#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long util_read_file(const char *path, char **out, size_t *out_len)
{
	/* TODO: read file into malloc buffer */
	(void)path;
	(void)out;
	(void)out_len;
	return -1;
}

unsigned long util_hash_string(const char *s)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *s++))
		hash = ((hash << 5) + hash) + (unsigned char)c;

	return hash;
}

void util_chomp(char *s)
{
	size_t n = strlen(s);

	if (n > 0 && s[n - 1] == '\n')
		s[n - 1] = '\0';
}
