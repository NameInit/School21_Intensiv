#include <stdio.h>
#include <stdlib.h>

#include "bin_f.h"
#include "data_io.h"

int main() {
    char* namefile = input_string();
    if (namefile == NULL) {
        printf("n/a");
        return -1;
    }
    FILE* file;
    if ((file = fopen(namefile, "r+b")) == NULL) {
        printf("n/a");
        free(namefile);
        return -1;
    }
    int option;
    if (!scanf("%d", &option) || (len_str_in_file(file) == 0)) {
        printf("n/a");
        free(namefile);
        fclose(file);
        return -1;
    }

    switch (option) {
        case 0:
            show_bf(file);
            break;
        case 1:
            sorting_data_file(file);
            show_bf(file);
            break;
        case 2:
            time_f new_time;
            if (take_new_time(&new_time)) {
                fseek(file, 0, SEEK_END);
                fwrite(&new_time, sizeof(time_f), 1, file);
                sorting_data_file(file);
                show_bf(file);
            } else
                printf("n/a");
            break;
        default:
            printf("n/a");
            break;
    }

    fclose(file);
    free(namefile);
    return 0;
}