#include "queue.h"
#include <stdlib.h>
#include <assert.h>

queue_t *queue_create(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    assert(queue != NULL);

    queue->list = list_create();
    assert(queue->list != NULL);

    return queue;
}

void queue_destroy(queue_t *queue)
{
    if (queue == NULL)
        return;

    list_destroy(queue->list);
    free(queue);
}

void queue_enqueue(queue_t *queue, void *data)
{
    assert(queue != NULL);
    list_push_back(queue->list, data);
}

int queue_dequeue(queue_t *queue, void **out_data)
{

    assert(queue != NULL);

    return list_pop_front(queue->list, out_data);
}

int queue_is_empty(const queue_t *queue)
{
    assert(queue != NULL);
    return list_size(queue->list) == 0;
}