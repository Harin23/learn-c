#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define MU_BUF_SIZE 128

static inline void mu_die_perror(const char *msg)
{
	perror(msg);
}

#endif /* COMMON_H */
