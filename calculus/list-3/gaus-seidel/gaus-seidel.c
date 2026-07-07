#include <stdio.h>
#include <math.h>

#define N 4

int main() {
    // Inicio
    // Definir N como 4
    // (Definido via macro pre-processador #define N 4)

    // Definir Matriz A[N][N] 
    double A[N][N] = {
        { 4,  1,  1,  1},
        { 2, -8,  1, -1},
        { 1,  2, -5,  1},
        { 1,  1,  1, -4}
    };
    
    // Definir Vetor b[N] 
    double b[N] = {7, -6, -1, -1};
    
    // Definir Vetor x[N] inicializado com 0
    double x[N] = {0.0, 0.0, 0.0, 0.0};
    
    // Definir variavel epsilon como 0.0001
    double epsilon = 0.0001;
    
    // Definir variavel max_iter como 100
    int max_iter = 100;
    
    // Definir variaveis erro, soma, x_novo
    double erro, soma, x_novo;
    
    // Definir k como 0
    int k = 0;

    printf("Iter          x1          x2          x3          x4        erro\n");

    // Repetir
    do {
        // erro = 0
        erro = 0.0;
        
        // Para i de 1 ate N faca (Em C: 0 ate N-1)
        for (int i = 0; i < N; i++) {
            // soma = b[i]
            soma = b[i];
            
            // Para j de 1 ate i-1 faca
            for (int j = 0; j < i; j++) {
                // soma = soma - (A[i][j] * x[j])
                soma -= A[i][j] * x[j];
            }
            
            // Para j de i+1 ate N faca
            for (int j = i + 1; j < N; j++) {
                // soma = soma - (A[i][j] * x[j])
                soma -= A[i][j] * x[j];
            }
            
            // x_novo = soma / A[i][i]
            x_novo = soma / A[i][i];
            
            // Se absoluto(x_novo - x[i]) > erro entao
            if (fabs(x_novo - x[i]) > erro) {
                // erro = absoluto(x_novo - x[i])
                erro = fabs(x_novo - x[i]);
            }
            // FimSe
            
            // x[i] = x_novo
            x[i] = x_novo;
        }
        // FimPara
        
        // k = k + 1
        k++;
        
        printf("%3d %11.6f %11.6f %11.6f %11.6f %11.6f\n", k, x[0], x[1], x[2], x[3], erro);
        
    // Ate que (erro < epsilon) ou (k >= max_iter)
    } while (erro >= epsilon && k < max_iter);
    
    // Retornar x (Neste caso, exibimos os resultados)
    printf("\n[Resultados Finais]\n");
    printf("Numero de iteracoes: %d\n", k);
    printf("Vetor solucao aproximado: x = (%.6f, %.6f, %.6f, %.6f)^T\n", x[0], x[1], x[2], x[3]);
    printf("Erro final (criterio de parada): %.6f\n", erro);

    // Fim
    return 0;
}