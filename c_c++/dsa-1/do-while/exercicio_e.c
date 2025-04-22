#include <stdio.h>

int main() {
  float s = 1, r;
  int i=2, limit = 100;

  do {
    r = (float)1/i; 
    s = s + r;
    i++;
  } while(i <= limit);

  printf("%.2f\n", s);

  return 0;
}
