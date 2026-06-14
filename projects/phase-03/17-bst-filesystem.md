# Project 17: File-System Tree (BST)

**Module:** 3.3 — Trees  
**Estimated time:** 6–7 hours

## Description

Model a hierarchical file system using a BST keyed by name at each directory level, or a single BST where keys are full paths. **Recommended:** tree of nodes where each node has a name, optional file payload, and BST of child directories by name.

## Simplified Model (Recommended)

```c
typedef struct FsNode {
    char name[64];
    int is_file;              /* 0 = directory, 1 = file */
    struct FsNode *left;      /* sibling BST by name — or use child tree */
    struct FsNode *right;
    struct FsNode *children;  /* BST of child nodes for directories */
} FsNode;
```

**Alternative (simpler):** Single BST keyed by full path string (`/home/alice/docs/report.txt`).

Choose one approach; document in README.

## Commands (main.c)

```
mkdir /home/alice
mkdir /home/alice/docs
touch /home/alice/docs/readme.txt
ls /home/alice/docs
find /home
tree
```

Minimum required:
- `mkdir <path>` — create intermediate directories
- `touch <path>` — create file leaf
- `ls <path>` — list children sorted by name (in-order traversal)
- `tree` — print indented tree from root

## Rubric

| Criterion | Points |
|-----------|--------|
| mkdir creates nested paths | 25 |
| touch creates files at paths | 15 |
| ls prints sorted children | 20 |
| tree prints readable hierarchy | 15 |
| Search/lookup by path works | 10 |
| Valgrind-clean destroy entire tree | 10 |
| Zero warnings | 5 |
| **Total** | **100** |

## Test Sequence

```
mkdir /tmp/a
mkdir /tmp/a/b
touch /tmp/a/b/file.txt
touch /tmp/a/hello.txt
ls /tmp/a
tree
```

## Starter

[labs/phase-03/bst_starter/](../../labs/phase-03/bst_starter/)

## Extension (Optional)

Implement `rm <path>` for files and empty directories.
