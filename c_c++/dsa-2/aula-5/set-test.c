#include "set.h"
#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para imprimir os itens do conjunto
void print_set(Set *s) {
  printf("Itens do conjunto: { ");
  for (int i = 0; i < s->tamanho; i++) {
    printf("%d", s->items[i]);
    if (i < s->tamanho - 1) {
      printf(", ");
    }
  }
  printf(" }\n");
}

void test_set_add() {
  printf("\n[Teste: set_add]\n");
  Set *s = set_criar();
  set_add(s, 1);
  set_add(s, 2);
  set_add(s, 3);
  printf("Após adicionar 1, 2, 3:\n");
  print_set(s);
  printf("Tamanho: %d\n", set_tamanho(s));
  printf("vamos tentar adicionar o 2 novamente:\n");
  set_add(s, 2);
  print_set(s);
  free(s->items);
  free(s);
}

void test_set_remove() {
  printf("\n[Teste: set_remove]\n");
  Set *s = set_criar();
  set_add(s, 1);
  set_add(s, 2);
  set_add(s, 3);
  printf("Antes de remover:\n");
  print_set(s);
  set_remove(s, 2);
  printf("Após remover 2:\n");
  print_set(s);
  printf("Tamanho: %d\n", set_tamanho(s));
  free(s->items);
  free(s);
}

void test_set_contem() {
  printf("\n[Teste: set_contem]\n");
  Set *s = set_criar();
  set_add(s, 1);
  set_add(s, 2);
  set_add(s, 3);
  printf("Conjunto atual:\n");
  print_set(s);
  printf("Conjunto contém 2? %s\n", set_contem(s, 2) ? "Sim" : "Não");
  printf("Conjunto contém 4? %s\n", set_contem(s, 4) ? "Sim" : "Não");
  free(s->items);
  free(s);
}

void test_set_min_max() {
  printf("\n[Teste: set_min e set_max]\n");
  Set *s = set_criar();
  set_add(s, 1);
  set_add(s, 2);
  set_add(s, 3);
  printf("Conjunto atual:\n");
  print_set(s);
  printf("Mínimo: %d\n", set_min(s));
  printf("Máximo: %d\n", set_max(s));
  free(s->items);
  free(s);
}

void test_set_atribui() {
  printf("\n[Teste: set_atribui]\n");
  Set *s1 = set_criar();
  Set *s2 = set_criar();
  set_add(s1, 1);
  set_add(s1, 2);
  set_add(s1, 3);
  set_add(s2, 4);
  set_add(s2, 5);
  printf("Conjunto 1 antes de atribuir:\n");
  print_set(s1);
  printf("Conjunto 2 antes de atribuir:\n");
  print_set(s2);
  set_atribui(s1, s2);
  printf("Conjunto 1 após atribuir:\n");
  print_set(s1);
  printf("Conjunto 2 após atribuir:\n");
  print_set(s2);
  printf("Tamanho do Conjunto 1: %d\n", set_tamanho(s1));
  printf("Tamanho do Conjunto 2: %d\n", set_tamanho(s2));
  free(s1->items);
  free(s2->items);
  free(s1);
  free(s2);
}

void test_set_uniao() {
  printf("\n[Teste: set_uniao]\n");
  Set *s1 = set_criar();
  Set *s2 = set_criar();
  set_add(s1, 1);
  set_add(s1, 2);
  set_add(s2, 3);
  set_add(s2, 4);
  printf("Conjunto 1:\n");
  print_set(s1);
  printf("Conjunto 2:\n");
  print_set(s2);
  Set *s3 = set_uniao(s1, s2);
  printf("União dos conjuntos:\n");
  print_set(s3);
  printf("Tamanho da união: %d\n", set_tamanho(s3));
  free(s1->items);
  free(s2->items);
  free(s3->items);
  free(s1);
  free(s2);
  free(s3);
}

void test_set_interseccao() {
  printf("\n[Teste: set_interseccao]\n");
  Set *s1 = set_criar();
  Set *s2 = set_criar();
  set_add(s1, 1);
  set_add(s1, 2);
  set_add(s2, 2);
  set_add(s2, 3);
  printf("Conjunto 1:\n");
  print_set(s1);
  printf("Conjunto 2:\n");
  print_set(s2);
  Set *s3 = set_interseccao(s1, s2);
  printf("Interseção dos conjuntos:\n");
  print_set(s3);
  printf("Tamanho da interseção: %d\n", set_tamanho(s3));
  free(s1->items);
  free(s2->items);
  free(s3->items);
  free(s1);
  free(s2);
  free(s3);
}

void test_set_diferenca() {
  printf("\n[Teste: set_diferenca]\n");
  Set *s1 = set_criar();
  Set *s2 = set_criar();
  set_add(s1, 1);
  set_add(s1, 2);
  set_add(s2, 2);
  set_add(s2, 3);
  printf("Conjunto 1:\n");
  print_set(s1);
  printf("Conjunto 2:\n");
  print_set(s2);
  Set *s3 = set_diferenca(s1, s2);
  printf("Diferença dos conjuntos:\n");
  print_set(s3);
  printf("Tamanho da diferença: %d\n", set_tamanho(s3));
  free(s1->items);
  free(s2->items);
  free(s3->items);
  free(s1);
  free(s2);
  free(s3);
}

void test_set_igual() {
  printf("\n[Teste: set_igual]\n");
  Set *s1 = set_criar();
  Set *s2 = set_criar();
  set_add(s1, 1);
  set_add(s1, 2);
  set_add(s2, 1);
  set_add(s2, 2);
  printf("Conjunto 1:\n");
  print_set(s1);
  printf("Conjunto 2:\n");
  print_set(s2);
  printf("Os conjuntos são iguais? %s\n", set_igual(s1, s2) ? "Sim" : "Não");

  set_remove(s2, 2);

  printf("Após remover o elemento do Conjunto 2:\n");
  print_set(s2);

  printf("Os conjuntos são iguais? %s\n", set_igual(s1, s2) ? "Sim" : "Não");

  free(s1->items);
  free(s2->items);
  free(s1);
  free(s2);
}

int main() {
  test_set_igual();
  return 0;
}
