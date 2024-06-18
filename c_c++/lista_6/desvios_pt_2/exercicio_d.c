// D. Faça uma solução para ler 4 notas de um aluno, de uma mesma disciplina.
// Calcular a média aritmética. Escrever a média aritmética, e escrever se o
// aluno foi aprovado ou reprovado. Será aprovado o aluno que obtiver nota
// maior ou igual a 7

#include <stdio.h>

int main () {
  float notas[4];
  float soma = 0, media;
  
  printf("Calcular a media aritmética");

  for (int i = 0; i < 4; i++) {
    printf("\nDigite a nota %d: ", i+1);
    scanf("%f", &notas[i]);
    soma+= notas[i];
  }

  media = soma/4;

  printf("\nMédia em %f pontos. = ", media);
  media >= 7 ? printf("Aprovado") : printf("Reprovado");

  return 0;
}
