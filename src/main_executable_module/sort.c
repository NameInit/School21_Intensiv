#include "sort.h"

void sort(double* data, int n) {
    double c;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (data[i] > data[j]) {
                c = data[i];
                data[i] = data[j];
                data[j] = c;
            }
}