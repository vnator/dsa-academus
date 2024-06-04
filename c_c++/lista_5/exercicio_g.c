#include <stdio.h>

int main() {
  char nome[100], sexo;
  int idade, exercicio_militar = 0, resposta_alistamento = 0;

  printf("Digite seu nome: ");
  scanf("%99[^\n]", nome);

  printf("Digite seu sexo (m/f): ");
  scanf(" %c", &sexo);

  printf("Digite sua idade: ");
  scanf("%d", &idade);

  exercicio_militar = (sexo == 'm' || sexo == 'M') && idade == 18 ? 1 : 0;

  if (exercicio_militar) {
    printf("Você já se alistou? 1 = sim, 0 = nao: ");
    scanf("%d", &resposta_alistamento);

    if (resposta_alistamento) {
      printf("Obrigado por se Alistar.\n");
    } else {
      printf("Procure a agencia nacional das forças armadas.\n");
    }
  }

  return 0;
}
