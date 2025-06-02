#include <stdio.h>

int delenie(int a, int b) {
  int ans = 0;
  while (a >= b) {
    a -= b;
    ans++;
  }
  return ans;
}

int is_prime(int a) {
  for (int i = 2; i < a; i++) {
    if (delenie(a, i) * i == a)
      return 0;
  }
  return 1;
}

int nod(int a) {
  int ans;
  if (a < 0)
    a = -a;
  for (ans = a; ans != 0; ans--) {
    if ((is_prime(ans)) && (delenie(a, ans) * ans == a))
      break;
  }
  if (a == 0)
    ans = 2;
  return ans;
}

int main() {
  int num;
  if (scanf("%d", &num) != 1) {
    printf("n/a\n");
    return -1;
  }

  if (num == 1) {
    printf("Number 1 don\'t have nod\n");
    return 0;
  }

  printf("%d\n", nod(num));
  return 0;
}