#include <math.h>
#include <stdio.h>

int main() {

  int a, b, r_soma, r_sub, r_div, r_mult, r_mod, r_doub_a, r_doub_b, r_pow_a,
      r_pow_b;

  printf("Digite o primeiro valor: ");
  scanf("%d", &a);

  printf("Digite o segundo valor: ");
  scanf("%d", &b);

  r_soma = a + b;
  r_sub = a - b;
  r_mult = a * b;
  r_div = a / b;
  r_mod = a % b;
  r_doub_a = a * 2;
  r_doub_b = b * 2;
  r_pow_a = pow(a, 2);
  r_pow_b = pow(b, 2);

  printf("\nSoma: %d ", r_soma);
  printf("\nSubtração: %d ", r_sub);
  printf("\nMultiplicação: %d ", r_mult);
  printf("\nDivisão: %d ", r_div);
  printf("\nResto: %d ", r_mod);
  printf("\nDobro do primeiro: %d ", r_doub_a);
  printf("\nDobro do segundo: %d ", r_doub_b);
  printf("\nQuadrado do primeiro: %d ", r_pow_a);
  printf("\nQuadrado do segundo: %d ", r_pow_b);
}
