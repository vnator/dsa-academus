#include <stdio.h>

int main() {
  float saldo;
  float *Psaldo;
  Psaldo = &saldo;

  scanf("%f", Psaldo);
  printf("\n");
  printf("%f", saldo);
}
