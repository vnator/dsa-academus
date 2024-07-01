#include <stdio.h>

int main() {
    int codigo;
    printf("Digite o código (0 a 6) correspondente ao dia da semana: ");
    scanf("%d", &codigo);

    switch (codigo) {
        case 0:
            printf("\nDomingo");
            break;
        case 1:
            printf("\nSegunda-feira");
            break;
        case 2:
            printf("\nTerça-feira");
            break;
        case 3:
            printf("\nQuarta-feira");
            break;
        case 4:
            printf("\nQuinta-feira");
            break;
        case 5:
            printf("\nSexta-feira");
            break;
        case 6:
            printf("\nSábado");
            break;
        default:
            printf("\nCódigo inválido. Digite um valor entre 0 e 6.");
            break;
    }

    return 0;
}
