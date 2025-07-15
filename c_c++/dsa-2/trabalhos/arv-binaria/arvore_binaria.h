#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore binária
typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
    struct No* pai;
} No;

// Estrutura da árvore binária
typedef struct {
    No* raiz;
} ArvoreBinaria;

// Funções básicas
ArvoreBinaria* criar_arvore();
No* criar_no(int chave);
void destruir_arvore(ArvoreBinaria* arvore);
void destruir_no(No* no);

// Funções principais
void inserir(ArvoreBinaria* arvore, int chave);
No* busca_chave(ArvoreBinaria* arvore, int chave);
void remover(ArvoreBinaria* arvore, int chave);

// Percursos
void pre_ordem(No* no);
void em_ordem(No* no);
void pos_ordem(No* no);

// Funções auxiliares
No* predecessor(No* no);
No* sucessor(No* no);
No* maximo(No* no);
No* minimo(No* no);

// Funções auxiliares internas
No* busca_no(No* no, int chave);
No* inserir_no(No* no, int chave, No* pai);
No* remover_no(No* raiz, int chave);
void transplant(ArvoreBinaria* arvore, No* u, No* v);

#endif
