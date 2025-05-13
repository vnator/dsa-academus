#include "pilha.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
            printf("%c", p->itens[i]);
            if (i < p->topo) {
                printf(", ");
            }
        }
    }
    printf(" ]\n");
}

bool eh_palindromo(char *texto) {
    Pilha p;
    inicializa_pilha(&p);
    int i, j = 0;
    int tamanho = strlen(texto);
    char texto_limpo[MAX_PILHA];
    char texto_invertido[MAX_PILHA];
    
    for (i = 0; i < tamanho; i++) {
        if (isalnum(texto[i])) {
            texto_limpo[j] = tolower(texto[i]);
            j++;
        }
    }
    texto_limpo[j] = '\0'; 

    for (i = 0; i < j; i++) {
        empilha(&p, texto_limpo[i]);
    }
    
    i = 0;
    while (!pilha_vazia(&p)) {
        char c;
        desempilha(&p, &c);
        texto_invertido[i] = c;
        i++;
    }
    texto_invertido[i] = '\0';
    
    return (strcmp(texto_limpo, texto_invertido) == 0);
}