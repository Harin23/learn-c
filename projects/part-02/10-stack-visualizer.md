# Project 10: Stack Frame Visualizer

**Module:** 2.3 — Memory Layout: Stack vs Heap  
**Estimated time:** 4–5 hours

## Description

Write a program that visualizes stack frame addresses during recursion and contrasts them with heap allocations.

## Requirements

### Functional

1. Implement recursive function `void show_stack(int depth, int max_depth)` that:
   - Declares a local `int frame_marker`
   - Prints depth, address of `frame_marker` with `%p`, and address of the function itself if desired
   - Recurses until `depth == max_depth`

2. In `main`:
   - Allocate an `int` on the heap with `malloc`
   - Print heap address and several stack addresses
   - Call `show_stack(0, 5)` (or user-provided depth via argv)
   - Print label indicating whether stack addresses increase or decrease (platform-dependent — document your observation)

3. Optional: print address of a `static` local and a global for comparison

### Output Format

```
=== Memory Layout Report ===
global_var     at 0x...
static_var     at 0x...
heap_var       at 0x...
main_local     at 0x...
stack frame 0  marker at 0x...
stack frame 1  marker at 0x...
...
Stack direction: toward lower addresses (example)
```

## Technical Requirements

- Cast all addresses to `(void *)` for `%p`
- Compile with `-g -O0` for stable debugging
- Include README explaining stack vs heap findings on your machine

## Rubric

| Criterion | Points |
|-----------|--------|
| Recursive stack addresses printed correctly | 30 |
| Heap vs stack addresses both shown | 20 |
| Global/static comparison included | 15 |
| Written explanation of stack direction | 15 |
| Uses GDB `info frame` screenshot or transcript in README | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## GDB Exercise (Required)

Run under GDB at deepest recursion:

```
break show_stack
run 5
info frame
info locals
backtrace
```

Paste relevant output in project README.

## Extension (Optional)

Add a function that incorrectly returns pointer to local; show Valgrind/GDB failure mode briefly.
