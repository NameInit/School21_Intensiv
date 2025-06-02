#include "logger.h"

#include <string.h>
#include <time.h>

FILE* log_init(char* filename) {
    FILE* file = fopen(filename, "w");
    return file;
}

int logcat(FILE* log_file, char* message, log_level level) {
    time_t cur_time = time(NULL);
    struct tm* tm = localtime(&cur_time);
    char str[10];  // debug, trace, info, warning, error
    switch (level) {
        case 0:
            strcpy(str, "debug");
            break;
        case 1:
            strcpy(str, "trace");
            break;
        case 2:
            strcpy(str, "info");
            break;
        case 3:
            strcpy(str, "warning");
            break;
        case 4:
            strcpy(str, "error");
            break;
        default:
            break;
    }
    return fprintf(log_file, "[%s] %02d:%02d:%02d %s\n", str, tm->tm_hour, tm->tm_min, tm->tm_sec, message);
}

int log_close(FILE* log_file) { return fclose(log_file); }