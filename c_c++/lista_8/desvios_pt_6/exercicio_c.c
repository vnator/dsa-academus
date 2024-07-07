// C. Faça uma solução que permita ao usuário fornecer dois números inteiros e
// escolher dentre as opções: calcular a média, calcular a soma, calcular o módulo
// dos números, ou mostrar o maior e o menor. Mostrar os número informados, a
// operação realizada e o resultado da operação

#include <stdio.h>
#include <math.h>

int main () {
  int a, b, c;

  printf("Entre com primeiro valor: ");
  scanf("%d", &a);

  
  printf("Entre com segundo valor: ");
  scanf("%d", &b);

  printf("Escolha a operacao:  0 media, 1 soma, 2 modulo dos dois, 3+ qual o maior");
  scanf("%d", &c);

  switch (c) {
    case 0:
      printf("Media - (%d+%d)/2 = %d", a, b, (a+b)/2);
      break;
    case 1:
      printf("Soma - %d+%d = %d", a, b, a+b);
      break;
    case 2:
      printf("Modulo - |%d| |%d|", a < 0 ? a*(-1) : a, b < 0 ? b*(-1) : b);
      break;
    default:
      a > b
        ? printf("Maior: %d > %d", a, b)
        : printf("Maior: %d > %d", b, a);
      break;
  }

  return 0;
}

