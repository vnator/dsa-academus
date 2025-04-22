#include <stdio.h>

int main() {
  int mtx_a[3][2];
  int mtx_b[3][2];
  int mtx_c[3][2];

  printf("Entre com os algarismos da sua matriz A 3x2\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <2; j++) {
      scanf("%d", &mtx_c[i][j]);
    }
  }

  printf("Entre com os algarismos da sua matriz B 3x2\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <2; j++) {
      scanf("%d", &mtx_b[i][j]);
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <2; j++) {
      mtx_c[i][j] =  mtx_a[i][j] + mtx_b[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <2; j++) {
      printf("%d", mtx_c[i][j]);
    }
  }

  return 0;
}
