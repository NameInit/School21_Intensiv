#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    t_btree* start = bstree_create_node(1);
    printf("%p\n", start);
    free(start);
    start = bstree_create_node(2);
    printf("%p\n", start);
    free(start);
    return 0;
}