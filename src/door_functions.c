#include <math.h>
#include <stdio.h>

int main() {
  FILE *file;
  if ((file = fopen("data/door_data.txt", "w")) == NULL) {
    printf("n/a");
    return -1;
  }
  double pi = -3.141592653;
  double step = pi / 20.5;
  for (int i = 0; i < 42; i++) {
    fprintf(file, "%.7lf | %.7lf | ", pi, 1 / (1 + pi * pi));
    ((sqrt(1 + 4 * pi * pi) - pi * pi - 1) < 0)
        ? fprintf(file, "-")
        : fprintf(file, "%.7lf", sqrt(sqrt(1 + 4 * pi * pi) - pi * pi - 1));
    (pi == 0) ? fprintf(file, " | -\n")
              : fprintf(file, " | %.7lf\n", 1 / (pi * pi));
    pi -= step;
  }
  return 0;
}