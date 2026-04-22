#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;

  printf("Qual o tamanho do array: ");
  scanf("%d", &size);

  int *list = malloc(sizeof(int) * size);

  printf("\nDigite uma lista de numeros separados por espaco e pressione ENTER "
         "quando terminar: ");

  for (int i = 0; i < size; i++) {
    scanf("%d", list + i);
  }

  for (int i = size - 1; i >= 0; i--) {
    printf("%d ", list[i]);
  }

  return 0;
}
