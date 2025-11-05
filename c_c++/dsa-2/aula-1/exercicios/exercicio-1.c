#include <stdint.h>
#include <stdio.h>

int main() {

  char x = 'A';
  char *pc1, *pc2_alpha, *pc2, *pc3, *pc4;

  pc1 = &x;

  pc2_alpha = pc1 + 1;
  pc2 = pc1++;
  pc3 = pc2 + 4;
  pc4 = pc3 - 5;

  printf("x:   %p\t(decimal: %lu)\n", (void *)&x, (uintptr_t)&x);
  printf("pc1: %p\t(decimal: %lu)\n", (void *)pc1, (uintptr_t)pc1);
  printf("pc2: %p\t(decimal: %lu)\n", (void *)pc2, (uintptr_t)pc2);
  printf("pc3: %p\t(decimal: %lu)\n", (void *)pc3, (uintptr_t)pc3);
  printf("pc4: %p\t(decimal: %lu)\n", (void *)pc4, (uintptr_t)pc4);

  return 0;
}
