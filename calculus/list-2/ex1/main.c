#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

// ==========================================
// FUNÇÕES PARA O EXERCÍCIO 1(a)
// f(x) = x^3 - x + 1   no intervalo [-2, -1]
// ==========================================
double f_a(double x) { return pow(x, 3) - x + 1.0; }
double df_a(double x) { return 3.0 * pow(x, 2) - 1.0; }
// Isolando 'x' da forma que |phi'(x)| < 1
double phi_a(double x) { return cbrt(x - 1.0); } 

// ==========================================
// FUNÇÕES PARA O EXERCÍCIO 1(b)
// f(x) = x^2 + 3x - cos(x) - 2.45   no intervalo [0.5, 1]
// ==========================================
double f_b(double x) { return pow(x, 2) + 3.0 * x - cos(x) - 2.45; }
double df_b(double x) { return 2.0 * x + 3.0 + sin(x); }
// Isolando o termo linear "3x" para garantir convergência
double phi_b(double x) { return (-pow(x, 2) + cos(x) + 2.45) / 3.0; }

void run_test(char label, double x0, double (*f)(double), double (*df)(double), double (*phi)(double), FILE *file) {
    
    // Configurando os critérios de parada de forma isolada
    double tol_f = 1e-3; // O exercício 1 pede |f(x)| <= 10^-3
    double tol_x = 0.0;  // Ignorado neste exercício
    int max_iter = 1000;
    
    Result res_nr = newton_raphson(x0, f, df, tol_f, tol_x, max_iter);
    Result res_mil = mil(x0, phi, f, tol_f, tol_x, max_iter);

    fprintf(file, "#### Exercício 1(%c)\n", label);
    fprintf(file, "**Chute Inicial ($x_0$):** `%.2f`\n\n", x0);
    fprintf(file, "| Método | Raiz Aproximada | Iterações | Resíduo $|f(x)|$ | Tempo (ms) |\n");
    fprintf(file, "|:---|---:|---:|---:|---:|\n");
    fprintf(file, "| **Newton-Raphson** | `%.6f` | %d | `%.6f` | `%.6f` |\n", 
            res_nr.root, res_nr.iterations, fabs(f(res_nr.root)), res_nr.time_ms);
    fprintf(file, "| **Iteração Linear (MIL)** | `%.6f` | %d | `%.6f` | `%.6f` |\n\n", 
            res_mil.root, res_mil.iterations, fabs(f(res_mil.root)), res_mil.time_ms);
}

int main() {
    FILE *file = fopen("resposta.md", "w");
    if (!file) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(file, "# Resultados - Exercício 1\n\n");
    fprintf(file, "**Critério de parada:** $|f(x_k)| \\le 10^{-3}$\n\n");

    // Letra (a) - Chute inicial no meio do intervalo [-2, -1]
    run_test('a', -1.5, f_a, df_a, phi_a, file);

    // Letra (b) - Chute inicial no meio do intervalo [0.5, 1.0]
    run_test('b', 0.75, f_b, df_b, phi_b, file);

    fclose(file);
    printf("Resolvido! Arquivo 'resposta.md' gerado com sucesso para as alternativas (a) e (b).\n");
    return 0;
}