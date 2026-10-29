# Exercício 3 — Consumo de Energia

**Função:** `P(t) = 40 + 15e^(-0.1t) + 0.02t²`

**Intervalo:** `[0, 60]` segundos

**Valor exato:** `3989.6281871735 J` (`3990 - 150e⁻⁶`)

## Regra dos Trapézios Repetida

| n | h | Aproximação | Erro absoluto |
|---:|---:|---:|---:|
| 60 | 1.00000000 | 3989.9528565527 | 0.3246693792 |
| 600 | 0.10000000 | 3989.6314340730 | 0.0032468995 |

## Regra de Simpson 1/3 Repetida

| n | h | Aproximação | Erro absoluto |
|---:|---:|---:|---:|
| 60 | 1.00000000 | 3989.6282702014 | 0.0000830279 |
| 600 | 0.10000000 | 3989.6281871818 | 0.0000000083 |
