#include <stdio.h>

int main() {
  int n[10];
  
  for (int i = 0; i < 10; i++) {
    scanf("%d", &n[i]);

    if (n[i] < 1)
      n[i] = 1;

    printf("X[%d] = %d\n", i, n[i]);
  }

  return 0;
}

