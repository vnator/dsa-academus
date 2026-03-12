#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, count = 0;

  scanf("%d", &n);

  int *array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    scanf("%d", array + i);
  }

  for (int i = 0; i < n; i++) {
    if (!(array[i] % 2)) {
      count++;
    }
  }

  printf("pares: %d", count);

  free(array);
  return 0;
}
