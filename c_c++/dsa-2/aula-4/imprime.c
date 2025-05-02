#include <malloc.h>
#include <stdio.h>

int main() {
  int *x, *y;

  x = (int *)malloc(sizeof(int));
  *x = 123;
  y = (int *)malloc(sizeof(int));
  *y = 456;
  y = x;

  printf("\n*x: %d", *x);
  printf("\n*y: %d", *y);
  printf("\nx: %d", x);
  printf("\ny: %d", y);
}
