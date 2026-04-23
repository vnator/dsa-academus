# Exercicio 3 - Comparativo: Bisseccao vs Falsa Posicao

**Problema:** calcular `1249^(1/6)` com cinco casas decimais exatas

**Funcao usada:** `f(x) = x^6 - 1249`

**Intervalo inicial:** `[3.0, 4.0]`

**Criterios de parada:** `|f(xk)| <= 1e-12` ou `|bk-ak| <= 1e-6`

| Metodo | Raiz Aproximada | Raiz (5 casas) | Iteracoes | Tempo (ms) | Precisao &#124;f(xk)&#124; |
|:---|---:|---:|---:|---:|---:|
| Bisseccao | `3.2816610336` | `3.28166` | 20 | 0.001924 | 3.3560368911e-04 |
| Falsa Posicao | `3.2816611806` | `3.28166` | 40 | 0.001713 | 6.8212102633e-13 |
