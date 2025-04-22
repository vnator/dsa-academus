#include <stdio.h>
#include <string.h>

struct Conta {
    int num_conta;
    char tipo_conta;
    char nome[50];
    float saldo;
};

int main() {
    struct Conta vcliente[100];
    int n, i = 0;

    printf("Digite o número de clientes (máximo 100): ");
    scanf("%d", &n);

    while (n < 1 || n > 100) {
        printf("\nNúmero de clientes inválido. O número deve estar entre 1 e 100.");
        printf("\nDigite novamente o número de clientes: ");
        scanf("%d", &n);
    }

    while (i < n) {
        printf("\nInserindo dados para o cliente %d", i + 1);

        printf("\nNúmero da conta: ");
        scanf("%d", &vcliente[i].num_conta);

        printf("\nTipo de conta (C para corrente, P para poupança, etc.): ");
        scanf(" %c", &vcliente[i].tipo_conta);

        printf("\nNome do cliente: ");
        scanf(" %[^\n]s", vcliente[i].nome);

        printf("\nSaldo da conta: ");
        scanf("%f", &vcliente[i].saldo);

        i++;
    }

    printf("\nImprime dados dos clientes");
    printf("\nNro Cta Tipo Cta Nome Cliente Saldo Cta");

    i = 0;
    while (i < n) {
        printf("\n - %3d, %c %s %.2f", vcliente[i].num_conta, vcliente[i].tipo_conta, vcliente[i].nome, vcliente[i].saldo);
        i++;
    }

    return 0;
}
