#include <conio.h>
#include <stdio.h>

int tam_str(char st[]);

int main(void) {

  printf("%d", tam_str("Algoritmos e Estruturas de Dados"));

  getch();
  return 0;
}

int tam_str(char st[]) {
  int i;

  for (i = 0; *(st + i) != '\0'; i++)
    ;

  return i;
}
