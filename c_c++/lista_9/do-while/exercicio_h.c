#include <stdio.h>
#include <math.h>

int main() {
  int a, b, c;

  do {
    scanf("%d %d %d", &a, &b, &c);

    if (!a || !b || !c)
      break;

    printf("%d\n", (int)sqrt(a*b*100/c));
  } while (a && b && c);

  return 0;
}
