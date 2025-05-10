#include <stdio.h>
#include <stdlib.h>

typedef struct set {
  int *items;
  int tamanho;
} Set;

Set *set_criar() {
  Set *set = malloc(sizeof(Set));

  if (set == NULL) {
    printf("memoria insuficiente");
    return NULL;
  }

  set->items = malloc(sizeof(int));

  if (set->items == NULL) {
    printf("memoria insuficiente");
    free(set);
    return NULL;
  }

  set->tamanho = 0;

  return set;
}

int set_indice(Set *s, int v) {
  for (int i = 0; i < (s->tamanho / 2) + 1; i++) {
    if (s->items[i] == v) {
      return i;
    }

    if (s->items[s->tamanho - i - 1] == v) {
      return s->tamanho - i - 1;
    }
  }

  return -1;
}

void set_add(Set *s, int v) {
  if (set_indice(s, v) == -1) {
    s->items[s->tamanho] = v;
    s->tamanho++;
  }
}

void set_remove(Set *s, int v) {
  int indice = set_indice(s, v);

  for (int i = indice; i <= s->tamanho - 1; i++) {
    s->items[indice] = i + 1;
  }

  s->items[s->tamanho - 1] = 0;
  s->tamanho--;
}

int set_tamanho(Set *s) { return s->tamanho; }

int set_min(Set *s) { return s->items[0]; }

int set_max(Set *s) { return s->items[s->tamanho - 1]; }

int set_contem(Set *s, int v) {
  int indice = set_indice(s, v);

  return indice != -1 ? 1 : 0;
}

// vamos ver todas as funcoes com 2 Set

void set_atribui(Set *s1, Set *s2) {
  s2->items = s1->items;
  s2->tamanho = s1->tamanho;
}

Set *set_uniao(Set *s1, Set *s2) {
  Set *s3 = set_criar();

  int maiorTamanho = s1->tamanho > s2->tamanho ? s2->tamanho : s1->tamanho;

  for (int i = 0; i < maiorTamanho; i++) {
    if (i < s1->tamanho)
      set_add(s3, s1->items[i]);

    if (i < s2->tamanho)
      set_add(s3, s2->items[i]);
  }

  return s3;
}

Set *set_interseccao(Set *s1, Set *s2) {
  Set *s3 = set_criar();

  for (int i = 0; i < s1->tamanho; i++) {
    int val = s1->items[i];

    if (set_contem(s2, val))
      set_add(s3, val);
  }

  return s3;
}

Set *set_diferenca(Set *s1, Set *s2) {
  Set *s3 = set_criar();

  for (int i = 0; i < s1->tamanho; i++) {
    if (!set_contem(s2, s1->items[i])) {
      s3->items[i] = s1->items[i];
      s3->tamanho++;
    }
  }

  return s3;
}

int set_igual(Set *s1, Set *s2) {
  if (s1->tamanho != s2->tamanho)
    return 0;

  for (int i = 0; i < s1->tamanho; i++) {
    if (!set_contem(s2, s1->items[i]))
      return 0;
  }

  return 1;
}
