#include <stdio.h>

int main() {
  int i = 0, n, l, j;

  scanf("%d", &l);
  do {
    scanf("%d", &n);
    j = 2;
    do {

      if (n%j == 0)
        break;

      j++;
    } while (j <= n);

    j == n || n == 2
      ? printf("%d eh primo\n", n) 
      : printf("%d nao eh primo\n", n);

    i++;
  } while (i < l);

  return 0;
}
