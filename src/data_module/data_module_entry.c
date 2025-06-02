#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data;
    int n = 0;
    if ((!scanf("%d", &n)) || (n <= 0)) {
        printf("n/a");
        return -1;
    }
    // Don`t forget to allocate memory !
    data = (double *)malloc(sizeof(double) * n);

    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    free(data);
    return 0;
}
