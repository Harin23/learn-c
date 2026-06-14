# Phase 3 — Data Structures and Algorithms

Build fundamental data structures in C and develop algorithmic thinking with performance analysis. Structures from this phase appear throughout Linux user-space and kernel code.

**Estimated time:** 70–85 hours (5 modules × 14–17 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [3.1](module-03-01-lists-stacks-queues/README.md) | Linked Lists, Stacks, and Queues | 14–17 |
| [3.2](module-03-02-hash-tables/README.md) | Hash Tables | 14–17 |
| [3.3](module-03-03-trees/README.md) | Trees | 14–17 |
| [3.4](module-03-04-algorithmic-thinking/README.md) | Algorithmic Thinking | 14–17 |
| [3.5](module-03-05-performance-analysis/README.md) | Performance Analysis | 14–17 |

## Prerequisites

Complete the [Phase 2 exit gate](../phase-02-memory-core-c/README.md#phase-exit-gate) before starting.

You should be comfortable with:

- Pointers and dynamic memory (`malloc`/`free`/`realloc`)
- Multi-file C projects with Makefiles
- Valgrind-clean heap usage
- Function pointers (for comparators and callbacks)

## Phase Exit Gate

Do not start Phase 4 until you can independently:

- Implement a singly linked list with insert, delete, and search
- Implement stack and queue ADTs with O(1) push/pop (or enqueue/dequeue)
- Implement a chained hash table with resize and string keys
- Implement a binary search tree with insert, search, and in-order traversal
- Analyze time complexity of your implementations in Big-O notation
- Choose appropriate data structures for a given problem
- Run and interpret a sort benchmark comparing O(n²) vs O(n log n) algorithms
- Submit Valgrind-clean implementations for Projects 13–17
- Complete the **Phase 3 capstone integration**: sort benchmark with written analysis ([project spec](../projects/phase-03/18-sort-benchmark.md))

## Resources

See [resources/phase-03.md](../resources/phase-03.md) for the canonical reading list.

## Projects in This Phase

| # | Project | Module | Spec |
|---|---------|--------|------|
| 13 | Singly linked list toolkit | 3.1 | [13-linked-list-toolkit.md](../projects/phase-03/13-linked-list-toolkit.md) |
| 14 | RPN calculator (stack) | 3.1 | [14-rpn-calculator.md](../projects/phase-03/14-rpn-calculator.md) |
| 15 | Job queue | 3.1 | [15-job-queue.md](../projects/phase-03/15-job-queue.md) |
| 16 | Simple hash map | 3.2 | [16-hash-map.md](../projects/phase-03/16-hash-map.md) |
| 17 | File-system tree (BST) | 3.3 | [17-bst-filesystem.md](../projects/phase-03/17-bst-filesystem.md) |
| 18 | Sort benchmark suite | 3.5 | [18-sort-benchmark.md](../projects/phase-03/18-sort-benchmark.md) |
