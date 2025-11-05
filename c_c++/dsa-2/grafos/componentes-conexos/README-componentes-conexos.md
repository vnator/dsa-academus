# Algoritmo para Encontrar Componentes Conexos

Este programa resolve o problema de identificar componentes conexos em grafos não direcionados.

## Descrição do Algoritmo

O algoritmo utiliza **Busca em Profundidade (DFS)** para encontrar todos os componentes conexos de um grafo:

1. **Representação do Grafo**: Utiliza lista de adjacência para representar o grafo
2. **DFS**: Para cada vértice não visitado, executa uma DFS que encontra todos os vértices conectados
3. **Componentes**: Cada execução de DFS encontra um componente conexo completo
4. **Ordenação**: Os vértices dentro de cada componente são ordenados alfabeticamente

## Complexidade

- **Tempo**: O(V + E), onde V é o número de vértices e E é o número de arestas
- **Espaço**: O(V + E) para armazenar a lista de adjacência

## Como Funciona

### Estrutura Principal

```cpp
class GrafoComponentesConexos {
private:
    vector<vector<int>> adj;     // Lista de adjacência
    vector<bool> visitado;       // Array de vértices visitados
    int numVertices;
    
    void dfs(int vertice, vector<int>& componente);
public:
    void adicionarAresta(int u, int v);
    vector<vector<int>> encontrarComponentesConexos();
};
```

### Algoritmo DFS

```cpp
void dfs(int vertice, vector<int>& componente) {
    visitado[vertice] = true;
    componente.push_back(vertice);
    
    for (int vizinho : adj[vertice]) {
        if (!visitado[vizinho]) {
            dfs(vizinho, componente);
        }
    }
}
```

### Processo Principal

1. Lê o número de casos de teste
2. Para cada caso:
   - Lê número de vértices e arestas
   - Constrói o grafo adicionando as arestas
   - Executa o algoritmo de componentes conexos
   - Ordena e imprime os resultados

## Entrada e Saída

### Formato de Entrada
```
N (número de casos de teste)
V E (vértices e arestas do caso 1)
u1 v1 (primeira aresta)
u2 v2 (segunda aresta)
...
V E (vértices e arestas do caso 2)
...
```

### Formato de Saída
```
Case #n:
vértices_componente_1,
vértices_componente_2,
...
X connected components

```

## Exemplo

### Entrada
```
3
3 1
a c
10 10
a b
a c
a g
b c
c g
e d
d f
h i
i j
j h
6 4
a b
b c
c a
e f
```

### Saída
```
Case #1:
a,c,
b,
2 connected components

Case #2:
a,b,c,g,
d,e,f,
h,i,j,
3 connected components

Case #3:
a,b,c,
d,
e,f,
3 connected components

```

## Como Compilar e Executar

### Usando GCC/G++
```bash
g++ -o componentes-conexos componentes-conexos.cpp
./componentes-conexos < entrada.txt
```

### Usando MSVC (Visual Studio)
```cmd
cl componentes-conexos.cpp
componentes-conexos.exe < entrada.txt
```

### Usando MinGW no Windows
```cmd
g++ -o componentes-conexos.exe componentes-conexos.cpp
componentes-conexos.exe < entrada.txt
```

## Características do Algoritmo

1. **Eficiência**: O algoritmo DFS visita cada vértice e cada aresta exatamente uma vez
2. **Correto**: Garante que encontra todos os componentes conexos
3. **Ordenação**: Os resultados são apresentados em ordem alfabética
4. **Flexibilidade**: Funciona para grafos com 1 a 26 vértices (a-z)

## Observações Importantes

- Os vértices são sempre representados por letras minúsculas (a-z)
- O grafo é não direcionado (se há aresta de a para b, há de b para a)
- Cada caso de teste tem vértices começando sempre em 'a'
- A saída deve incluir vírgula após cada vértice e linha em branco após cada caso