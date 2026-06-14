#include "io.h"

#include <stdio.h>

/* TODO: implement CSV save — see projects/part-01/07-gradebook-capstone.md */
int io_save_csv(const Gradebook *gb, const char *path)
{
	(void)gb;
	(void)path;
	fprintf(stderr, "io_save_csv not implemented\n");
	return -1;
}

/* TODO: implement CSV load */
int io_load_csv(Gradebook *gb, const char *path)
{
	(void)gb;
	(void)path;
	fprintf(stderr, "io_load_csv not implemented\n");
	return -1;
}
