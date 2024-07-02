// while mostra a soma se for par
#include <stdio.h>

int main() {
    int a = 0, b = 0;
    printf("Digite 2 valores: =D \n");

    while(a%2==0 && b%2==0){
        printf("Digite o valor de A: ");
        scanf("%d", &a);
        printf("\nDigite o valor de B: ");
        scanf("%d", &b);

        printf("%d", a+b);
        printf("Soma")
    }

    printf("o valor a: %d, ou b: %d, não são pares.", a, b);

    return 0;
}