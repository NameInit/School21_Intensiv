#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack* init(int a) {
    struct stack* start = (struct stack*)malloc(sizeof(struct stack));
    start->next = NULL;
    start->num = a;
    return start;
}

void push(struct stack** start, int a) {
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    new->num = a;
    new->next = (*start);
    (*start) = new;
}

int pop(struct stack** start) {
    if ((*start) == NULL) return 0;
    int a = (*start)->num;
    if ((*start)->next == NULL) {
        free(*start);
        return a;
    }
    struct stack* new_start = (*start)->next;
    free(*start);
    (*start) = new_start;
    return a;
}

void destroy(struct stack* start) {
    if (start->next == NULL) {
        free(start);
        return;
    }
    struct stack* pnext;
    while (start->next != NULL) {
        pnext = start->next;
        free(start);
        start = pnext;
    }
    free(start);
}