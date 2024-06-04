#include <stdio.h>

int main() {
  int filhos, ano, mes, dia, anos_empresa, casado_flag;
  float pretencao_salarial;
  char nome[240] = "";

  printf("Qual o seu nome? ");
  scanf("%99[^\n]", nome);

  printf("\nQual a sua pretenção salarial: ");
  scanf("%f", &pretencao_salarial);

  printf("\nVoce possui quantos filhos? ");
  scanf("%d", &filhos);

  printf("\ntrabalhou quantos anos na sua empresa? ");
  scanf("%d", &anos_empresa);

  printf("\nÉ casado?\n1 = sim, 0 = não;\n");
  scanf("%d", &casado_flag);

  if (casado_flag) {
    printf("\nInforme a sua data de Casamento");

    printf("\nDia: ");
    scanf("%d", &dia);

    printf("\nMes: ");
    scanf("%d", &mes);

    printf("\nAno: ");
    scanf("%d", &ano);
  }

  printf(
      "\n\n%s trabalha a %d na sua atual empresa, pediu %f R$ na sua pretenção "
      "salarial, possui %d filhos ",
      nome, anos_empresa, pretencao_salarial, filhos);

  if (casado_flag) {
    printf(" e é casado desde %d/%d/%d", dia, mes, ano);
  }
}
