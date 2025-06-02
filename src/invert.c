#include <stdio.h>
#include <stdlib.h>
double det(double** matrix, int n);
double** input(int* n, int* m);
double** minor(double** matrix, int row, int col, int n);
void output(double** m, int n);
void fill_rm(double** m, double** obr, int n);

int main() {
    double** matrix;
    double** rmatr;
    int n = 0, m = 0;
    matrix = input(&n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!scanf("%lf", &matrix[i][j])) {
                for (int k = 0; k < n; k++) free(matrix[k]);
                free(matrix);
                printf("n/a");
                return -1;
            }
    double d = det(matrix, n);
    if (d == 0) {
        for (int i = 0; i < n; i++) free(matrix[i]);
        free(matrix);
        printf("n/a");
        return -1;
    }
    rmatr = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) rmatr[i] = (double*)malloc(n * sizeof(double));

    fill_rm(matrix, rmatr, n);
    output(rmatr, n);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(rmatr[i]);
    }
    free(rmatr);
    free(matrix);
    return 0;
}

double** minor(double** matrix, int row, int col, int n) {
    double** a2minor = (double**)malloc(sizeof(double) * (n - 1) * (n - 1) + (n - 1) * sizeof(double*));
    double* ptr = (double*)(a2minor + (n - 1));
    for (int i = 0; i < (n - 1); i++) a2minor[i] = ptr + (n - 1) * i;
    for (int i = 0; i < n; i++) {
        if (row == i) continue;
        for (int j = 0; j < n; j++) {
            if (j == col) continue;
            a2minor[i - (i > row)][j - (j > col)] = matrix[i][j];
        }
    }
    return a2minor;
}

double det(double** matrix, int n) {
    if (n == 1) return matrix[0][0];
    double sum = 0;
    int znak = 1;
    for (int i = 0; i < n; i++) {
        double** matr;
        sum += znak * matrix[0][i] * det(matr = minor(matrix, 0, i, n), n - 1);
        free(matr);
        znak = -znak;
    }
    return sum;
}

double** input(int* n, int* m) {
    if ((scanf("%d%d", n, m) != 2) || ((*n) <= 0) || (*m <= 0) || (*n != *m)) {
        printf("n/a");
        exit(-1);
    }
    double** arr2 = (double**)malloc((*n) * sizeof(double*));
    for (int i = 0; i < *n; i++) arr2[i] = (double*)malloc(sizeof(double) * (*m));
    return arr2;
}

void output(double** m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.6lf", m[i][j]);
            if ((j + 1) != n) putchar(' ');
        }
        if ((i + 1) != n) putchar('\n');
    }
}

void fill_rm(double** m, double** obr, int n) {
    int sig;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1)
                sig = -1;
            else
                sig = 1;
            obr[i][j] = sig * det(minor(m, j, i, n), n - 1) / det(m, n);
        }
}