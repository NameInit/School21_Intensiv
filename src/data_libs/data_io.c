#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++)
        if (!scanf("%lf", &data[i])) {
            printf("n/a");
            free(data);
            exit(-1);
        }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if ((i + 1) != n) putchar(' ');
    }
}