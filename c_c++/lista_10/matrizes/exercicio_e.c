#include <stdio.h>


int main() {
  int n;

  printf("Qual o limite de linhas da matriz?\n");
  scanf("%d", &n);

  int mtx_a[n][2];
  int mtx_b[n][2];

  printf("Entre com os algarismos da sua matriz %dx2\n", n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <2; j++) {
      scanf("%d", &mtx_a[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <2; j++) {
      mtx_b[i][j] = mtx_a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <2; j++) {
      printf("%d\n", mtx_b[i][j]);
    }
  }

  return 0;
}
