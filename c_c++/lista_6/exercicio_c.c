// C. Escreva uma solução para ler as dimensões de um retângulo (base e
// altura), calcular e escrever a área do retângulo. Se os lados forem iguais,
// escreva “QUADRADO”, caso contrário escreva “RETÂNGULO”. Faça uma
// solução utilizando o operador ternário e outra com a estrutura if-else
#include <stdio.h>

int calculoAreaRetanguloIf() {
  float a, b, c;

  printf("Calculo da área do retangulo\n");

  printf("entre com o valor da base\n");
  scanf("%f", &a);

  printf("entre com o valor da altura\n");
  scanf("%f", &b);

  c = a * b;

  printf("Area: %f\n", c);

  if (a > b) {
    printf("QUADRADO\n");
  } else {
    printf("RETANGULO\n");
  }

  return 0;
}

int calculoAreaRetanguloTernario() {
  float a, b, c;

  printf("Calculo da área do retangulo\n");

  printf("entre com o valor da base\n");
  scanf("%f", &a);

  printf("entre com o valor da altura\n");
  scanf("%f", &b);

  c = a * b;

  printf("Area: %f\n", c);

  a > b
    ? printf("QUADRADO\n")
    : printf("RETANGULO\n");

  return 0;
}
