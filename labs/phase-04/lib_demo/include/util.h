#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

long util_read_file(const char *path, char **out, size_t *out_len);
unsigned long util_hash_string(const char *s);
void util_chomp(char *s);

#endif /* UTIL_H */
