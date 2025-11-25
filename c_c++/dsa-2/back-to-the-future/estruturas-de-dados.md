# 🏗️ Estruturas de Dados no Algoritmo Min-Cost Max-Flow

## 📊 **Estruturas Utilizadas no Código**

### 1. 📦 **STRUCT (Estrutura Personalizada)**
```cpp
struct Aresta {
    int destino, capacidade, custo, fluxo, rev;
    Aresta(int d, int cap, int c, int rev_idx) : 
           destino(d), capacidade(cap), custo(c), fluxo(0), rev(rev_idx) {}
};
```

**🎯 Tipo:** Estrutura de dados personalizada (ADT - Abstract Data Type)
**📋 Função:** Representa uma aresta do grafo com todos os seus atributos
**📝 Componentes:**
- `destino`: vértice de destino
- `capacidade`: máximo fluxo suportado
- `custo`: custo por unidade de fluxo
- `fluxo`: fluxo atual passando pela aresta
- `rev`: índice da aresta reversa (para grafo residual)

---

### 2. 🌐 **LISTA DE ADJACÊNCIA (Array of Vectors)**
```cpp
vector<Aresta> grafo[MAXN];
```

**🎯 Tipo:** Array de Vectors (Lista de Adjacência)
**📋 Função:** Representação do grafo
**📝 Estrutura:**
```
grafo[1] = [Aresta(4,10,1,0), Aresta(3,10,3,0), Aresta(2,10,2,0)]
grafo[2] = [Aresta(1,0,-2,2), Aresta(4,10,5,0)]
grafo[3] = [Aresta(1,0,-3,1), Aresta(4,10,4,0)]
grafo[4] = [Aresta(1,0,-1,0), Aresta(2,0,-5,1), Aresta(3,0,-4,1)]
```

**💡 Vantagens:**
- ✅ Acesso rápido às arestas de um vértice: O(1)
- ✅ Espaço eficiente: O(V + E)
- ✅ Fácil adição/remoção de arestas

---

### 3. 🔢 **ARRAYS ESTÁTICOS**
```cpp
int dist[MAXN], pai_no[MAXN], pai_aresta[MAXN];
bool em_fila[MAXN];
```

**🎯 Tipo:** Arrays unidimensionais
**📋 Função:** Armazenar informações temporárias do SPFA

| Array | Tipo | Função |
|-------|------|--------|
| `dist[]` | `int` | Distâncias mínimas da origem |
| `pai_no[]` | `int` | Nó pai no caminho mínimo |
| `pai_aresta[]` | `int` | Índice da aresta usada |
| `em_fila[]` | `bool` | Controle de vértices na fila |

---

### 4. 📤 **QUEUE (Fila)**
```cpp
queue<int> fila;
```

**🎯 Tipo:** Fila (FIFO - First In, First Out)
**📋 Função:** Implementar o algoritmo SPFA
**📝 Operações:**
- `fila.push(v)`: adiciona vértice no final
- `fila.front()`: acessa primeiro vértice
- `fila.pop()`: remove primeiro vértice
- `fila.empty()`: verifica se está vazia

**🔄 Fluxo no SPFA:**
```
Iteração 1: fila = [1]
Iteração 2: fila = [4, 3, 2] (após processar vértice 1)
Iteração 3: fila = [3, 2] (após processar vértice 4)
...
```

---

## 🏛️ **Classificação das Estruturas**

### 🟦 **Estruturas de Dados Fundamentais:**
1. **Array** → `dist[]`, `pai_no[]`, `pai_aresta[]`, `em_fila[]`
2. **Queue** → `queue<int> fila`

### 🟩 **Estruturas de Dados Abstratas (ADT):**
1. **Struct** → `struct Aresta`
2. **Vector** → `vector<Aresta>`

### 🟪 **Estruturas de Dados Compostas:**
1. **Lista de Adjacência** → `vector<Aresta> grafo[MAXN]`

---

## 📈 **Complexidades por Estrutura**

| Estrutura | Acesso | Inserção | Remoção | Busca | Espaço |
|-----------|--------|----------|---------|-------|--------|
| **Array** | O(1) | N/A | N/A | O(n) | O(n) |
| **Vector** | O(1) | O(1)* | O(n) | O(n) | O(n) |
| **Queue** | O(1) | O(1) | O(1) | N/A | O(n) |
| **Struct** | O(1) | O(1) | N/A | N/A | O(1) |

*amortizado

---

## 🎯 **Por que Essas Estruturas?**

### ✅ **Lista de Adjacência (Vector Array):**
- **Ideal para grafos esparsos** (poucas arestas)
- **Permite arestas múltiplas** (grafo residual)
- **Acesso eficiente** aos vizinhos

### ✅ **Queue (SPFA):**
- **FIFO garante** exploração em largura
- **Evita recálculos** desnecessários
- **Melhor que Bellman-Ford** na prática

### ✅ **Arrays para SPFA:**
- **Acesso O(1)** por índice
- **Memória contígua** → cache-friendly
- **Inicialização rápida** com `fill()` e `memset()`

### ✅ **Struct Aresta:**
- **Encapsula dados** relacionados
- **Fácil manutenção** de arestas reversas
- **Código mais legível** e organizad

---

## 🧠 **Conceito de Grafo Residual**

```cpp
// Aresta direta: capacidade real, custo original
grafo[u].push_back(Aresta(v, cap, custo, grafo[v].size()));

// Aresta reversa: capacidade 0, custo negativo
grafo[v].push_back(Aresta(u, 0, -custo, grafo[u].size() - 1));
```

**📝 Interpretação:**
- **Rede residual** = grafo original + arestas reversas
- **Permite "cancelar"** fluxo subótimo
- **Mantém dualidade** forte entre fluxo e custo

---

## 🎭 **Resumo das Responsabilidades**

| Componente | Estrutura | Responsabilidade |
|------------|-----------|------------------|
| **Grafo** | `vector<Aresta>[]` | Armazenar topology e capacidades |
| **SPFA** | `queue<int>`, `arrays` | Encontrar caminhos mínimos |
| **Fluxo** | `struct Aresta` | Controlar fluxo nas arestas |
| **Residual** | Arestas reversas | Permitir otimizações |

**🚀 Resultado:** Algoritmo eficiente que combina teoria dos grafos, programação dinâmica e estruturas de dados otimizadas!