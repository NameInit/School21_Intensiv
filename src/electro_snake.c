#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m);

int **input(int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix;
    int n = 0, m = 0;
    matrix = input(&n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!scanf("%d", &matrix[i][j])) {
                free(matrix);
                printf("n/a");
                return -1;
            }
    sort_vertical(matrix, n, m);
    output(matrix, n, m);
    printf("\n\n");
    sort_horizontal(matrix, n, m);
    output(matrix, n, m);
    free(matrix);
    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if ((j + 1) != m) putchar(' ');
        }
        if ((i + 1) != n) putchar('\n');
    }
}

int **input(int *n, int *m) {
    if ((scanf("%d%d", n, m) != 2) || ((*n) <= 0) || (*m <= 0)) {
        printf("n/a");
        exit(-1);
    }
    int **arr2 = malloc((*n) * (*m) * sizeof(int) + (*n) * sizeof(int *));
    int *ptr = (int *)(arr2 + (*n));
    for (int i = 0; i < *n; i++) arr2[i] = ptr + i * (*m);
    return arr2;
}

void sort_vertical(int **matrix, int n, int m) {
    int c;
    for (int i = 0; i < (n * m); i++)
        for (int j = i + 1; j < (n * m); j++)
            if (matrix[i % n][i / n] > matrix[j % n][j / n]) {
                c = matrix[i % n][i / n];
                matrix[i % n][i / n] = matrix[j % n][j / n];
                matrix[j % n][j / n] = c;
            }
    for (int i = 1; i < m; i += 2)
        for (int j = 0; j < n / 2; j++) {
            c = matrix[j][i];
            matrix[j][i] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = c;
        }
}

void sort_horizontal(int **matrix, int n, int m) {
    int c;
    for (int i = 0; i < (n * m); i++)
        for (int j = i + 1; j < (n * m); j++)
            if (matrix[i / m][i % m] > matrix[j / m][j % m]) {
                c = matrix[i / m][i % m];
                matrix[i / m][i % m] = matrix[j / m][j % m];
                matrix[j / m][j % m] = c;
            }

    for (int i = 1; i < n; i += 2)
        for (int j = 0; j < m / 2; j++) {
            c = matrix[i][j];
            matrix[i][j] = matrix[i][m - 1 - j];
            matrix[i][m - 1 - j] = c;
        }
}
