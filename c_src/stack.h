#ifndef STACK_H
#define STACK_H

#include "ds.h"

/* Stack is implemented using a linked list */

typedef struct {
    list_t *list;
} stack_t;

/* Create / destroy */
stack_t *stack_create(void);
void stack_destroy(stack_t *stack);

/* Stack operations */
void stack_push(stack_t *stack, void *data);
int stack_pop(stack_t *stack, void **out_data);
int stack_is_empty(const stack_t *stack);

#endif