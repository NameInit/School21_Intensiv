#include <stdio.h>
#include <stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int picture[][M], int n, int m);
void reset_picture(int picture[][M], int n, int m);
void show_picture(int picture_data[][M], int n, int m);

int main() {
    int picture_data[N][M];
    reset_picture(picture_data, N, M);
    make_picture(picture_data, N, M);
    show_picture(picture_data, N, M);
    return 0;
}

void make_picture(int picture[][M], int n, int m) {
    const int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int tree_trunk[] = {7, 7, 7, 7};
    const int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    for (int i = 0; i < m; i++) picture[0][i] = picture[n - 1][i] = picture[n / 2][i] = frame_w[i];

    for (int i = 0; i < n; i++) picture[i][0] = picture[i][m - 1] = picture[i][m / 2] = frame_h[i];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++) picture[1 + i][7 + j] = sun_data[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = (i % 3 == 0); j < 4 - (i % 3 == 0); j++) picture[2 + i][2 + j] = tree_foliage[0];

    for (int i = 0; i < 6; i++) {
        if (i == 1) continue;
        for (int j = (i != 5); j < 4 - (i != 5); j++) picture[6 + i][2 + j] = tree_trunk[0];
    }
}

void reset_picture(int picture[][M], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) picture[i][j] = 0;
}

void show_picture(int picture_data[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture_data[i][j]);
            if ((j + 1) != m) putchar(' ');
        }
        if ((i + 1) != n) putchar('\n');
    }
}