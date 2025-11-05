#include "lista.h"
#include <stdbool.h>
#include <stdio.h>

void teste_listaLkd_criar() {
  ListaLkd lista = listaLkd_criar();
  printf("Teste listaLkd_criar: ");
  if (lista.inicio == INV && lista.livre == 0) {
    printf("OK\n");
  } else {
    printf("Falhou\n");
  }
}

void teste_listaLkd_inserir_asc() {
  ListaLkd lista = listaLkd_criar();
  bool resultado;

  resultado = listaLkd_inserir_asc(&lista, 10);
  printf("Teste listaLkd_inserir_asc (10): %s\n", resultado ? "OK" : "Falhou");

  resultado = listaLkd_inserir_asc(&lista, 20);
  printf("Teste listaLkd_inserir_asc (20): %s\n", resultado ? "OK" : "Falhou");

  resultado = listaLkd_inserir_asc(&lista, 15);
  printf("Teste listaLkd_inserir_asc (15): %s\n", resultado ? "OK" : "Falhou");
}

void teste_listaLkd_remover() {
  ListaLkd lista = listaLkd_criar();
  listaLkd_inserir_asc(&lista, 10);
  listaLkd_inserir_asc(&lista, 20);
  listaLkd_inserir_asc(&lista, 15);

  bool resultado = listaLkd_remover(&lista, 15);
  printf("Teste listaLkd_remover (15): %s\n", resultado ? "OK" : "Falhou");

  resultado = listaLkd_remover(&lista, 30);
  printf("Teste listaLkd_remover (30): %s\n", resultado ? "OK" : "Falhou");
}
void teste_listaLkd_buscar() {
  ListaLkd lista = listaLkd_criar();
  listaLkd_inserir_asc(&lista, 10);
  listaLkd_inserir_asc(&lista, 20);
  listaLkd_inserir_asc(&lista, 15);

  int pos = listaLkd_buscar(&lista, 15);
  printf("Teste listaLkd_buscar (15): %s\n", pos != INV ? "OK" : "Falhou");

  pos = listaLkd_buscar(&lista, 30);
  printf("Teste listaLkd_buscar (30): %s\n", pos == INV ? "OK" : "Falhou e deveria");
}
void teste_listaLkd_imprimir() {
  ListaLkd lista = listaLkd_criar();
  listaLkd_inserir_asc(&lista, 10);
  listaLkd_inserir_asc(&lista, 20);
  listaLkd_inserir_asc(&lista, 15);

  printf("Teste listaLkd_imprimir: ");
  listaLkd_imprimir(&lista);
}
void teste_listaLkd_tamanho() {
  ListaLkd lista = listaLkd_criar();
  listaLkd_inserir_asc(&lista, 10);
  listaLkd_inserir_asc(&lista, 20);
  listaLkd_inserir_asc(&lista, 15);

  int tamanho = listaLkd_tamanho(&lista);
  printf("Teste listaLkd_tamanho: %s\n", tamanho == 3 ? "OK" : "Falhou");
}
void teste_listaLkd_reinicializar() {
  ListaLkd lista = listaLkd_criar();
  listaLkd_inserir_asc(&lista, 10);
  listaLkd_inserir_asc(&lista, 20);
  listaLkd_inserir_asc(&lista, 15);

  listaLkd_reinicializar(&lista);
  printf("Teste listaLkd_reinicializar: %s\n", lista.inicio == INV && lista.livre == 0 ? "OK" : "Falhou");
}

int main() {
  teste_listaLkd_inserir_asc();
  teste_listaLkd_remover();
  teste_listaLkd_buscar();
  teste_listaLkd_imprimir();
  teste_listaLkd_tamanho();
  teste_listaLkd_reinicializar();
  teste_listaLkd_criar();
  return 0;
}
