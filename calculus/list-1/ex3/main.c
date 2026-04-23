#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

double f(double x) { return pow(x, 6.0) - 1249.0; }

typedef struct {
    double root;
    int iterations;
    double time_ms;
    double abs_fx;
} MethodOutput;

static MethodOutput run_bisection(double a, double b) {
    Result r = bisection(a, b, f, 1e-12, 1e-6, 100000, 1);
    MethodOutput out;
    out.root = r.root;
    out.iterations = r.iterations;
    out.time_ms = r.time_ms;
    out.abs_fx = fabs(f(r.root));
    return out;
}

static MethodOutput run_false_position(double a, double b) {
    Result r = false_position(a, b, f, 1e-12, 1e-6, 100000, 1);
    MethodOutput out;
    out.root = r.root;
    out.iterations = r.iterations;
    out.time_ms = r.time_ms;
    out.abs_fx = fabs(f(r.root));
    return out;
}

int main() {
    double a = 3.0;
    double b = 4.0;
    FILE *file = fopen("resultados_comparativo.md", "w");
    MethodOutput mb;
    MethodOutput mf;

    if (file == NULL) {
        printf("Erro: nao foi possivel criar resultados_comparativo.md\n");
        return 1;
    }

    mb = run_bisection(a, b);
    mf = run_false_position(a, b);

    fprintf(file, "# Exercicio 3 - Comparativo: Bisseccao vs Falsa Posicao\n\n");
    fprintf(file, "**Problema:** calcular `1249^(1/6)` com cinco casas decimais exatas\n\n");
    fprintf(file, "**Funcao usada:** `f(x) = x^6 - 1249`\n\n");
    fprintf(file, "**Intervalo inicial:** `[%.1f, %.1f]`\n\n", a, b);
    fprintf(file, "**Criterios de parada:** `|f(xk)| <= 1e-12` ou `|bk-ak| <= 1e-6`\n\n");

    fprintf(file, "| Metodo | Raiz Aproximada | Raiz (5 casas) | Iteracoes | Tempo (ms) | Precisao &#124;f(xk)&#124; |\n");
    fprintf(file, "|:---|---:|---:|---:|---:|---:|\n");
    fprintf(file, "| Bisseccao | `%.10f` | `%.5f` | %d | %.6f | %.10e |\n", mb.root, mb.root, mb.iterations, mb.time_ms, mb.abs_fx);
    fprintf(file, "| Falsa Posicao | `%.10f` | `%.5f` | %d | %.6f | %.10e |\n", mf.root, mf.root, mf.iterations, mf.time_ms, mf.abs_fx);

    fclose(file);
    printf("Arquivo 'resultados_comparativo.md' gerado com sucesso.\n");
    return 0;
}
