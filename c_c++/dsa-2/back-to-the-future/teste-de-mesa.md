# Teste de Mesa - Back to the Future (Min-Cost Max-Flow)

## Instância 1: Análise Completa

### Dados de Entrada
```
4 5        // 4 cidades, 5 rotas
1 4 1      // Rota: 1→4, custo=1
1 3 3      // Rota: 1→3, custo=3  
3 4 4      // Rota: 3→4, custo=4
1 2 2      // Rota: 1→2, custo=2
2 4 5      // Rota: 2→4, custo=5
20 10      // 20 amigos, 10 assentos por voo
```

### Construção do Grafo Residual

#### Estado Inicial (após leitura)
```
Grafo[1]:
  → (4, cap=10, custo=1, fluxo=0, rev=1)
  → (3, cap=10, custo=3, fluxo=0, rev=1)  
  → (2, cap=10, custo=2, fluxo=0, rev=1)

Grafo[2]:
  → (1, cap=0, custo=-2, fluxo=0, rev=2)
  → (4, cap=10, custo=5, fluxo=0, rev=1)

Grafo[3]:  
  → (1, cap=0, custo=-3, fluxo=0, rev=1)
  → (4, cap=10, custo=4, fluxo=0, rev=1)

Grafo[4]:
  → (1, cap=0, custo=-1, fluxo=0, rev=0)
  → (2, cap=0, custo=-5, fluxo=0, rev=1)
  → (3, cap=0, custo=-4, fluxo=0, rev=1)
```

### Execução do Algoritmo

## ITERAÇÃO 1

### Chamada: minCostMaxFlow(1, 4, 4, 20)
```
custo_total = 0
fluxo_atual = 0
demanda = 20
```

### 1.1 SPFA (busca caminho mínimo)
```
INICIALIZAÇÃO:
dist[1] = 0,  dist[2] = INF,  dist[3] = INF,  dist[4] = INF
pai_no = [-1, -1, -1, -1]
pai_aresta = [-1, -1, -1, -1]
fila = [1]
em_fila[1] = true
```

**Processamento da fila:**

**u = 1 (removido da fila)**
```
em_fila[1] = false

Aresta 0: 1→4, cap_residual = 10-0 = 10 > 0
  dist[4] = INF > dist[1] + 1 = 0 + 1 = 1? SIM
  dist[4] = 1
  pai_no[4] = 1
  pai_aresta[4] = 0
  fila.push(4), em_fila[4] = true

Aresta 1: 1→3, cap_residual = 10-0 = 10 > 0  
  dist[3] = INF > dist[1] + 3 = 0 + 3 = 3? SIM
  dist[3] = 3
  pai_no[3] = 1
  pai_aresta[3] = 1
  fila.push(3), em_fila[3] = true

Aresta 2: 1→2, cap_residual = 10-0 = 10 > 0
  dist[2] = INF > dist[1] + 2 = 0 + 2 = 2? SIM  
  dist[2] = 2
  pai_no[2] = 1
  pai_aresta[2] = 2
  fila.push(2), em_fila[2] = true

Estado da fila: [4, 3, 2]
```

**u = 4 (removido da fila)**
```
em_fila[4] = false

Aresta 0: 4→1, cap_residual = 0-0 = 0 (não explora)
Aresta 1: 4→2, cap_residual = 0-0 = 0 (não explora)  
Aresta 2: 4→3, cap_residual = 0-0 = 0 (não explora)

Estado da fila: [3, 2]
```

**u = 3 (removido da fila)**
```
em_fila[3] = false

Aresta 0: 3→1, cap_residual = 0-0 = 0 (não explora)
Aresta 1: 3→4, cap_residual = 10-0 = 10 > 0
  dist[4] = 1 > dist[3] + 4 = 3 + 4 = 7? NÃO (1 < 7)

Estado da fila: [2]
```

**u = 2 (removido da fila)**
```
em_fila[2] = false

Aresta 0: 2→1, cap_residual = 0-0 = 0 (não explora)
Aresta 1: 2→4, cap_residual = 10-0 = 10 > 0
  dist[4] = 1 > dist[2] + 5 = 2 + 5 = 7? NÃO (1 < 7)

Estado da fila: []
```

**Resultado SPFA:**
```
dist[4] = 1 ≠ INF → caminho encontrado!
Caminho: 1→4 (via pai_no e pai_aresta)
```

### 1.2 Encontrar gargalo do caminho
```
fluxo_caminho = demanda - fluxo_atual = 20 - 0 = 20
atual = 4

atual = 4:
  anterior = pai_no[4] = 1
  idx = pai_aresta[4] = 0
  cap_residual = grafo[1][0].capacidade - grafo[1][0].fluxo = 10 - 0 = 10
  fluxo_caminho = min(20, 10) = 10
  atual = 1

atual = 1 (origem) → para

fluxo_caminho = 10
```

### 1.3 Atualizar fluxos
```
atual = 4

atual = 4:
  anterior = pai_no[4] = 1
  idx = pai_aresta[4] = 0
  
  // Aresta direta 1→4
  grafo[1][0].fluxo += 10  → fluxo = 0 + 10 = 10
  
  // Aresta reversa 4→1  
  idx_reversa = grafo[1][0].rev = 1
  grafo[4][1].fluxo -= 10  → fluxo = 0 - 10 = -10
  
  // Custo
  custo_total += 10 * 1 = 10
  atual = 1

atual = 1 (origem) → para

fluxo_atual += 10 → fluxo_atual = 10
```

**Estado após iteração 1:**
```
custo_total = 10
fluxo_atual = 10 (restam 10 amigos)
```

## ITERAÇÃO 2

### 2.1 SPFA (busca novo caminho mínimo)
```
INICIALIZAÇÃO:
dist[1] = 0,  dist[2] = INF,  dist[3] = INF,  dist[4] = INF
pai_no = [-1, -1, -1, -1]  
pai_aresta = [-1, -1, -1, -1]
fila = [1]
em_fila[1] = true
```

**Processamento da fila:**

**u = 1 (removido da fila)**
```
em_fila[1] = false

Aresta 0: 1→4, cap_residual = 10-10 = 0 (não explora - saturada!)
Aresta 1: 1→3, cap_residual = 10-0 = 10 > 0
  dist[3] = INF > dist[1] + 3 = 0 + 3 = 3? SIM
  dist[3] = 3
  pai_no[3] = 1
  pai_aresta[3] = 1
  fila.push(3), em_fila[3] = true

Aresta 2: 1→2, cap_residual = 10-0 = 10 > 0
  dist[2] = INF > dist[1] + 2 = 0 + 2 = 2? SIM
  dist[2] = 2
  pai_no[2] = 1  
  pai_aresta[2] = 2
  fila.push(2), em_fila[2] = true

Estado da fila: [3, 2]
```

**u = 3 (removido da fila)**
```
em_fila[3] = false

Aresta 0: 3→1, cap_residual = 0-0 = 0 (não explora)
Aresta 1: 3→4, cap_residual = 10-0 = 10 > 0
  dist[4] = INF > dist[3] + 4 = 3 + 4 = 7? SIM
  dist[4] = 7
  pai_no[4] = 3
  pai_aresta[4] = 1
  fila.push(4), em_fila[4] = true

Estado da fila: [2, 4]
```

**u = 2 (removido da fila)**
```
em_fila[2] = false

Aresta 0: 2→1, cap_residual = 0-0 = 0 (não explora)
Aresta 1: 2→4, cap_residual = 10-0 = 10 > 0  
  dist[4] = 7 > dist[2] + 5 = 2 + 5 = 7? NÃO (7 = 7, não melhora)

Estado da fila: [4]
```

**u = 4 (removido da fila)**
```
em_fila[4] = false

Aresta 0: 4→1, cap_residual = 0-(-10) = 10 > 0
  dist[1] = 0 > dist[4] + (-1) = 7 + (-1) = 6? NÃO (0 < 6)
Aresta 1: 4→2, cap_residual = 0-0 = 0 (não explora)
Aresta 2: 4→3, cap_residual = 0-0 = 0 (não explora)

Estado da fila: []
```

**Resultado SPFA:**
```
dist[4] = 7 ≠ INF → caminho encontrado!
Caminhos disponíveis com custo 7:
- 1→3→4 (custo 3+4=7)
- 1→2→4 (custo 2+5=7)

Caminho escolhido: 1→3→4 (via pai_no e pai_aresta)
```

### 2.2 Encontrar gargalo do caminho
```
fluxo_caminho = demanda - fluxo_atual = 20 - 10 = 10
atual = 4

atual = 4:
  anterior = pai_no[4] = 3
  idx = pai_aresta[4] = 1
  cap_residual = grafo[3][1].capacidade - grafo[3][1].fluxo = 10 - 0 = 10
  fluxo_caminho = min(10, 10) = 10
  atual = 3

atual = 3:
  anterior = pai_no[3] = 1
  idx = pai_aresta[3] = 1
  cap_residual = grafo[1][1].capacidade - grafo[1][1].fluxo = 10 - 0 = 10
  fluxo_caminho = min(10, 10) = 10
  atual = 1

atual = 1 (origem) → para

fluxo_caminho = 10
```

### 2.3 Atualizar fluxos
```
atual = 4

atual = 4:
  anterior = pai_no[4] = 3
  idx = pai_aresta[4] = 1
  
  // Aresta direta 3→4
  grafo[3][1].fluxo += 10  → fluxo = 0 + 10 = 10
  
  // Aresta reversa 4→3
  idx_reversa = grafo[3][1].rev = 1
  grafo[4][2].fluxo -= 10  → fluxo = 0 - 10 = -10
  
  // Custo
  custo_total += 10 * 4 = 40  → custo_total = 10 + 40 = 50
  atual = 3

atual = 3:
  anterior = pai_no[3] = 1
  idx = pai_aresta[3] = 1
  
  // Aresta direta 1→3
  grafo[1][1].fluxo += 10  → fluxo = 0 + 10 = 10
  
  // Aresta reversa 3→1
  idx_reversa = grafo[1][1].rev = 1  
  grafo[3][0].fluxo -= 10  → fluxo = 0 - 10 = -10
  
  // Custo
  custo_total += 10 * 3 = 30  → custo_total = 50 + 30 = 80
  atual = 1

atual = 1 (origem) → para

fluxo_atual += 10 → fluxo_atual = 20
```

**Estado final:**
```
custo_total = 80
fluxo_atual = 20 (= demanda) → TERMINA!
```

## RESULTADO FINAL

### Fluxos Finais
```
1→4: fluxo = 10/10 (saturada)
1→3: fluxo = 10/10 (saturada)
3→4: fluxo = 10/10 (saturada)
1→2: fluxo = 0/10 (não usada)
2→4: fluxo = 0/10 (não usada)
```

### Caminhos Utilizados
1. **10 amigos via 1→4:** custo = 10 × 1 = 10
2. **10 amigos via 1→3→4:** custo = 10 × (3+4) = 70

### Custo Total
**80** (10 + 70)

### Saída
```
Instancia 1
80
```

---

## Instância 2: Teste de Mesa Resumido

### Dados de Entrada
```
3 2        // 3 cidades, 2 rotas  
1 2 3      // Rota: 1→2, custo=3
2 3 4      // Rota: 2→3, custo=4
20 10      // 20 amigos, 10 assentos por voo
```

### Execução
**Iteração 1:**
- Caminho: 1→2→3 (custo = 3+4 = 7)
- Fluxo: 10 amigos
- Custo parcial: 10 × 7 = 70

**Iteração 2:**
- Caminho: 1→2→3 (mesmo caminho, capacidades permitem)
- Fluxo: 10 amigos
- Custo parcial: 10 × 7 = 70

**Resultado:** 70 + 70 = **140**

---

## Instância 3: Teste de Mesa Resumido

### Dados de Entrada  
```
2 0        // 2 cidades, 0 rotas
15 10      // 15 amigos, 10 assentos por voo
```

### Execução
**Iteração 1:**
- SPFA não encontra caminho (grafo vazio)
- Retorna -1

**Resultado:** **impossivel**

---

## Verificação dos Invariantes

### 1. Conservação de Fluxo (Instância 1)
```
Vértice 2: entrada=0, saída=0 ✓
Vértice 3: entrada=10 (de 1), saída=10 (para 4) ✓
```

### 2. Restrição de Capacidade
```
Todas as arestas: 0 ≤ fluxo ≤ 10 ✓
```

### 3. Otimalidade
```
Iteração 1: escolheu custo 1 (mínimo possível)
Iteração 2: escolheu custo 7 (mínimo após saturação)
```

### 4. Terminação
```
fluxo_atual (20) = demanda (20) → sucesso ✓
```