#include <stdio.h>

int main() {
    int n, m, menor, maior, iMenor = 0, jMenor = 0, iMaior = 0, jMaior = 0;

    printf("\nEntre com o número de linhas (N): ");
    scanf("%d", &n);
    printf("\nEntre com o número de colunas (M): ");
    scanf("%d", &m);

    int matriz[n][m];

    printf("\nEntre com os elementos da matriz %dx%d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("\nElemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if (i == 0 && j == 0) {
              menor = matriz[i][j];
              maior = matriz[i][j];
            } else {
              
              if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                iMenor = i;
                jMenor = j;
              }

              if (matriz[i][j] > maior) {
                  maior = matriz[i][j];
                  iMaior = i;
                  jMaior = j;
              }
            }
        }
    }

    printf("Menor valor: %d, na posição [%d][%d]\n", menor, iMenor, jMenor);
    printf("Maior valor: %d, na posição [%d][%d]\n", maior, iMaior, jMaior);

    return 0;
}
