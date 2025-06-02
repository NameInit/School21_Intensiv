#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define DOORS_COUNT 3

void add_door_test(struct node*, struct door*);
void remove_door_test(struct node*, struct node*);

int main() {
    struct node* head = NULL;
    struct door doors[DOORS_COUNT] = {{1, 0}, {2, 1}, {3, 1}};
    head = init(&doors[0]);
    printf("add_door tests:\n");
    add_door_test(head, &doors[1]);
    add_door_test(head->pNext, &doors[2]);
    add_door_test(head, &doors[0]);
    printf("remove_door tests:\n");
    remove_door_test(head->pNext, head);
    return 0;
}

void add_door_test(struct node* elem, struct door* door) {
    printf("input data: %d %d %p\n", door->id, door->status, elem);
    printf("output data: %p\n", add_door(elem, door));
    printf("result: %s\n\n", (elem->pNext && elem->pNext->data_door->id == door->id &&
                              elem->pNext->data_door->status == door->status)
                                 ? "SUCCESS"
                                 : "FAIL");
}

void remove_door_test(struct node* elem, struct node* root) {
    printf("input data: %d %d %p %p\n", elem->data_door->id, elem->data_door->status, elem, root);
    struct node* prev = elem->pNext;
    struct node* res = remove_door(elem, root);
    printf("output data: %p\n", res);
    printf("result: %s\n\n", res->pNext == prev ? "SUCCESS" : "FAIL");
}
