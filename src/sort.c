#include <stdio.h>
#include <stdlib.h>

int input(int* a, int n);
void output_mass(int* a, int n);
void ssort(int* a, int n);

int main() {
    int n = 0;
    if ((!scanf("%d", &n)) || (n <= 0)) {
        printf("n/a");
        return -1;
    }
    int* mass = (int*)malloc(sizeof(int) * n);
    if (!input(mass, n)) {
        free(mass);
        printf("n/a");
        return -1;
    }
    ssort(mass, n);
    output_mass(mass, n);
    free(mass);
    return 0;
}

int input(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if (!scanf("%d", &a[i])) return 0;
    }
    return 1;
}

void output_mass(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i + 1 != n) putchar(' ');
    }
}

void ssort(int* a, int n) {
    int c;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
}