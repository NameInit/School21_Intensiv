#include <stdio.h>
#define LEN_MASS 10

int input_10_number(int* a);
void output_mass(int* a);
void ssort(int* a);

int main() {
    int mass[LEN_MASS];
    if (!input_10_number(mass)) {
        printf("n/a");
        return -1;
    }
    ssort(mass);
    output_mass(mass);
    return 0;
}

int input_10_number(int* a) {
    for (int i = 0; i < LEN_MASS; i++) {
        if (!scanf("%d", &a[i])) return 0;
    }
    return 1;
}

void output_mass(int* a) {
    for (int i = 0; i < LEN_MASS; i++) {
        printf("%d", a[i]);
        if (i + 1 != LEN_MASS) putchar(' ');
    }
}

void ssort(int* a) {
    int c;
    for (int i = 0; i < LEN_MASS; i++)
        for (int j = i + 1; j < LEN_MASS; j++)
            if (a[i] > a[j]) {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
}