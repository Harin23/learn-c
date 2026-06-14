# Project 24: Mini Text Editor

**Module:** 4.3 — Threads  
**Estimated time:** 6–8 hours

## Description

A minimal terminal text editor for single-file editing with raw mode input.

## Usage

```bash
minied file.txt
```

## Key Bindings (minimum)

| Key | Action |
|-----|--------|
| Arrow keys | move cursor (optional; hjkl acceptable) |
| Character keys | insert at cursor |
| Backspace | delete before cursor |
| Ctrl+S | save file |
| Ctrl+Q | quit |

## Requirements

- Load file into memory (dynamic buffer from Phase 2 `IntArray` or growable char buffer)
- Use `termios` to disable canonical mode and echo while running; restore on exit
- Save with `open`/`write` or stdio
- Handle empty new file
- Optional: background thread autosave every 30s (pthread + mutex on buffer)

## Rubric

| Criterion | Points |
|-----------|--------|
| Load and display file | 20 |
| Insert and backspace work | 25 |
| Save persists changes | 20 |
| Terminal restored on quit/error | 15 |
| Ctrl+Q and Ctrl+S work | 10 |
| Zero warnings, -pthread if needed | 10 |
| **Total** | **100** |

## Notes

Full arrow key support requires parsing escape sequences (`\033[A`). Simpler milestone: `h/j/k/l` movement only — document in README if chosen.

## Starter

[labs/phase-04/termios_starter.c](../../labs/phase-04/termios_starter.c)
