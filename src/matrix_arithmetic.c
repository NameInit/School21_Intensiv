#include <stdio.h>
#include <stdlib.h>

int inputRC(int *row, int *col);
void sum(int **matrix_first, int **matrix_second, int **matrix_result, int row, int col);
void transpose(int **matrix, int n, int m, int **matr1);
void mul(int **matrix_first, int m_first, int **matrix_second, int **matrix_result, int n_result,
         int m_result);
int input(int **mass, int row, int col);
void output(int **mass, int row1, int col1);

int main() {
    int rezhim = 0;
    if (!scanf("%d", &rezhim) || (rezhim <= 0) || (rezhim >= 4)) {
        printf("n/a");
        return -1;
    }
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
    inputRC(&row1, &col1);
    int **matr1 = malloc(col1 * row1 * sizeof(int) + row1 * sizeof(int *));
    if (!input(matr1, row1, col1)) {
        free(matr1);
        return -1;
    }

    switch (rezhim) {
        case 1: {
            if (!inputRC(&row2, &col2)) {
                free(matr1);
                return -1;
            }
            int **matr2 = malloc(col2 * row2 * sizeof(int) + row2 * sizeof(int *));
            if (!input(matr2, row2, col2)) {
                free(matr1);
                free(matr2);
                return -1;
            }
            if ((row1 != row2) || (col1 != col2)) {
                free(matr1);
                free(matr2);
                return -1;
            }
            int **res = malloc(col2 * row2 * sizeof(int) + row2 * sizeof(int *));
            sum(matr1, matr2, res, row1, col1);
            output(res, row1, col1);
            free(res);
            free(matr2);
            break;
        }
        case 2: {
            if (!inputRC(&row2, &col2)) {
                free(matr1);
                return -1;
            }
            int **matr2 = malloc(col2 * row2 * sizeof(int) + row2 * sizeof(int *));
            if (!input(matr2, row2, col2)) {
                free(matr1);
                free(matr2);
                return -1;
            }
            if (col1 != row2) {
                free(matr1);
                free(matr2);
                return -1;
            }
            int row = row1, col = col2;
            int **res = malloc(col * row * sizeof(int) + row * sizeof(int *));
            mul(matr1, col1, matr2, res, row, col);
            output(res, row, col);
            free(res);
            free(matr2);
            break;
        }
        case 3: {
            int row = col1, col = row1;
            int **res = malloc(col * row * sizeof(int) + row * sizeof(int *));
            transpose(res, row, col, matr1);
            output(res, row, col);
            free(res);
            break;
        }
        default:
            break;
    }

    free(matr1);
    return 0;
}

int inputRC(int *row, int *col) {
    if ((!scanf("%d", row)) || (!scanf("%d", col)) || (*row <= 0) || (*col <= 0)) {
        printf("n/a");
        return 0;
    }
    return 1;
}

void output(int **mass, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", mass[i][j]);
            if ((j + 1) != col) putchar(' ');
        }
        if ((i + 1) != row) putchar('\n');
    }
}

int input(int **mass, int row, int col) {
    int *ptr = (int *)(mass + row);
    for (int i = 0; i < row; i++) mass[i] = ptr + col * i;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!scanf("%d", &mass[i][j])) {
                printf("n/a");
                return 0;
            }
    return 1;
}

void sum(int **matrix_first, int **matrix_second, int **matrix_result, int row, int col) {
    int *ptr = (int *)(matrix_result + row);
    for (int i = 0; i < row; i++) matrix_result[i] = ptr + col * i;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
}

void mul(int **matrix_first, int m_first, int **matrix_second, int **matrix_result, int n_result,
         int m_result) {
    int *ptr = (int *)(matrix_result + n_result);
    for (int i = 0; i < n_result; i++) matrix_result[i] = ptr + m_result * i;

    for (int i = 0; i < n_result; i++)
        for (int j = 0; j < m_result; j++) matrix_result[i][j] = 0;

    for (int i = 0; i < n_result; i++)
        for (int j = 0; j < m_result; j++)
            for (int k = 0; k < m_first; k++) matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
}

void transpose(int **matrix, int n, int m, int **matr1) {
    int *ptr = (int *)(matrix + n);
    for (int i = 0; i < n; i++) matrix[i] = ptr + m * i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) matrix[i][j] = 0;

    for (int i = 0; i < ((n < m) ? n : m); i++) matrix[i][i] = matr1[i][i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) matrix[i][j] = matr1[j][i];
}