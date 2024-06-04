#include <math.h>
#include <stdio.h>

int main() {
  // EXERCICIO_1
  // a) Calculo Area
  // faça uma solução para calcular e mostrar a area ao quadrado
  float raio, pi = acos(-1.0), area;

  printf("Escreva o raio do circulo: ");
  scanf("%f", &raio);

  area = pi * pow(raio, 2);
  printf("Area = %f ", area);
}

