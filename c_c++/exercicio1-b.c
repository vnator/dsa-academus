#include <stdio.h>

int main() {
  // EXERCIOCIO_1
  // b) calculo area triangulo
  // Faça uma solução para calcular a area de um triangulo
  float base, height;

  printf("Digite a base do triangulo: ");
  scanf("%f", &base);

  printf("Digite a altura do triangulo: ");
  scanf("%f", &height);

  printf("%f", ((base * height) / 2));

  return 0;
}
