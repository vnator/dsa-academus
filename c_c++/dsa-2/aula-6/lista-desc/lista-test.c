#include "lista-desc.h"
#include <stdbool.h>
#include <stdio.h>

void teste_lista_inserir() {
  ListaDesc lista = lista_criar();
  int i;

  for (i = 0; i < 4; i++) {
    lista_inserir(&lista, i);
  }

  lista_imprimir(&lista);

  lista_inserir(&lista, 7);
  lista_inserir(&lista, 5);
  lista_inserir(&lista, 5);
  lista_inserir(&lista, 8);

  lista_imprimir(&lista);
}

void teste_lista_remover() {
  ListaDesc lista = lista_criar();
  int i;

  for (i = 0; i < 8; i++) {
    lista_inserir(&lista, i);
  }

  printf("Lista antes de remover:\n");
  lista_imprimir(&lista);

  lista_remover(&lista, 2);
  lista_remover(&lista, 5);
  lista_remover(&lista, 1);

  printf("Lista depois de remover:\n");
  lista_imprimir(&lista);
}

void teste_lista_buscar() {
  ListaDesc lista = lista_criar();
  int i;

  for (i = 0; i < 8; i++) {
    lista_inserir(&lista, i);
  }

  printf("Lista antes de buscar:\n");
  lista_imprimir(&lista);

  printf("Buscar 2: %d\n", lista_buscar(&lista, 2));
  printf("Buscar 5: %d\n", lista_buscar(&lista, 5));
  printf("Buscar 1: %d\n", lista_buscar(&lista, 1));
}


int main() {
  teste_lista_remover();
  return 0;
}
