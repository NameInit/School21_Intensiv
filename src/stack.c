#include "stack.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

stack* init(char* item) {
    stack* root = (stack*)malloc(sizeof(stack));
    root->item = item;
    root->next = NULL;
    return root;
}

void push(stack** root, char* item) {
    stack* new = (stack*)malloc(sizeof(stack));
    new->item = item;
    new->next = *root;
    *root = new;
}

char* pop(stack** root) {
    if ((*root) == NULL) return NULL;
    char* item = (*root)->item;
    if ((*root)->next == NULL) {
        free(*root);
        (*root) = NULL;
        return item;
    }
    stack* new_start = (*root)->next;
    free(*root);
    (*root) = new_start;
    return item;
}

void show_stack(stack* root) {
    if (root == NULL) return;
    stack* cur = root;
    while (cur->next != NULL) {
        printf("%s ", cur->item);
        cur = cur->next;
    }
}

void destroy(stack* root) {
    if (root == NULL) return;
    stack* pnext;
    while (root->next != NULL) {
        pnext = root->next;
        free(root->item);
        free(root);
        root = pnext;
    }
    free(root->item);
    free(root);
}

int len_stack(stack* root) {
    if (root == NULL) return 0;
    int len = 0;
    while (root->next != NULL) {
        root = root->next;
        len++;
    }
    return len;
}

d_stack* d_init(double item) {
    d_stack* root = (d_stack*)malloc(sizeof(d_stack));
    root->item = item;
    root->next = NULL;
    return root;
}

void d_push(d_stack** root, double item) {
    d_stack* new = (d_stack*)malloc(sizeof(d_stack));
    new->item = item;
    new->next = *root;
    *root = new;
}

double d_pop(d_stack** root) {
    double item = (*root)->item;
    if ((*root)->next == NULL) {
        free(*root);
        (*root) = NULL;
        return item;
    }
    d_stack* new_start = (*root)->next;
    free(*root);
    (*root) = new_start;
    return item;
}

void d_show_stack(d_stack* root) {
    if (root == NULL) return;
    d_stack* cur = root;
    while (cur->next != NULL) {
        printf("%lf ", cur->item);
        cur = cur->next;
    }
}

void d_destroy(d_stack* root) {
    if (root == NULL) return;
    d_stack* pnext;
    while (root->next != NULL) {
        pnext = root->next;
        free(root);
        root = pnext;
    }
    free(root);
}

void un_minus(d_stack** root) {
    double op;
    op = d_pop(root);
    op = -op;
    d_push(root, op);
}

void sum_bin(d_stack** root) {
    double op1 = d_pop(root);
    double op2 = d_pop(root);
    op1 = op1 + op2;
    d_push(root, op1);
}

void minus_bin(d_stack** root) {
    double op1 = d_pop(root);
    double op2 = d_pop(root);
    op1 = op2 - op1;
    d_push(root, op1);
}

void mul(d_stack** root) {
    double op1 = d_pop(root);
    double op2 = d_pop(root);
    op1 = op2 * op1;
    d_push(root, op1);
}

void del(d_stack** root) {
    double op1 = d_pop(root);
    double op2 = d_pop(root);
    op1 = op2 / op1;
    d_push(root, op1);
}

void logarifm(d_stack** root) {
    double op1 = d_pop(root);
    op1 = log(op1);
    d_push(root, op1);
}

void tangens(d_stack** root) {
    double op1 = d_pop(root);
    op1 = tan(op1);
    d_push(root, op1);
}

void sinus(d_stack** root) {
    double op1 = d_pop(root);
    op1 = sin(op1);
    d_push(root, op1);
}

void cosin(d_stack** root) {
    double op1 = d_pop(root);
    op1 = cos(op1);
    d_push(root, op1);
}

void cotan(d_stack** root) {
    double op1 = d_pop(root);
    op1 = 1 / tan(op1);
    d_push(root, op1);
}

void sqrt_stack(d_stack** root) {
    double op1 = d_pop(root);
    op1 = sqrt(op1);
    d_push(root, op1);
}