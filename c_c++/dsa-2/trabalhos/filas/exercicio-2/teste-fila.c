#include <stdio.h>
#include "fila.h"

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
    
    int opcao, resultado;
    TipoItem item;
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &item);
                
                resultado = inserir_item(&fila, item);
                if (resultado == SUCESSO) {
                    printf("Item %d inserido com sucesso!\n", item);
                } else if (resultado == ERRO_FILA_CHEIA) {
                    printf("Erro: Fila cheia!\n");
                }
                break;
                
            case 2:
                resultado = remover_item(&fila, &item);
                if (resultado == SUCESSO) {
                    printf("Item removido: %d\n", item);
                } else if (resultado == ERRO_FILA_VAZIA) {
                    printf("Erro: Fila vazia!\n");
                }
                break;
                
            case 3:
                listar_fila(&fila);
                printf("Tamanho atual da fila: %d elementos\n", tamanho_fila(&fila));
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