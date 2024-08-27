#include <stdio.h>
#include <math.h>

void exercicio_a() {
  int a = -1, b = -1, c = -1, d = 0;

  printf("Digite o primeiro valor: ");
  scanf("%d", &a);
  while(a < 0) {
    scanf("%d", &a);
  }

  printf("\nDigite o segundo valor: ");
  scanf("%d", &b);

  printf("\nDigite o terceiro valor: ");
  scanf("%d", &c);
  while(b > c) {
    scanf("%d", &c);
  }

  if (a > 1) {
    for (int i = b; i <= c; i++) {
      if (i % a == 0) {
        d += i;
      }
    }
    printf("resulta da soma dos numeros no intervalo entre %d e %d que são divisíveis por %d é: %d\n", b, c, a, d);
  }
}

void exercicio_b() {
  float height, idealWeight;
  char sex;

  printf("Qual a sua altura? \n");
  scanf("%f", &height);

  do {
    printf("Digite o sexo (M ou F): ");
    scanf(" %c", &sex);
  } while (sex != 'M' && sex != 'm' && sex != 'F' && sex != 'f');

  if (sex == 'M' || sex == 'm') {
    idealWeight = 0.95 * (height * 100) - 95;
  } else {
    idealWeight = 0.85 * (height *100) - 85;
  }

  printf("\nO peso ideal é: %.2f kg\n", idealWeight);
}

void exercicio_c() {
  int num = 0, fatorial = 1;

  printf("Digite um número natural: \n");
  scanf("%d", &num);
    
  while (num < 1) {
    scanf("%d", &num);
  }

  for (int i = 1; i <= num; i++) {
      fatorial *= i;
  }

  printf("\n%d\n", fatorial);
}

void exercicio_d() {
  int a, b, c = 1;

  printf("Digite a base: \n");
  scanf("%d\n", &a);
  printf("Digite a potencia: \n");
  scanf("%d\n", &b);

  for (int i = 0; i < b; i++) {
    c *= a;
  }

  printf("\n%d elevado a %d é: %d\n", a, b, c);
}

int main() {
  exercicio_a();
  exercicio_b();
  exercicio_c();
  exercicio_d();

  return 0;
}
