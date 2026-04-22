#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

int exponential_mod(int base, int potency, int mod) {
  long long result = 1;
  long long b = base % mod;

  while (potency > 0) {
    if (potency % 2 == 1) {
      result = (result * b) % mod;
    }

    potency = potency / 2;

    b = (b * b) % mod;
  }

  return (int)result;
}

bool is_prime_number(int n) {
  int prime_number_list[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

  if (n < 2)
    return false;

  for (int i = 0; i < SIZE; i++) {
    int a = prime_number_list[i];

    if (n == a)
      return true;

    if (n % a == 0)
      return false;
  }

  if (n % 2 == 0)
    return false;

  int d = n - 1;
  int s = 0;

  while (d % 2 == 0) {
    d = d / 2;
    s++;
  }

  for (int i = 0; i < SIZE; i++) {
    int a = prime_number_list[i];

    if (a >= n)
      break;

    int x = exponential_mod(a, d, n);

    if (x == 1 || x == n - 1)
      continue;

    bool finish_exponential_loop = false;

    for (int j = 1; j < s; j++) {
      x = exponential_mod(x, 2, n);

      if (x == n - 1) {
        finish_exponential_loop = true;
        break;
      }
    }

    if (!finish_exponential_loop)
      return false;
  }

  return true;
}

int main() {
  int input = 0;

  printf("Quantos numeros quer digitar: ");
  scanf("%d", &input);

  int *list = malloc(sizeof(int) * input);

  printf("\nEntre com os valores da lista: ");

  for (int i = 0; i < input; i++)
    scanf("%d", list + i);

  for (int i = 0; i < input; i++) {
    bool is_prime = is_prime_number(list[i]);

    if (is_prime)
      printf("\n %d eh Numero primo", list[i]);
    else
      printf("\n %d nao eh Numero primo", list[i]);
  }

  return 0;
}
