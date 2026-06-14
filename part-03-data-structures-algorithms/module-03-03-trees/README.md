# Module 3.3 — Trees

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Implement a binary search tree (BST) with insert and search
- Perform in-order, pre-order, and post-order traversals
- Explain BST ordering invariant: left < node < right
- Analyze average vs worst-case height (balanced trees preview)
- Apply a tree to model hierarchical data (file paths, symbols)

## Prerequisites

- Completed [Module 3.2](../module-03-02-hash-tables/README.md) exit criteria

## Concepts to Study

1. **Tree terminology** — root, leaf, parent, child, subtree, height, depth
2. **Binary tree** — each node has at most two children
3. **BST invariant** — all keys in left subtree < node key < all keys in right subtree
4. **Insert** — recursive or iterative descent; attach at NULL child
5. **Search** — O(h) where h is height; O(log n) balanced, O(n) skewed
6. **Traversals** — in-order yields sorted order for BST
7. **Delete** — three cases: leaf, one child, two children (successor swap); implement in project extension or lab
8. **Filesystem mapping** — path components as nested tree structure

## Hands-On Labs

### Lab 1: Manual BST Insert

On paper, insert keys `5, 3, 7, 1, 4, 6, 8` into a BST. Write in-order traversal result.

### Lab 2: Traversal Implementations

Implement recursive in-order, pre-order, post-order on the starter tree.

Starter: [labs/part-03/bst_starter/](../../labs/part-03/bst_starter/)

### Lab 3: Tree Height

Write `int bst_height(const Node *root)` recursively.

### Lab 4: Path Lookup

Given a BST keyed by string (path segment), implement `find_path` for nested lookup.

## Mini-Project

**File-System Tree (BST)** — [projects/part-03/17-bst-filesystem.md](../../projects/part-03/17-bst-filesystem.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| CLRS, Ch. 12 | Binary search trees |
| Sedgewick, Algorithms in C | Tree implementations |
| Linux VFS / dentry tree | Part 7 reading target |

## Exit Criteria

Before advancing to Module 3.4, confirm:

- [ ] BST project passes rubric
- [ ] In-order traversal prints keys in sorted order
- [ ] Search returns correct node or NULL
- [ ] Valgrind-clean after tree destroy
- [ ] You can explain worst-case skewed BST degenerating to linked list

## Next Module

[Module 3.4 — Algorithmic Thinking](../module-03-04-algorithmic-thinking/README.md)
