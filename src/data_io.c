#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

char* input_string() {
    char* buffer = NULL;
    char* buffer_copy = NULL;
    int size = 0;
    int c;
    while ((c = getchar()) != '\n') {
        size++;
        buffer_copy = (char*)malloc(sizeof(char) * size);
        for (int i = 0; i < (size - 1); i++) buffer_copy[i] = buffer[i];
        buffer_copy[size - 1] = (char)c;
        free(buffer);
        buffer = buffer_copy;
    }
    buffer[size] = '\0';
    return buffer;
}
