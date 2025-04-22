#include <stdio.h>
#include <math.h>

int main() {
  int a, b, c, escolha;

  printf("Entre com o primeiro valor");
  scanf("%d", &a);

  printf("\nEntre com o segundo valor");
  scanf("%d", &b);
 
  printf("\nEscolha uma operacao: 1 - soma, 2 - subtracao, 3 - multiplicacao, 4 - divisao");
  scanf("%d", &escolha);

  switch(escolha) {
    case 1:
      c = a + b;
      printf("\nSoma: ");
      break;
    case 2:
      c = a - b;
      printf("\nSubtracao: ");
      break;
    case 3:
      c = a * b;
      printf("\nMultiplicacao: ");
      break;
    case 4:
      c = a / b;
      printf("\nDivisao: ");
      break;
    default:
      printf("\nOpcao secreta a soma do dobro dos dois: ");
      c = a*2 + b*2;
      break;
  }

  printf("%d", c);
  
  return 0;
}
