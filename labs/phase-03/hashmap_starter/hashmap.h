#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

typedef struct HashMap HashMap;

HashMap *map_create(size_t initial_buckets);
void     map_destroy(HashMap *map);
int      map_set(HashMap *map, const char *key, const char *value);
const char *map_get(const HashMap *map, const char *key);
int      map_delete(HashMap *map, const char *key);
size_t   map_size(const HashMap *map);

#endif /* HASHMAP_H */
