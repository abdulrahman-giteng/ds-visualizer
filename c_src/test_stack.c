#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(void)
{
    printf("Creating stack...\n");
    stack_t *stack = stack_create();
    assert(stack != NULL);
    assert(stack_is_empty(stack));

    printf("Pushing elements onto stack...\n");
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    assert(!stack_is_empty(stack));

    printf("Popping elements from stack...\n");
    int value;
    assert(stack_pop(stack, &value) && value == 30);
    assert(stack_pop(stack, &value) && value == 20);
    assert(stack_pop(stack, &value) && value == 10);

    assert(stack_is_empty(stack));

    printf("Testing pop on empty stack...\n");
    assert(stack_pop(stack, &value) == 0);

    printf("Destroying stack...\n");
    stack_destroy(stack);

    printf("All tests passed ✅\n");
    return 0;
}
