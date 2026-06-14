#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct List List;

List *list_create(void);
void  list_destroy(List *list);
int   list_prepend(List *list, int value);
int   list_append(List *list, int value);
int   list_remove(List *list, int value);
int   list_contains(const List *list, int value);
size_t list_length(const List *list);
void  list_print(const List *list);

#endif /* LIST_H */
