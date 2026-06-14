#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack *stack_create(void);
void   stack_destroy(Stack *s);
int    stack_push(Stack *s, int value);
int    stack_pop(Stack *s, int *out);
int    stack_peek(const Stack *s, int *out);
int    stack_is_empty(const Stack *s);

#endif /* STACK_H */
