#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <stddef.h>

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

typedef struct {
	Student students[MAX_STUDENTS];
	int count;
} Gradebook;

void gradebook_init(Gradebook *gb);
LetterGrade letter_from_average(double avg);
int gradebook_add_student(Gradebook *gb, const Student *s);
const Student *gradebook_find_by_id(const Gradebook *gb, int id);
void gradebook_recompute_letters(Gradebook *gb);
void gradebook_list(const Gradebook *gb);

#endif /* GRADEBOOK_H */
