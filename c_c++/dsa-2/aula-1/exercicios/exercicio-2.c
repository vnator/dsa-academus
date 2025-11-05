#include <stdio.h>

int main() {
  int *px;
  int x[] = {10, 7, 2, 6, 3};
  px = x;

  printf("*px = %d\n", *px);
  printf("*(px + 2) = %d\n", *(px + 2));
  printf("px[4] = %d\n", px[4]);
  printf("px[1] = %d\n", px[1]);
  printf("*(x + 3) = %d\n", *(x + 3));
}
