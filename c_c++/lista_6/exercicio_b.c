// B. Faça uma solução para ler dois números inteiros. Escreva uma mensagem
// dizendo qual deles é o maior. Utilize a estrutura ternária
// <condicao> ? <instrucao1> : <instrucao2>;
#include <stdio.h>

int main () {
  int a, b;
  char *message = "%d é maior que %d";

  printf("Escreva o primeiro numero: ");
  scanf("%d", &a);

  printf("\nEscreva o segundo numero: ");
  scanf("%d", &b);
  
  a > b ? printf(message, a, b) : printf(message, b, a);
  
  return 0;
}
