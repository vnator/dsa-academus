// E. Faça uma solução para ler um número inteiro e exibir uma mensagem
// dizendo se ele é par ou ímpar (utilize o operador módulo %)
#include <stdio.h>

int main() {
  int a;

  printf("Digite um numero: ");
  scanf("%d", &a);

  a%2 == 0
    ? printf("%d é par",a)
    : printf("%d é impar", a);

  return 0;
}
