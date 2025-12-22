#include "ds.h"
#include <stdlib.h> // malloc, free
#include <assert.h>

/* =========================
   List creation / destruction
   ========================= */

// creates an empty list
list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t)); // allocates memory for the list

    if (list == NULL)
    {
        return NULL; // allocation failed → caller handles
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

// deletes the whole list and frees the memory
void list_destroy(list_t *list)
{
    node_t *current = list->head;
    while (current != NULL)
    {
        node_t *tofree = current;
        current = current->next;
        free(tofree);
    }
    free(list);
}

/* =========================
   List operations
   ========================= */
void list_push_front(list_t *list, int value)
{
    assert(list != NULL);

    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node != NULL); // ensure memory allocation succeeded

    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void list_push_back(list_t *list, int value)
{
    assert(list != NULL);

    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node != NULL); // ensure memory allocation succeeded

    new_node->value = value;
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        node_t *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

int list_pop_front(list_t *list, int *out_value)
{
}
