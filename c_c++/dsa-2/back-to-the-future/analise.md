/*
ANÁLISE DO PROBLEMA: BACK TO THE FUTURE
======================================

ALGORITMO: Min-Cost Max-Flow (Fluxo de Custo Mínimo)

REPRESENTAÇÃO DO GRAFO:
- Vértices: Cidades (1 a N)
- Arestas: Rotas bidirecionais
- Capacidades: K assentos por rota
- Custos: C reais por pessoa por rota
- Objetivo: Transportar D amigos de 1 para N com menor custo

GRAFO DE ENTRADA (Instância 1):
4 cidades, 5 rotas:
1-4 (custo 1, cap 10)
1-3 (custo 3, cap 10)  
3-4 (custo 4, cap 10)
1-2 (custo 2, cap 10)
2-4 (custo 5, cap 10)

ASCII ART DO GRAFO:
       [10, 3]         [10, 4]
   (1) ---------> (3) ---------> (4)
    | \                           ^
    |  \ [10, 1]                  |
    |   \-------------------------|
    |                             |
    |  [10, 2]         [10, 5]    |
    ------------> (2) ------------|

ESTRATÉGIA:
1. Encontrar caminho mais barato de 1 a N
2. Enviar máximo fluxo possível (min(capacidade, amigos_restantes))
3. Repetir até transportar todos os D amigos
4. Usar grafo residual com arestas reversas de custo negativo

COMPLEXIDADE:
- Tempo: O(F * E * log V) onde F = fluxo total
- Espaço: O(V + E)
*/