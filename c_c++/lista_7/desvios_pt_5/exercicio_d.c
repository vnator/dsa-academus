#include <stdio.h>
#include <ctype.h>

int main() {
    char sexo;
    int idade, engravidou, tem_filhos, quantos_filhos, idade_mais_velho;

    printf("\nSexo (M/F): ");
    scanf("%c", &sexo);
    sexo = tolower(sexo);

    printf("\nIdade: ");
    scanf("%d", &idade);

    if (sexo == 'f' && idade > 10) {
        printf("\nJá engravidou? (1 = sim, 0 = nao): ");
        scanf("%d", &engravidou);

        if (engravidou) {
            printf("\nTem filhos? (1 = sim, 0 = nao): ");
            scanf("%d", &tem_filhos);

            if (tem_filhos) {
                printf("\nQuantos filhos tem? "); 
                scanf("%d", &quantos_filhos);

                printf("\nIdade do filho mais velho: ");
                scanf("%d", &idade_mais_velho);
            }
        }
    }

    printf("\nSexo: %s", sexo == 'm' ? "Masculino" : "Feminino");
    printf("\nIdade: %d anos", idade);

    if (sexo == 'f' && idade > 10) {
        printf(engravidou ? "\nJa engravidou" : "\nNunca engravidou");

        if (engravidou) {
            printf(tem_filhos ? "\nTem filhos" : "\nmas nao tem filhos");
            if (tem_filhos) {
                printf("\nQuantidade de filhos: %d", quantos_filhos);
                printf("\n O filho mais velho tem %d anos", idade_mais_velho);
            }
        }
    }

    return 0;
}
