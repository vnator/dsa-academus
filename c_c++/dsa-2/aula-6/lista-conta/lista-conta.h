#include <stdbool.h>

#define MAX 30

typedef struct conta {
  char nome[120];
  int conta;
  float saldo;
} Conta;

typedef struct listaConta {
  Conta v[MAX];
  int n;
} ListaConta;

ListaConta lista_criar();
void lista_imprimir(ListaConta *lista);
bool lista_inserir(ListaConta *lista, Conta cliente);
int lista_tamanho(ListaConta *lista);
int lista_buscar(ListaConta *lista, int conta, char *nome);
bool lista_remover(ListaConta *lista, int conta, char *nome);
void lista_reinicializar(ListaConta *lista);
