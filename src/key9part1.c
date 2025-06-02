/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int mass[NMAX];
    int n;
    int numbers[NMAX];
    int len_num, sum;
    if (!input(mass, &n)) {
        printf("n/a");
        return -1;
    }
    sum = sum_numbers(mass, n);
    len_num = find_numbers(mass, n, sum, numbers);
    if ((sum == -1) || (len_num == 0)) {
        printf("n/a");
        return -1;
    }
    printf("%d\n", sum);
    output(numbers, len_num);
    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = -1;

    for (int i = 0; i < length; i++) {
        if ((buffer[i] % 2 == 0) && (sum == -1)) sum = 0;
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int p = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) continue;
        if ((number % buffer[i]) == 0) {
            numbers[p] = buffer[i];
            p++;
        }
    }
    return p;
}

int input(int *buffer, int *length) {
    if (!scanf("%d", length)) return 0;
    if (*length > 10) return 0;
    if (*length < 1) return 0;
    for (int *p = buffer; p - buffer < *length; p++)
        if (!scanf("%d", p)) return 0;
    return 1;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer + 1 < length) putchar(' ');
    }
}