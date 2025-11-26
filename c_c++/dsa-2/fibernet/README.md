# FiberNet - Conectividade em Grafos Direcionados

## 📋 Descrição do Problema

O problema "FiberNet" envolve determinar quais empresas podem fornecer conectividade entre pares de nós em uma rede. Cada empresa possui um conjunto específico de cabos (arestas) e queremos saber se existe um caminho de A para B usando apenas os cabos de uma determinada empresa.

## 🎯 Abordagem: Floyd-Warshall para Fechamento Transitivo

### Conceito
- **Fechamento Transitivo**: Determinar se existe caminho entre todos os pares de vértices
- **Floyd-Warshall Adaptado**: Em vez de calcular distâncias mínimas, calculamos conectividade (True/False)
- **Múltiplos Grafos**: Uma matriz de conectividade para cada empresa (a-z)

### Complexidade
- **Tempo**: O(26 × N³) onde N ≤ 200
- **Espaço**: O(26 × N²) para as matrizes de conectividade

## 🧮 Algoritmo

### Estruturas de Dados
```cpp
bool conectado[26][201][201];  // [empresa][origem][destino]
```

### Passos Principais
1. **Inicialização**: Criar matriz de adjacência para cada empresa
2. **Leitura**: Marcar conexões diretas para cada empresa
3. **Floyd-Warshall**: Calcular fechamento transitivo para cada empresa
4. **Consultas**: Verificar conectividade e retornar empresas válidas

### Fórmula de Recorrência
```
conectado[emp][i][j] = conectado[emp][i][j] || 
                      (conectado[emp][i][k] && conectado[emp][k][j])
```

## 📊 Exemplo de Execução

### Entrada
```
3
1 2 abc
2 3 ad  
1 3 b
3 1 de
0 0
1 3
2 1
3 2
0 0
```

### Matrizes Iniciais (após leitura)

**Empresa 'a'**: 1→2, 2→3
```
  1 2 3
1 0 1 0
2 0 0 1  
3 0 0 0
```

**Empresa 'b'**: 1→2, 1→3
```
  1 2 3
1 0 1 1
2 0 0 0
3 0 0 0
```

**Empresa 'd'**: 2→3, 3→1
```
  1 2 3
1 0 0 0
2 0 0 1
3 1 0 0
```

### Após Floyd-Warshall

**Empresa 'a'**: Agora 1→3 (via 1→2→3)
```
  1 2 3
1 0 1 1  ← novo caminho
2 0 0 1  
3 0 0 0
```

**Empresa 'd'**: Agora 2→1 (via 2→3→1)
```
  1 2 3
1 0 0 0
2 1 0 1  ← novo caminho
3 1 0 0
```

### Consultas e Resultados
- **1→3**: empresas 'a' e 'b' → saída: `ab`
- **2→1**: apenas empresa 'd' → saída: `d` 
- **3→2**: nenhuma empresa → saída: `-`

## 🔍 Características do Algoritmo

### Vantagens
- ✅ Resolve todas as consultas em O(1) após pré-processamento
- ✅ Funciona para grafos com múltiplas empresas
- ✅ Implementação simples e eficiente
- ✅ Garante correção através da programação dinâmica

### Invariantes
1. **Conectividade Transitiva**: Se A→B e B→C, então A→C
2. **Separação por Empresa**: Caminhos de empresas diferentes são independentes
3. **Preservação de Conectividade**: Conexões diretas são mantidas

### Casos Especiais
- **Sem conexão**: retorna "-"
- **Múltiplas empresas**: ordena alfabeticamente
- **Ciclos**: algoritmo funciona corretamente
- **Autoconexões**: não permitidas pelo problema

## 📈 Análise de Performance
- **Casos pequenos** (N ≤ 50): < 1ms
- **Casos médios** (N ≤ 100): < 10ms  
- **Casos grandes** (N = 200): < 100ms
- **Bottleneck**: Triplo loop aninhado do Floyd-Warshall