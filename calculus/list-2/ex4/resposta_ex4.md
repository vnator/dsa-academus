# Resultados - Exercício 4

**Problema:** Cálculo da taxa de juros real do empréstimo com acréscimo.
**Método Utilizado:** Newton-Raphson
**Critério de parada:** $|f(x)| \le 10^{-5}$ ou $\Delta x \le 10^{-5}$

### Execução
- **Chute Inicial ($x_0$):** `0.0500` (5% ao mês)
- **Raiz Aproximada ($x$):** `0.075790`
- **Iterações:** 13
- **Resíduo $|F(x)|$:** `0.000018`
- **Tempo de Execução:** `0.006412` ms

### Conclusão Financeira
=> **Verdadeira Taxa de Juros Mensal:** `7.58%`
=> **Verdadeira Taxa de Juros Anual:** `90.95%`
