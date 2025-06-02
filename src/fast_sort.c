#include <stdio.h>
#define LEN_MASS 10

void qsort(int* a, int ind_start, int ind_end);
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
    qsort(mass, 0, LEN_MASS - 1);

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

void qsort(int* a, int ind_start, int ind_end) {
    int pivot = a[ind_start];
    int ind_pivot;
    int pStart = ind_start;
    int pEnd = ind_end;
    while (ind_start < ind_end) {
        while ((a[ind_end] > pivot) && (ind_start < ind_end)) ind_end--;
        if (ind_start != ind_end) {
            a[ind_start] = a[ind_end];
            ind_start++;
        }
        while ((ind_start[a] < pivot) && (ind_start < ind_end)) ind_start++;
        if (ind_start != ind_end) {
            a[ind_end] = a[ind_start];
            ind_end--;
        }
    }
    a[ind_start] = pivot;
    ind_pivot = ind_start;
    ind_start = pStart;
    ind_end = pEnd;
    if (ind_start < ind_pivot) qsort(a, ind_start, ind_pivot - 1);
    if (ind_end > ind_pivot) qsort(a, ind_pivot + 1, ind_end);
}

void ssort(int* a) {
    int mass1[LEN_MASS];
    for (int i = 0; i < LEN_MASS; i += 2) {
        if (a[i] < a[i + 1]) {
            mass1[i] = a[i];
            mass1[i + 1] = a[i + 1];
        } else {
            mass1[i] = a[i + 1];
            mass1[i + 1] = a[i];
        }
    }
    int mass2[LEN_MASS];
    int p1, p2;
    for (int i = 0; i < LEN_MASS; i += 4) {
        p1 = 0, p2 = 0;
        while ((p1 != 2) || (p2 != 2)) {
            if ((p1 == 2) && (p2 != 2)) {
                mass2[i + p1 + p2] = mass1[i + p1 + p2];
                p2++;
            } else if ((p2 == 2) && (p1 != 2)) {
                mass2[i + p1 + p2] = mass1[i + p1];
                p1++;
            } else if (mass1[i + 2 + p2] > mass1[i + p1]) {
                mass2[i + p1 + p2] = mass1[i + p1];
                p1++;
            } else {
                mass2[i + p1 + p2] = mass1[i + p2 + 2];
                p2++;
            }
        }
    }
    mass2[8] = mass1[8];
    mass2[9] = mass1[9];

    int mass3[LEN_MASS];
    p1 = 0, p2 = 0;
    while ((p1 != 4) || (p2 != 4)) {
        if ((p1 == 4) && (p2 != 4)) {
            mass3[p1 + p2] = mass2[p1 + p2];
            p2++;
        } else if ((p2 == 4) && (p1 != 4)) {
            mass3[p1 + p2] = mass2[p1];
            p1++;
        } else if (mass2[4 + p2] > mass2[p1]) {
            mass3[p1 + p2] = mass2[p1];
            p1++;
        } else {
            mass3[p1 + p2] = mass2[p2 + 4];
            p2++;
        }
    }
    mass3[8] = mass2[8];
    mass3[9] = mass2[9];

    p1 = 0, p2 = 0;
    while ((p1 != 8) || (p2 != 2)) {
        if ((p1 == 8) && (p2 != 2)) {
            a[p1 + p2] = mass3[p1 + p2];
            p2++;
        } else if ((p2 == 2) && (p1 != 8)) {
            a[p1 + p2] = mass3[p1];
            p1++;
        } else if (mass3[8 + p2] > mass3[p1]) {
            a[p1 + p2] = mass3[p1];
            p1++;
        } else {
            a[p1 + p2] = mass3[p2 + 8];
            p2++;
        }
    }
}