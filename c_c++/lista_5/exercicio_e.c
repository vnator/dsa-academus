#include <stdio.h>

int main() {
  float salario, porcentagem = 1.0 / 10;

  printf("Informe seu salario: ");
  scanf("%f", &salario);

  if (salario < 2000) {
    porcentagem = salario * porcentagem;
    salario += porcentagem;

    printf("\nSalário reajustado para: %f", salario);
  }
}
