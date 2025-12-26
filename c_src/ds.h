#ifndef DS_H
#define DS_H

#include <stddef.h> // for size_t

/* =========================
   Linked List Structures
   ========================= */

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;

/* =========================
   Linked List API
   ========================= */

// Create and destroy
list_t *list_create(void);
void list_destroy(list_t *list);

// Operations
void list_push_front(list_t *list, void *data);
void list_push_back(list_t *list, void *data);
int list_pop_front(list_t *list, void **out_data);

// Accessors (for visualization)
size_t list_size(const list_t *list);
node_t *list_head(const list_t *list);

#endif // DS_H