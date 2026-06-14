/*
 * Gradebook capstone starter — implement menu and CSV I/O
 * See: projects/phase-01/07-gradebook-capstone.md
 */
#include "gradebook.h"
#include "io.h"

#include <stdio.h>
#include <string.h>

static void print_menu(void)
{
	puts("Gradebook");
	puts("1. Add student");
	puts("2. List students");
	puts("3. Show student (by ID)");
	puts("4. Compute/update letter grades");
	puts("5. Save to CSV");
	puts("6. Load from CSV");
	puts("7. Quit");
	printf("Choice: ");
}

int main(void)
{
	Gradebook gb;

	gradebook_init(&gb);

	/* Optional: load existing CSV on startup */
	io_load_csv(&gb, DEFAULT_CSV);

	for (;;) {
		print_menu();

		int choice = 0;
		if (scanf("%d", &choice) != 1) {
			puts("Invalid choice");
			while (getchar() != '\n')
				;
			continue;
		}

		switch (choice) {
		case 1:
			/* TODO: prompt for student fields and call gradebook_add_student */
			puts("Not implemented — add student menu");
			break;
		case 2:
			gradebook_list(&gb);
			break;
		case 3:
			puts("Not implemented — show by ID");
			break;
		case 4:
			gradebook_recompute_letters(&gb);
			puts("Letter grades updated.");
			break;
		case 5:
			if (io_save_csv(&gb, DEFAULT_CSV) == 0)
				puts("Saved.");
			break;
		case 6:
			if (io_load_csv(&gb, DEFAULT_CSV) == 0)
				puts("Loaded.");
			break;
		case 7:
			return 0;
		default:
			puts("Unknown option");
			break;
		}
	}
}
