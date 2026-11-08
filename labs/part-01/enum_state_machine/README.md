# Lab 1.4 — Enum State Machine

Model a system that is always in exactly one state and moves between states by fixed rules. Use `enum` for the states and `switch` for the transitions, and print every state change.

From [Module 1.4](../../part-01-programming-foundations/module-01-04-arrays-structs/README.md#lab-3-enum-state-machine):

> Implement a traffic light or bank transaction state machine using `enum` for states and `switch` for transitions. Log each state change to stdout.

## What this lab teaches

- **`enum`**: readable named constants and their underlying integer values (Concept 8)
- **`typedef`**: giving the enum type a short name (Concept 9)
- **`switch`**: choosing behavior by state, and letting the compiler catch states you forgot
- **Program design**: separating *what state we're in* from *what happens next*, and making invalid states or moves impossible or visible

## Requirements

Items 1–4 come straight from the module brief. Items 5–9 were added to practice this module's concepts; they are not in the module README.

### Core (from the module brief)

1. Pick **one** system: a traffic light or a bank transaction.
2. Define the states as an `enum` with a `typedef` name. No magic numbers: never use `0`, `1`, `2` for states anywhere in the code.
3. Write a function that takes the current state (and, for the bank version, an event) and returns the next state. It must use a `switch` on the state.
4. Print every state change to stdout, using names, not numbers. For example: `GREEN -> YELLOW`.

### Practice (added for this lab)

5. Write a function that converts a state to its name (`const char *`) using a `switch`. Use it for all printing.
6. Handle every enum value explicitly in each `switch`. Don't use `default:` to hide missing cases. Compile with `-Wall -Wextra` (`-Wall` turns on `-Wswitch`, which warns when an enum value has no `case`), and get zero warnings.
7. The program must end on its own: run a fixed number of steps (traffic light) or stop at a final state (bank).
8. Bank version only: an event that isn't allowed in the current state (for example, a withdrawal before the transaction is authorized) is rejected with a message, and the state stays the same.
9. Print each state's underlying integer value once at startup (for example, `RED = 0`), so you can see what an `enum` really is.

## Suggested layout

```
labs/part-01/enum_state_machine/
├── README.md
└── state_machine.c
```

One `.c` file is enough. A `Makefile` is optional (you built one in Lab 1.3).

## Done when

- [ ] Builds with `gcc -std=c23 -Wall -Wextra -Wpedantic` with zero warnings
- [ ] Every transition is printed with state names
- [ ] Every `switch` lists every enum value
- [ ] The program terminates without input or Ctrl-C
- [ ] (Bank version) an invalid event is rejected and logged
- [ ] You can explain: what integer an enum constant is, why `default:` can hide bugs, and why a state machine is easier to test than a pile of `if` flags
