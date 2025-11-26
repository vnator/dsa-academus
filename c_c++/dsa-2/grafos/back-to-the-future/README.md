# Back to the Future - Problema de Fluxo de Custo Mínimo

## Descrição do Problema
Transportar amigos da cidade 1 à cidade N com menor custo, respeitando capacidades limitadas dos voos.

## Algoritmo Utilizado
**Min-Cost Max-Flow** (Fluxo de Custo Mínimo) usando **Successive Shortest Path**

## Estrutura de Arquivos

- `analise.md` - Análise detalhada do problema e estratégia
- `pseudo-codigo.txt` - Pseudocódigo completo do algoritmo  
- `back-to-the-future.cpp` - Implementação em C++
- `entrada.txt` - Casos de teste de entrada
- `saida-esperada.txt` - Saídas esperadas
- `compilar-e-testar.sh` - Script para compilar e testar

## Como Executar

### Opção 1: Script Automático
```bash
bash compilar-e-testar.sh
```

### Opção 2: Manual
```bash
# Compilar
g++ -o back-to-the-future back-to-the-future.cpp -std=c++17

# Executar com entrada
./back-to-the-future < entrada.txt
```

## Casos de Teste

### Instância 1: 
- 4 cidades, 20 amigos, 10 assentos/voo
- Resultado: 80 (10 pela rota direta + 10 pela rota alternativa)

### Instância 2:
- 4 cidades, 20 amigos, 100 assentos/voo  
- Resultado: 140 (todos pela rota direta custosa)

### Instância 3:
- 4 cidades, 20 amigos, 1 assento/voo
- Resultado: impossível (capacidade insuficiente)

## Complexidade
- **Tempo:** O(F × E × log V) onde F = fluxo total
- **Espaço:** O(V + E)

## Conceitos Aplicados
- Teoria de Grafos
- Fluxo em Redes
- Algoritmos de Caminho Mínimo (SPFA)
- Grafo Residual com arestas reversas