#include <stdio.h>
#include <math.h>

void exercicio_2_a() {
  int a;

  printf("Digite um numero inteiro: \n");
  scanf("%d", &a);

  if (a%4==0) {
    printf("%d é multiplo de 4\n", a);
  } else {
    printf("%d não é multiplo de 4\n", a);
  }
}

void exercicio_2_b() {
  int a;

  printf("Digite um numero inteiro: \n");
  scanf("%d", &a);

  if (a%2==0) {
    printf("%d é par\n", a);
  } else {
    printf("%d é impar\n", a);
  }
}

void exercicio_2_c() {
  int a = -1, b = -1, c = 0;

  printf("Digite o primeiro número inteiro positivo: ");
  while(a < 0) {
    scanf("%d", &a);
  }

  printf("Digite o segundo número inteiro positivo: ");
  while(b < 0) {
    scanf("%d", &b);
  }

  if (a > b) {
      int d = a;
      a = b;
      b = d;
  }
  
  for (int i = a + 1; i < b; i++) {
      c += i;
  }
  
  printf("\n%d\n", c);
}

void exercicio_2_d() {
  float a, b;

  printf("Digite o raio da esfera: ");
  scanf("%f", &a);
  
  b = (4.0/3.0) * 3.14 * pow(a, 3);
  
  printf("\n%.2f\n", b);
}


int main() {

  exercicio_2_a();

  exercicio_2_b();
  exercicio_2_c();
  exercicio_2_d();

  return 0;
}
