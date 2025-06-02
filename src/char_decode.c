#include <stdio.h>

void dek() {
  int a;
  int flag_error = 1;
  while (scanf("%X", &a)) {
    if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z'))) {
      flag_error = 0;
      printf("%c ", a);
      if (getchar() != 32) {
        putchar('\n');
        return;
      }
    } else
      break;
  }
  if (flag_error)
    printf("n/a\n");
}

void kod() {
  char a;
  int flag_error = 1;
  while (scanf("%c", &a)) {
    if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z'))) {
      flag_error = 0;
      printf("%X ", a);
      if (getchar() != 32) {
        putchar('\n');
        return;
      }
    } else
      break;
  }
  if (flag_error)
    printf("n/a\n");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("n/a\n");
    return -1;
  }
  if ((argv[1][1] != 0) || (argv[1][0] > '1') || (argv[1][0] < '0')) {
    printf("n/a\n");
    return -1;
  }
  (argv[1][0] == '0') ? kod() : dek();
  return 0;
}