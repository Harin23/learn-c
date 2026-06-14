# Module 3.1 — Linked Lists, Stacks, and Queues

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Implement a singly linked list with dynamic allocation
- Implement stack and queue abstract data types
- Choose linked structures vs arrays for a given use case
- Manage ownership of heap nodes (allocate on insert, free on remove)
- Draw pointer diagrams for list operations before coding

## Prerequisites

- Completed [Part 2 exit gate](../../part-02-memory-core-c/README.md#part-exit-gate)
- Dynamic array project ([Project 9](../../projects/part-02/09-dynamic-array.md)) completed or equivalent

## Concepts to Study

1. **Singly linked list** — node struct with `data` and `next` pointer
2. **Head pointer** — empty list is `NULL`; always update head on prepend
3. **Insertion** — prepend O(1), append O(n) without tail pointer
4. **Deletion** — find predecessor or use dummy head node technique
5. **Stack ADT** — LIFO; push/pop at head of list or top of array
6. **Queue ADT** — FIFO; array ring buffer or list with head/tail
7. **Memory ownership** — each node `malloc`'d; `free` on removal; free entire list on destroy
8. **Iterator pattern** — walk list with `for (Node *p = head; p; p = p->next)`

## Hands-On Labs

### Lab 1: Node Diagrams on Paper

Before coding, draw diagrams for:
- Insert at head
- Delete middle node
- Empty list after deleting last node

### Lab 2: Singly Linked List Starter

Complete the linked list API in the starter code.

Starter: [labs/part-03/list_starter/](../../labs/part-03/list_starter/)

### Lab 3: Stack with Linked List Backend

Implement push/pop/peek using a linked list (no array). Verify LIFO order.

Starter: [labs/part-03/stack_starter/](../../labs/part-03/stack_starter/)

### Lab 4: Queue with Circular Buffer

Implement a queue using a fixed-capacity ring buffer with `malloc`'d storage, or a linked queue with tail pointer.

Starter: [labs/part-03/queue_starter/](../../labs/part-03/queue_starter/)

## Mini-Projects

Complete all three — they reinforce different ADTs from the same module:

1. **Singly Linked List Toolkit** — [projects/part-03/13-linked-list-toolkit.md](../../projects/part-03/13-linked-list-toolkit.md)
2. **RPN Calculator** — [projects/part-03/14-rpn-calculator.md](../../projects/part-03/14-rpn-calculator.md)
3. **Job Queue** — [projects/part-03/15-job-queue.md](../../projects/part-03/15-job-queue.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Chapter 5 | Linked structures |
| *Algorithms in C* (Sedgewick) Part 3 | Lists, stacks, queues |
| Linux kernel `list.h` | Preview for Part 7 — doubly linked lists |

## Exit Criteria

Before advancing to Module 3.2, confirm:

- [ ] All three mini-projects pass their rubrics
- [ ] Valgrind reports no leaks on list destroy and queue drain
- [ ] You can draw head/tail pointer updates for insert and delete
- [ ] RPN calculator evaluates `3 4 + 2 *` correctly (= 14)
- [ ] You can explain when a linked list beats a dynamic array

## Next Module

[Module 3.2 — Hash Tables](../module-03-02-hash-tables/README.md)
