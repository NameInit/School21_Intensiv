/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int first_number(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, mass[NMAX];
    if (!input(mass, &n)) {
        printf("n/a");
        return -1;
    }
    printf("%d", first_number(mass, n));
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if (*n < 1) return 0;
    for (int *p = a; p - a < *n; p++)
        if (!scanf("%d", p)) return 0;
    return 1;
}

int first_number(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] >= mean(a, n)) && (a[i] != 0) &&
            (a[i] <= (mean(a, n) + 3 * sqrt(variance(a, n)))))
            return a[i];
    }
    return 0;
}

double mean(int *a, int n) {
    double ans;
    for (int i = 0; i < n; i++) ans += a[i];
    ans = ans / n;
    return ans;
}

double variance(int *a, int n) {
    double mean_v = 0;
    double ans = 0;
    for (int *p = a; p - a < n; p++) {
        mean_v += *p;
    }
    mean_v = mean_v / n;
    for (int *p = a; p - a < n; p++) {
        ans += (mean_v - *p) * (mean_v - *p);
    }
    ans = ans / n;
    return ans;
}