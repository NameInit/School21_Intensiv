#ifndef BST_H
#define BST_H

typedef struct {
    int item;
    struct t_btree* left;
    struct t_btree* right;
} t_btree;

int compare(int a, int b);
void app(int a);

t_btree* bstree_create_node(int item);
void bstree_clear(t_btree* root);
void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int));
void bstree_apply_infix(t_btree* root, void (*applyf)(int));
void bstree_apply_prefix(t_btree* root, void (*applyf)(int));
void bstree_apply_postfix(t_btree* root, void (*applyf)(int));
#endif