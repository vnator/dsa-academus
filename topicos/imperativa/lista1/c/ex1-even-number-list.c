#include <stdio.h>
#include <stdlib.h>

int main() {

  int input, counter = 0;

  printf(" Entre com o tamanho do conjunto: ");
  scanf("%d", &input);

  int *list = malloc(input * sizeof(int));

  printf("\n Entre com os valores da lista: ");

  for (int i = 0; i < input; i++) {
    scanf("%d", list + i);
  }

  for (int i = 0; i < input; i++) {
    if (!(list[i] % 2))
      counter++;
  }

  printf("\n %d dos numeros informados sao pares", counter);

  free(list);
  return 0;
}
