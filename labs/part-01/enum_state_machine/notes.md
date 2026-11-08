# Notes — Enums and State Machines

Background for [this lab](README.md). The examples use a door, not a traffic light or a bank, so the lab itself is still yours to solve.

Every example and output below was compiled and run with GCC 15.2 (`-std=c23 -Wall -Wextra`) on 2026-11-07, except where a note says otherwise.

---

## 1. Enums: named integers

```c
typedef enum { DOOR_CLOSED, DOOR_OPEN, DOOR_LOCKED } DoorState;
```

An `enum` gives names to integer values. You get a set of constants and a type to store them in.

- **Values start at 0 and go up by 1** unless you choose them:
  ```c
  typedef enum { SIZE_SMALL = 10, SIZE_BIG, SIZE_HUGE = 50 } Size;
  ```
  Printing them shows `0 1 2` for the door and `10 11 50` for the sizes. `SIZE_BIG` follows the value before it.
- **Under the hood it's an `int`:** `sizeof(DOOR_OPEN)` and `sizeof(DoorState)` are both 4 bytes on this machine. Each constant is effectively a named `int` that can't be changed.
- **C23 lets you pick the size:** `enum Small : unsigned char { ... }` gives a 1-byte enum. Not needed yet.
- **`typedef`** lets you write `DoorState s;` instead of `enum DoorState s;`. Same trick as `Person` in the CSV lab.

### Why bother, if it's just numbers?
`if (state == 2)` tells the reader nothing. `if (state == DOOR_LOCKED)` explains itself. The compiler also knows the full list of values, and that lets it check your `switch` statements (section 3).

### The catch: C doesn't police enums
```c
DoorState s = 42;   // compiles, no warning
```
That's not a valid door state, but C accepts it, because an enum is just an integer (the test printed `s=42`). Unlike some other languages, C doesn't stop an enum variable from holding a value outside its list. It's up to your code to keep enum variables valid.

---

## 2. State machines

A **state machine** is a way to design a program around three ideas:

1. The system is in **exactly one state** at a time: the door is closed, open, or locked, never two at once.
2. **Events** happen: push, pull, lock, unlock.
3. **Transition rules** say: *in state X, when event Y happens, move to state Z*. Anything not in the rules isn't allowed.

As a diagram:

```
          open              lock
CLOSED ─────────► OPEN      CLOSED ─────────► LOCKED
CLOSED ◄───────── OPEN      CLOSED ◄───────── LOCKED
          close             unlock
```

There's no arrow from `OPEN` to `LOCKED`: you can't lock an open door. That rule is part of the design, and it's written down in one place.

### Why the design helps
Without a state machine, code tends to grow flags like `bool is_open, is_locked;`. Two flags allow four combinations, including "open **and** locked", which is impossible but representable. Bugs grow in those gaps. A single enum variable can only hold one state at a time, so impossible combinations go away.

It's also easy to test: list every (state, event) pair and check that each gives the right next state.

State machines show up all through this course: network protocols (TCP connection states), parsers, device drivers, and hardware power states in the Part 10 driver work.

---

## 3. `switch`: how C writes the rules

Transition rules are written as a `switch` on the current state:

```c
const char *name(DoorState s) {
    switch (s) {
        case DOOR_CLOSED: return "CLOSED";
        case DOOR_OPEN:   return "OPEN";
        // DOOR_LOCKED forgotten
    }
    return "?";
}
```

Compiling with `-Wall` catches the mistake:

```
warning: enumeration value 'DOOR_LOCKED' not handled in switch [-Wswitch]
```

This is the main reason to pair `enum` with `switch`: the compiler checks that every case is covered. Add a new state later and it shows every `switch` that needs updating.

### Why not rely on `default:`
Adding `default: return "other";` to the same code makes **the warning disappear**. `default:` tells the compiler "I've handled everything else", so it stops checking. The forgotten `DOOR_LOCKED` quietly becomes "other".

A stricter flag, `-Wswitch-enum`, warns even when `default:` is present (tested). For this lab, the simpler habit is to list every case and leave out `default:`.

### Two `switch` mistakes to watch for
- **Fall-through:** in C, a `case` keeps running into the next one unless you `break` or `return`. Forgetting `break` is a classic bug. GCC's `-Wimplicit-fallthrough` warns about it and is enabled by `-Wextra`. (From GCC's documentation; not tested here.)
- **Missing value after the `switch`:** the `return "?";` after the `switch` covers an invalid value like 42. Without it, the function could reach its end without returning anything.

---

## Putting it together for the lab

Four pieces, all written by you:

1. a `typedef enum` listing your states
2. a function `next_state(current)`, or `(current, event)` for the bank version, built around a `switch`
3. a `state_name()` function, also a `switch`, for printing
4. a loop in `main` that calls `next_state`, prints `OLD -> NEW`, and stops on its own

The traffic light is simpler: a cycle with no events. The bank version teaches more because of the rejected-event rule (README item 8).
