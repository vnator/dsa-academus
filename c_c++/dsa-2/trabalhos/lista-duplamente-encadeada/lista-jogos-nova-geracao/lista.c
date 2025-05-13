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
    
    printf("=== Lista de Wyverns Ordenada por Nome (%d monstros) ===\n", lista->tamanho);
    while (atual != NULL) {
        printf("Nome: %s\n", atual->monstro.nome);
        printf("Tipo: %s\n", atual->monstro.tipo);
        printf("Jogo: %s\n", atual->monstro.jogo);
        printf("Dificuldade: %d\n", atual->monstro.dificuldade);
        printf("-----------------------\n");
        atual = atual->proximo;
    }
}

// Função para inserir na lista de forma ordenada (por nome do monstro)
bool inserir_chave(Lista *lista, Wyvern monstro) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return false; // Falha na alocação de memória
    }
    
    novo->monstro = monstro;
    
    // Caso especial: lista vazia
    if (lista->inicio == NULL) {
        novo->anterior = NULL;
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
        return true;
    }
    
    // Caso especial: inserir no início (nome menor que o primeiro)
    if (strcmp(monstro.nome, lista->inicio->monstro.nome) < 0) {
        novo->anterior = NULL;
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        lista->tamanho++;
        return true;
    }
    
    // Caso especial: inserir no fim (nome maior que o último)
    if (strcmp(monstro.nome, lista->fim->monstro.nome) > 0) {
        novo->proximo = NULL;
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
        lista->tamanho++;
        return true;
    }
    
    // Caso geral: inserir no meio (ordenado por nome)
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(monstro.nome, atual->monstro.nome) < 0) {
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            atual->anterior->proximo = novo;
            atual->anterior = novo;
            lista->tamanho++;
            return true;
        }
        atual = atual->proximo;
    }
    
    // Este ponto nunca deve ser alcançado
    free(novo);
    return false;
}

No* buscar_chave(Lista *lista, char *nome) {
    No *atual = lista->inicio;
    
    while (atual != NULL) {
        int comparacao = strcmp(atual->monstro.nome, nome);
        if (comparacao == 0) {
            return atual; // Encontrou o monstro
        }
        // Como a lista está ordenada, podemos parar a busca se passarmos do ponto onde o nome deveria estar
        if (comparacao > 0) {
            break;
        }
        atual = atual->proximo;
    }
    
    return NULL; // Não encontrou o monstro
}

bool remover_chave(Lista *lista, char *nome) {
    No *no = buscar_chave(lista, nome);
    
    if (no == NULL) {
        return false; // Monstro não encontrado
    }
    
    // Se for o primeiro nó
    if (no->anterior == NULL) {
        lista->inicio = no->proximo;
        if (lista->inicio == NULL) {
            lista->fim = NULL;
        } else {
            lista->inicio->anterior = NULL;
        }
    }
    // Se for o último nó
    else if (no->proximo == NULL) {
        lista->fim = no->anterior;
        lista->fim->proximo = NULL;
    }
    // Nó do meio
    else {
        no->anterior->proximo = no->proximo;
        no->proximo->anterior = no->anterior;
    }
    
    free(no);
    lista->tamanho--;
    
    return true;
}

void reinicializar_lista(Lista *lista) {
    No *atual = lista->inicio;
    No *proximo;
    
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}