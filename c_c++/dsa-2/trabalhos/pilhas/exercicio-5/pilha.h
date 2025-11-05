#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_PILHA 100

typedef char TipoItem;

typedef struct {
    TipoItem itens[MAX_PILHA];
    int topo;
} Pilha;

void inicializa_pilha(Pilha *p);
bool pilha_vazia(Pilha *p);
bool pilha_cheia(Pilha *p);
bool empilha(Pilha *p, TipoItem item);
bool desempilha(Pilha *p, TipoItem *item);
bool topo_pilha(Pilha *p, TipoItem *item);
int tamanho_pilha(Pilha *p);
void imprime_pilha(Pilha *p);

bool eh_palindromo(char *texto);

#endif