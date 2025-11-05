#include "lista-linear-sequencial.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_inserir() {
  Lista lista;
  lista_inicializar(&lista);
  Registro r1, r2, r3;
  r1.chave = 10;
  r2.chave = 20;
  r3.chave = 30;

  printf("Lista antes das inserções:\n");
  lista_imprimir(&lista);
  printf("\n");
  lista_inserir(&lista, r1, 0);
  lista_inserir(&lista, r2, 1);
  lista_inserir(&lista, r3, 2);
  printf("Lista após inserções:\n");
  lista_imprimir(&lista);
}

void testa_tamanho() {
  Lista lista;
  lista_inicializar(&lista);
  Registro r1, r2;
  r1.chave = 10;
  r2.chave = 20;

  lista_inserir(&lista, r1, 0);
  lista_inserir(&lista, r2, 1);
  printf("Tamanho da lista: %d\n", lista_tamanho(&lista));
}

void testa_buscar() {
  Lista lista;
  lista_inicializar(&lista);
  Registro r1, r2, r3, r4, r5;
  r1.chave = 10;
  r2.chave = 20;
  r3.chave = 30;
  r4.chave = 40;
  r5.chave = 50;

  lista_inserir(&lista, r1, 0);
  lista_inserir(&lista, r2, 1);
  lista_inserir(&lista, r3, 2);
  lista_inserir(&lista, r4, 3);
  lista_inserir(&lista, r5, 4);

  int pos = lista_buscar(&lista, 20);
  printf("Posição do elemento 20: %d\n", pos);

  pos = lista_buscar(&lista, 100);
  printf("Posição do elemento 100: %d\n", pos);

  pos = lista_buscar(&lista, 30);
  printf("Posição do elemento 30: %d\n", pos);
}
void testa_excluir() {
  Lista lista;
  lista_inicializar(&lista);
  Registro r1, r2;
  r1.chave = 10;
  r2.chave = 20;

  printf("Lista antes da exclusão:\n");
  lista_inserir(&lista, r1, 0);
  lista_inserir(&lista, r2, 1);
  lista_imprimir(&lista);
  printf("\n");

  lista_excluir(&lista, 10);
  printf("Lista após exclusão:\n");
  lista_imprimir(&lista);
}
void testa_reinicializar() {
  Lista lista;
  lista_inicializar(&lista);
  Registro r1, r2;
  r1.chave = 10;
  r2.chave = 20;

  lista_inserir(&lista, r1, 0);
  lista_inserir(&lista, r2, 1);
  printf("Lista antes da reinicialização:\n");
  lista_imprimir(&lista);
  printf("\n");
  lista_reinicializar(&lista);
  printf("Lista após reinicialização:\n");
  lista_imprimir(&lista);
}

void testa_inserir_sem_repeticao() {
  Lista lista;
  lista_inicializar(&lista);

  Registro r1, r2, r3;
  r1.chave = 10;
  r2.chave = 20;
  r3.chave = 10;

  lista_inserir_sem_repeticao(&lista, r1);
  lista_inserir_sem_repeticao(&lista, r2);

  lista_imprimir(&lista);

  bool result = lista_inserir_sem_repeticao(&lista, r3);

  printf("Resultado da tentativa de inserção de repetição: %s\n",
         result ? "Sucesso" : "Falha");

  lista_imprimir(&lista);
}

int main() {
  printf("Testando inserção sem  repeticacão:\n");
  testa_inserir_sem_repeticao();
  return 0;
}
