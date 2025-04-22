#include <stdio.h>
#include <time.h>

int main(void) {
  int casado, ano_casamento=0, ano_atual=0, filhos=0, idade_filho=0;
  float pretensao_salarial;
  time_t data_ano;
  time(&data_ano);
  struct tm *data = localtime(&data_ano);
  ano_atual = (data->tm_year+1900);

  printf("É casado? 1 = sim, 0 = não: ");
  scanf("%d", &casado);

  if (casado) {
    printf("\nqual o ano do seu casamento? ");
    scanf("%d", &ano_casamento);

    if (ano_casamento+2 < ano_atual) {
      printf("\nquantos filhos? ");
      scanf("%d", &filhos);
      
      printf("\nqual a idade do mais novo? ");
      scanf("%d", &idade_filho);
    }
  }

  printf("\nQual sua pretensão salarial? ");
  scanf("%f", &pretensao_salarial);

  printf("\nCasado: ");
  casado ? printf("sim") : printf("nao");
  
  printf("\ncasado desde: %d", ano_casamento);

  printf("\nquantidade filhos: %d", filhos);
  
  printf("\nidade do filho mais jovem: %d", idade_filho);

  printf("\npretenção salarial: R$: %.2f", pretensao_salarial);

  return 0;
}
