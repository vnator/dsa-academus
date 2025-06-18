#include "avr_binaria.h"

// Criar uma nova árvore vazia
ArvoreBinaria* criar_arvore() {
    ArvoreBinaria* arvore = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    arvore->raiz = NULL;
    return arvore;
}

// Criar um novo nó
No* criar_no(int chave) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    novo_no->pai = NULL;
    return novo_no;
}

// Destruir um nó e seus filhos recursivamente
void destruir_no(No* no) {
    if (no != NULL) {
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}

// Destruir a árvore
void destruir_arvore(ArvoreBinaria* arvore) {
    if (arvore != NULL) {
        destruir_no(arvore->raiz);
        free(arvore);
    }
}

// Buscar um nó recursivamente
No* busca_no(No* no, int chave) {
    if (no == NULL || no->chave == chave) {
        return no;
    }
    
    if (chave < no->chave) {
        return busca_no(no->esquerda, chave);
    } else {
        return busca_no(no->direita, chave);
    }
}

// Buscar uma chave na árvore
No* busca_chave(ArvoreBinaria* arvore, int chave) {
    if (arvore == NULL) {
        return NULL;
    }
    return busca_no(arvore->raiz, chave);
}

// Inserir um nó recursivamente
No* inserir_no(No* no, int chave, No* pai) {
    if (no == NULL) {
        No* novo_no = criar_no(chave);
        novo_no->pai = pai;
        return novo_no;
    }
    
    if (chave < no->chave) {
        no->esquerda = inserir_no(no->esquerda, chave, no);
    } else if (chave > no->chave) {
        no->direita = inserir_no(no->direita, chave, no);
    }
    // Se chave == no->chave, não inserimos (não há duplicatas)
    
    return no;
}

// Inserir uma chave na árvore
void inserir(ArvoreBinaria* arvore, int chave) {
    if (arvore == NULL) {
        return;
    }
    arvore->raiz = inserir_no(arvore->raiz, chave, NULL);
}
