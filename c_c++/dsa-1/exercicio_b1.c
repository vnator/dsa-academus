#include <stdio.h>

int main() {
    int escolha;

    printf("Escolha o melhor filme de todos os tempos:\n");
    printf("1 - O Poderoso Chefão\n");
    printf("2 - A Paixão de Cristo\n");
    printf("3 - Mad Max: Estrada da Fúria\n");
    printf("4 - Sin City\n");
    printf("5 - Os Imperdoáveis\n");
    printf("Digite o número correspondente ao filme escolhido: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Você escolheu: O Poderoso Chefão\n");
    } else if (escolha == 2) {
        printf("Você escolheu: A Paixão de Cristo\n");
    } else if (escolha == 3) {
        printf("Você escolheu: Mad Max: Estrada da Fúria\n");
    } else if (escolha == 4) {
        printf("Você escolheu: Sin City\n");
    } else if (escolha == 5) {
        printf("Você escolheu: Os Imperdoáveis\n");
    } else {
        printf("Qualquer coisa do Clint Eastwood.\n");
    }

    return 0;
}