#include <stdio.h>
#include <stdlib.h>
#define N_STAT 100

void fil_matrix_stat(int mass[][N_STAT], int row, int col);
int fil_matrix_dyn1(int **mass, int row, int col);
int fil_matrix_dyn2(int **mass, int row, int col);
int fil_matrix_dyn3(int **mass, int row, int col, int *ptr);
void output_stat_matrix(int mass[][N_STAT], int row, int col);
void output_dyn_matrix(int **mass, int row, int col);

int main() {
    int rezhim = 0;
    if ((!scanf("%d", &rezhim)) || (rezhim <= 0) || (rezhim >= 5)) {
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
            int mass[N_STAT][N_STAT];
            fil_matrix_stat(mass, row, col);
            output_stat_matrix(mass, row, col);
            break;
        }
        case 2: {
            int **mass = malloc(col * row * sizeof(int) + row * sizeof(int *));
            if (!fil_matrix_dyn1(mass, row, col)) {
                free(mass);
                return -1;
            }
            output_dyn_matrix(mass, row, col);
            free(mass);
            break;
        }
        case 3: {
            int **mass = malloc(row * sizeof(int *));
            if (!fil_matrix_dyn2(mass, row, col)) {
                for (int i = 0; i < row; i++) free(mass[i]);
                free(mass);
                return -1;
            }
            output_dyn_matrix(mass, row, col);
            for (int i = 0; i < row; i++) free(mass[i]);
            free(mass);
            break;
        }
        case 4: {
            int **mass = malloc(row * sizeof(int *));
            int *ptr = malloc(row * col * sizeof(int));
            if (!fil_matrix_dyn3(mass, row, col, ptr)) {
                free(ptr);
                free(mass);
                return -1;
            }
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

void output_stat_matrix(int mass[][N_STAT], int row, int col) {
    int max[3] = {0};
    int min[3] = {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", mass[i][j]);
            if ((j + 1) != col) putchar(' ');
        }
        putchar('\n');
    }
    for (int i = 0; i < row; i++) {
        max[i] = mass[i][0];
        for (int j = 0; j < col; j++)
            if (max[i] < mass[i][j]) max[i] = mass[i][j];
    }

    for (int i = 0; i < col; i++) {
        min[i] = mass[0][i];
        for (int j = 0; j < row; j++)
            if (min[i] > mass[j][i]) min[i] = mass[j][i];
    }
    for (int i = 0; i < 3; i++) {
        printf("%d", max[i]);
        if ((i + 1) != 3) putchar(' ');
    }
    putchar('\n');
    for (int i = 0; i < 3; i++) {
        printf("%d", min[i]);
        if ((i + 1) != 3) putchar(' ');
    }
}

void fil_matrix_stat(int mass[][N_STAT], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!scanf("%d", &mass[i][j])) {
                printf("n/a");
                exit(-1);
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

void output_dyn_matrix(int **mass, int row, int col) {
    int max[3] = {0};
    int min[3] = {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", mass[i][j]);
            if ((j + 1) != col) putchar(' ');
        }
        putchar('\n');
    }
    for (int i = 0; i < row; i++) {
        max[i] = mass[i][0];
        for (int j = 0; j < col; j++)
            if (max[i] < mass[i][j]) max[i] = mass[i][j];
    }

    for (int i = 0; i < col; i++) {
        min[i] = mass[0][i];
        for (int j = 0; j < row; j++)
            if (min[i] > mass[j][i]) min[i] = mass[j][i];
    }
    for (int i = 0; i < 3; i++) {
        printf("%d", max[i]);
        if ((i + 1) != 3) putchar(' ');
    }
    putchar('\n');
    for (int i = 0; i < 3; i++) {
        printf("%d", min[i]);
        if ((i + 1) != 3) putchar(' ');
    }
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