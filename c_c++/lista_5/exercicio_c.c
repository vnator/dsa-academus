#include <stdio.h>

int main() {
  int vec[5], i = 0;

  printf("Verificando se os os proximos 5 digitos informados multiplos de 3\n");

  while (i < 5) {
    printf("Digite um núnero: ");
    scanf("%d", &vec[i]);

    if (vec[i] % 3 == 0) {
      printf("%d é multiplo de 3\n\n", vec[i]);
    } else {
      printf("%d NÃO é multiplo de 3\n\n", vec[i]);
    }

    i++;
  }
}
