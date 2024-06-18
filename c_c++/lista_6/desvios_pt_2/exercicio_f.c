// F. Faça uma solução para determinar se um número informado pelo usuário é
// positivo, negativo ou zero
#include <stdio.h>

int main() {
  int a;

  printf("Digite um numero: ");
  scanf("%d", &a);

  if (a > 0) {
    printf("\n%d é positivo", a);
  } else {
    a < 0
      ? printf("\n%d é negativo", a)
      : printf("\n%d é zero", a);
  }
}
