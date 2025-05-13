#include <stdio.h>
#include <stdbool.h>

#define MAX_FILA 100

typedef int TipoItem;

typedef struct {
    TipoItem itens[MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
} Fila;

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

bool inserir_item(Fila *f, TipoItem item) {
    if (fila_cheia(f)) {
        return false;
    }
    
    f->itens[f->fim] = item;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->tamanho++;
    
    return true;
}

bool remover_item(Fila *f, TipoItem *item) {
    if (fila_vazia(f)) {
        return false;
    }
    
    *item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->tamanho--;
    
    return true;
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

void exibir_menu() {
    printf("\n---- MENU DE OPERACOES ----\n");
    printf("1. INSERIR ITEM NA FILA\n");
    printf("2. REMOVER ITEM DA FILA\n");
    printf("3. LISTAR DADOS DA FILA\n");
    printf("4. SAIR\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila fila;
    inicializa_fila(&fila);
    
    int opcao;
    TipoItem item;
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &item);
                
                if (inserir_item(&fila, item)) {
                    printf("Item %d inserido com sucesso!\n", item);
                } else {
                    printf("Erro: Fila cheia!\n");
                }
                break;
                
            case 2:
                if (remover_item(&fila, &item)) {
                    printf("Item removido: %d\n", item);
                } else {
                    printf("Erro: Fila vazia!\n");
                }
                break;
                
            case 3:
                listar_fila(&fila);
                break;
                
            case 4:
                printf("Programa encerrado.\n");
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != 4);
    
    return 0;
}