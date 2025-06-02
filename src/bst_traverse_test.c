#include <stdio.h>

#include "bst.h"

int main() {
    t_btree* root = bstree_create_node(5);
    bstree_insert(root, 5, compare);
    bstree_insert(root, 3, compare);
    bstree_insert(root, 7, compare);
    bstree_insert(root, -1, compare);
    bstree_insert(root, 2, compare);
    bstree_insert(root, 0, compare);
    bstree_apply_infix(root, app);
    putchar('\n');
    bstree_apply_prefix(root, app);
    putchar('\n');
    bstree_apply_postfix(root, app);
    bstree_clear(root);
    return 0;
}