#include "matriz.h"
#include <stdio.h>

int main() {
  Matriz *m1 = matriz_criar(3, 3);
  Matriz *m2 = matriz_criar(4, 5);

  matriz_add(m1, 1);
  matriz_add(m1, 2);
  matriz_add(m1, 3);
  matriz_add(m1, 4);
  matriz_add(m1, 5);
  matriz_add(m1, 6);
  matriz_add(m1, 7);
  matriz_add(m1, 8);
  matriz_add(m1, 9);

  matriz_add(m2, 1);
  matriz_add(m2, 2);
  matriz_add(m2, 3);
  matriz_add(m2, 4);
  matriz_add(m2, 5);
  matriz_add(m2, 6);
  matriz_add(m2, 7);
  matriz_add(m2, 8);
  matriz_add(m2, 9);
  matriz_add(m2, 10);
  matriz_add(m2, 11);
  matriz_add(m2, 12);
  matriz_add(m2, 13);
  matriz_add(m2, 14);
  matriz_add(m2, 15);
  matriz_add(m2, 16);
  matriz_add(m2, 17);
  matriz_add(m2, 18);
  matriz_add(m2, 19);
  matriz_add(m2, 20);

  printf("Matriz 1:\n");
  matriz_print(m1);

  printf("Diagonal principal da matriz 1:\n");
  float *dp = matriz_dprincipal(m1);
  printf("{");

  int size = sizeof(dp) / sizeof(dp[0]);

  for (int i = 0; i <= size; i++) {

    printf("%0.2f - posicao i: %d", dp[i], i);

    if (i < size) {
      printf(", ");
    }
  }
  printf("}\n");

  printf("Diagonal secundaria da matriz 1:\n");
  float *ds = matriz_dsecundaria(m1);
  printf("{");

  int size_s = sizeof(ds) / sizeof(ds[0]);

  for (int i = 0; i <= size_s; i++) {

    printf("%0.2f - posicao i: %d", ds[i], i);

    if (i < size_s) {
      printf(", ");
    }
  }
  printf("}\n");

  matriz_atualiza(m1, 1, 1, 0);
  matriz_atualiza(m1, 2, 2, 0);
  matriz_atualiza(m1, 3, 3, 0);
  printf("Atualizada:\n");

  printf("Matriz 2:\n");
  matriz_print(m2);
  matriz_atualiza(m2, 1, 1, 44);
  printf("Atualizada:\n");
  matriz_print(m2);
}
