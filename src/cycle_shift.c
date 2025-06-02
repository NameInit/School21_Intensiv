#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
void sdv(int *a, int len, int sdvig);

int main() {
    int mass[NMAX];
    int n, sdvig;
    if ((!input(mass, &n)) || (!scanf("%d", &sdvig))) {
        printf("n/a");
        return -1;
    }
    sdv(mass, n, sdvig);
    output(mass, n);
    return 0;
}

int input(int *buffer, int *length) {
    if (!scanf("%d", length)) return 0;
    if (*length > 10) return 0;
    if (*length < 1) return 0;
    for (int *p = buffer; p - buffer < *length; p++)
        if (!scanf("%d", p)) return 0;
    return 1;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer + 1 < length) putchar(' ');
    }
}

void sdv(int *a, int len, int sdvig) {
    int copy_mass[len];
    for (int i = 0; i < len; i++) copy_mass[i] = a[i];
    for (int i = 0; i < len; i++) a[i] = copy_mass[(len + i + sdvig) % len];
}