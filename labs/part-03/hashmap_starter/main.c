#include "hashmap.h"

#include <stdio.h>

int main(void)
{
	HashMap *map = map_create(8);

	if (!map)
		return 1;

	map_set(map, "name", "Alice");
	map_set(map, "city", "Paris");

	const char *name = map_get(map, "name");

	if (name)
		printf("name=%s\n", name);

	printf("size=%zu\n", map_size(map));
	map_destroy(map);
	return 0;
}
