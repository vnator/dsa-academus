#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

// ==========================================
// (a) f(x) = sqrt(x) - e^(-x) | I = [0.4, 0.5]
// ==========================================
double f_a(double x) { return sqrt(x) - exp(-x); }
double phi_a(double x) { return exp(-2.0 * x); }

// ==========================================
// (b) f(x) = ln(x) - x + 2 | I = [3, 4]
// ==========================================
double f_b(double x) { return log(x) - x + 2.0; }
double phi_b(double x) { return log(x) + 2.0; }

// ==========================================
// (c) f(x) = e^(x/2) - x^3 | I = [1, 2]
// ==========================================
double f_c(double x) { return exp(x / 2.0) - pow(x, 3.0); }
double phi_c(double x) { return exp(x / 6.0); }

// ==========================================
// (d) f(x) = sin(x) - x^2 | I = [0.5, 1.0]
// ==========================================
double f_d(double x) { return sin(x) - pow(x, 2.0); }
double phi_d(double x) { return sqrt(sin(x)); }

// ==========================================
// (e) f(x) = x/4 - cos(x) | I = [1.0, 1.5]
// ==========================================
double f_e(double x) { return x / 4.0 - cos(x); }
double phi_e(double x) { return acos(x / 4.0); }

void run_test(char label, double x0, double (*f)(double), double (*phi)(double), FILE *file) {
    // O exercício 2 não especificou o critério de parada.
    // Vamos usar um padrão acadêmico rigoroso de 10^-5 para garantir a raiz.
    double tol_f = 1e-5; 
    double tol_x = 1e-5;
    int max_iter = 1000;
    
    // O exercício pede especificamente o Método Iterativo Linear (MIL)
    Result res = mil(x0, phi, f, tol_f, tol_x, max_iter);

    fprintf(file, "| %c | `%.2f` | `%.6f` | %d | `%.6f` |\n", 
            label, x0, res.root, res.iterations, res.time_ms);
}

int main() {
    FILE *file = fopen("resposta.md", "w");
    if (!file) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(file, "# Resultados - Exercício 2 (MIL)\n\n");
    fprintf(file, "**Critério de parada adotado:** $|f(x)| \\le 10^{-5}$ ou $\\Delta x \\le 10^{-5}$\n\n");
    
    fprintf(file, "| Alínea | Chute Inicial ($x_0$) | Raiz Aproximada | Iterações | Tempo (ms) |\n");
    fprintf(file, "|:---:|---:|---:|---:|---:|\n");

    // Chutes iniciais escolhidos dentro dos intervalos definidos analiticamente
    run_test('a', 0.45, f_a, phi_a, file); // Meio de [0.4, 0.5]
    run_test('b', 3.50, f_b, phi_b, file); // Meio de [3, 4]
    run_test('c', 1.50, f_c, phi_c, file); // Meio de [1, 2]
    run_test('d', 0.75, f_d, phi_d, file); // Meio de [0.5, 1.0]
    run_test('e', 1.25, f_e, phi_e, file); // Meio de [1.0, 1.5]

    fclose(file);
    printf("Resolvido! Arquivo 'resposta.md' gerado com todas as alíneas do Exercício 2.\n");
    return 0;
}