#include <stdio.h>
#include <stdlib.h>

int main() {
  int t, i = 0, j = 0;
  float curr, litle, *runs = (float *)malloc(t * sizeof(float));

  while (scanf("%d", &t) == 1) {
    while (i < t) {
      scanf("%f", &curr);

      if (curr < litle || i == 0)
        litle = curr;

      i++;
    }

    runs[j] = litle;
    j++;
    i=0;
  }

  while(i<j) {
    printf("%.2f\n", runs[i]);
    i++;
  }


  free(runs);
  return 0;
} 
