# Exercício 3 — Consumo de Energia

**Função:** `P(t) = 40 + 15e^(-0.1t) + 0.02t²`

**Intervalo:** `[0, 60]` segundos

**Valor exato:** `3989.628187173500 J` (`3990 - 150e⁻⁶`)

## Regra dos Trapézios Repetida

| n | h | Aproximação | Erro absoluto |
|---:|---:|---:|---:|
| 60 | 1.00000000 | 3989.952856552733 | 0.324669379233 |
| 600 | 0.10000000 | 3989.631434072980 | 0.003246899480 |

## Regra de Simpson 1/3 Repetida

| n | h | Aproximação | Erro absoluto |
|---:|---:|---:|---:|
| 60 | 1.00000000 | 3989.628270201413 | 0.000083027913 |
| 600 | 0.10000000 | 3989.628187181811 | 0.000000008311 |
