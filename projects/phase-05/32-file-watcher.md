# Project 32: File Watcher (inotify)

**Module:** 5.6 — Event-Driven Programming  
**Estimated time:** 6–8 hours

## Description

Watch a directory tree and print filesystem events using `inotify` and an event loop.

## Usage

```bash
fwatch /path/to/watch
fwatch -r /path          # recursive (one level at a time or walk on CREATE)
```

## Events to Report

- `IN_CREATE`, `IN_MODIFY`, `IN_DELETE`, `IN_MOVED_FROM`, `IN_MOVED_TO`
- Print human-readable lines: `[CREATE] /path/file.txt`

## Requirements

- Use `inotify_init1(IN_NONBLOCK)` or blocking with `select`/`poll`
- Watch directory passed as argv
- Recursive mode: when directory created, add watch for it (optional depth limit)
- Run until SIGINT; clean up watches and fd
- Handle `IN_Q_OVERFLOW` with warning message

## Rubric

| Criterion | Points |
|-----------|--------|
| Detects create/modify/delete in watched dir | 35 |
| Event loop with select or poll | 20 |
| SIGINT clean exit | 15 |
| Recursive mode or documented non-recursive | 10 |
| Zero warnings | 10 |
| README test procedure | 10 |
| **Total** | **100** |

## Test

```bash
./fwatch /tmp/watchtest &
mkdir /tmp/watchtest
touch /tmp/watchtest/a.txt
echo x >> /tmp/watchtest/a.txt
rm /tmp/watchtest/a.txt
```

## Starter

[labs/phase-05/inotify_starter.c](../../labs/phase-05/inotify_starter.c)
