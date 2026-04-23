# Comparativo de Performance - Métodos Numéricos

## Raízes de Equações: Bissecção vs Falsa Posição

**Critério de parada:** |f(x)| ≤ 0.001

#### Função (a)
**Intervalo:** `[0.5, 1.0]`

| Método | Raiz Aproximada | Iterações | Erro &#124;f(x)&#124; | Tempo (ms) |
|:---|---:|---:|---:|---:|
| **Falsa Posição** | `0.652931` | **2** | `0.000036` | `0.000070` |
| Bissecção | `0.652832` | 10 | `0.000246` | `0.000401` |

#### Função (b)
**Intervalo:** `[1.0, 2.0]`

| Método | Raiz Aproximada | Iterações | Erro &#124;f(x)&#124; | Tempo (ms) |
|:---|---:|---:|---:|---:|
| **Falsa Posição** | `1.145885` | **8** | `0.000662` | `0.000130` |
| Bissecção | `1.146484` | 9 | `0.000625` | `0.000391` |

#### Função (c)
**Intervalo:** `[4.0, 5.0]`

| Método | Raiz Aproximada | Iterações | Erro &#124;f(x)&#124; | Tempo (ms) |
|:---|---:|---:|---:|---:|
| **Falsa Posição** | `4.569777` | **5** | `0.000199` | `0.000060` |
| Bissecção | `4.569794` | 15 | `0.000862` | `0.000161` |

