# mini-util — Known Issues (for Project 41)

## Issue #1: mu-wc extra word on trailing whitespace

**Symptom:** `echo -n "hello  "` piped to `mu-wc -w` returns 2 instead of 1.

**Hint:** Inspect `count_words()` in `src/mu_wc.c` — loop boundary after whitespace run.

**Test:** `tests/run_tests.sh` test `wc_trailing_spaces`.

## Issue #2: mu-cat silent truncate on long lines

**Symptom:** Lines longer than internal buffer (128 bytes) are truncated without error.

**Hint:** `src/mu_cat.c` uses fixed `char buf[128]` with `fgets`.

**Expected fix options:**

- Increase buffer with documented limit, or
- Read with `getline`, or
- Loop `fread` like real cat

**Test:** `tests/run_tests.sh` test `cat_long_line`.

Fix one issue per commit minimum; both issues for full marks on bug-fix rubric.
