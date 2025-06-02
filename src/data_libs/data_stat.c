#include "data_stat.h"

double max(double *data, int n) {
    double ans = data[0];
    for (int i = 1; i < n; i++)
        if (ans < data[i]) ans = data[i];
    return ans;
}

double min(double *data, int n) {
    double ans = data[0];
    for (int i = 1; i < n; i++)
        if (ans > data[i]) ans = data[i];
    return ans;
}

double mean(double *data, int n) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += data[i];
    }
    ans = ans / n;
    return ans;
}

double variance(double *data, int n) {
    double mean_v = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        mean_v += data[i];
    }
    mean_v = mean_v / n;
    for (int i = 0; i < n; i++) {
        ans += (mean_v - data[i]) * (mean_v - data[i]);
    }
    ans = ans / n;
    return ans;
}
