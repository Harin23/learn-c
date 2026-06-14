/*
 * Lab 2.5 / Project 12 — Leaky program (intentional memory bugs)
 *
 * DO NOT FIX before running Valgrind — find bugs yourself first.
 * See BUGS.md only after attempting the lab.
 *
 * Build: make
 * Run:   valgrind --leak-check=full --show-leak-kinds=all ./leaky
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 3
#define NAME_LEN 32

typedef struct {
	char **names;
	size_t count;
} NameList;

static char *read_line(void)
{
	char buf[NAME_LEN];
	char *copy;

	if (!fgets(buf, sizeof(buf), stdin))
		return NULL;

	buf[strcspn(buf, "\n")] = '\0';

	if (buf[0] == '\0')
		return NULL;

	copy = malloc(strlen(buf) + 1);
	if (!copy)
		return NULL;

	strcpy(copy, buf);
	return copy;
}

static void name_list_init(NameList *list)
{
	list->names = malloc(MAX_NAMES * sizeof(char *));
	list->count = 0;
}

/* Takes ownership of name pointer — does not copy */
static int name_list_add(NameList *list, char *name)
{
	if (list->count >= MAX_NAMES)
		return -1;

	list->names[list->count] = name;
	list->count++;
	return 0;
}

static void name_list_print(const NameList *list)
{
	for (size_t i = 0; i < list->count; i++)
		printf("Hello, %s\n", list->names[i]);
}

static void name_list_free(NameList *list)
{
	for (size_t i = 0; i < list->count; i++) {
		free(list->names[i]);
		/* BUG 2: double free first element */
		if (i == 0)
			free(list->names[i]);
	}

	free(list->names);
}

static void process_orphan(void)
{
	char *temp = malloc(64);

	strcpy(temp, "temporary");
	printf("orphan allocated: %s\n", temp);
	/* BUG 1: memory leak — temp never freed */
}

int main(void)
{
	NameList list;
	char *line;

	name_list_init(&list);
	process_orphan();

	printf("Enter up to %d names (empty line to finish):\n", MAX_NAMES);

	while (list.count < MAX_NAMES && (line = read_line()) != NULL) {
		name_list_add(&list, line);
		/* BUG 3: use-after-free — name_list owns line but we free it here */
		free(line);
	}

	name_list_print(&list);
	printf("Processed %zu names.\n", list.count);

	name_list_free(&list);

	return 0;
}
