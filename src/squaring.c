#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a");
        return -1;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if (*n < 1) return 0;
    for (int *p = a; p - a < *n; p++)
        if (!scanf("%d", p)) return 0;
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) printf(" ");
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) *p = (*p) * (*p);
}
