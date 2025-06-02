#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push_test(struct stack**, int);
void pop_test(struct stack**);
int len(struct stack* start);
void show(struct stack* start);

int main() {
    struct stack* start = NULL;
    start = init(1);
    printf("push tests:\n");
    push_test(&start, 2);
    push_test(&start, 3);
    push_test(&start, 4);
    printf("\npop tests\n");
    pop_test(&start);
    pop_test(&start);
    pop_test(&start);
    destroy(start);
    return 0;
}

void push_test(struct stack** start, int n) {
    printf("INPUT: New int %d; Stack:", n);
    show(*start);
    putchar('\n');
    int l1 = len(*start);
    int l2;
    push(start, n);
    l2 = len(*start);
    printf("OUTPUT: Stack:");
    show(*start);
    putchar('\n');
    printf("result: %s\n", (((l2 - l1) == 1) && ((*start)->num == n)) ? "SUCCESS" : "FAIL");
}

void pop_test(struct stack** start) {
    printf("INPUT: Stack:");
    show(*start);
    putchar('\n');
    int a = (*start)->num, l1 = len(*start);
    int b = pop(start);
    int l2 = len(*start);
    printf("OUTPUT: Stack:");
    show(*start);
    putchar('\n');
    printf("result: %s\n", ((a == b) && ((l1 - l2) == 1)) ? "SUCCESS" : "FAIL");
}

int len(struct stack* start) {
    int ans = 0;
    while (start != NULL) {
        ans++;
        start = start->next;
    }
    return ans;
}

void show(struct stack* start) {
    struct stack* cur = start;
    while (cur != NULL) {
        printf(" %d", cur->num);
        cur = cur->next;
    }
}