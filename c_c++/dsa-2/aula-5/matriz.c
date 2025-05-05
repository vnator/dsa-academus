#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz {
  int l;
  int c;
  int livre;
  float *val;
} Matriz;

Matriz *matriz_criar(int l, int c) {
  Matriz *m = malloc(sizeof(Matriz));
  m->l = l;
  m->c = c;
  m->livre = 0;
  m->val = malloc(l * c * sizeof(float));

  if (m->val == NULL) {
    printf("Memoria insuficiente\n");
    free(m);
    return NULL;
  }

  return m;
}

void matriz_libera(Matriz *m) {
  free(m->val);
  free(m);
}

void matriz_add(Matriz *m, float v) {
  if (m->livre == m->l * m->c) {
    printf("Matriz cheia\n");
  } else {
    m->val[m->livre] = v;
    m->livre++;
  }
}

float matriz_px(Matriz *m, int l, int c) {
  if (l < 1 || l > m->l || c < 1 || c > m->c) {
    printf("posição inválida\n");
    return 0;
  }

  return (l * m->c - (m->c - c)) - 1;
}

float matriz_le(Matriz *m, int l, int c) {
  int k = matriz_px(m, l, c);

  return m->val[k];
}

void matriz_atualiza(Matriz *m, int l, int c, float v) {
  int k = matriz_px(m, l, c);

  m->val[k] = v;
}

int matriz_colunas(Matriz *m) { return m->c; }

int matriz_linhas(Matriz *m) { return m->l; }

void matriz_print(Matriz *m) {
  for (int i = 0; i < m->l * m->c; i++) {
    printf("[%f]", m->val[i]);

    if ((i + 1) % m->c == 0)
      printf("\n");
  }
}

float *matriz_dprincipal(Matriz *m) {

  if (m->l != m->c) {
    printf("A matriz não é quadrada\n");
    return NULL;
  }

  float *dp = malloc(m->c * sizeof(float));

  for (int i = 1; i <= m->c; i++) {
    dp[i - 1] = matriz_le(m, i, i);
  }

  return dp;
}

float *matriz_dsecundaria(Matriz *m) {

  if (m->l != m->c) {
    printf("A matriz não é quadrada\n");
    return NULL;
  }

  float *ds = malloc(m->c * sizeof(float));

  for (int i = m->c; i >= 1; i--) {
    ds[i - 1] = matriz_le(m, m->l - (i - 1), i);
  }

  return ds;
}
