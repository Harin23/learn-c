/*
 * Lab 3.2 — Hash function experiments (djb2)
 * Compile: gcc -Wall -Wextra -std=c11 -o hash_fn hash_fn_starter.c
 */
#include <stdio.h>
#include <string.h>

static unsigned long hash_djb2(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + (unsigned char)c;

	return hash;
}

int main(void)
{
	const char *words[] = { "linux", "kernel", "hash", "table",
				"pointer", "memory", "ubuntu", "c" };
	size_t buckets = 8;
	size_t n = sizeof(words) / sizeof(words[0]);

	for (size_t i = 0; i < n; i++) {
		unsigned long h = hash_djb2(words[i]);

		printf("%10s hash=%8lu bucket=%zu\n", words[i], h, h % buckets);
	}

	return 0;
}
