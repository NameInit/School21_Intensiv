#include <stdio.h>
#include <stdlib.h>

int fil_matrix_dyn1(int **mass, int row, int col);
int fil_matrix_dyn2(int **mass, int row, int col);
int fil_matrix_dyn3(int **mass, int row, int col, int *ptr);
void output_dyn_matrix(int **mass, int row, int col);
void change_mass(int **mass, int row, int col);

int main() {
    int rezhim = 0;
    if ((!scanf("%d", &rezhim)) || (rezhim <= 0) || (rezhim >= 4)) {
        printf("n/a");
        return -1;
    }
    int row = 0, col = 0;
    if ((!scanf("%d", &row)) || (!scanf("%d", &col)) || (row <= 0) || (col <= 0) ||
        ((rezhim == 1) && ((col > 100) || (row > 100)))) {
        printf("n/a");
        return -1;
    }
    switch (rezhim) {
        case 1: {
            int **mass = malloc(col * row * sizeof(int) + row * sizeof(int *));
            if (!fil_matrix_dyn1(mass, row, col)) {
                free(mass);
                return -1;
            }
            change_mass(mass, row, col);
            output_dyn_matrix(mass, row, col);
            free(mass);
            break;
        }
        case 2: {
            int **mass = malloc(row * sizeof(int *));
            if (!fil_matrix_dyn2(mass, row, col)) {
                for (int i = 0; i < row; i++) free(mass[i]);
                free(mass);
                return -1;
            }
            change_mass(mass, row, col);
            output_dyn_matrix(mass, row, col);
            for (int i = 0; i < row; i++) free(mass[i]);
            free(mass);
            break;
        }
        case 3: {
            int **mass = malloc(row * sizeof(int *));
            int *ptr = malloc(row * col * sizeof(int));
            if (!fil_matrix_dyn3(mass, row, col, ptr)) {
                free(ptr);
                free(mass);
                return -1;
            }
            change_mass(mass, row, col);
            output_dyn_matrix(mass, row, col);
            free(ptr);
            free(mass);
            break;
        }
        default:
            break;
    }
    return 0;
}

void output_dyn_matrix(int **mass, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", mass[i][j]);
            if ((j + 1) != col) putchar(' ');
        }
        if ((i + 1) != row) putchar('\n');
    }
}

int fil_matrix_dyn1(int **mass, int row, int col) {
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

int fil_matrix_dyn2(int **mass, int row, int col) {
    for (int i = 0; i < row; i++) mass[i] = malloc(col * sizeof(int));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!scanf("%d", &mass[i][j])) {
                printf("n/a");
                return 0;
            }
    return 1;
}

int fil_matrix_dyn3(int **mass, int row, int col, int *ptr) {
    for (int i = 0; i < row; i++) mass[i] = ptr + col * i;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!scanf("%d", &mass[i][j])) {
                printf("n/a");
                return 0;
            }
    return 1;
}

void change_mass(int **mass, int row, int col) {
    int *sum_row = (int *)malloc(sizeof(int) * row);
    int c;

    for (int i = 0; i < row; i++) sum_row[i] = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) sum_row[i] += mass[i][j];

    for (int i = 0; i < row; i++)
        for (int j = i + 1; j < row; j++)
            if (sum_row[i] > sum_row[j])
                for (int k = 0; k < col; k++) {
                    c = mass[i][k];
                    mass[i][k] = mass[j][k];
                    mass[j][k] = c;
                }
    free(sum_row);
}