#ifndef STACK_H
#define STACK_H

typedef struct d_stack {
    double item;
    struct d_stack* next;
} d_stack;

typedef struct stack {
    char* item;
    struct stack* next;
} stack;

stack* init(char* item);
int len_stack(stack* root);
void push(stack** root, char* item);
char* pop(stack** root);
void show_stack(stack* root);
void destroy(stack* root);

d_stack* d_init(double item);
void d_push(d_stack** root, double item);
double d_pop(d_stack** root);
void d_show_stack(d_stack* root);
void d_destroy(d_stack* root);

void un_minus(d_stack** root);
void sum_bin(d_stack** root);
void minus_bin(d_stack** root);
void mul(d_stack** root);
void del(d_stack** root);
void logarifm(d_stack** root);
void tangens(d_stack** root);
void sinus(d_stack** root);
void cosin(d_stack** root);
void cotan(d_stack** root);
void sqrt_stack(d_stack** root);

#endif