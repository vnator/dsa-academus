#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    char nome[50];

    int trying[3] = {0, 0, 0}; // 0 = saque, 1 = bloqueio, 2 = ataque
    int sucess[3] = {0, 0, 0};

    int totalTry[3] = {0, 0, 0};
    int totalSucess[3] = {0, 0, 0};


    for (int i = 0; i < n; i++) {
        scanf("%s", nome);
        scanf("%d %d %d", &trying[0], &trying[1], &trying[2]);
        scanf("%d %d %d", &sucess[0], &sucess[1], &sucess[2]);

        totalTry[0] += trying[0];
        totalTry[1] += trying[1];
        totalTry[2] += trying[2];
        
        totalSucess[0] += sucess[0];
        totalSucess[1] += sucess[1];
        totalSucess[2] += sucess[2];
    }

    double percent[3] = {
      (totalSucess[0] * 100.0) / totalTry[0],
      (totalSucess[1] * 100.0) / totalTry[1],
      (totalSucess[2] * 100.0) / totalTry[2]
    };

    printf("Pontos de Saque: %.2f %%.\n", percent[0]);
    printf("Pontos de Bloqueio: %.2f %%.\n", percent[1]);
    printf("Pontos de Ataque: %.2f %%.\n", percent[2]);

    return 0;
}
