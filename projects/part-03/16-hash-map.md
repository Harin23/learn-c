# Project 16: Simple Hash Map

**Module:** 3.2 — Hash Tables  
**Estimated time:** 6–7 hours

## Description

Implement a string-to-string hash map with separate chaining and automatic resize.

## File Layout

```
hashmap/
├── Makefile
├── hashmap.h
├── hashmap.c
└── main.c
```

## API (hashmap.h)

```c
typedef struct HashMap HashMap;

HashMap *map_create(size_t initial_buckets);
void     map_destroy(HashMap *map);

int map_set(HashMap *map, const char *key, const char *value);
      /* 0 ok, -1 alloc fail; updates if key exists */
const char *map_get(const HashMap *map, const char *key);
      /* NULL if missing */
int map_delete(HashMap *map, const char *key);
      /* 0 if removed, -1 if not found */
size_t map_size(const HashMap *map);
```

## Requirements

- Hash function: djb2 or FNV-1a (document choice)
- Separate chaining with linked lists per bucket
- Resize when `load_factor > 0.75` (double bucket count, rehash)
- Copy keys and values into heap storage (strings owned by map)
- `map_destroy` frees all entries and buckets

## main.c Demo

```
map_set map name Alice
map_set map city Paris
map_get map name
map_delete map city
map_size map
```

Or run word-frequency mode on a test file:

[labs/part-03/testdata/words.txt](../../labs/part-03/testdata/words.txt)

## Rubric

| Criterion | Points |
|-----------|--------|
| set/get/delete correct | 30 |
| Update existing key | 10 |
| Resize at load factor threshold | 20 |
| String keys copied/owned correctly | 15 |
| Valgrind-clean | 15 |
| Zero warnings | 10 |
| **Total** | **100** |

## Starter

[labs/part-03/hashmap_starter/](../../labs/part-03/hashmap_starter/)

## Extension (Optional)

Iterator over all keys; `map_foreach(fn)` callback.
