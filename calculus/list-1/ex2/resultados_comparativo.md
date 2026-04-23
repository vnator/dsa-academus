# Exercicio 2 - Comparativo: Bisseccao vs Falsa Posicao

**Criterios de parada:** `|f(xk)| <= 1e-5` ou `|bk-ak| <= 1e-5`

#### Funcao (a)
**Intervalo inicial:** `[0.000000, 1.000000]`

| Metodo | Raiz Aproximada | Iteracoes | Tempo (ms) | Precisao &#124;f(xk)&#124; |
|:---|---:|---:|---:|---:|
| Bisseccao | `0.5885314941` | 15 | 0.000762 | 1.7334023407e-06 |
| Falsa Posicao | `0.5885363697` | 7 | 0.000220 | 5.0285204791e-06 |

#### Funcao (b)
**Intervalo inicial:** `[1.000000, 2.000000]`

| Metodo | Raiz Aproximada | Iteracoes | Tempo (ms) | Precisao &#124;f(xk)&#124; |
|:---|---:|---:|---:|---:|
| Bisseccao | `1.4171066284` | 17 | 0.000501 | 1.8827984452e-05 |
| Falsa Posicao | `1.4171092736` | 13 | 0.000190 | 8.3890729616e-06 |

#### Funcao (c)
**Intervalo inicial:** `[2.000000, 3.000000]`

| Metodo | Raiz Aproximada | Iteracoes | Tempo (ms) | Precisao &#124;f(xk)&#124; |
|:---|---:|---:|---:|---:|
| Bisseccao | `2.2191162109` | 13 | 0.000652 | 9.5556792673e-06 |
| Falsa Posicao | `2.2191052206` | 6 | 0.000140 | 2.0333379296e-06 |

