// 10 pessoas, pedir, sexo idade
// retornar 
// - quantas de cada sexo
// - media da idade masc
// - media da idade fem
// - porcentagem de homens que participaram
// - porcentagem de mulheres  que participaram
#include <stdio.h>
#include <ctype.h>

int main() {
    int idades[10];
    char generos[10]
    int i = 0;
    int quant_masc, quant_fem, media_masc, media_fem, por_masc, por_fem;

    printf("Vamos coletar informações de 10 Pessoas, sexo e idade.\n")

    while (i < 10) {
        printf("Digite seu sexo: ");
        scanf(&generos[i]);

        printf("Digite sua idade: ");
        scanf(&idades[i]);

        generos[i] = tolower(generos[i]);
    
        if (generos[i] == 'm') {

        } else {
            
        }
    }

    return 0;
}