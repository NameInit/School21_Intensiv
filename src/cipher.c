#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_io.h"
#include "logger.h"
#include "shifr_caeser.h"

void button3(const char* dir_path, int shift);

int main() {
    int state;
    char* last_str = NULL;
#ifdef PRINT_MODULE
    FILE* log_file = log_init("peer");
    logcat(log_file, "peer registred", info);
#endif
    while (1) {
        if ((!scanf("%d", &state)) || ((state != 1) && (state != -1) && (state != 2) && (state != 3))) {
            printf("n/a\n");
#ifdef PRINT_MODULE
            logcat(log_file, "input error", error);
#endif
            getchar();
            continue;
        } else if (state == -1)
            break;
        getchar();

        if (state == 1) {
#ifdef PRINT_MODULE
            logcat(log_file, "button1", info);
#endif
            char* str = input_string();
            FILE* file = NULL;
            if ((file = fopen(str, "r")) == NULL) {
                printf("n/a\n");
#ifdef PRINT_MODULE
                logcat(log_file, "input error", warning);
#endif
            } else {
                int c;
                int flag_empty_file = 1;
                while ((c = fgetc(file)) != EOF) {
                    putchar(c);
                    flag_empty_file = 0;
                }
                if (flag_empty_file) {
                    printf("n/a");
#ifdef PRINT_MODULE
                    logcat(log_file, "input error", warning);
#endif
                }
#ifdef PRINT_MODULE
                logcat(log_file, "button1 peer show file", trace);
#endif
                fclose(file);
                putchar('\n');
                if (last_str != NULL) {
                    free(last_str);
                    last_str = NULL;
                }
                last_str = strdup(str);
            }
            free(str);
        }

        else if (state == 2) {
#ifdef PRINT_MODULE
            logcat(log_file, "button2", info);
#endif
            char* str = input_string();
            FILE* file = NULL;
            if (last_str == NULL) {
                printf("n/a\n");
#ifdef PRINT_MODULE
                logcat(log_file, "input error", warning);
#endif
            } else {
                if ((file = fopen(last_str, "r+")) == NULL) {
                    printf("n/a\n");
#ifdef PRINT_MODULE
                    logcat(log_file, "input error", warning);
#endif
                } else {
#ifdef PRINT_MODULE
                    logcat(log_file, "new line in file", trace);
#endif
                    fseek(file, 0, SEEK_END);
                    fprintf(file, "%s", str);
                    fclose(file);
                }
            }
            free(str);
        }

        else if (state == 3) {
#ifdef PRINT_MODULE
            logcat(log_file, "button3", info);
#endif
            printf("Dir: ");
            char* str = input_string();
            printf("Shift: ");
            int shift;
            if (!scanf("%d", &shift))
                printf("n/a\n");
            else
                button3(str, shift);
            getchar();
            free(str);
        }
    }
#ifdef PRINT_MODULE
    logcat(log_file, "peer out", info);
    log_close(log_file);
#endif
    if (last_str != NULL) free(last_str);
    return 0;
}

void button3(const char* dir_path, int shift) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(dir_path)) == NULL) {
        printf("n/a\n");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        int path_length = strlen(dir_path) + strlen(ent->d_name) + 2;
        char file_path[path_length];
        snprintf(file_path, path_length, "%s/%s", dir_path, ent->d_name);
        if (strstr(ent->d_name, ".c") != NULL) {
            shifr_caeser(file_path, shift);
        } else if (strstr(ent->d_name, ".h") != NULL) {
            FILE* file = fopen(file_path, "w");
            if (!file) {
                printf("n/a\n");
                return;
            }
            fclose(file);
        }
    }
    closedir(dir);
}