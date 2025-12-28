#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(void)
{
    stack_t *stack = stack_create();
    assert(stack != NULL);

    // Push integers 1, 2, 3 onto the stack
    for (int i = 1; i <= 3; i++)
    {
        int *x = malloc(sizeof(int));
        assert(x != NULL);
        *x = i;
        stack_push(stack, x);
    }

    // Pop and check values
    for (int expected = 3; expected >= 1; expected--)
    {
        void *data;
        assert(stack_pop(stack, &data)); // Ensure pop succeeded
        int *value = data;
        assert(*value == expected); // Check if the popped value is as expected
        free(value);                // Free the allocated integer
    }

    assert(stack_is_empty(stack)); // Stack should be empty now
    stack_destroy(stack);

    printf("All stack tests passed!\n");
    return 0;
}
