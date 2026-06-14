# Project 20: Log Parser

**Module:** 4.1 — Linux Filesystem and File I/O  
**Estimated time:** 5–6 hours

## Description

Parse Apache-style combined log lines and produce summary statistics.

## Log Format (simplified combined)

```
127.0.0.1 - alice [10/Oct/2025:13:55:36 +0000] "GET /index.html HTTP/1.1" 200 2326
```

Fields: host, ident (`-`), user, timestamp in brackets, request in quotes, status, size.

Test file: [labs/phase-04/testdata/sample.log](../../labs/phase-04/testdata/sample.log)

## Usage

```bash
logparser sample.log
logparser sample.log --errors    # status >= 400 only
logparser sample.log --top-hosts 5
```

## Output (default)

```
lines: 120
errors: 8
bytes_total: 456789
status_2xx: 100
status_4xx: 15
status_5xx: 5
```

## Requirements

- Stream file line-by-line (do not load entire file if >10MB design allows)
- Skip malformed lines with warning to stderr
- Use your Phase 3 hash map optionally for `--top-hosts`

## Rubric

| Criterion | Points |
|-----------|--------|
| Correct line/byte/status counts | 30 |
| Malformed lines handled | 15 |
| --errors filter works | 20 |
| --top-hosts works | 20 |
| Zero warnings, Makefile | 10 |
| Valgrind-clean if using heap | 5 |
| **Total** | **100** |

## Starter

Parse one line in [labs/phase-04/log_parse_starter.c](../../labs/phase-04/log_parse_starter.c)
