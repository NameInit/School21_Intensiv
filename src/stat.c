#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a");
        return -1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if (*n < 1) return 0;
    for (int *p = a; p - a < *n; p++)
        if (!scanf("%d", p)) return 0;
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) putchar(' ');
    }
    putchar('\n');
}

int max(int *a, int n) {
    int ans = a[0];
    for (int *p = a; p - a < n; p++) {
        if (ans < *p) ans = *p;
    }
    return ans;
}

int min(int *a, int n) {
    int ans = a[0];
    for (int *p = a; p - a < n; p++) {
        if (ans > *p) ans = *p;
    }
    return ans;
}

double mean(int *a, int n) {
    double ans = 0;
    for (int *p = a; p - a < n; p++) {
        ans += *p;
    }
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}