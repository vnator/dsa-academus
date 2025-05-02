#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int a;

  printf("Qual o tamanho do array: ");
  scanf("%d", &a);

  int *array = malloc(a * sizeof(int));

  printf("Preencha o array, e use enter apos digitar cada numero \n");
  for (int i = 0; i < a; i++)
    scanf("%d", &array[i]);

  printf("Revertendo o array \n");

  for (int i = a - 1; i >= 0; i--)
    printf("%d, ", array[i]);

  free(array);
  return 0;
}
