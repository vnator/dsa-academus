#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max_common_divisor(int a, int b) {
  if (b == 0)
    return a;

  int r = a % b;

  return max_common_divisor(b, r);
}

int find_next_prime(int *prime_list, int size) {
  int last = size - 1;
  int candidate = prime_list[last];

  while (true) {
    int isPrime = true;
    candidate = (candidate == 2) ? 3 : candidate + 2;

    for (int i = 0; i < last + 1; i++) {
      int p = prime_list[i];

      if (candidate % p == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime)
      return candidate;
  }
}

int main() {
  // valores de entrada
  int input_a, input_b;

  // minimos e maximo divisor comun
  int min = -1;
  int max;

  printf("Entre com os valores A e B Maiores que 0, para encontrarmos o Minimo "
         "Divisor comum "
         "e o Maximo divisor comum entre eles: ");
  scanf("%d %d", &input_a, &input_b);

  if (input_b == 0 || input_a == 0) {
    printf("\nValor maior que zero porra loca");
    return 0;
  }

  max = max_common_divisor(input_a, input_b);

  if (max != 1) {
    int *prime_num_list = malloc(sizeof(int) * max);
    prime_num_list[0] = 2;

    if (prime_num_list == NULL) {
      printf("Erro ao alocar memoria.\n");
      return 1;
    }

    int prime_count = 1;

    while (true) {
      int p = prime_num_list[prime_count - 1];

      if (max % p == 0) {
        min = p;
        break;
      }

      if (p > input_a || p > input_b) {
        break;
      }

      prime_num_list[prime_count] =
          find_next_prime(prime_num_list, prime_count);

      prime_count++;
    }

    printf("Minimo Divisor Comum: %d\n Maximo divisor comum: %d", min, max);

    free(prime_num_list);
  } else {

    printf("Minimo Divisor Comum: 1, Maximo divisor comum: 1");
  }
}
