#include <stdio.h>
#include <stdlib.h>

#include "bin_f.h"
#include "data_io.h"

int is_real_time(int year, int month, int day);

int main() {
    char* namefile = input_string();
    if (namefile == NULL) {
        printf("n/a");
        return -1;
    }
    FILE* file;
    if ((file = fopen(namefile, "rb")) == NULL) {
        printf("n/a");
        free(namefile);
        return -1;
    }
    int year, month, day;
    if (scanf("%d.%d.%d", &day, &month, &year) != 3) {
        printf("n/a");
        free(namefile);
        fclose(file);
        return -1;
    }
    if (!is_real_time(year, month, day)) {
        printf("n/a");
        free(namefile);
        fclose(file);
        return -1;
    }

    search_in_bf(file, year, month, day);

    free(namefile);
    fclose(file);
    return 0;
}

int is_real_time(int year, int month, int day) {
    int state = 1;

    if (year < 0)
        state = 0;
    else if ((month < 1) || (month > 12))
        state = 0;
    else if ((day < 1) || (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) ||
                            (month == 10) || (month == 12)) &&
                           (day > 31)))
        state = 0;
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30))
        state = 0;
    else if (((year % 4 == 0) || (year % 100 == 0)) && (month == 2) && (day > 29))
        state = 0;
    else if (((year % 4 != 0) || (year % 100 != 0)) && (month == 2) && (day > 28))
        state = 0;

    return state;
}