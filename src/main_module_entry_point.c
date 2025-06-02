#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef PRINT_MODULE
    print_log(print_char, Module_load_success_message);
#endif

#ifdef DOCUMENTATION_MODULE
    const char* docs[4] = {"Linked lists", "Queues", "Maps", "Binary Trees"};
    int* availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    for (int i = 0; i < Documents_count; i++) {
        printf("%d. %-15s: %s", i + 1, docs[i], (availability_mask[i] == 1) ? "available" : "unavailable");
        if ((i + 1) != Documents_count) putchar('\n');
    }
#endif

    return 0;
}
