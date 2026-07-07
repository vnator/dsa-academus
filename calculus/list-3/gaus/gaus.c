#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

void gauss_elimination(double A[N][N], double b[N], double x[N]) {
    int i, j, k;
    double mult, sum, pivot;

    // Triangularização da matriz aumentada O(N^3)
    for (k = 0; k < N - 1; k++) {
        
        // Identificação do pivô
        pivot = A[k][k];
        
        // Proteção contra divisão por zero (falha catastrófica sem pivoteamento)
        if (fabs(pivot) < 1e-15) {
            fprintf(stderr, "Erro numérico: Pivô nulo ou próximo da precisão de máquina detectado.\n");
            exit(EXIT_FAILURE);
        }

        for (i = k + 1; i < N; i++) {
            // Cálculo dos multiplicadores
            mult = A[i][k] / pivot;
            
            // Atualização dos elementos da matriz aumentada (Otimização de Cache: Acesso contíguo)
            for (j = k + 1; j < N; j++) {
                A[i][j] -= mult * A[k][j];
            }
            // Atualização do vetor independente
            b[i] -= mult * b[k];
        }
    }

    // Validação do último pivô
    if (fabs(A[N-1][N-1]) < 1e-15) {
        fprintf(stderr, "Erro numérico: Matriz singular.\n");
        exit(EXIT_FAILURE);
    }

    // Substituição regressiva O(N^2)
    x[N - 1] = b[N - 1] / A[N - 1][N - 1];
    
    for (i = N - 2; i >= 0; i--) {
        sum = b[i];
        for (j = i + 1; j < N; j++) {
            sum -= A[i][j] * x[j];
        }
        x[i] = sum / A[i][i];
    }
}

int main() {
    // Sistema do exemplo
    double A[N][N] = {
        { 2,  1, -1,  3,  0},
        { 1,  3,  2, -1,  4},
        { 0,  2,  4,  1, -2},
        {-1,  4,  1,  2,  3},
        { 3, -1,  3,  0,  2}
    };
    
    double b[N] = {-9, 12, -1, 6, -3};
    double x[N];

    gauss_elimination(A, b, x);

    printf("Vetor Solucao (x):\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.15f\n", i + 1, x[i]);
    }

    return 0;
}