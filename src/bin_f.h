#ifndef BIN_F_H
#define BIN_F_H

#include <stdio.h>

typedef struct time_f {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int state;
    int code;
} time_f;

void show_bf(FILE* file);
void sorting_data_file(FILE* file);
int len_str_in_file(FILE* file);
int compare(time_f* time1, time_f* time2);
int take_new_time(time_f* new_time);
void search_in_bf(FILE* file, int year, int month, int day);
FILE* clear_interval_bf(FILE* file, const char* namefile, time_f* start_interval, time_f* end_interval);

#endif