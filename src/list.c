#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* doors) {
    struct node* pStart = (struct node*)malloc(sizeof(struct node));
    pStart->pNext;
    pStart->data_door = doors;
    return pStart;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data_door = door;
    new_node->pNext = elem->pNext;
    elem->pNext = new_node;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* pCur = root;
    while (pCur != NULL) {
        if (pCur->data_door->id == door_id) break;
        pCur = pCur->pNext;
    }
    return pCur;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* pCur = root;
    if (pCur == NULL) return NULL;
    while (pCur->pNext != NULL) {
        if (pCur->pNext == elem) {
            pCur->pNext = elem->pNext;
            free(elem);
            break;
        }
        pCur = pCur->pNext;
    }
    return root;
}

void destroy(struct node* root) {
    struct node* pCur = root;
    if (pCur == NULL) return;
    struct node* pNextt;
    while (pCur->pNext != NULL) {
        pNextt = pCur->pNext;
        free(pCur);
        pCur = pNextt;
    }
    free(pCur);
}