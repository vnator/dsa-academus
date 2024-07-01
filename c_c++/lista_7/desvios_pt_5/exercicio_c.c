#include <stdio.h>

int main() {
    int mora_com_pessoas, quantas_pessoas, idade_mais_velha, divide_quarto, quantas_divide, tempo_dividem;

    printf("Mora com outras pessoas na casa? (1 = sim, 0 = nao): ");
    scanf("%d", &mora_com_pessoas);

    if (mora_com_pessoas) {
        printf("\nCom quantas pessoas? ");
        scanf("%d", &quantas_pessoas);

        printf("\nQual a idade da mais velha? ");
        scanf("%d", &idade_mais_velha);

        printf("\nDivide o quarto com outras pessoas? (1 = sim, 0 = nao): ");
        scanf("%d", &divide_quarto);

        if (divide_quarto) {
            printf("\n com quantas pessoas vc divide o quarto? ");
            scanf("%d", &quantas_divide);

            printf("\nHá quanto tempo dividem o mesmo quarto (ano)? ");
            scanf("%d", &tempo_dividem);
        }
    }

    printf(mora_com_pessoas ? "\nMora com outras pessoas na casa" : "\nNao mora com mais ninguem");
    if (mora_com_pessoas) {
        printf("\nQuantidade de pessoas na casa: %d", quantas_pessoas);
        printf("\nIdade da pessoa mais velha: %d", idade_mais_velha);
        printf(divide_quarto ? "Divide o quarto com outras pessoas" : "Nao divide o quarto com ningem");
        if (divide_quarto) {
            printf("\nDivide o quarto com %d pessoa(s)", quantas_divide);
            printf("\nDivide o o quarto a %d anos", tempo_dividem);
        }
    }

    return 0;
}
