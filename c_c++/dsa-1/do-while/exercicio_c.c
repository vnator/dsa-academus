#include <stdio.h>

int main() {
  int n, entrace_n, i = 0, total = 0, total_rat = 0, total_rabbit = 0, total_toad = 0;
  char species_n;

  scanf("%d", &n);
  do {
    scanf("%d %c", &entrace_n, &species_n);

    total+=entrace_n;

    if (species_n == 'C') {
      total_rabbit+=entrace_n;
    } else if (species_n == 'R') {
      total_rat+=entrace_n;
    } else {
      total_toad+=entrace_n;
    }

    i++;
  } while (i < n);

  printf("Total: %d cobaias\n", total);
  printf("Total de coelhos: %d\n", total_rabbit);
  printf("Total de ratos: %d\n", total_rat);
  printf("Total de sapos: %d\n", total_toad);
  printf("Percentual de coelhos: %.2f %%\n", (float)total_rabbit/total*100);
  printf("Percentual de ratos: %.2f %%\n", (float)total_rat/total*100);
  printf("Percentual de sapos: %.2f %%\n", (float)total_toad/total*100);
}
