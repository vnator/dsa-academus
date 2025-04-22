#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[80];
    char situacao[20];
    float saldo;
} conta;

void recebeDados(conta *cliente) {
    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, 80, stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
    printf("\nDigite o saldo do cliente: ");
    scanf("%f", &cliente->saldo);
}

void atualizaSituacao(conta *cliente) {
    if (cliente->saldo >= 1000.0) {
        strcpy(cliente->situacao, "PREFERENCIAL");
        cliente->saldo += cliente->saldo * 0.10; // Incrementa 10% ao saldo
    } else {
        strcpy(cliente->situacao, "CONVENCIONAL");
    }
}

void exibeDados(const conta *cliente) {
    printf("\n--- Dados do Cliente ---\n");
    printf("\nNome: %s\n", cliente->nome);
    printf("\nSituação: %s\n", cliente->situacao);
    printf("\nSaldo: R$ %.2f\n", cliente->saldo);
}

int main() {
    conta cliente;
    recebeDados(&cliente);
    atualizaSituacao(&cliente);
    exibeDados(&cliente);

    return 0;
}
