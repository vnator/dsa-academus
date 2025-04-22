#include <stdio.h>

void exibe_e_altera(int a, int b, int c);

int main(void) {
  int a = 1, b = 2, c = 3;

  exibe_e_altera(a, b, c);
  printf(" fora da funcao: %d %d %d\n", a, b, c);

  return 0;
}

void exibe_e_altera(int a, int b, int c) {
  a += 100;
  b += 200;
  c += 300;

  printf(" dentro da funcao: %d %d %d\n", a, b, c);
}
