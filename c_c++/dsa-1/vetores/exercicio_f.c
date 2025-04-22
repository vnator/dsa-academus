#include <stdio.h>

int main() {
  int a, b = 0;

  scanf("%d", &a);

  int n[a];
  for (int i = 0; i < a; i++) {
    scanf("%d", &n[i]);

    if (n[i] < n[i-1] && i > 0) {
      b = i+1;
      break;
    }
  }

  printf("%d\n", b);

  return 0;
}
