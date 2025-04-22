#include <stdio.h>

int main() {

  int x, *px;
  x = 10;
  px = &x;

  printf("x = %d\n", x);
  printf("px = %p\n", px);

  *px *= 10;
  printf("x = %d\n", x);
  printf("px = %p\n", px);

  px += 2;
  printf("x = %d\n", x);
  printf("px = %p\n", px);
}
