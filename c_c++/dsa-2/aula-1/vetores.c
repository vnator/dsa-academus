#include <stdio.h>
#define MAX 4

int main(void) {

  int vet[MAX] = {10, 20, 30, 40};

  int count = 0;
  int *pvet;

  pvet = vet;

  for (; count < MAX; count++) {
    printf("Endereço do vetor[%d]: %d\n", count, *pvet);
    pvet++;
  }

  return 0;
}
