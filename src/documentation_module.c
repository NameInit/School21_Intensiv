#include "documentation_module.h"

#include <stdarg.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    static int state[Documents_count];
    va_list args;
    va_start(args, document_count);
    for (int i = 0; i < document_count; i++) {
        char* doc = va_arg(args, char*);
        state[i] = validate(doc);
    }
    va_end(args);
    return state;
}