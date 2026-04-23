#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

double f_a(double x) { return exp(-x) - sin(x); }
double f_b(double x) { return (x * x * x) - (x * exp(x)) + 3.0; }
double f_c(double x) { return sin(x) - log(x); }

typedef struct {
    char label;
    double a;
    double b;
    FunctionType f;
} TestCase;

static int is_valid_root(double x) {
    return !isnan(x) && !isinf(x);
}

static void write_test(FILE *file, const TestCase *tc) {
    Result rb = bisection(tc->a, tc->b, tc->f, 1e-5, 1e-5, 100000, 1);
    Result rf = false_position(tc->a, tc->b, tc->f, 1e-5, 1e-5, 100000, 1);
    double err_b = is_valid_root(rb.root) ? fabs(tc->f(rb.root)) : NAN;
    double err_fp = is_valid_root(rf.root) ? fabs(tc->f(rf.root)) : NAN;

    fprintf(file, "#### Funcao (%c)\n", tc->label);
    fprintf(file, "**Intervalo inicial:** `[%.6f, %.6f]`\n\n", tc->a, tc->b);
    fprintf(file, "| Metodo | Raiz Aproximada | Iteracoes | Tempo (ms) | Precisao &#124;f(xk)&#124; |\n");
    fprintf(file, "|:---|---:|---:|---:|---:|\n");

    if (is_valid_root(rb.root)) {
        fprintf(file, "| Bisseccao | `%.10f` | %d | %.6f | %.10e |\n", rb.root, rb.iterations, rb.time_ms, err_b);
    } else {
        fprintf(file, "| Bisseccao | `falhou` | %d | %.6f | `-` |\n", rb.iterations, rb.time_ms);
    }

    if (is_valid_root(rf.root)) {
        fprintf(file, "| Falsa Posicao | `%.10f` | %d | %.6f | %.10e |\n\n", rf.root, rf.iterations, rf.time_ms, err_fp);
    } else {
        fprintf(file, "| Falsa Posicao | `falhou` | %d | %.6f | `-` |\n\n", rf.iterations, rf.time_ms);
    }
}

int main() {
    FILE *file = fopen("resultados_comparativo.md", "w");
    TestCase tests[] = {
        {'a', 0.0, 1.0, f_a},
        {'b', 1.0, 2.0, f_b},
        {'c', 2.0, 3.0, f_c}
    };
    int n = (int)(sizeof(tests) / sizeof(tests[0]));
    int i;

    if (file == NULL) {
        printf("Erro: nao foi possivel criar resultados_comparativo.md\n");
        return 1;
    }

    fprintf(file, "# Exercicio 2 - Comparativo: Bisseccao vs Falsa Posicao\n\n");
    fprintf(file, "**Criterios de parada:** `|f(xk)| <= 1e-5` ou `|bk-ak| <= 1e-5`\n\n");

    for (i = 0; i < n; i++) {
        write_test(file, &tests[i]);
    }

    fclose(file);

    printf("Arquivo 'resultados_comparativo.md' gerado com sucesso.\n");
    return 0;
}
