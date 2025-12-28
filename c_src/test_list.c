#include "ds.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    list_t *list = list_create();
    assert(list != NULL); // Ensure list creation succeeded

    for (int i = 1; i <= 3; i++)
    {
        int *x = malloc(sizeof(int));
        assert(x != NULL);
        *x = i;
        list_push_back(list, x); // Push integers 1, 2, 3 to the list
    }

    for (int expected = 1; expected <= 3; expected++)
    {
        void *data;
        assert(list_pop_front(list, &data)); // Ensure pop succeeded
        int *value = data;
        assert(*value == expected); // Check if the popped value is as expected
        free(value);                // Free the allocated integer
    }

    assert(list_size(list) == 0); // List should be empty now
    list_destroy(list);

    printf("All tests passed!\n");
    return 0;
}
