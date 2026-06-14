# Project 6: Word Counter CLI

**Module:** 1.4 — Arrays, Strings, Structs, and Enums  
**Estimated time:** 3–4 hours

## Description

Implement a simplified version of the Unix `wc` utility that counts lines, words, and characters in text input.

## Requirements

### Functional

1. If no arguments: read from **stdin** until EOF (Ctrl+D).
2. If one filename argument: read from that file.
3. Print three counts in format matching `wc`:
   ```
        lines   words  chars filename
   ```
   Omit filename when reading stdin.

### Definitions (match `wc` behavior)

- **Line:** count of newline characters (`\n`)
- **Word:** sequence of non-whitespace characters separated by whitespace
- **Character:** total bytes read (including newlines)

### Error Handling

- File not found: print error to stderr, exit code 1
- More than one filename: print usage message (extension: support multiple files)

## Technical Requirements

- Use `fgetc` or `fgets` for reading (not `scanf` for whole file)
- Single file: `wc_clone.c`
- Compare output to system `wc` on test files

Test files provided:

- [labs/part-01/testdata/simple.txt](../../labs/part-01/testdata/simple.txt)
- [labs/part-01/testdata/multiline.txt](../../labs/part-01/testdata/multiline.txt)

## Rubric

| Criterion | Points |
|-----------|--------|
| Line count matches `wc -l` | 25 |
| Word count matches `wc -w` | 25 |
| Character count matches `wc -c` | 25 |
| Stdin and file modes work | 15 |
| Error handling for missing file | 10 |
| **Total** | **100** |

## Verification

```bash
gcc -Wall -Wextra -std=c11 -o wc_clone wc_clone.c
./wc_clone labs/part-01/testdata/simple.txt
wc labs/part-01/testdata/simple.txt
# Compare outputs
```

## Extension (Optional)

Support multiple filenames and print a total line like `wc file1 file2`.
