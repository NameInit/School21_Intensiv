#include "string_lite.h"

#include <stdlib.h>
#include <string.h>

int priority(const char* taken) {
    int state;
    if ((taken[0] == '+') || (taken[0] == '-') || (taken[0] == '~'))
        state = 0;
    else if ((taken[0] == 's') || (taken[0] == 'c') || (taken[0] == 't') || (taken[0] == 'l'))
        state = 1;
    else if ((taken[0] == '*') || (taken[0] == '/'))
        state = 2;
    else if (taken[0] == ')')
        state = 3;
    else
        state = 4;
    return state;
}

int is_digit(const char* a) {
    return ((a[0] == '.') || (a[0] == 'x') || ((a[0] >= '0') && (a[0] <= '9'))) ? 1 : 0;
}

int strcmp_start(char* str1, char* str2) {  // str2 in str1
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int diff = 0;
    int i = 0;
    while (i < len_str2) {
        if ((str1[i] != str2[i]) || (len_str1 < len_str2)) {
            diff = 1;
            break;
        }
        i++;
    }
    return (diff == 0) ? 1 : 0;
}

char* dyn_str_one_char(char c) {
    char* a = (char*)malloc(sizeof(char));
    a[0] = c;
    return a;
}