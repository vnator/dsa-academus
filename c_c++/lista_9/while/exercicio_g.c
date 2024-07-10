#include <stdio.h>

int main() {

  int t, pa, pb, i, j = 1;
  float ga, gb;

  scanf("%d", &t);
  while (i < t) {
    scanf("%d %d %f %f", &pa, &pb, &ga, &gb);  
    
    while (1) {
      pa += pa*(ga/100);
      pb += pb*(gb/100);
      
      if (pa > pb) {
        printf("%d anos.\n", j);
        break;
      }

      j++;

      if (j>100) {
        printf("Mais de 1 seculo.\n");
        break;
      }
    }

    j=1;
    i++;
  }

  return 0;
}
