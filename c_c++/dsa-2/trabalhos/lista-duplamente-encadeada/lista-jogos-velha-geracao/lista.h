#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definição da estrutura do nó da lista (Wyvern/Monstro)
typedef struct Wyvern {
    char nome[50];
    char tipo[30];
    char jogo[20];
    int dificuldade;
} Wyvern;

// Definição da estrutura do nó da lista
typedef struct No {
    Wyvern monstro;
    struct No *anterior;
    struct No *proximo;
} No;

// Definição da estrutura da lista
typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

// Funções da lista duplamente encadeada
void inicializar(Lista *lista);
int retornar_tamanho(Lista *lista);
void imprimir_lista(Lista *lista);
bool inserir_inicio(Lista *lista, Wyvern monstro);
bool inserir_final(Lista *lista, Wyvern monstro);
No* buscar_chave(Lista *lista, char *nome);
bool remover_inicio(Lista *lista);
bool remover_final(Lista *lista);
bool remover_chave(Lista *lista, char *nome);
void reinicializar_lista(Lista *lista);

#endif