#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

// Define PI caso o compilador não tenha o padrão (_USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ==========================================
// FUNÇÕES PARA O EXERCÍCIO 5
// Valores substituídos: L=10, r=1, V=12.4
// Equação: f(h) = 10 * [0.5*pi - asin(h) - h*sqrt(1 - h^2)] - 12.4 = 0
// ==========================================

double f_ex5(double h) {
    return 10.0 * (0.5 * M_PI - asin(h) - h * sqrt(1.0 - h * h)) - 12.4;
}

// Derivada purificada analiticamente
double df_ex5(double h) {
    return -20.0 * sqrt(1.0 - h * h);
}

int main() {
    // Abrindo arquivo de resposta para o Exercício 5
    FILE *file = fopen("resposta_ex5.md", "w");
    if (!file) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    // A precisão exigida pelo exercício é de 0,01 pé
    double tol_f = 0.01;
    double tol_x = 0.01;
    int max_iter = 1000;
    
    // Como provamos que a raiz está no intervalo [0, 1], o meio é o chute mais seguro
    double h0 = 0.5;

    // Chamada do nosso módulo agnóstico de Newton-Raphson
    Result res = newton_raphson(h0, f_ex5, df_ex5, tol_f, tol_x, max_iter);

    // Cálculo da resposta final: a profundidade é o Raio (1) menos a distância do topo (h)
    double profundidade = 1.0 - res.root;

    // Gerando o relatório no Markdown
    fprintf(file, "# Resultados - Exercício 5\n\n");
    fprintf(file, "**Problema:** Cálculo da profundidade da água num meio cilindro (Gamela).\n");
    fprintf(file, "**Método Utilizado:** Newton-Raphson\n");
    fprintf(file, "**Critério de parada:** Precisão de `0.01` pé\n\n");
    
    fprintf(file, "### Execução do Algoritmo\n");
    fprintf(file, "- **Chute Inicial ($h_0$):** `%.2f`\n", h0);
    fprintf(file, "- **Raiz Aproximada ($h$):** `%.6f` pés\n", res.root);
    fprintf(file, "- **Iterações:** %d\n", res.iterations);
    fprintf(file, "- **Resíduo $|F(h)|$:** `%.6f`\n", fabs(f_ex5(res.root)));
    fprintf(file, "- **Tempo de Execução:** `%.6f` ms\n\n", res.time_ms);
    
    fprintf(file, "### Resposta Física\n");
    fprintf(file, "=> **Distância do topo da gamela ($h$):** `%.2f` pés\n", res.root);
    fprintf(file, "=> **Profundidade real da água:** `%.2f` pés\n", profundidade);

    fclose(file);
    printf("Resolvido! Arquivo 'resposta_ex5.md' gerado com sucesso.\n");
    return 0;
}