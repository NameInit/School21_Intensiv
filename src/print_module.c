#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t cur_time = time(NULL);
    struct tm* now_time = localtime(&cur_time);
    for (int i = 0; Log_prefix[i] != '\0'; i++) print(Log_prefix[i]);
    printf(" %02d:%02d:%02d ", now_time->tm_hour, now_time->tm_min, now_time->tm_sec);
    for (int i = 0; message[i] != '\0'; i++) print(message[i]);
}
