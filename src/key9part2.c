#include <stdio.h>

#define LEN 100

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
int input(int *a);
void printsum(int *a, int len);
int error(const int *buff1, int len1, const int *buff2, int len2, int *eq);
void printsub(int *a, int len);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int number1[LEN], number2[LEN], asum[LEN + 1], asub[LEN];
    int len1 = 0, len2 = 0, sumlen = 0, sublen = 0, eq;
    len1 = input(number1);
    len2 = input(number2);
    if ((len1 == -1) || (len2 == -1) || (len2 > len1)) {
        printf("n/a");
        return -1;
    }
    if (error(number1, len1, number2, len2, &eq)) {
        printf("n/a");
        return -1;
    }
    sum(number1, len1, number2, len2, asum, &sumlen);
    printsum(asum, sumlen);
    putchar('\n');
    sub(number1, len1, number2, len2, asub, &sublen);
    if (eq) putchar('0');
    printsub(asub, sublen);
    return 0;
}

int input(int *a) {
    int l = 0;
    int c = 0;
    while (1) {
        if (!scanf("%d", &c)) return -1;
        if ((c > 9) || (c < 0)) return -1;
        a[l++] = c;
        if (getchar() == '\n') break;
    }
    while ((a[0] == 0) && (l > 0)) {
        for (int i = 0; i < l; i++) a[i] = a[i + 1];
        l--;
    }
    if (l == 0) a[0] = 0;
    return l;
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int dop = 0;
    int p1 = len1 - 1, p2 = len2 - 1;
    int l = LEN;
    while ((p1 != -1) || (p2 != -1)) {
        if ((p1 == -1) && (p2 != -1)) {
            result[l] = buff2[p2] + dop;
            dop = 0;
            l--;
            p2--;
        } else if ((p1 != -1) && (p2 == -1)) {
            result[l] = buff1[p1] + dop;
            dop = 0;
            l--;
            p1--;
        } else {
            result[l] = buff1[p1] + buff2[p2] + dop;
            dop = 0;
            p1--;
            p2--;
            l--;
        }
        if (result[l + 1] >= 10) {
            dop = 1;
            result[l + 1] -= 10;
        }
    }
    *result_length = LEN - l;
}

void printsum(int *a, int len) {
    for (int i = LEN - len + 1; i < LEN + 1; i++) {
        printf("%d", a[i]);
    }
}

int error(const int *buff1, int len1, const int *buff2, int len2, int *eq) {
    if (len1 > len2) return 0;
    int p = 0;
    while (p < len1) {
        if (buff1[p] < buff2[p]) return 1;
        if (buff1[p] > buff2[p]) return 0;
        p++;
    }
    *eq = 1;
    return 0;
}

void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int l = LEN - 1;
    int p1 = len1 - 1, p2 = len2 - 1;
    int dop = 0;
    while ((p1 != -1) || (p2 != -1)) {
        if (p2 != -1) {
            result[l] = buff1[p1] - buff2[p2] - dop;
            dop = 0;
            p2--;
            p1--;
            l--;
            while (result[l + 1] < 0) {
                dop += 1;
                result[l + 1] += 10;
            }
        } else {
            result[l] = buff1[p1] - dop;
            dop = 0;
            p1--;
            l--;
            while (result[l + 1] < 0) {
                dop += 1;
                result[l + 1] += 10;
            }
        }
    }
    *result_length = LEN - 1 - l;
}

void printsub(int *a, int len) {
    int first = 1;
    for (int i = LEN - len; i < LEN; i++) {
        if (first && (a[i] == 0)) continue;
        first = 0;
        printf("%d", a[i]);
    }
}