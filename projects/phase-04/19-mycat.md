# Project 19: mycat — cat Clone

**Module:** 4.1 — Linux Filesystem and File I/O  
**Estimated time:** 3–4 hours

## Description

Implement a simplified `cat` utility using POSIX `open`/`read`/`write` (not stdio for the core loop).

## Usage

```bash
mycat [file...]          # print files to stdout
mycat                    # copy stdin to stdout
mycat -n file            # optional: line numbers
```

## Requirements

- Buffer size 4096 bytes
- If no files given, read stdin until EOF
- Multiple files concatenated in order
- On open failure: print `perror` message, exit non-zero
- Optional `-n`: prefix each line with line number (extension for rubric bonus)

## Rubric

| Criterion | Points |
|-----------|--------|
| Single file and stdin modes work | 30 |
| Multiple files concatenated | 20 |
| Uses open/read/write/close | 25 |
| Error handling with errno | 15 |
| Zero warnings | 10 |
| **Total** | **100** |

## Verification

```bash
./mycat file.txt
diff <(./mycat file.txt) file.txt
./mycat < file.txt
```

## Starter

[labs/phase-04/copy_starter.c](../../labs/phase-04/copy_starter.c)
