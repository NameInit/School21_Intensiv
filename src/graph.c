#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_io.h"
#include "stack.h"
#include "string_lite.h"

void drow(char** reverse_polish, int len_polish);
void create_lekschemes_in_stack(char* str, stack** mix);
void create_reverse_notation(stack** operands, stack** operators, char** mass, int len_mass);
double calc(char** mass, int len_mass, double x);

int main() {
    stack* mix = init(strdup((char*)"end"));
    stack* operands = init(strdup((char*)"end"));
    stack* operators = init(strdup((char*)"end"));
    char* expression = input_expression();
    create_lekschemes_in_stack(expression, &mix);
    int len_mass = len_stack(mix);
    char** mass = (char**)malloc(sizeof(char*) * len_mass);
    for (int i = 0; i < len_mass; i++) mass[len_mass - 1 - i] = pop(&mix);
    create_reverse_notation(&operands, &operators, mass, len_mass);
    int len_polish = len_stack(operands);
    char** reverse_polish = (char**)malloc(sizeof(char*) * len_polish);
    for (int i = 0; i < len_polish; i++) reverse_polish[len_polish - 1 - i] = pop(&operands);
    drow(reverse_polish, len_polish);
    free(expression);
    destroy(mix);
    destroy(operands);
    destroy(operators);
    for (int i = 0; i < len_polish; i++) free(reverse_polish[i]);
    free(reverse_polish);
    for (int i = 0; i < len_mass; i++) free(mass[i]);
    free(mass);
    return 0;
}

void create_reverse_notation(stack** operands, stack** operators, char** mass, int len_mass) {
    for (int i = 0; i < len_mass; i++) {
        if (is_digit(mass[i])) {
            push(operands, strdup(mass[i]));
        } else if ((mass[i][0] == 's') || (mass[i][0] == 'c') || (mass[i][0] == 't') || (mass[i][0] == 'l')) {
            push(operators, strdup(mass[i]));
        } else if (mass[i][0] == '(')
            push(operators, strdup(mass[i]));
        else if (mass[i][0] == ')') {
            char* item;
            while (((*operators)->item)[0] != '(') {
                item = pop(operators);
                push(operands, item);
            }
            item = pop(operators);
            free(item);
            if ((mass[i][0] == 's') || (mass[i][0] == 'c') || (mass[i][0] == 't') || (mass[i][0] == 'l')) {
                item = pop(operators);
                push(operands, item);
            }
        } else {
            while ((strcmp((*operators)->item, "end") != 0) && (((*operators)->item)[0] != '(') &&
                   (priority(mass[i]) <= priority((*operators)->item))) {
                char* item = pop(operators);
                push(operands, item);
            }
            push(operators, strdup(mass[i]));
        }
    }
    while (strcmp((*operators)->item, "end") != 0) {
        char* item = pop(operators);
        push(operands, item);
    }
}

void create_lekschemes_in_stack(char* str, stack** mix) {
    char* str_copy = strdup(str);
    int len_str = strlen(str);
    int ind_str = 0;
    char one_char[1];
    char* token = strtok(str_copy, "~+-/*()sincoqrtgla");
    while (token != NULL) {
        while (!strcmp_start((char*)str + ind_str, token)) {
            if (strcmp_start((char*)str + ind_str, "sin")) {
                push(mix, strdup((char*)"sin"));
                ind_str += 3;
            } else if (strcmp_start((char*)str + ind_str, "cos")) {
                push(mix, strdup((char*)"cos"));
                ind_str += 3;
            } else if (strcmp_start((char*)str + ind_str, "tan")) {
                push(mix, strdup((char*)"tan"));
                ind_str += 3;
            } else if (strcmp_start((char*)str + ind_str, "ctg")) {
                push(mix, strdup((char*)"ctg"));
                ind_str += 3;
            } else if (strcmp_start((char*)str + ind_str, "ln")) {
                push(mix, strdup((char*)"ln"));
                ind_str += 2;
            } else if (strcmp_start((char*)str + ind_str, "sqrt")) {
                push(mix, strdup((char*)"sqrt"));
                ind_str += 4;
            } else {
                push(mix, dyn_str_one_char(str[ind_str]));
                ind_str++;
            }
        }
        push(mix, strdup(token));
        ind_str += strlen(token);
        token = strtok(NULL, "~+-/*()sincoqrtgla");
    }
    while (ind_str < len_str) {
        one_char[0] = str[ind_str];
        push(mix, strdup(one_char));
        ind_str++;
    }
    free(str_copy);
}

double calc(char** mass, int len_mass, double x) {
    double ans;
    d_stack* root_d = d_init(1.);
    for (int i = 0; i < len_mass; i++) {
        if (is_digit(mass[i])) {
            double op;
            if (mass[i][0] == 'x')
                op = x;
            else
                op = atof(mass[i]);
            d_push(&root_d, op);
        } else {
            if (mass[i][0] == '~')
                un_minus(&root_d);
            else if (mass[i][0] == '+')
                sum_bin(&root_d);
            else if (mass[i][0] == '-')
                minus_bin(&root_d);
            else if (mass[i][0] == '*')
                mul(&root_d);
            else if (mass[i][0] == '/')
                del(&root_d);
            else if (mass[i][0] == 'l')
                logarifm(&root_d);
            else if (mass[i][0] == 't')
                tangens(&root_d);
            else if ((mass[i][0] == 's') && (mass[i][1] == 'i'))
                sinus(&root_d);
            else if ((mass[i][0] == 'c') && (mass[i][1] == 'o'))
                cosin(&root_d);
            else if ((mass[i][0] == 'c') && (mass[i][1] == 't'))
                cotan(&root_d);
            else
                sqrt_stack(&root_d);
        }
    }
    ans = d_pop(&root_d);
    d_destroy(root_d);
    return ans;
}

void drow(char** reverse_polish, int len_polish) {
    double shag_x = 4 * M_PI / 80;
    double shag_y = 2.0 / 25;
    double poz_y = -1.0;
    for (int i = 0; i < 25; i++) {
        double poz_x = 0.0;
        for (int j = 0; j < 80; j++) {
            double ans = calc(reverse_polish, len_polish, poz_x);
            if (poz_y <= ans && ans < poz_y + shag_y) {
                printf("*");
            } else if (poz_y < ans && fabs(ans - (poz_y + shag_y)) < 0.00001 && i == 24) {
                printf("*");
            } else {
                printf(".");
            }
            poz_x += shag_x;
        }
        printf("\n");
        poz_y += shag_y;
    }
}