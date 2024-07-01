#include <stdio.h>

int main(void) {
    float salario, contas[3];
    printf("Digite o valor do salário: ");
    scanf("%f", &salario);

    float alimentacao, transporte, educacao;
    printf("\nDigite o valor dos gastos com alimentação: ");
    scanf("%f", &alimentacao);
    printf("\nDigite o valor dos gastos com transporte: ");
    scanf("%f", &transporte);
    printf("\nDigite o valor dos gastos com educação: ");
    scanf("%f", &educacao);

    float total_gastos = alimentacao + transporte + educacao;

    if (total_gastos > salario) {
        printf("\nOs gastos excedem o salário. Encerrando o programa.");
        return 0;
    }

    printf("\nPercentuais de gastos em ordem crescente");
    if (alimentacao >= transporte && alimentacao >= educacao) {
        contas[0] = (alimentacao / salario) * 100;
        if (transporte >= educacao) {
            contas[1] = (transporte / salario) * 100;
            contas[2] = (educacao / salario) * 100;
        } else {
            contas[1] = (educacao / salario) * 100;
            contas[2] = (transporte / salario) * 100;
        }
    } else if (transporte >= educacao) {
        contas[0] = (transporte / salario) * 100;
        contas[1] = (alimentacao / salario) * 100;
        contas[2] = (educacao / salario) * 100;
    } else {
        contas[0] =  (educacao / salario) * 100;
        contas[1] =  (transporte / salario) * 100;
        contas[2] =  (alimentacao / salario) * 100;
    }

    printf("\nGastos do maior para o menor:");
    for (int i = 0; i < 3; i++) {
        printf(" %.2f", contas[i]);
    }

    printf("\nGastos do menor para o maior:");
    for (int i = 2; i >= 0; i--) {
        printf(" %.2f", contas[i]);
    }
    
    return 0;
}
