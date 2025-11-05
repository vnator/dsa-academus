#include "lista-linear-sequencial.h"
#include <stdbool.h>
#include <stdio.h>

void lista_inicializar(Lista *lista) { lista->n = 0; }

int lista_tamanho(Lista *lista) { return lista->n; }

void lista_imprimir(Lista *lista) {
  printf("Lista : [");

  for (int i = 0; i < lista->n; i++) {

    if (i != lista->n - 1)
      printf("%d, ", lista->v[i].chave);
    else
      printf("%d", lista->v[i].chave);
  }

  printf("] \n");
  printf("Tamanho: %d\n", lista->n);
}

int lista_buscar(Lista *lista, TipoChave ch) {

  for (int i = 0; i < lista->n; i++) {
    if (lista->v[i].chave == ch)
      return i;
  }

  return -1;
}

bool lista_inserir(Lista *lista, Registro item, int i) {
  if (i > MAX || i > lista->n || i < 0) {
    return false;
  }

  if (i == lista->n) {
    lista->v[i] = item;
    lista->n++;

    return true;
  } else {

    for (int j = lista->n; j > i; j--) {
      lista->v[j] = lista->v[j - 1];
    }

    lista->v[i] = item;
  }

  lista->n++;

  return true;
}

bool lista_inserir_sem_repeticao(Lista *lista, Registro item) {
  int i = lista_buscar(lista, item.chave);

  if (i != -1)
    return false;

  lista->v[lista->n] = item;
  lista->n++;
  return true;
}

bool lista_excluir(Lista *lista, TipoChave ch) {

  int i = lista_buscar(lista, ch);

  if (i > MAX && i < lista->n && i >= 0)
    return false;

  while (i < lista->n) {
    lista->v[i] = lista->v[i + 1];
    i++;
  }

  lista->v[i].chave = 0;

  lista->n--;

  return true;
}

void lista_reinicializar(Lista *lista) { lista->n = 0; }
