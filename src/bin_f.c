#include "bin_f.h"

#include <stdio.h>

void show_bf(FILE* file) {
    int i = 0;
    int c;
    fseek(file, 0, SEEK_SET);
    while (fread(&c, sizeof(int), 1, file)) {
        if ((i != 0) && (i % 8 == 0)) putchar('\n');
        printf("%d", c);
        if (i % 8 < 7) putchar(' ');
        i++;
    }
}

void sorting_data_file(FILE* file) {
    fseek(file, 0, SEEK_END);
    long len = ftell(file) / sizeof(time_f);
    fseek(file, 0, SEEK_END);
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++) {
            time_f time1, time2;
            fseek(file, i * sizeof(time_f), SEEK_SET);
            fread(&time1, sizeof(time_f), 1, file);
            fseek(file, j * sizeof(time_f), SEEK_SET);
            fread(&time2, sizeof(time_f), 1, file);
            if (compare(&time1, &time2)) {
                fseek(file, j * sizeof(time_f), SEEK_SET);
                fwrite(&time1, sizeof(time_f), 1, file);
                fseek(file, i * sizeof(time_f), SEEK_SET);
                fwrite(&time2, sizeof(time_f), 1, file);
            }
        }
}

int len_str_in_file(FILE* file) {
    int size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}

int compare(time_f* time1, time_f* time2) {
    int state = 0;
    state += (time1->year > time2->year) ? 32 : (time1->year != time2->year) * (-32);
    state += (time1->month > time2->month) ? 16 : (time1->month != time2->month) * (-16);
    state += (time1->day > time2->day) ? 8 : (time1->day != time2->day) * (-8);
    state += (time1->hour > time2->hour) ? 4 : (time1->hour != time2->hour) * (-4);
    state += (time1->min > time2->min) ? 2 : (time1->min != time2->min) * (-2);
    state += (time1->sec > time2->min) ? 1 : (time1->sec != time2->min) * (-1);
    return (state > 0) ? 1 : 0;
}

int take_new_time(time_f* new_time) {
    int state = 1;
    if (scanf("%d%d%d%d%d%d%d%d", &new_time->year, &new_time->month, &new_time->day, &new_time->hour,
              &new_time->min, &new_time->sec, &new_time->state, &new_time->code) != 8) {
        return 0;
    };
    if (new_time->year < 0)
        state = 0;
    else if ((new_time->month < 1) || (new_time->month > 12))
        state = 0;
    else if ((new_time->day < 1) ||
             (((new_time->month == 1) || (new_time->month == 3) || (new_time->month == 5) ||
               (new_time->month == 7) || (new_time->month == 8) || (new_time->month == 10) ||
               (new_time->month == 12)) &&
              (new_time->day > 31)))
        state = 0;
    else if (((new_time->month == 4) || (new_time->month == 6) || (new_time->month == 9) ||
              (new_time->month == 11)) &&
             (new_time->day > 30))
        state = 0;
    else if (((new_time->year % 4 == 0) || (new_time->year % 100 == 0)) && (new_time->month == 2) &&
             (new_time->day > 29))
        state = 0;
    else if (((new_time->year % 4 != 0) || (new_time->year % 100 != 0)) && (new_time->month == 2) &&
             (new_time->day > 28))
        state = 0;
    else if ((new_time->hour > 23) || (new_time->hour < 0) || (new_time->min > 59) || (new_time->min < 0) ||
             (new_time->sec < 0) || (new_time->sec > 59))
        state = 0;
    else if ((new_time->state != 0) && (new_time->state != 1))
        state = 0;
    return state;
}

void search_in_bf(FILE* file, int year, int month, int day) {
    time_f time_f_temp;
    fseek(file, 0, SEEK_SET);
    while (fread(&time_f_temp, sizeof(time_f), 1, file)) {
        if (year == time_f_temp.year && month == time_f_temp.month && day == time_f_temp.day) {
            printf("%d", time_f_temp.code);
            return;
        }
    }
    printf("n/a");
    return;
}

FILE* clear_interval_bf(FILE* file, const char* namefile, time_f* start_interval, time_f* end_interval) {
    FILE* file_temp = fopen("../datasets/empty", "w+b");
    time_f time_main_file;
    fseek(file, 0, SEEK_CUR);
    while (fread(&time_main_file, sizeof(time_f), 1, file)) {
        if ((!(compare(&time_main_file, start_interval) && compare(end_interval, &time_main_file))) ||
            ((time_main_file.year == start_interval->year) &&
             (time_main_file.month == start_interval->month) &&
             (time_main_file.day == start_interval->day)) ||
            ((time_main_file.year == end_interval->year) && (time_main_file.month == end_interval->month) &&
             (time_main_file.day == end_interval->day)))
            fwrite(&time_main_file, sizeof(time_f), 1, file_temp);
    }
    fclose(file);
    remove(namefile);
    rename("../datasets/empty", namefile);
    return file_temp;
}