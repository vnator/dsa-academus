#include <stdio.h>

int main() {
  float s = 1, r;
  int i=2, j=3 ,limit = 39;

  do {
    r = (float)j/i;
    s = s + r;
    i += i;
    j += 2;
  } while(j <= limit);

  printf("%.2f\n", s);

  return 0;
}
