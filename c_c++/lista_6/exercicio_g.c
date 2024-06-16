// G. Faça uma solução para ler dois números inteiros. Em seguida, peça ao
// usuário escolher uma das opções abaixo. Mostre uma mensagem dizendo a
// operação escolhida e o resultado da operação
// • Soma
// •  Subtração
// • Divisão
// • Módulo
// • Dobro dos dois
// • Quadrado dos dois
#include <stdio.h>

int main() {
  int a, b, c;

  printf("Escreva o primeiro numero: ");
  scanf("%d", &a);

  printf("\nEscreva o segundo numero: ");
  scanf("%d", &b);
 
  printf("\nEscolha a operação: \n 1 - Soma: \n 2 - Subtração: \n 3 - Divisão: \n 4 - Módulo: \n 5 - Dobro dos dois: \n 6 - Quadrado dos dois: \n -> ");
  scanf("%d", &c);

  switch (c) {
    case 1:
      printf("\n Soma: %d", a+b);
      break;
    case 2:
      printf("\n Subtração: %d", a-b);
      break;
    case 3:
      printf("\n Divisão: %d", a/b);
      break;
    case 4:
      printf("\n Módulo: %d", a%b);
      break;
    case 5:
      printf("\n Dobro de %d: %d", a, a*2);
      printf("\n Dobro de %d: %d", b, b*2);
      break;
    case 6:
      printf("\n Quadrado de %d: %d", a, a*a);
      printf("\n Quadrado de %d: %d", b, b*b);
      break;

    default:
      printf("Operação não listada");
      break;
  }

  return 0;
}

