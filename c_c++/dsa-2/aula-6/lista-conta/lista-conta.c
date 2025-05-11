#include "lista-conta.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


ListaConta lista_criar() {
  ListaConta lista;
  lista.n = 0;

  return lista;
}

void lista_imprimir(ListaConta *lista) {
  printf("Lista de Clientes: [ ");

  for (int i = 0; i < lista->n; i++) {
    printf("{ %s, %d, %f }", lista->v[i].nome, lista->v[i].conta,
           lista->v[i].saldo);

    if (i != lista->n - 1) {
      printf(", ");
    }
  }

  printf("]\n");
  printf("Tamanho: %d\n", lista->n);
}

int lista_buscar(ListaConta *lista, int conta, char *nome) {
  for (int i = 0; i < lista->n; i++) {
    Conta c = lista->v[i];

    if (c.conta == conta || strcmp(c.nome, nome) == 0) {
      return i;
    }
  }

  return -1;
}

bool lista_inserir(ListaConta *lista, Conta cliente) {
  int i = lista_buscar(lista, cliente.conta, cliente.nome);

  if ((i == -1 || lista->n == 0) && lista->n != MAX) {
    lista->v[lista->n] = cliente;
    lista->n++;
    return true;
  }

  return false;
}

bool lista_remover(ListaConta *lista, int conta, char *nome) {
  int i = lista_buscar(lista, conta, nome);

  if (i == -1)
    return false;

  while (i < lista->n) {
    lista->v[i] = lista->v[i + 1];
    i++;
  }

  lista->n--;
  return true;
}

int lista_tamanho(ListaConta *lista) { return lista->n; }

void lista_reinicializar(ListaConta *lista) { lista->n = 0; }
