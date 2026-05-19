#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

// ==========================================
// (a) f(x) = sqrt(x) - e^(-x)
// ==========================================
double f_a(double x) { return sqrt(x) - exp(-x); }
double df_a(double x) { return (1.0 / (2.0 * sqrt(x))) + exp(-x); }
double phi_a(double x) { return exp(-2.0 * x); }

// ==========================================
// (b) f(x) = ln(x) - x + 2
// ==========================================
double f_b(double x) { return log(x) - x + 2.0; }
double df_b(double x) { return (1.0 / x) - 1.0; }
double phi_b(double x) { return log(x) + 2.0; }

// ==========================================
// (c) f(x) = e^(x/2) - x^3
// ==========================================
double f_c(double x) { return exp(x / 2.0) - pow(x, 3.0); }
double df_c(double x) { return (0.5 * exp(x / 2.0)) - (3.0 * pow(x, 2.0)); }
double phi_c(double x) { return exp(x / 6.0); }

// ==========================================
// (d) f(x) = sin(x) - x^2
// ==========================================
double f_d(double x) { return sin(x) - pow(x, 2.0); }
double df_d(double x) { return cos(x) - (2.0 * x); }
double phi_d(double x) { return sqrt(sin(x)); }

// ==========================================
// (e) f(x) = x/4 - cos(x)
// ==========================================
double f_e(double x) { return x / 4.0 - cos(x); }
double df_e(double x) { return 0.25 + sin(x); }
double phi_e(double x) { return acos(x / 4.0); }

// ==========================================
// EXECUTOR
// ==========================================
void run_test(char label, double x0, double (*f)(double), double (*df)(double), double (*phi)(double), FILE *file) {
    
    // O exercício 3 EXIGE o critério de parada |f(x)| <= 10^-3
    double tol_f = 1e-3; 
    double tol_x = 0.0;  // Ignorado
    int max_iter = 1000;
    
    Result res_nr = newton_raphson(x0, f, df, tol_f, tol_x, max_iter);
    Result res_mil = mil(x0, phi, f, tol_f, tol_x, max_iter);

    fprintf(file, "#### Função (%c)\n", label);
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

    fprintf(file, "# Resultados - Exercício 3\n\n");
    fprintf(file, "**Critério de parada:** $|f(x_k)| \\le 10^{-3}$\n\n");

    // Usando os mesmos chutes iniciais que definimos analiticamente no Ex 2
    run_test('a', 0.45, f_a, df_a, phi_a, file);
    run_test('b', 3.50, f_b, df_b, phi_b, file);
    run_test('c', 1.50, f_c, df_c, phi_c, file);
    run_test('d', 0.75, f_d, df_d, phi_d, file);
    run_test('e', 1.25, f_e, df_e, phi_e, file);

    fclose(file);
    printf("Resolvido! Arquivo 'resposta.md' gerado para o Exercício 3.\n");
    return 0;
}