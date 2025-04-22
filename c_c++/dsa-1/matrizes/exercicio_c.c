#include <stdio.h>

int main() {
    int notas[3][4];
    float medias[3];

    for (int i = 0; i < 3; i++) {
        printf("Entre com as 4 notas do aluno %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%d", &notas[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        float soma = 0;
        for (int j = 0; j < 4; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / 4;
    }

    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Notas: ");
        for (int j = 0; j < 4; j++) {
            printf("%d ", notas[i][j]);
        }
        printf("\nMedia: %.2f\n", medias[i]);
    }

    return 0;
}

