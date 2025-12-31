#include "queue.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(void)
{
    queue_t *queue = queue_create();
    assert(queue != NULL);

    // Enqueue integers 1, 2, 3 onto the queue
    for (int i = 1; i <= 3; i++)
    {
        int *x = malloc(sizeof(int));
        assert(x != NULL);
        *x = i;
        queue_enqueue(queue, x);
    }

    // Dequeue and check values
    for (int expected = 1; expected <= 3; expected++)
    {
        void *data;
        assert(queue_dequeue(queue, &data)); // Ensure dequeue succeeded
        int *value = data;
        assert(*value == expected); // Check if the dequeued value is as expected
        free(value);                // Free the allocated integer
    }

    assert(queue_is_empty(queue)); // Queue should be empty now
    queue_destroy(queue);

    printf("All queue tests passed!\n");
    return 0;
}