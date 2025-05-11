#include "lista-conta.h"
#include <stdbool.h>
#include <stdio.h>

void test_lista_inserir() {
  ListaConta lista = lista_criar();
  Conta cliente1 = {"João", 12345, 1000.0};
  Conta cliente2 = {"Maria", 67890, 2000.0};

  bool resultado1 = lista_inserir(&lista, cliente1);
  bool resultado2 = lista_inserir(&lista, cliente2);
  bool resultado3 =
      lista_inserir(&lista, cliente1); // Tentativa de inserir duplicado

  printf("Teste de Inserção:\n");
  printf("Inserir %s: %s\n", cliente1.nome, resultado1 ? "Sucesso" : "Falha");
  printf("Inserir Maria: %s\n", resultado2 ? "Sucesso" : "Falha");
  lista_imprimir(&lista);
}

void test_lista_buscar() {

  ListaConta lista = lista_criar();
  Conta cliente1 = {"João", 12345, 1000.0};
  Conta cliente2 = {"Maria", 67890, 2000.0};

  lista_inserir(&lista, cliente1);
  lista_inserir(&lista, cliente2);

  int pos1 = lista_buscar(&lista, 12345, "João");
  int pos2 = lista_buscar(&lista, 67890, "Maria");
  int pos3 = lista_buscar(&lista, 11111, "Carlos");

  printf("Teste de Busca:\n");
  printf("Buscar João: %d\n", pos1);
  printf("Buscar Maria: %d\n", pos2);
  printf("Buscar Carlos: %d\n", pos3);
}

void test_lista_remover() {
  ListaConta lista = lista_criar();
  Conta cliente1 = {"João", 12345, 1000.0};
  Conta cliente2 = {"Maria", 67890, 2000.0};

  lista_inserir(&lista, cliente1);
  lista_inserir(&lista, cliente2);

  bool resultado1 = lista_remover(&lista, 12345, "João");
  bool resultado2 = lista_remover(&lista, 11111, "Carlos");

  printf("Teste de Remoção:\n");
  printf("Remover João: %s\n", resultado1 ? "Sucesso" : "Falha");
  printf("Remover Carlos: %s\n", resultado2 ? "Sucesso" : "Falha");

  lista_imprimir(&lista);
}

int main() {
  test_lista_remover();
  return 0;
}
