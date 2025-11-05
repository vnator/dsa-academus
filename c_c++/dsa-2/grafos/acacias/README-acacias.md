# Problema das Acácias - Árvore Geradora Mínima

## 🌳 Descrição do Problema

O problema das acácias é um problema clássico de **Árvore Geradora Mínima (MST - Minimum Spanning Tree)**. 

### Cenário Típico:
- Há várias localizações que precisam ser conectadas
- Cada conexão tem um custo associado
- Objetivo: Conectar todas as localizações com o menor custo total
- Solução: Plantar acácias ao longo das conexões escolhidas

## 🎯 Algoritmo Escolhido: Kruskal

### Por que Kruskal?
1. **Simplicidade**: Mais fácil de implementar e entender
2. **Eficiência**: O(E log E) é adequado para a maioria dos casos
3. **Flexibilidade**: Funciona bem com lista de arestas
4. **Robustez**: Detecta automaticamente se o grafo é conexo

### Comparação com Prim:
| Aspecto | Kruskal | Prim |
|---------|---------|------|
| Complexidade | O(E log E) | O(E log V) com heap |
| Implementação | Mais simples | Mais complexa |
| Estrutura de dados | Union-Find | Priority Queue |
| Melhor para | Grafos esparsos | Grafos densos |

## 🔧 Componentes do Algoritmo

### 1. Estrutura Aresta
```cpp
struct Aresta {
    int origem, destino, peso;
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};
```

### 2. Union-Find (Disjoint Set)
- **Find**: Encontra representante do conjunto (com compressão)
- **Union**: Une dois conjuntos (por rank)
- **Objetivo**: Detectar ciclos eficientemente

### 3. Algoritmo de Kruskal
```
1. Ordenar todas as arestas por peso crescente
2. Para cada aresta (em ordem):
   a. Se não cria ciclo: adicionar à MST
   b. Senão: descartar
3. Parar quando MST tiver V-1 arestas
```

## 📊 Análise de Complexidade

### Complexidade de Tempo:
- **Ordenação das arestas**: O(E log E)
- **Union-Find**: O(α(V)) ≈ O(1) amortizado por operação
- **Total**: O(E log E + E·α(V)) = **O(E log E)**

### Complexidade de Espaço:
- **Armazenamento das arestas**: O(E)
- **Union-Find**: O(V)
- **MST resultante**: O(V)
- **Total**: **O(E + V)**

## 🧪 Exemplo de Funcionamento

### Entrada:
```
Vértices: 4 (0, 1, 2, 3)
Arestas:
0-1 peso 10
0-2 peso 6
0-3 peso 5
1-2 peso 15
1-3 peso 4
2-3 peso 8
```

### Processo Kruskal:
1. **Ordenar arestas**: (1-3,4), (0-3,5), (0-2,6), (2-3,8), (0-1,10), (1-2,15)
2. **Processar**:
   - Adicionar 1-3 (peso 4) ✓
   - Adicionar 0-3 (peso 5) ✓
   - Adicionar 0-2 (peso 6) ✓
   - Tentar 2-3 (peso 8) - cria ciclo ✗
   - MST completa (3 arestas para 4 vértices)

### Resultado:
- **Custo mínimo**: 4 + 5 + 6 = 15
- **Arestas da MST**: {1-3, 0-3, 0-2}

## 🎮 Casos de Uso

### 1. Problema Original das Acácias:
- Conectar fazendas plantando acácias
- Minimizar custo de plantio

### 2. Outras Aplicações:
- **Redes de comunicação**: Conectar servidores
- **Estradas**: Conectar cidades com menor custo
- **Circuitos**: Minimizar comprimento de fios
- **Cluster analysis**: Agrupar dados similares

## 🔍 Casos Especiais

### 1. Grafo Desconexo:
```cpp
if (!grafo.ehConexo()) {
    cout << "Impossivel conectar todas as acacias" << endl;
}
```

### 2. Grafo Completo:
- Todas as arestas estão presentes
- Kruskal escolhe as V-1 menores

### 3. Árvore Já Formada:
- Input já é uma árvore
- MST = própria árvore de entrada

## 🚀 Otimizações Possíveis

### 1. Union-Find Otimizado:
- ✅ **Compressão de caminho** implementada
- ✅ **Union by rank** implementada

### 2. Pré-processamento:
- Filtrar arestas muito pesadas
- Verificar conectividade antes de executar

### 3. Paralelização:
- Ordenação paralela das arestas
- Union-Find concorrente (avançado)

## 📝 Formato de Entrada/Saída

### Entrada:
```
n (casos de teste)
v e (vértices e arestas)
origem destino peso (para cada aresta)
```

### Saída:
```
Case #n:
Custo minimo para conectar as acacias: X
Arestas da arvore geradora minima:
origem -- destino (peso: X)
...
```

## ⚡ Vantagens da Implementação

1. **Robusta**: Trata grafos desconexos
2. **Eficiente**: Union-Find otimizado
3. **Clara**: Código bem estruturado e comentado
4. **Flexível**: Fácil de adaptar para variações do problema
5. **Testável**: Saída detalhada para verificação