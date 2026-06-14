#include "hashmap.h"

#include <stdlib.h>

struct HashMap {
	/* TODO: buckets array, bucket count, entry count */
	size_t size;
};

HashMap *map_create(size_t initial_buckets)
{
	(void)initial_buckets;
	HashMap *map = malloc(sizeof(*map));

	if (!map)
		return NULL;
	map->size = 0;
	return map;
}

void map_destroy(HashMap *map)
{
	free(map);
}

int map_set(HashMap *map, const char *key, const char *value)
{
	(void)map;
	(void)key;
	(void)value;
	return -1;
}

const char *map_get(const HashMap *map, const char *key)
{
	(void)map;
	(void)key;
	return NULL;
}

int map_delete(HashMap *map, const char *key)
{
	(void)map;
	(void)key;
	return -1;
}

size_t map_size(const HashMap *map)
{
	return map->size;
}
