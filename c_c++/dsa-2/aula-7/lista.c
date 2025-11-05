#include "./lista.h"
#include <stdbool.h>
#include <stdio.h>

ListaLkd listaLkd_criar() {
  ListaLkd l;
  l.inicio = INV;
  l.livre = 0;

  for (int i = 0; i < MAX - 1; i++) {
    l.no[i].prox = i + 1;
  }

  l.no[MAX - 1].prox = INV;

  return l;
}

int listaLkd_tamanho(ListaLkd *l) {
  int n = 0;
  int reset = l->inicio;

  while (l->inicio != INV) {
    n++;
    l->inicio = l->no[l->inicio].prox;
  }

  l->inicio = reset;

  return n;
}

int listaLkd_buscar(ListaLkd *l, int v) {
  int i = l->inicio;

  while (i != INV) {
    if (l->no[i].v == v)
      return i;

    i = l->no[i].prox;
  }

  return INV;
}

bool listaLkd_inserir_asc(ListaLkd *l, int v) {
  int i = l->inicio;
  int ant = INV;

  if (l->livre == INV) {
    return false;
  }

  while (i != INV && l->no[i].v < v) {
    ant = i;
    i = l->no[i].prox;
  }

  if (i != INV && l->no[i].v == v) {
    return false;
  }

  int novo = l->livre;
  l->livre = l->no[novo].prox;
  l->no[novo].v = v;

  if (ant == INV) {
    l->no[novo].prox = l->inicio;
    l->inicio = novo;
  } else {
    l->no[novo].prox = l->no[ant].prox;
    l->no[ant].prox = novo;
  }

  return true;
}

bool listaLkd_remover(ListaLkd *l, int v) {

  int i = l->inicio;
  int ant = INV;

  while (i != INV && l->no[i].v < v) {
    ant = i;
    i = l->no[i].prox;
  }

  if (i == INV || l->no[i].v != v)
    return false;

  if (ant == INV) {
    l->inicio = l->no[i].prox;
  } else {
    l->no[ant].prox = l->no[i].prox;
  }

  l->no[i].prox = l->livre;
  l->livre = i;
  return true;
}

void listaLkd_imprimir(ListaLkd *l) {

  int i = l->inicio;

  printf("Lista Ligada: [");

  while (i != INV) {
    printf("%d", l->no[i].v);

    if (l->no[i].prox != INV)
      printf(" -> ");

    i = l->no[i].prox;
  }

  printf("]\n");
}

void listaLkd_reinicializar(ListaLkd *l) {
  l->inicio = INV;
  l->livre = 0;

  for (int i = 0; i < MAX - 1; i++) {
    l->no[i].prox = i + 1;
    l->no[i].v = 0;
  }

  l->no[MAX - 1].prox = INV;
  l->no[MAX - 1].v = 0;
}
