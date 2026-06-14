# Project 7: Student Gradebook Capstone

**Module:** 1.5 — Basic Debugging and Git Fundamentals  
**Estimated time:** 6–8 hours

## Description

Phase 1 capstone project. Build a multi-file student gradebook CLI with CSV persistence, Makefile, GDB debugging practice, and Git version control.

## File Layout

```
gradebook/
├── .gitignore
├── Makefile
├── README.md
├── main.c
├── gradebook.h
├── gradebook.c
├── io.h
└── io.c
```

## Data Model

```c
#define MAX_NAME_LEN 64
#define MAX_STUDENTS 100
#define MAX_SCORES 10

typedef enum {
    GRADE_A,
    GRADE_B,
    GRADE_C,
    GRADE_D,
    GRADE_F
} LetterGrade;

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    double scores[MAX_SCORES];
    int score_count;
    LetterGrade letter;
} Student;
```

## Menu

```
Gradebook
1. Add student
2. List students
3. Show student (by ID)
4. Compute/update letter grades
5. Save to CSV
6. Load from CSV
7. Quit
```

### Operations

- **Add student:** name, numeric ID, up to 10 scores (0–100). Compute average and letter grade on add.
- **List:** print ID, name, average, letter grade for all students.
- **Show:** print full detail including all scores for one ID.
- **Compute/update:** recalculate letter grades for all students from averages.
- **Save/Load:** persist to `gradebook.csv` (default filename).

### Letter Grade Scale

| Average | Grade |
|---------|-------|
| 90–100 | A |
| 80–89 | B |
| 70–79 | C |
| 60–69 | D |
| 0–59 | F |

## CSV Format

One student per line:

```
id,name,score1,score2,...,scoreN
```

Example:

```
101,Alice,88,92,90
102,Bob,72,68,75
```

- Load on startup if `gradebook.csv` exists (optional but recommended)
- Save should overwrite the file completely

## Makefile Targets

| Target | Purpose |
|--------|---------|
| `all` | Build `gradebook` binary |
| `clean` | Remove build artifacts |
| `debug` | Build with `-g -O0` explicitly |

## Git Requirements

- Initialize a Git repository in `gradebook/`
- Minimum **5 meaningful commits** (not one big commit)
- Suggested commit sequence: scaffold → add student logic → CSV I/O → letter grades → README/Makefile polish
- Use the repository `.gitignore` patterns for build artifacts

## GDB Requirement

During development, use GDB at least once to:

- Set a breakpoint in student add or CSV load
- Inspect a `Student` struct with `print`
- Step through a function with `step` or `next`

Document the GDB session in your project README (commands used and what you learned).

## Rubric

| Criterion | Points |
|-----------|--------|
| Add/list/show students correct | 25 |
| Letter grades computed correctly | 15 |
| CSV save/load round-trip works | 25 |
| Multi-file layout + header guards | 10 |
| Makefile (all, clean, debug) | 10 |
| Git: ≥5 logical commits | 10 |
| GDB session documented | 5 |
| Zero compiler warnings | 5 |
| **Total** | **100** |

## Test Cases

1. Add two students, list — both appear with correct averages
2. Save, quit, restart, load — data restored
3. Edit CSV manually, load — changes reflected
4. Duplicate ID on add — error message, no overwrite
5. `make clean && make` — builds without warnings

## Phase 1 Completion

Passing this project (≥80 rubric points) plus all module exit checklists completes Phase 1. You may then proceed to Phase 2 when its content is available.

## Starter Template

Optional starter files: [labs/phase-01/gradebook_starter/](../../labs/phase-01/gradebook_starter/)
