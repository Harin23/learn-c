# Module 6.1 — CPU Architecture and Instruction Execution

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Describe CPU components: registers, ALU, control unit, program counter
- Explain the fetch-decode-execute cycle
- Read x86-64 assembly produced by GCC for simple C functions
- Relate Phase 2 stack frames to register and stack pointer usage in assembly
- Use `objdump`, `gcc -S`, and GDB `disassemble` confidently

## Prerequisites

- Completed [Phase 5 exit gate](../../phase-05-linux-systems-programming/README.md#phase-exit-gate)
- Phase 2 stack/heap module recommended

## Concepts to Study

1. **Machine model** — instructions operate on registers and memory
2. **x86-64 registers** — `%rax`, `%rdi`, `%rsi`, `%rsp`, `%rbp`, `%rip` (preview)
3. **System V AMD64 ABI** — integer args in `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, `%r9`
4. **Stack pointer** — `%rsp` grows down; `push`/`pop`; `call`/`ret`
5. **Compilation pipeline revisited** — C → assembly → machine code → linking
6. **Endianness** — little-endian on x86
7. **Instruction types** — data movement, arithmetic, control flow (`jmp`, `je`, `call`)

## Hands-On Labs

### Lab 1: Generate Assembly

```bash
gcc -S -O0 -fno-omit-frame-pointer -o hello.s labs/phase-06/hello.c
```

Identify `main`, `call`, `ret`, and stack setup in output.

### Lab 2: objdump Binary

```bash
gcc -g -O0 -o hello labs/phase-06/hello.c
objdump -d -M intel hello | less
```

Compare Intel syntax to AT&T (`objdump -d` default).

### Lab 3: GDB disassemble

Set breakpoint in `add` function; `disassemble` and `info registers`.

Starter: [labs/phase-06/add_regs.c](../../labs/phase-06/add_regs.c)

### Lab 4: Trace a Function Call

Step through caller → callee in GDB; note `%rip`, `%rsp`, `%rbp` changes. Document in 10 lines.

## Mini-Project

**Assembly and Register Trace** — [projects/phase-06/34-assembly-trace.md](../../projects/phase-06/34-assembly-trace.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| *Computer Systems: A Programmer's Perspective* (CS:APP) Ch. 3 | Machine-level representation |
| [x86-64 ABI doc](https://wiki.osdev.org/System_V_ABI) | Calling convention |
| `man objdump` | Disassembly |

## Exit Criteria

Before advancing to Module 6.2, confirm:

- [ ] Can identify function prologue/epilogue in assembly
- [ ] Can explain where first two integer args go in registers
- [ ] Project 34 analysis document complete
- [ ] GDB stepping matched your written trace

## Next Module

[Module 6.2 — Memory Hierarchy and Virtual Memory](../module-06-02-virtual-memory/README.md)
