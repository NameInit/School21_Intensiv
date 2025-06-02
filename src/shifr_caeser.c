#include "shifr_caeser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shifr_caeser(const char* file_name, int shift) {
    FILE* start_file;
    if ((start_file = fopen(file_name, "r+")) == NULL) {
        printf("n/a\n");
        return;
    }

    char copy_file[1024];
    strcpy(copy_file, file_name);
    strcat(copy_file, ".copy");

    FILE* temp_file = fopen(copy_file, "w");
    if (!temp_file) {
        printf("n/a\n");
        fclose(start_file);
        return;
    }

    char c;
    while ((c = fgetc(start_file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + shift) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26;
        }
        fputc(c, temp_file);
    }

    fclose(start_file);
    fclose(temp_file);

    remove(file_name);
    rename(copy_file, file_name);
}