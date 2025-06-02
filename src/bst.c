#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void bstree_clear(t_btree* root) {
    if (!root) return;
    if (root->left) bstree_clear((t_btree*)root->left);
    if (root->right) bstree_clear((t_btree*)root->right);
    free(root);
}

void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int)) {
    t_btree* new = bstree_create_node(item);
    new->left = NULL;
    new->right = NULL;
    t_btree* cur = root;
    t_btree* root2;
    while (root) {
        root2 = root;
        if (cmpf(item, root->item))
            root = (t_btree*)root->left;
        else
            root = (t_btree*)root->right;
    }
    if (cmpf(item, root2->item))
        root2->left = (struct t_btree*)new;
    else
        root2->right = (struct t_btree*)new;
}

t_btree* bstree_create_node(int item) {
    t_btree* start = (t_btree*)malloc(sizeof(t_btree));
    start->item = item;
    start->left = NULL;
    start->right = NULL;
    return start;
}

int compare(int a, int b) { return a < b; }
void app(int a) { printf("%d", a); }

void bstree_apply_infix(t_btree* root, void (*applyf)(int)) {
    if (root == NULL) return;
    bstree_apply_infix((t_btree*)root->left, applyf);
    applyf(root->item);
    bstree_apply_infix((t_btree*)root->right, applyf);
}

void bstree_apply_prefix(t_btree* root, void (*applyf)(int)) {
    if (root == NULL) return;
    applyf(root->item);
    bstree_apply_prefix((t_btree*)root->left, applyf);
    bstree_apply_prefix((t_btree*)root->right, applyf);
}

void bstree_apply_postfix(t_btree* root, void (*applyf)(int)) {
    if (root == NULL) return;
    bstree_apply_postfix((t_btree*)root->left, applyf);
    bstree_apply_postfix((t_btree*)root->right, applyf);
    applyf(root->item);
}