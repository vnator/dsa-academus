# ALGORITMO: Back to the Future - Min-Cost Max-Flow (Implementação Real)

## Descrição do Problema
Transportar **D** amigos da cidade 1 até cidade N usando voos com capacidade **K** e custo **C** por pessoa, minimizando o custo total.

## Estruturas de Dados

### Estrutura Aresta
```pseudocode
ESTRUTURA Aresta:
    destino: inteiro
    capacidade: inteiro  
    custo: inteiro
    fluxo: inteiro (inicializado com 0)
    rev: inteiro (índice da aresta reversa)
    
    CONSTRUTOR(d, cap, c, rev_idx):
        destino ← d
        capacidade ← cap
        custo ← c
        fluxo ← 0
        rev ← rev_idx
```

### Variáveis Globais
```pseudocode
VARIAVEIS GLOBAIS:
    grafo[MAXN]: array de vetores de Arestas
    dist[MAXN]: inteiro (distâncias para SPFA)
    pai_no[MAXN]: inteiro (pai de cada nó no caminho)
    pai_aresta[MAXN]: inteiro (índice da aresta usada)
    em_fila[MAXN]: booleano (controle do SPFA)

CONSTANTES:
    MAXN = 105
    INF = INT_MAX
```

## Funções Auxiliares

### Função adicionarAresta
```pseudocode
FUNCAO adicionarAresta(u, v, cap, custo):
    INICIO
        // Aresta direta
        idx_reversa ← tamanho(grafo[v])
        grafo[u].adicionar(nova Aresta(v, cap, custo, idx_reversa))
        
        // Aresta reversa (capacidade 0, custo negativo)
        idx_direta ← tamanho(grafo[u]) - 1
        grafo[v].adicionar(nova Aresta(u, 0, -custo, idx_direta))
    FIM
```

### Função SPFA (Shortest Path Faster Algorithm)
```pseudocode
FUNCAO spfa(origem, destino, n):
    INICIO
        // Inicializar distâncias
        PARA i = 0 ATÉ n FAÇA
            dist[i] ← INF
            em_fila[i] ← FALSO
        FIM PARA
        
        dist[origem] ← 0
        fila ← nova_fila()
        fila.adicionar(origem)
        em_fila[origem] ← VERDADEIRO
        
        ENQUANTO fila NÃO vazia FAÇA
            u ← fila.remover_primeiro()
            em_fila[u] ← FALSO
            
            PARA i = 0 ATÉ tamanho(grafo[u]) - 1 FAÇA
                aresta ← grafo[u][i]
                v ← aresta.destino
                capacidade_residual ← aresta.capacidade - aresta.fluxo
                
                SE capacidade_residual > 0 E 
                   dist[v] > dist[u] + aresta.custo ENTÃO
                    dist[v] ← dist[u] + aresta.custo
                    pai_no[v] ← u
                    pai_aresta[v] ← i
                    
                    SE NÃO em_fila[v] ENTÃO
                        fila.adicionar(v)
                        em_fila[v] ← VERDADEIRO
                    FIM SE
                FIM SE
            FIM PARA
        FIM ENQUANTO
        
        RETORNAR (dist[destino] ≠ INF)
    FIM
```

### Função Min-Cost Max-Flow
```pseudocode
FUNCAO minCostMaxFlow(origem, destino, n, demanda):
    INICIO
        custo_total ← 0 (long long)
        fluxo_atual ← 0
        
        ENQUANTO fluxo_atual < demanda FAÇA
            SE NÃO spfa(origem, destino, n) ENTÃO
                RETORNAR -1  // Impossível
            FIM SE
            
            // Encontrar gargalo do caminho
            fluxo_caminho ← demanda - fluxo_atual
            atual ← destino
            
            ENQUANTO atual ≠ origem FAÇA
                anterior ← pai_no[atual]
                idx ← pai_aresta[atual]
                cap_residual ← grafo[anterior][idx].capacidade - grafo[anterior][idx].fluxo
                fluxo_caminho ← MIN(fluxo_caminho, cap_residual)
                atual ← anterior
            FIM ENQUANTO
            
            // Atualizar fluxos
            atual ← destino
            ENQUANTO atual ≠ origem FAÇA
                anterior ← pai_no[atual]
                idx ← pai_aresta[atual]
                
                // Atualizar aresta direta
                grafo[anterior][idx].fluxo += fluxo_caminho
                
                // Atualizar aresta reversa
                idx_reversa ← grafo[anterior][idx].rev
                grafo[atual][idx_reversa].fluxo -= fluxo_caminho
                
                // Acumular custo
                custo_total += fluxo_caminho * grafo[anterior][idx].custo
                atual ← anterior
            FIM ENQUANTO
            
            fluxo_atual += fluxo_caminho
        FIM ENQUANTO
        
        RETORNAR custo_total
    FIM
```

## Algoritmo Principal

```pseudocode
FUNCAO main():
    INICIO
        instancia ← 1
        
        ENQUANTO LER(n, m) E (n ≠ 0 OU m ≠ 0) FAÇA
            // Limpar grafo
            PARA i = 1 ATÉ n FAÇA
                grafo[i].limpar()
            FIM PARA
            
            // Ler rotas e adicionar com capacidade temporária
            PARA i = 1 ATÉ m FAÇA
                LER(a, b, c)
                adicionarAresta(a, b, 1, c)  // Capacidade temporária = 1
                adicionarAresta(b, a, 1, c)  // Bidirecional
            FIM PARA
            
            LER(d, k)  // d = amigos, k = assentos por voo
            
            // Atualizar capacidades reais
            PARA i = 1 ATÉ n FAÇA
                PARA CADA aresta EM grafo[i] FAÇA
                    SE aresta.capacidade = 1 ENTÃO
                        aresta.capacidade ← k
                    FIM SE
                FIM PARA
            FIM PARA
            
            ESCREVER("Instancia ", instancia)
            
            resultado ← minCostMaxFlow(1, n, n, d)
            
            SE resultado = -1 ENTÃO
                ESCREVER("impossivel")
            SENÃO
                ESCREVER(resultado)
            FIM SE
            
            ESCREVER(nova_linha)
            instancia ← instancia + 1
        FIM ENQUANTO
        
        RETORNAR 0
    FIM
```

## Características da Implementação

### 1. Grafo Residual
- **Arestas diretas:** capacidade real, custo positivo
- **Arestas reversas:** capacidade 0 inicial, custo negativo
- **Função:** permite "cancelar" fluxo subótimo

### 2. SPFA (Shortest Path Faster Algorithm)
- Otimização do Bellman-Ford
- Lida com custos negativos das arestas reversas
- **Complexidade:** média O(E), pior caso O(VE)

### 3. Sucessivos Caminhos Mínimos
- Encontra caminho mais barato no grafo residual
- Envia máximo fluxo possível
- Repete até satisfazer demanda total

### 4. Tratamento de Capacidades
- Inicialização com capacidade temporária (1)
- Atualização após ler k (assentos reais)
- Evita problemas de referência circular

## Análise de Complexidade

### Tempo
**O(F × E × V)** onde:
- F = fluxo total (demanda)
- E = número de arestas (2 × m)  
- V = número de vértices (n)

### Espaço
**O(V + E)** para:
- Listas de adjacência
- Arrays de distância e pai
- Fila do SPFA

## Invariantes do Algoritmo

### 1. Conservação de Fluxo
∀v ≠ origem, destino: Σ(fluxo_entrada) = Σ(fluxo_saída)

### 2. Capacidade
∀aresta: 0 ≤ fluxo ≤ capacidade

### 3. Otimalidade
Caminho encontrado é sempre o mais barato disponível

### 4. Complementaridade
Fluxo(u→v) + Fluxo(v→u) = 0 (arestas reversas)

## Exemplo de Execução (Instância 1)

### Entrada
```
4 5
1 4 1    // Rota direta: cidade 1 → cidade 4, custo 1
1 3 3    // Rota: cidade 1 → cidade 3, custo 3
3 4 4    // Rota: cidade 3 → cidade 4, custo 4  
1 2 2    // Rota: cidade 1 → cidade 2, custo 2
2 4 5    // Rota: cidade 2 → cidade 4, custo 5
20 10    // 20 amigos, 10 assentos por voo
```

### Execução
**1ª Iteração:**
- SPFA encontra caminho mais barato: `1 → 4` (custo 1)
- Fluxo enviado: `min(10 assentos, 20 amigos) = 10 amigos`
- Custo: `10 × 1 = 10`
- Amigos restantes: `10`

**2ª Iteração:**
- Rota direta 1→4 saturada (capacidade residual = 0)
- SPFA encontra: `1 → 2 → 4` (custo 2+5 = 7)
- Fluxo enviado: `min(10 assentos, 10 amigos) = 10 amigos`
- Custo: `10 × 7 = 70`
- Amigos restantes: `0`

### Resultado Final
**Custo total** = 10 + 70 = **80**

### Saída
```
Instancia 1
80
```