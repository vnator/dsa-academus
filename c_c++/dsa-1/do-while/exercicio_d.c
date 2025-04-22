#include <stdio.h>
int main() {
  int i = 1, n, lb, lbi = 1;
  scanf("%d %d", &lb, &n);
  do {
    printf("%d", i);
    if (lb == lbi) {
      printf("\n");
      lbi=0;
    } else {
      printf(" ");
    }

    i++;
    lbi++;
  } while (i <= n);

  return 0;
}
