#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main() {
    Estacionamento estacionamento;
    inicializa_estacionamento(&estacionamento);
    
    char linha[20];
    char operacao;
    int placa;
    
    printf("=== Exercício 6: Estacionamento de Bashemin ===\n\n");
    printf("Digite as operações (E/S seguido da placa do carro).\n");
    printf("Digite 'fim' para encerrar o programa.\n\n");
    printf("Executando casos de teste automáticos:\n\n");
    
    // Estacionar alguns carros
    processar_operacoes(&estacionamento, 'E', 1234);
    processar_operacoes(&estacionamento, 'E', 5678);
    processar_operacoes(&estacionamento, 'E', 9012);
    processar_operacoes(&estacionamento, 'E', 3456);
    printf("\n");
    
    // Retirar um carro que não é o mais próximo da saída
    processar_operacoes(&estacionamento, 'S', 9012);
    printf("\n");
    
    // Retirar o carro mais próximo da saída
    processar_operacoes(&estacionamento, 'S', 3456);
    printf("\n");
    
    // Tentar retirar um carro que não está no estacionamento
    processar_operacoes(&estacionamento, 'S', 7777);
    printf("\n");
    
    // Encher o estacionamento e tentar estacionar mais um
    processar_operacoes(&estacionamento, 'E', 1111);
    processar_operacoes(&estacionamento, 'E', 2222);
    processar_operacoes(&estacionamento, 'E', 3333);
    processar_operacoes(&estacionamento, 'E', 4444);
    processar_operacoes(&estacionamento, 'E', 5555);
    processar_operacoes(&estacionamento, 'E', 6666);
    processar_operacoes(&estacionamento, 'E', 7777);
    processar_operacoes(&estacionamento, 'E', 8888);
    printf("\n");
    
    // Esvaziar o estacionamento
    processar_operacoes(&estacionamento, 'S', 8888);
    processar_operacoes(&estacionamento, 'S', 7777);
    processar_operacoes(&estacionamento, 'S', 6666);
    processar_operacoes(&estacionamento, 'S', 5555);
    processar_operacoes(&estacionamento, 'S', 4444);
    processar_operacoes(&estacionamento, 'S', 3333);
    processar_operacoes(&estacionamento, 'S', 2222);
    processar_operacoes(&estacionamento, 'S', 1111);
    processar_operacoes(&estacionamento, 'S', 5678);
    processar_operacoes(&estacionamento, 'S', 1234);
    printf("\n");

    // Agora vamos permitir que o usuário interaja com o programa
    printf("Agora é sua vez! Digite as operações (ou 'fim' para encerrar):\n");
    
    while (1) {
        printf("\nDigite operação e placa (ex: 'E 1234' ou 'S 5678') ou 'fim': ");
        scanf("%s", linha);
        
        if (strcmp(linha, "fim") == 0) {
            break;
        }
        
        operacao = linha[0];
        
        if (scanf("%d", &placa) != 1) {
            printf("Formato inválido. Use 'E placa' ou 'S placa'.\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (operacao != 'E' && operacao != 'S') {
            printf("Operação inválida. Use 'E' para entrada ou 'S' para saída.\n");
            continue;
        }
        
        processar_operacoes(&estacionamento, operacao, placa);
    }
    
    printf("\nPrograma encerrado.\n");
    return 0;
}