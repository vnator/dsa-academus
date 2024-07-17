#include <stdio.h>
#include <string.h>

int main() {
  int t, n, i = 0;

  scanf("%d", &t);
  while (i < t) {
    char def1[20], def2[20];

    scanf("%d", &n);
  
    if (n == 0) {
      printf("NULL\n");
    } else {
      
      if (n%2==0) {
        if (n > 0) {
          printf("EVEN POSITIVE\n");
        } else {
          printf("EVEN NEGATIVE\n");
        }
      } else {
        if (n > 0) {
          printf("ODD POSITIVE\n");
        } else {
          printf("ODD NEGATIVE\n");
        }
      }
    }

    i++;
  }
}
