#include <stdio.h>

int main() {
  int a, b, c;

  scanf("%d", &a);

  int n[a];
  for (int i = 0; i < a; i++) {
    scanf("%d", &n[i]);

    if (n[i] < b || i == 0) {
      b = n[i];
      c = i;
    }
  }

  printf("Menor valor: %d\nPosicao: %d\n", b, c);

  return 0;
}
