#include <math.h>
#include <stdio.h>

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
      printf("\nOpcao secreta, potencia: ");
      break;
  }

  c = pow(a, b);
  printf("%d", c);
  
  return 0;
}
