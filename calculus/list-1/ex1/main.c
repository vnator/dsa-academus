#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

double f_a(double x) { return (x * x) + log(x); }
double f_b(double x) { return exp(x) - x - 2.0; }
double f_c(double x) { return (x * x * x) + x - 100.0; }

void run_test(char label, double a, double b, FunctionType f, FILE *file) {
    Result res_b = bisection(a, b, f, 1e-3, 1e-3, 10000, 0);
    Result res_fp = false_position(a, b, f, 1e-3, 1e-3, 10000, 0);
    double err_b = fabs(f(res_b.root));
    double err_fp = fabs(f(res_fp.root));

    fprintf(file, "#### Função (%c)\n", label);
    fprintf(file, "**Intervalo:** `[%.1f, %.1f]`\n\n", a, b);
    fprintf(file, "| Método | Raiz Aproximada | Iterações | Erro &#124;f(x)&#124; | Tempo (ms) |\n");
    fprintf(file, "|:---|---:|---:|---:|---:|\n");
    fprintf(file, "| **Falsa Posição** | `%.6f` | **%d** | `%.6f` | `%.6f` |\n", res_fp.root, res_fp.iterations, err_fp, res_fp.time_ms);
    fprintf(file, "| Bissecção | `%.6f` | %d | `%.6f` | `%.6f` |\n\n", res_b.root, res_b.iterations, err_b, res_b.time_ms);
}

int main() {
    FILE *file = fopen("resultados_comparativo.md", "w");

    if (file == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo.\n");
        return 1;
    }

    fprintf(file, "# Comparativo de Performance - Métodos Numéricos\n\n");
    fprintf(file, "## Raízes de Equações: Bissecção vs Falsa Posição\n\n");
    fprintf(file, "**Critério de parada:** |f(x)| ≤ 0.001\n\n");

    run_test('a', 0.5, 1.0, f_a, file);
    run_test('b', 1.0, 2.0, f_b, file);
    run_test('c', 4.0, 5.0, f_c, file);

    fclose(file);

    printf("Arquivo 'resultados_comparativo.md' gerado com sucesso!\n");

    return 0;
}
