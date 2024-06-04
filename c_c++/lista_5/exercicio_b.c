#include <stdio.h>

int main() {
  float side, area;

  printf("vamos calcular a area de um quadrado.\n\n Digite o valor de um dos "
         "lados: ");
  scanf("%f", &side);

  area = side * side;

  if (area <= 0) {
    printf("Erro: area %f do quadrado tem um valor invalido.", area);
  } else {
    printf("Valor da area do quadrado é %f", area);
  }

  return 0;
}
