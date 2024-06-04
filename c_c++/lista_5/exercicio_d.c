#include <stdio.h>

int main() {
  float notas[5], pesos[5] = {2, 3, 3, 4, 1}, soma, media, somaPesos;
  int i = 0;

  printf("digite as notas do aluno\n");

  while (i < 5) {
    printf("\nDigite a %d° nota: ", i + 1);
    scanf("%f", &notas[i]);

    soma += notas[i] * pesos[i];
    somaPesos += pesos[i];
    i++;
  }

  media = soma / somaPesos;

  printf("\n\nMedia ponderada: %f", media);

  return 0;
}
