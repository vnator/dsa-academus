#include "pilha.h"
#include <stdio.h>

void inicializa_pilha(Pilha *p) {
    p->topo = -1;
}

bool pilha_vazia(Pilha *p) {
    return (p->topo == -1);
}

bool pilha_cheia(Pilha *p) {
    return (p->topo == MAX_PILHA - 1);
}

bool empilha(Pilha *p, TipoItem item) {
    if (pilha_cheia(p)) {
        return false;
    }
    p->topo++;
    p->itens[p->topo] = item;
    return true;
}

bool desempilha(Pilha *p, TipoItem *item) {
    if (pilha_vazia(p)) {
        return false;
    }
    *item = p->itens[p->topo];
    p->topo--;
    return true;
}

bool topo_pilha(Pilha *p, TipoItem *item) {
    if (pilha_vazia(p)) {
        return false;
    }
    *item = p->itens[p->topo];
    return true;
}

int tamanho_pilha(Pilha *p) {
    return p->topo + 1;
}

void imprime_pilha(Pilha *p) {
    printf("[ ");
    if (!pilha_vazia(p)) {
        int i;
        for (i = 0; i <= p->topo; i++) {
            printf("%d", p->itens[i]);
            if (i < p->topo) {
                printf(", ");
            }
        }
    }
    printf(" ]\n");
}

/* Exercício 1: Transfere os valores de uma pilha P1 para uma pilha P2 */
void transfere_pilha(Pilha *p1, Pilha *p2) {
    Pilha aux;
    inicializa_pilha(&aux);
    TipoItem item;
    
    while (!pilha_vazia(p1)) {
        desempilha(p1, &item);
        empilha(&aux, item);
    }
    
    while (!pilha_vazia(&aux)) {
        desempilha(&aux, &item);
        empilha(p2, item);
    }
}

/* Exercício 2: Testa se uma pilha P1 tem mais elementos que uma pilha P2 */
bool tem_mais_elementos(Pilha *p1, Pilha *p2) {
    return tamanho_pilha(p1) > tamanho_pilha(p2);
}

/* Exercício 3: Inverte a posição dos elementos de uma pilha P */
void inverte_pilha(Pilha *p) {
    Pilha aux1, aux2;
    inicializa_pilha(&aux1);
    inicializa_pilha(&aux2);
    TipoItem item;
    
    while (!pilha_vazia(p)) {
        desempilha(p, &item);
        empilha(&aux1, item);
    }
    
    while (!pilha_vazia(&aux1)) {
        desempilha(&aux1, &item);
        empilha(&aux2, item);
    }
    
    while (!pilha_vazia(&aux2)) {
        desempilha(&aux2, &item);
        empilha(p, item);
    }
}

/* Exercício 4: Testa se duas pilhas P1 e P2 são iguais */
bool pilhas_iguais(Pilha *p1, Pilha *p2) {
    if (tamanho_pilha(p1) != tamanho_pilha(p2)) {
        return false;
    }
    
    Pilha aux1, aux2;
    inicializa_pilha(&aux1);
    inicializa_pilha(&aux2);
    TipoItem item1, item2;
    bool sao_iguais = true;
    
    while (!pilha_vazia(p1)) {
        desempilha(p1, &item1);
        desempilha(p2, &item2);
        
        if (item1 != item2) {
            sao_iguais = false;
        }
        
        empilha(&aux1, item1);
        empilha(&aux2, item2);
    }
    
    while (!pilha_vazia(&aux1)) {
        desempilha(&aux1, &item1);
        desempilha(&aux2, &item2);
        
        empilha(p1, item1);
        empilha(p2, item2);
    }
    
    return sao_iguais;
}