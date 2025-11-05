#include "lista.h"

void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int retornar_tamanho(Lista *lista) {
    return lista->tamanho;
}

void imprimir_lista(Lista *lista) {
    No *atual = lista->inicio;
    
    if (atual == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("=== Lista de Wyverns (%d monstros) ===\n", lista->tamanho);
    while (atual != NULL) {
        printf("Nome: %s\n", atual->monstro.nome);
        printf("Tipo: %s\n", atual->monstro.tipo);
        printf("Jogo: %s\n", atual->monstro.jogo);
        printf("Dificuldade: %d\n", atual->monstro.dificuldade);
        printf("-----------------------\n");
        atual = atual->proximo;
    }
}

bool inserir_inicio(Lista *lista, Wyvern monstro) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return false; // Falha na alocação de memória
    }
    
    novo->monstro = monstro;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;
    
    if (lista->inicio == NULL) {
        // Lista vazia
        lista->fim = novo;
    } else {
        // Lista não vazia
        lista->inicio->anterior = novo;
    }
    
    lista->inicio = novo;
    lista->tamanho++;
    
    return true;
}

bool inserir_final(Lista *lista, Wyvern monstro) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return false; // Falha na alocação de memória
    }
    
    novo->monstro = monstro;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    
    if (lista->fim == NULL) {
        // Lista vazia
        lista->inicio = novo;
    } else {
        // Lista não vazia
        lista->fim->proximo = novo;
    }
    
    lista->fim = novo;
    lista->tamanho++;
    
    return true;
}

No* buscar_chave(Lista *lista, char *nome) {
    No *atual = lista->inicio;
    
    while (atual != NULL) {
        if (strcmp(atual->monstro.nome, nome) == 0) {
            return atual; // Encontrou o monstro
        }
        atual = atual->proximo;
    }
    
    return NULL; // Não encontrou o monstro
}

bool remover_inicio(Lista *lista) {
    if (lista->inicio == NULL) {
        return false; // Lista vazia
    }
    
    No *temp = lista->inicio;
    
    lista->inicio = lista->inicio->proximo;
    
    if (lista->inicio == NULL) {
        // A lista ficou vazia
        lista->fim = NULL;
    } else {
        lista->inicio->anterior = NULL;
    }
    
    free(temp);
    lista->tamanho--;
    
    return true;
}

bool remover_final(Lista *lista) {
    if (lista->fim == NULL) {
        return false; // Lista vazia
    }
    
    No *temp = lista->fim;
    
    lista->fim = lista->fim->anterior;
    
    if (lista->fim == NULL) {
        // A lista ficou vazia
        lista->inicio = NULL;
    } else {
        lista->fim->proximo = NULL;
    }
    
    free(temp);
    lista->tamanho--;
    
    return true;
}

bool remover_chave(Lista *lista, char *nome) {
    No *no = buscar_chave(lista, nome);
    
    if (no == NULL) {
        return false; // Monstro não encontrado
    }
    
    // Se for o primeiro nó
    if (no->anterior == NULL) {
        return remover_inicio(lista);
    }
    
    // Se for o último nó
    if (no->proximo == NULL) {
        return remover_final(lista);
    }
    
    // Nó do meio
    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;
    
    free(no);
    lista->tamanho--;
    
    return true;
}

void reinicializar_lista(Lista *lista) {
    while (lista->inicio != NULL) {
        remover_inicio(lista);
    }
}