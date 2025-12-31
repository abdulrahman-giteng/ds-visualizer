#include "hashtable.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define HT_INSERTED 1
#define HT_UPDATED  0
#define HT_ERROR   -1

int main(void) {

    printf("Creating hashtable...\n");

    hashtable_t *ht = ht_create(10);
    assert(ht != NULL);

    printf("Inserting entries...\n");

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));

    assert(a != NULL && b != NULL && c != NULL);

    *a = 100;
    *b = 200;
    *c = 300;

    assert(ht_put(ht, 1, a) == HT_INSERTED);
    assert(ht_put(ht, 2, b) == HT_INSERTED);
    assert(ht_put(ht, 3, c) == HT_INSERTED);

    printf("Retrieving entries...\n");

    int *aval = ht_get(ht, 1);
    int *bval = ht_get(ht, 2);
    int *cval = ht_get(ht, 3);

    assert(aval != NULL && bval != NULL && cval != NULL);
    assert(*aval == 100);
    assert(*bval == 200);
    assert(*cval == 300);

    printf("Updating existing entries...\n");
    int *a_new = malloc(sizeof(int));
    assert(a_new != NULL);
    *a_new = 150;
    assert(ht_put(ht, 1, a_new) == HT_UPDATED);

    free(a); // free old value

    printf("Removing an entry...\n");
    
    int *removed = ht_get(ht, 2);
    assert(removed != NULL);
    assert(ht_remove(ht, 2) == 1);
    free(removed); // free removed value

    assert(ht_get(ht, 2) == NULL);

    printf("Cleaning up...\n");

    free(a_new);
    free(c);

    ht_destroy(ht);

    printf("All hashtable tests passed!\n");
    return 0;






}