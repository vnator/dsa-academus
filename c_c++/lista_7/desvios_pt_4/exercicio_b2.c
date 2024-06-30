#include <stdio.h>

int main() {
    int estilo;

    printf("Escolha o estilo de banda:\n");
    printf("1 - Country\n");
    printf("2 - Rock\n");
    printf("3 - Metal\n");
    printf("4 - Folk\n");
    printf("Digite o número correspondente ao estilo: ");
    scanf("%d", &estilo);

    switch (estilo) {
        case 1:
            printf("Música do Marshall Tucker Band: Can't You See\n");
            break;
        case 2:
            printf("Música do ZZ Top: La Grange\n");
            break;
        case 3:
            printf("Música do Blind Guardian: Mirror Mirror\n");
            break;
        case 4:
            printf("Música do Neil Young: Heart of Gold\n");
            break;
        default:
            printf("Ouça um concerto clássico como As quatro estações de Vivaldi.\n");
    }

    return 0;
}