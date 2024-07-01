i#include <stdio.h>

int main() {
    int codigo;
    printf("Digite o código (0 a 6) correspondente ao dia da semana: ");
    scanf("%d", &codigo);

    switch (codigo) {
        case 0:
            printf("Domingo\n");
            break;
        case 1:
            printf("Segunda-feira\n");
            break;
        case 2:
            printf("Terça-feira\n");
            break;
        case 3:
            printf("Quarta-feira\n");
            break;
        case 4:
            printf("Quinta-feira\n");
            break;
        case 5:
            printf("Sexta-feira\n");
            break;
        case 6:
            printf("Sábado\n");
            break;
        default:
            printf("Código inválido. Digite um valor entre 0 e 6.\n");
            break;
    }

    return 0;
}
