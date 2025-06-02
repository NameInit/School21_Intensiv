#include <stdio.h>

#include "bst.h"

int main() {
    t_btree* start = bstree_create_node(3);
    bstree_insert(start, 4, compare);
    printf("%p\n", start->right);
    bstree_insert(start, 2, compare);
    printf("%p", start->right);
    bstree_clear(start);
    return 0;
}