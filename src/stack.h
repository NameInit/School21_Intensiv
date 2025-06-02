#ifndef STACK_H
#define STACK_H

struct stack {
    int num;
    struct stack* next;
};

struct stack* init(int a);
void push(struct stack** start, int a);
int pop(struct stack** start);
void destroy(struct stack* start);

#endif