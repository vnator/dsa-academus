#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  struct tm data_nascimento = {0};

  int ano = 0;
  int mes = 0;
  int dia = 0;

  printf("digite seu ano de nascimento: ");
  scanf("%d", &ano);
  data_nascimento.tm_year = ano - 1900;

  printf("digite seu mes de nascimento: ");
  scanf("%d", &mes);
  data_nascimento.tm_mon = mes - 1;

  printf("digite seu dia de nascimento: ");
  scanf("%d", &dia);
  data_nascimento.tm_mday = dia;

  time_t agora = time(NULL);
  time_t data_nascimento_convertida = mktime(&data_nascimento);

  double diferenca_segundos = difftime(agora, data_nascimento_convertida);

  int idade = (int)(diferenca_segundos / (365.25 * 24 * 3600));

  if (idade >= 16) {
    printf("\npode votar");
  } else {
    printf("\nainda não pode votar, ta muito xovem só tem %d anos.", idade);
  }

  return 0;
}
