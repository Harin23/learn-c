# Module 3.2 — Hash Tables

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain hashing, hash functions, and collision resolution
- Implement a chained hash table with dynamic resize
- Compute load factor and choose bucket count
- Handle string keys with a simple hash function (djb2 or FNV-1a)
- Compare average O(1) lookup vs worst-case O(n)

## Prerequisites

- Completed [Module 3.1](../module-03-01-lists-stacks-queues/README.md) exit criteria

## Concepts to Study

1. **Hash function** — maps key → bucket index; should spread keys uniformly
2. **Collision** — two keys map to same bucket; inevitable with finite buckets
3. **Separate chaining** — each bucket is a linked list of entries
4. **Load factor** — `n / buckets`; resize when threshold exceeded (e.g. 0.75)
5. **Resize/rehash** — allocate new bucket array, re-insert all entries
6. **Key ownership** — copy keys into table or document borrow semantics
7. **NULL values** — decide if table stores `void*` or typed values; handle missing keys
8. **Linux connection** — kernel hash tables, `hlist`, dentry cache (Phase 7 preview)

## Hands-On Labs

### Lab 1: Hash Function Experiments

Implement djb2 hash for strings. Print bucket indices for a set of test words with `bucket_count = 8`. Observe clustering.

Starter: [labs/phase-03/hash_fn_starter.c](../../labs/phase-03/hash_fn_starter.c)

### Lab 2: Collision Counting

Given fixed buckets and 100 random keys, count collisions. Relate to load factor.

### Lab 3: Hash Map Starter

Complete insert, get, delete, and resize in the starter.

Starter: [labs/phase-03/hashmap_starter/](../../labs/phase-03/hashmap_starter/)

### Lab 4: Word Frequency

Use your hash map to count word frequencies in a text file. Print top 10 words.

## Mini-Project

**Simple Hash Map** — [projects/phase-03/16-hash-map.md](../../projects/phase-03/16-hash-map.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| *Introduction to Algorithms* (CLRS), Ch. 11 | Hash tables (optional) |
| `man hsearch` | POSIX hash — read for API comparison, implement your own |
| [djb2 hash](http://www.cse.yorku.ca/~oz/hash.html) | Classic string hash |

## Exit Criteria

Before advancing to Module 3.3, confirm:

- [ ] Hash map project passes rubric
- [ ] Resize triggers correctly when load factor exceeds threshold
- [ ] Delete removes key and frees memory
- [ ] Valgrind-clean on insert/get/delete stress test
- [ ] You can explain chaining vs open addressing (implement chaining only)

## Next Module

[Module 3.3 — Trees](../module-03-03-trees/README.md)
