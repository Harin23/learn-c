# Notes — Project 5: Contact Card Manager

Background for [Project 5](05-contact-card-manager.md). These cover the parts the project needs that earlier labs and projects haven't used yet: `strstr`, `strcspn`, `snprintf`, `->`, reading text (not numbers) from stdin, and testing with redirected input. The project itself is still yours to write.

Every example and output below was compiled and run with GCC 15.2 (`-std=c23 -Wall -Wextra -Wpedantic -Wconversion -fsanitize=address,undefined`) on 2026-11-08, except where a note says it's reasoning only.

## Already covered elsewhere

| Project 5 needs | Done in |
|---|---|
| `typedef struct`, array of structs | CSV lab (`Person personArray[MAX_LINES]`), Project 3 (`Stats`) |
| `typedef enum` + `switch` without `default:` | Lab 3 + [its notes](../../labs/part-01/enum_state_machine/notes.md) |
| Menu loop, safe number input (`fgets` + `strtol`, range + `p_err` checks) | Project 3 `read_number_in_range`, reusable for the menu choice and age |
| Bounded copy `strncpy(..., MAX-1)` | CSV lab |
| Draining an overlong line | CSV lab `fgetc` loop |

---

## 1. `strncpy` doesn't add the `'\0'` for you

The spec asks for "explicit null termination". When the source is too long, `strncpy` copies exactly `n` bytes and stops, with no terminator:

```c
char buf[8];                      // filled with 'X' first
strncpy(buf, "longername", sizeof buf - 1);
// ran: buf[7] is still 'X', so the string has no terminator
```

The CSV lab only works because `personArray = {}` zeroed every byte first (reasoning, not run). A reused contact slot or an uninitialised local won't have that. The fix is always the same two lines:

```c
strncpy(c->name, src, sizeof c->name - 1);
c->name[sizeof c->name - 1] = '\0';
```

When the source is shorter, `strncpy` pads with `'\0'` up to `n` (ran: `buf[2]`–`buf[6]` were 0, `buf[7]` untouched). GCC also warns when the copy truncates: `-Wstringop-truncation`.

## 2. `snprintf`: a bounded copy that always terminates

```c
int r = snprintf(out, sizeof out, "%s", src);
if (r < 0 || r >= (int)sizeof out) { /* error, or truncated */ }
```

Ran with `out[8]` and `"longername"`: `r=10`, `out="longern"`. The return value is the length it *would* have written, so `r >= size` means the text was cut. That's how to report "name too long, max 63 chars" without a separate check. `snprintf` always writes the `'\0'` (when size > 0).

## 3. Reading text from the keyboard: `fgets` keeps the `'\n'`

`fgets` stores `"Alice\n"`. Leave the newline in and search and list output go wrong. The usual one-liner:

```c
name[strcspn(name, "\n")] = '\0';
```

`strcspn` returns the index of the first `'\n'`, or the string's length if there isn't one, so it's safe either way (ran: `strcspn("abc", "\n")` is 3).

No `'\n'` means the input was too long. Drain the rest of the line (the CSV-lab `fgetc` loop), or the leftover becomes the answer to the *next* prompt. Ran with a 16-byte buffer and the input `AliceAliceAliceAliceAlice`: the name read as `"AliceAliceAlice"`, and the next read got `"AliceAlice\n"`.

## 4. Don't mix `scanf` and `fgets`

`scanf("%d")` (used in Projects 1 and 2) leaves the `'\n'` in the input, so a following `fgets` returns at once with an empty line. Ran: input `1⏎Alice⏎` gave `name=[\n]`. Use `fgets` everywhere (the Project 3 helper already does) and the problem can't happen.

## 5. Partial match: `strstr`

```c
if (strstr(roster[i].name, query) != NULL) { /* match */ }
```

Ran: `strstr("Alice", "Ali")` matches; `"ali"` doesn't (it's case-sensitive, which the spec allows). An empty query `""` matches everything, so decide whether pressing Enter at the search prompt lists all contacts or is rejected. Search must also skip `CONTACT_DELETED` slots.

## 6. Struct pointers and `->`

When the work is split into `add_contact(...)`, `list_contacts(...)` and so on, you pass a contact or the roster to a function. Arrays decay to a pointer, so the function changes the caller's data. Use `->` for a member through a pointer:

```c
void set_age(Contact *c, int age) { c->age = age; }   // same as (*c).age
```

Ran: writing through `p = &roster[1]` changed `roster[1]`. Project 3's `*(int *)out` was the same idea. The roster count needs it too: pass `int *count` so `add` can increase it.

## 7. Soft delete: capacity, used slots and active contacts

These are three different numbers. Design reasoning, not run:

- **`MAX_CONTACTS` (50)** is the capacity. Test 4 ("add 51st contact") means `count == MAX_CONTACTS`.
- **`count`** is slots ever used. Delete doesn't lower it ("do not shift array"), so a deleted slot still counts toward the 50 unless you choose to reuse deleted slots. Either way is fine; write the decision down.
- **Active contacts** are found by checking `status` in the loop.
- **Decide what number the user types for Delete.** If List numbers active contacts 1, 2, 3 and skips deleted ones, those numbers stop matching array indices after a delete. Showing the slot index (`i + 1`) keeps it simple. Check that the number is in range and that the slot isn't already deleted.

## 8. Test by piping input in, and handle EOF

Typing 51 contacts by hand is painful. Put the inputs in a file and run:

```
./contacts < test51.txt
```

When the input runs out, `fgets` returns `NULL` (ran). The menu loop must treat that as Quit, or it loops forever printing the menu. Project 3's helper returns 0 on EOF, but its `main` ignores the return value. Check it this time.
