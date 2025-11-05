#include <stdio.h>
#define N 5

int main() {

  int x[N] = {10, 20, 30, 40, 50};
  int *px;
  px = x;

  for (int i = 5 - 1; i >= 0; i--) {
    printf(" x = %d \n", px[i]);
  }

  return 0;
}
