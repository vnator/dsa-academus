#include "lista-desc.h"
#include <stdbool.h>
#include <stdio.h>

ListaDesc lista_criar() {
  ListaDesc lista;
  lista.n = 0;

  return lista;
}

void lista_imprimir(ListaDesc *lista) {
  printf("ListaDesc: [");

  for (int i = 0; i < lista->n; i++) {
    printf("%d", lista->v[i]);

    if (i < lista->n - 1)
      printf(", ");
  }

  printf("]\n");
  printf("Tamanho: %d\n", lista->n);
}

bool lista_inserir(ListaDesc *lista, int val) {
  if (lista->n == MAX)
    return false;

  int i;

  for (i = lista->n - 1; i >= 0 && lista->v[i] < val; i--) {
    lista->v[i + 1] = lista->v[i];
  }

  lista->v[i + 1] = val;
  lista->n++;
  return true;
}

int lista_buscar(ListaDesc *lista, int val) {
  int r = lista->n - 1;
  int l = 0;

  while (l <= r) {
    int m = (l + r) / 2;

    if (val == lista->v[m])
      return m;

    if (lista->v[m] > val) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return -1;
}

bool lista_remover(ListaDesc *lista, int val) {
  int i = lista_buscar(lista, val);

  if (i == -1)
    return false;

  while (i < lista->n) {
    lista->v[i] = lista->v[i + 1];
    i++;
  }

  lista->n--;
  return true;
}
