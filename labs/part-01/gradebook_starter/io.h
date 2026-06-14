#ifndef IO_H
#define IO_H

#include "gradebook.h"

#define DEFAULT_CSV "gradebook.csv"

int io_save_csv(const Gradebook *gb, const char *path);
int io_load_csv(Gradebook *gb, const char *path);

#endif /* IO_H */
