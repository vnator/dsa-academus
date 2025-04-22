#include <stdio.h>

int main() {
  int n, i = 1, result = 1;

  scanf("%d", &n);
  

  while (i <= n && n < 13) {
    result = result*i;
    i++;
  }
  
  printf("%d\n", result);
}
