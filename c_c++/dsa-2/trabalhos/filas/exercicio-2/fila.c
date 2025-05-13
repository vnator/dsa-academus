#include "fila.h"
#include <stdio.h>

void inicializa_fila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

bool fila_vazia(Fila *f) {
    return (f->tamanho == 0);
}

bool fila_cheia(Fila *f) {
    return (f->tamanho == MAX_FILA);
}

int inserir_item(Fila *f, TipoItem item) {
    if (fila_cheia(f)) {
        return ERRO_FILA_CHEIA;
    }
    
    f->itens[f->fim] = item;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->tamanho++;
    
    return SUCESSO;
}

int remover_item(Fila *f, TipoItem *item) {
    if (fila_vazia(f)) {
        return ERRO_FILA_VAZIA;
    }
    
    *item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->tamanho--;
    
    return SUCESSO;
}

void listar_fila(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    
    printf("Elementos da fila: ");
    int i, pos;
    
    for (i = 0; i < f->tamanho; i++) {
        pos = (f->inicio + i) % MAX_FILA;
        printf("%d", f->itens[pos]);
        
        if (i < f->tamanho - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int tamanho_fila(Fila *f) {
    return f->tamanho;
}