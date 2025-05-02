#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[80];
  char situacao[20];
  float saldo;
} conta;

void show(conta *cliente);
void put_cliente(conta *cliente);
void put_cliente_situacao(conta *cliente);

int main() {

  conta cliente_1;

  put_cliente(&cliente_1);
  put_cliente_situacao(&cliente_1);

  show(&cliente_1);
}

void show(conta *cliente) {
  printf("nome: %s\n", cliente->nome);
  printf("situacao: %s\n", cliente->situacao);
  printf("saldo: %.2f\n", cliente->saldo);
}

void put_cliente(conta *cliente) {
  printf("nome: ");
  scanf("%s", cliente->nome);

  printf("saldo: ");
  scanf("%f", &cliente->saldo);
}

void put_cliente_situacao(conta *cliente) {
  if (cliente->saldo > 1000) {
    strcpy(cliente->situacao, "VIP");
    cliente->saldo += cliente->saldo * 0.1;
  } else {
    strcpy(cliente->situacao, "COMMON");
  }
}
