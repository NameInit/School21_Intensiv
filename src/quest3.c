#include <stdio.h>

int fib(int num) {
  if ((num == 1) || (num == 2))
    return 1;
  if (num == 0)
    return 0;
  return fib(num - 1) + fib(num - 2);
}

int main() {
  int num;
  if (scanf("%d", &num) != 1) {
    printf("n/a\n");
    return -1;
  }
  printf("%d\n", fib(num));
  return 0;
}