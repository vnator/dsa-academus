#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define MAX_FILA 100
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2
#define SUCESSO 0

typedef int TipoItem;

typedef struct {
    TipoItem itens[MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializa_fila(Fila *f);
bool fila_vazia(Fila *f);
bool fila_cheia(Fila *f);
int inserir_item(Fila *f, TipoItem item);
int remover_item(Fila *f, TipoItem *item);
void listar_fila(Fila *f);
int tamanho_fila(Fila *f);

#endif