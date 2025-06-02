#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

char* input_expression() {
    char* buffer = NULL;
    char* buffer_copy = NULL;
    int flag_operand = 0;
    int size = 1;
    int c;
    while ((c = getchar()) != '\n') {
        if (c != ' ') {
            if ((c == '-') && (!flag_operand))
                c = '~';
            else if ((c == ')') || (c == '.') || (c == 'x') || ((c >= '0') && (c <= '9')))
                flag_operand = 1;
            else
                flag_operand = 0;

            buffer_copy = (char*)malloc(sizeof(char) * size);
            for (int i = 0; i < size - 1; i++) buffer_copy[i] = buffer[i];
            buffer_copy[size - 1] = (char)c;

            free(buffer);
            buffer = buffer_copy;
            size++;
        }
    }
    return buffer;
}