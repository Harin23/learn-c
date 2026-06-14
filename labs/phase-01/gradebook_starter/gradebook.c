#include "gradebook.h"

#include <stdio.h>
#include <string.h>

void gradebook_init(Gradebook *gb)
{
	gb->count = 0;
}

LetterGrade letter_from_average(double avg)
{
	if (avg >= 90.0)
		return GRADE_A;
	if (avg >= 80.0)
		return GRADE_B;
	if (avg >= 70.0)
		return GRADE_C;
	if (avg >= 60.0)
		return GRADE_D;
	return GRADE_F;
}

int gradebook_add_student(Gradebook *gb, const Student *s)
{
	if (gb->count >= MAX_STUDENTS)
		return -1;

	if (gradebook_find_by_id(gb, s->id) != NULL)
		return -2;

	gb->students[gb->count] = *s;
	gb->count++;
	return 0;
}

const Student *gradebook_find_by_id(const Gradebook *gb, int id)
{
	for (int i = 0; i < gb->count; i++) {
		if (gb->students[i].id == id)
			return &gb->students[i];
	}
	return NULL;
}

void gradebook_recompute_letters(Gradebook *gb)
{
	for (int i = 0; i < gb->count; i++) {
		Student *s = &gb->students[i];
		double sum = 0.0;

		for (int j = 0; j < s->score_count; j++)
			sum += s->scores[j];

		double avg = s->score_count > 0 ? sum / s->score_count : 0.0;
		s->letter = letter_from_average(avg);
	}
}

void gradebook_list(const Gradebook *gb)
{
	for (int i = 0; i < gb->count; i++) {
		const Student *s = &gb->students[i];
		double sum = 0.0;

		for (int j = 0; j < s->score_count; j++)
			sum += s->scores[j];

		double avg = s->score_count > 0 ? sum / s->score_count : 0.0;

		printf("%d %s avg=%.1f grade=%d\n", s->id, s->name, avg,
		       (int)s->letter);
	}
}
