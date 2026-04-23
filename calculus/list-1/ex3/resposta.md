# Resposta pra questao descritiva

## Conclusao

- Valor obtido para `1249^(1/6)` com cinco casas: **3.28166** (ambos os metodos).
- Iteracoes: Bisseccao = **20**, Falsa Posicao = **40**.
- Tempo de CPU (ms): Bisseccao = **0.001924**, Falsa Posicao = **0.001713**.
- Precisao `|f(xk)|`: Bisseccao = **3.3560e-04**, Falsa Posicao = **6.8212e-13**.

## Justificativa pratica e analitica

Para a meta do enunciado (cinco casas decimais exatas), os dois metodos chegaram ao mesmo valor final `3.28166`.
Pelo criterio de custo iterativo, a **Bisseccao** foi mais eficiente, pois precisou de metade das iteracoes (20 contra 40).
Em tempo de CPU, a diferenca foi pequena e a Falsa Posicao ficou levemente menor; em precisao residual `|f(xk)|`, a Falsa Posicao foi superior.
