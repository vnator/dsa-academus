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

// Encontrar o nó mínimo
No* minimo(No* no) {
    if (no == NULL) {
        return NULL;
    }
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

// Encontrar o nó máximo
No* maximo(No* no) {
    if (no == NULL) {
        return NULL;
    }
    while (no->direita != NULL) {
        no = no->direita;
    }
    return no;
}

// Encontrar o sucessor de um nó
No* sucessor(No* no) {
    if (no == NULL) {
        return NULL;
    }
    
    // Caso 1: Se tem subárvore direita, sucessor é o mínimo da subárvore direita
    if (no->direita != NULL) {
        return minimo(no->direita);
    }
    
    // Caso 2: Não tem subárvore direita
    // Sobe até encontrar um nó que seja filho esquerdo de seu pai
    No* pai = no->pai;
    while (pai != NULL && no == pai->direita) {
        no = pai;
        pai = pai->pai;
    }
    return pai;
}

// Encontrar o predecessor de um nó
No* predecessor(No* no) {
    if (no == NULL) {
        return NULL;
    }
    
    // Caso 1: Se tem subárvore esquerda, predecessor é o máximo da subárvore esquerda
    if (no->esquerda != NULL) {
        return maximo(no->esquerda);
    }
    
    // Caso 2: Não tem subárvore esquerda
    // Sobe até encontrar um nó que seja filho direito de seu pai
    No* pai = no->pai;
    while (pai != NULL && no == pai->esquerda) {
        no = pai;
        pai = pai->pai;
    }
    return pai;
}

// Função auxiliar para transplante (substitui subárvore u por subárvore v)
void transplant(ArvoreBinaria* arvore, No* u, No* v) {
    if (u->pai == NULL) {
        arvore->raiz = v;
    } else if (u == u->pai->esquerda) {
        u->pai->esquerda = v;
    } else {
        u->pai->direita = v;
    }
    
    if (v != NULL) {
        v->pai = u->pai;
    }
}

// Remover um nó da árvore
void remover(ArvoreBinaria* arvore, int chave) {
    if (arvore == NULL) {
        return;
    }
    
    No* no = busca_chave(arvore, chave);
    if (no == NULL) {
        return; // Nó não encontrado
    }
    
    // Caso 1: Nó não tem filho esquerdo
    if (no->esquerda == NULL) {
        transplant(arvore, no, no->direita);
    }
    // Caso 2: Nó não tem filho direito
    else if (no->direita == NULL) {
        transplant(arvore, no, no->esquerda);
    }
    // Caso 3: Nó tem ambos os filhos
    else {
        No* sucessor_no = minimo(no->direita);
        
        // Se o sucessor não é filho direto do nó a ser removido
        if (sucessor_no->pai != no) {
            transplant(arvore, sucessor_no, sucessor_no->direita);
            sucessor_no->direita = no->direita;
            sucessor_no->direita->pai = sucessor_no;
        }
        
        transplant(arvore, no, sucessor_no);
        sucessor_no->esquerda = no->esquerda;
        sucessor_no->esquerda->pai = sucessor_no;
    }
    
    free(no);
}

// Percurso em pré-ordem (raiz, esquerda, direita)
void pre_ordem(No* no) {
    if (no != NULL) {
        printf("%d ", no->chave);
        pre_ordem(no->esquerda);
        pre_ordem(no->direita);
    }
}

// Percurso em ordem (esquerda, raiz, direita)
void em_ordem(No* no) {
    if (no != NULL) {
        em_ordem(no->esquerda);
        printf("%d ", no->chave);
        em_ordem(no->direita);
    }
}

// Percurso em pós-ordem (esquerda, direita, raiz)
void pos_ordem(No* no) {
    if (no != NULL) {
        pos_ordem(no->esquerda);
        pos_ordem(no->direita);
        printf("%d ", no->chave);
    }
}
