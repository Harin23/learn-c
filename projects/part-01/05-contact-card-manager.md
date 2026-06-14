# Project 5: Contact Card Manager

**Module:** 1.4 — Arrays, Strings, Structs, and Enums  
**Estimated time:** 4–5 hours

## Description

Build an in-memory contact manager using structs, fixed arrays, and bounded string handling.

## Data Model

```c
#define MAX_NAME_LEN 64
#define MAX_CONTACTS 50

typedef enum {
    CONTACT_ACTIVE,
    CONTACT_DELETED
} ContactStatus;

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
    int age;
    ContactStatus status;
} Contact;
```

## Menu

```
Contact Manager
1. Add contact
2. List contacts
3. Search by name
4. Delete contact
5. Quit
```

### Operations

- **Add:** Prompt for name, email, age. Reject if roster full (50 contacts).
- **List:** Print all active contacts (skip deleted).
- **Search:** Partial name match (case-sensitive is fine); print matches.
- **Delete:** Mark contact as `CONTACT_DELETED` (soft delete); do not shift array.

## Technical Requirements

- Use `snprintf` or `strncpy` with explicit null termination
- No unbounded string functions (`gets`, unbounded `strcpy`)
- Single-file or multi-file (your choice)

## Rubric

| Criterion | Points |
|-----------|--------|
| Add/list/search/delete work correctly | 40 |
| Soft delete preserves array slots | 15 |
| Bounded string handling (no overflows) | 25 |
| Uses struct and enum appropriately | 10 |
| Handles full roster gracefully | 10 |
| **Total** | **100** |

## Test Cases

1. Add 3 contacts, list all — 3 shown
2. Delete contact #2, list — 2 shown
3. Search partial name "Ali" matches "Alice"
4. Add 51st contact — error message, no crash

Sample CSV for parser lab (not required for this project): [sample_contacts.csv](../../labs/part-01/sample_contacts.csv)

## Extension (Optional)

Save/load contacts to a text file on quit/startup.
