#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_PILHA 100

typedef int TipoItem;

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

/* Exercício 1: Transfere elementos de uma pilha para outra */
void transfere_pilha(Pilha *p1, Pilha *p2);

/* Exercício 2: Testa se uma pilha tem mais elementos que outra */
bool tem_mais_elementos(Pilha *p1, Pilha *p2);

/* Exercício 3: Inverte os elementos de uma pilha */
void inverte_pilha(Pilha *p);

/* Exercício 4: Testa se duas pilhas são iguais */
bool pilhas_iguais(Pilha *p1, Pilha *p2);

#endif