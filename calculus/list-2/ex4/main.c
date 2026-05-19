#include <stdio.h>
#include <math.h>
#include "../methods/root_methods.h"

// ==========================================
// FUNÇÕES PARA O EXERCÍCIO 4
// Equação: F(x) = (Ax - P)(1+x)^n + P = 0
// ==========================================

double f_ex4(double x) {
    double A = 1000.0;
    double n = 24.0;
    // P = A * (1/n + q/100)
    double P = A * ((1.0 / n) + 0.05); 
    
    return (A * x - P) * pow(1.0 + x, n) + P;
}

// Derivada: F'(x) = A(1+x)^n + n(Ax - P)(1+x)^(n-1)
double df_ex4(double x) {
    double A = 1000.0;
    double n = 24.0;
    double P = A * ((1.0 / n) + 0.05);
    
    return A * pow(1.0 + x, n) + n * (A * x - P) * pow(1.0 + x, n - 1.0);
}

int main() {
    // Abrindo arquivo de resposta para o Exercício 4
    FILE *file = fopen("resposta_ex4.md", "w");
    if (!file) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    // O exercício não especificou a tolerância, usamos 10^-5 para precisão financeira
    double tol_f = 1e-5;
    double tol_x = 1e-5;
    int max_iter = 1000;
    
    // Chute inicial de 5% (0.05) pois sabemos que a taxa real é próxima e superior à nominal
    double x0 = 0.05;

    Result res = newton_raphson(x0, f_ex4, df_ex4, tol_f, tol_x, max_iter);

    // Conversão da raiz (decimal) para as taxas percentuais
    double taxa_mensal = res.root * 100.0;
    double taxa_anual = res.root * 12.0 * 100.0;

    // Gerando o relatório no Markdown
    fprintf(file, "# Resultados - Exercício 4\n\n");
    fprintf(file, "**Problema:** Cálculo da taxa de juros real do empréstimo com acréscimo.\n");
    fprintf(file, "**Método Utilizado:** Newton-Raphson\n");
    fprintf(file, "**Critério de parada:** $|f(x)| \\le 10^{-5}$ ou $\\Delta x \\le 10^{-5}$\n\n");
    
    fprintf(file, "### Execução\n");
    fprintf(file, "- **Chute Inicial ($x_0$):** `%.4f` (5%% ao mês)\n", x0);
    fprintf(file, "- **Raiz Aproximada ($x$):** `%.6f`\n", res.root);
    fprintf(file, "- **Iterações:** %d\n", res.iterations);
    fprintf(file, "- **Resíduo $|F(x)|$:** `%.6f`\n", fabs(f_ex4(res.root)));
    fprintf(file, "- **Tempo de Execução:** `%.6f` ms\n\n", res.time_ms);
    
    fprintf(file, "### Conclusão Financeira\n");
    fprintf(file, "=> **Verdadeira Taxa de Juros Mensal:** `%.2f%%`\n", taxa_mensal);
    fprintf(file, "=> **Verdadeira Taxa de Juros Anual:** `%.2f%%`\n", taxa_anual);

    fclose(file);
    printf("Resolvido! Arquivo 'resposta_ex4.md' gerado com sucesso.\n");
    return 0;
}