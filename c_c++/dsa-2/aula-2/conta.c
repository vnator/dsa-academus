#include <stdio.h>

struct Conta {
  int num_conta;
  char tipo_conta;
  char nome[80];
  float saldo;
};

int main() {
  int n;
  printf("digite quantas contas ira inserir:");
  scanf("%d", &n);

  struct Conta vcliente[n];
  int i;

  for (i = 0; i < n; i++) {
    vcliente[i].num_conta = i + 1;
    vcliente[i].tipo_conta = 'C';

    printf("\n conta %d", vcliente[i].num_conta);
    printf("\n nome cliente: ");
    scanf("%s", vcliente[i].nome);

    printf(" saldo: ");
    scanf("%f", &vcliente[i].saldo);

    printf("\n -----------//------------\n");
  }

  printf("\n Imprime dados dos clientes");

  for (i = 0; i < n; i++) {
    printf("\n conta %d, cliente: %s, saldo: %.2f", vcliente[i].num_conta,
           vcliente[i].nome, vcliente[i].saldo);
  }

  return 0;
}
