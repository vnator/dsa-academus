// B. Faça uma solução para decidir o diagnóstico a partir de possíveis
// enfermidades.
// que o paciente sinta enjoo e, adicionalmente, outras possíveis
// enfermidades a serem verificadas:
// 1: febril e dores no corpo
// 2: dores no corpo ou olhos vermelhos e aparência pálida
// 3: tosse e inflamação
// 4: caso contrário

#include <stdio.h>

int main() {
  int febril, dores_corpo, olhos_vermelhos, palido, tosse, inflamacao;

  printf("diagnóstico de um paciente que está apresentando enjoos.\n");

  printf("\nFebril? 1 - SIM, 0 - Não: ");
  scanf("%d", &febril);

  printf("\ndores pelo corpo? 1 - SIM, 0 - Não: ");
  scanf("%d", &dores_corpo);

  printf("\nolhos estão vermelhos? 1 - SIM, 0 - Não: ");
  scanf("%d", &olhos_vermelhos);

  printf("\nestá palido? 1 - SIM, 0 - Não: ");
  scanf("%d", &palido);

  printf("\nestá tossindo muito? 1 - SIM, 0 - Não: ");
  scanf("%d", &tosse);

  printf("\ntem alguma inflamação? 1 - SIM, 0 - Não: ");
  scanf("%d", &inflamacao);

  if (febril && dores_corpo) {
    printf("\ndiagnóstico 1");
  } else if (dores_corpo || (olhos_vermelhos && palido)) {
    printf("\ndiagnóstico 2");
  } else if (tosse && inflamacao) {
    printf("\ndiagnóstico 3");
  } else {
    printf("\ndiagnóstico 4");
  }
}
