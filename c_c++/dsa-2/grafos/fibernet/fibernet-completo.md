# FiberNet - Algoritmo de Fechamento Transitivo com Floyd-Warshall

## 📋 Descrição da Resolução

O problema "FiberNet" consiste em determinar quais empresas podem fornecer conectividade entre pares de nós em uma rede direcionada. Cada empresa possui um conjunto específico de cabos (arestas) e precisamos verificar se existe um caminho de A para B usando apenas os cabos de uma determinada empresa.

### 🎯 Estratégia de Solução
- **Modelagem**: Tratar como 26 grafos direcionados independentes (um para cada letra a-z)
- **Algoritmo**: Floyd-Warshall adaptado para Fechamento Transitivo
- **Pré-processamento**: Calcular todas as conectividades possíveis para cada empresa
- **Consulta**: Verificação em O(1) após pré-processamento

---

## 🧮 Pseudocódigo

```
ALGORITMO FiberNet_Solver
ENTRADA: n (número de nós), conexões, consultas
SAÍDA: Para cada consulta, empresas que conectam origem ao destino

INÍCIO
    // Inicialização das estruturas
    PARA cada empresa emp de 0 a 25 FAÇA
        PARA i de 1 a n FAÇA
            PARA j de 1 a n FAÇA
                conectado[emp][i][j] ← FALSO
            FIM PARA
        FIM PARA
    FIM PARA
    
    // Leitura das conexões diretas
    ENQUANTO LER(a, b) E (a ≠ 0 OU b ≠ 0) FAÇA
        LER(empresas)
        PARA cada caractere c EM empresas FAÇA
            emp ← c - 'a'  // conversão para índice
            conectado[emp][a][b] ← VERDADEIRO
        FIM PARA
    FIM ENQUANTO
    
    // Floyd-Warshall para Fechamento Transitivo
    PARA cada empresa emp de 0 a 25 FAÇA
        PARA k de 1 a n FAÇA  // vértice intermediário
            PARA i de 1 a n FAÇA  // origem
                SE conectado[emp][i][k] = VERDADEIRO ENTÃO
                    PARA j de 1 a n FAÇA  // destino
                        // Regra: se i→k e k→j, então i→j
                        conectado[emp][i][j] ← conectado[emp][i][j] OU 
                                              (conectado[emp][i][k] E conectado[emp][k][j])
                    FIM PARA
                FIM SE
            FIM PARA
        FIM PARA
    FIM PARA
    
    // Processamento das consultas
    ENQUANTO LER(origem, destino) E (origem ≠ 0 OU destino ≠ 0) FAÇA
        resultado ← ""
        PARA each empresa emp de 0 a 25 FAÇA
            SE conectado[emp][origem][destino] = VERDADEIRO ENTÃO
                resultado ← resultado + (char)('a' + emp)
            FIM SE
        FIM PARA
        
        SE resultado = vazio ENTÃO
            IMPRIMIR("-")
        SENÃO
            IMPRIMIR(resultado)
        FIM SE
    FIM ENQUANTO
    
    IMPRIMIR(linha_em_branco)
FIM
```

---

## 📊 Custo Algorítmico

### Complexidade Temporal
- **Inicialização**: O(26 × n²)
- **Leitura de conexões**: O(m × k) onde m = número de conexões, k = média de empresas por conexão
- **Floyd-Warshall**: O(26 × n³)
- **Consultas**: O(q × 26) onde q = número de consultas

**Complexidade Total**: **O(26 × n³)** = **O(n³)** (dominante)

### Complexidade Espacial
- **Matrizes de conectividade**: O(26 × n²)
- **Variáveis auxiliares**: O(1)

**Complexidade Total**: **O(n²)** para n ≤ 200

### Análise Prática
Para n = 200 (limite máximo):
- Operações: 26 × 200³ = 208.000.000
- Tempo estimado: < 1 segundo
- Memória: 26 × 200² = 1.040.000 posições booleanas ≈ 1MB

---

## 🛠️ Técnicas Empregadas

### 1. **Fechamento Transitivo**
- **Conceito**: Determinar se existe caminho entre todos os pares de vértices
- **Aplicação**: Verificar conectividade indireta através de vértices intermediários

### 2. **Algoritmo de Floyd-Warshall Adaptado**
- **Original**: Calcula caminhos mínimos entre todos os pares
- **Adaptação**: Calcula conectividade booleana (True/False)
- **Fórmula**: `conectado[i][j] = conectado[i][j] || (conectado[i][k] && conectado[k][j])`

### 3. **Programação Dinâmica**
- **Estado**: `conectado[emp][i][j][k]` = existe caminho de i para j usando vértices {1...k}
- **Transição**: Incluir ou não o vértice k como intermediário
- **Otimização**: Reutilizar matriz anterior (economia de espaço)

### 4. **Múltiplos Grafos Independentes**
- **Estratégia**: Tratar cada empresa como um grafo separado
- **Benefício**: Paralelização natural do processamento
- **Resultado**: 26 matrizes de conectividade independentes

---

## 🌐 Grafo de Entrada (Exemplo 1)

### Dados de Entrada
```
3
1 2 abc
2 3 ad
1 3 b
3 1 de
```

### Representação Visual do Grafo

```
        ┌─────────┐
        │ NODO 2  │
        └─────────┘
           ▲   │
      (abc)│   │(ad)
           │   ▼
┌─────────┐    ┌─────────┐
│ NODO 1  │    │ NODO 3  │
│(ORIGEM) │    └─────────┘
└─────────┘           │
    │   ▲             │(de)
 (b)│   │(de)         │
    ▼   │             ▼
┌─────────┐           ┌─────────┐
│ NODO 3  │◄──────────┤ NODO 1  │
└─────────┘    (b)    │(ORIGEM) │
                      └─────────┘

CONEXÕES POR EMPRESA:
• Empresa 'a': 1→2, 2→3
• Empresa 'b': 1→2, 1→3  
• Empresa 'c': 1→2
• Empresa 'd': 2→3, 3→1
• Empresa 'e': 3→1
```

### Grafo Simplificado (Layout Limpo)
```
     (abc)     (ad)
  1 ────────► 2 ────────► 3
  │           ▲           │
  │(b)        │           │(de)
  │           │           │
  └─────────► 3 ◄─────────┘
      (b)        (de)
```

---

## 🗂️ Estrutura de Dados Gerada

### Matriz de Conectividade Tridimensional
```cpp
bool conectado[26][201][201];
// conectado[empresa][origem][destino]
```

### Estado Inicial (Após Leitura)

**Empresa 'a' (índice 0):**
```
    1  2  3
1 [ 0  1  0 ]  // 1→2
2 [ 0  0  1 ]  // 2→3  
3 [ 0  0  0 ]
```

**Empresa 'b' (índice 1):**
```
    1  2  3
1 [ 0  1  1 ]  // 1→2, 1→3
2 [ 0  0  0 ]
3 [ 0  0  0 ]
```

**Empresa 'c' (índice 2):**
```
    1  2  3
1 [ 0  1  0 ]  // 1→2
2 [ 0  0  0 ]
3 [ 0  0  0 ]
```

**Empresa 'd' (índice 3):**
```
    1  2  3
1 [ 0  0  0 ]
2 [ 0  0  1 ]  // 2→3
3 [ 1  0  0 ]  // 3→1
```

### Estado Final (Após Floyd-Warshall)

**Empresa 'a':** Adicionou 1→3 (via 1→2→3)
```
    1  2  3
1 [ 0  1  1 ]  ← novo: 1→3
2 [ 0  0  1 ]
3 [ 0  0  0 ]
```

**Empresa 'd':** Adicionou 2→1 (via 2→3→1)
```
    1  2  3
1 [ 0  0  0 ]
2 [ 1  0  1 ]  ← novo: 2→1
3 [ 1  0  0 ]
```

---

## 🧪 Teste de Mesa Passo a Passo

### Entrada do Teste
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

### PASSO 1: Inicialização
```
Criar 26 matrizes 3×3 inicializadas com FALSE
conectado[0..25][1..3][1..3] = FALSE
```

### PASSO 2: Leitura das Conexões
```
Conexão: 1 2 abc
  conectado[0][1][2] = TRUE  // empresa 'a'
  conectado[1][1][2] = TRUE  // empresa 'b'  
  conectado[2][1][2] = TRUE  // empresa 'c'

Conexão: 2 3 ad
  conectado[0][2][3] = TRUE  // empresa 'a'
  conectado[3][2][3] = TRUE  // empresa 'd'

Conexão: 1 3 b
  conectado[1][1][3] = TRUE  // empresa 'b'

Conexão: 3 1 de
  conectado[3][3][1] = TRUE  // empresa 'd'
  conectado[4][3][1] = TRUE  // empresa 'e'
```

### PASSO 3: Floyd-Warshall (Empresa 'a')
```
k=1: Sem mudanças (linha 1 só tem saída para 2)
k=2: 
  i=1, j=3: conectado[0][1][3] = FALSE || (TRUE && TRUE) = TRUE
  Resultado: 1→3 via 1→2→3 é adicionado
k=3: Sem mudanças (linha 3 toda FALSE)

Matriz final empresa 'a':
    1  2  3
1 [ 0  1  1 ]  ← 1→3 adicionado
2 [ 0  0  1 ]
3 [ 0  0  0 ]
```

### PASSO 4: Floyd-Warshall (Empresa 'b')
```
Matriz já tem 1→2 e 1→3 diretos
Sem novos caminhos formados (nós 2 e 3 não têm saídas em 'b')

Matriz final empresa 'b':
    1  2  3
1 [ 0  1  1 ]
2 [ 0  0  0 ]
3 [ 0  0  0 ]
```

### PASSO 5: Floyd-Warshall (Empresa 'd')
```
k=1: Sem mudanças
k=2: Sem mudanças
k=3:
  i=2, j=1: conectado[3][2][1] = FALSE || (TRUE && TRUE) = TRUE
  Resultado: 2→1 via 2→3→1 é adicionado

Matriz final empresa 'd':
    1  2  3
1 [ 0  0  0 ]
2 [ 1  0  1 ]  ← 2→1 adicionado
3 [ 1  0  0 ]
```

### PASSO 6: Processamento das Consultas

#### Consulta 1→3:
```
Verificar empresas 0 a 25:
  empresa 0 ('a'): conectado[0][1][3] = TRUE ✓
  empresa 1 ('b'): conectado[1][1][3] = TRUE ✓
  empresa 2 ('c'): conectado[2][1][3] = FALSE
  empresa 3 ('d'): conectado[3][1][3] = FALSE
  ...
Resultado: "ab"
```

#### Consulta 2→1:
```
Verificar empresas 0 a 25:
  empresa 0 ('a'): conectado[0][2][1] = FALSE
  empresa 1 ('b'): conectado[1][2][1] = FALSE
  empresa 2 ('c'): conectado[2][2][1] = FALSE  
  empresa 3 ('d'): conectado[3][2][1] = TRUE ✓
  ...
Resultado: "d"
```

#### Consulta 3→2:
```
Verificar empresas 0 a 25:
  Todas retornam FALSE
Resultado: "-"
```

### PASSO 7: Saída Final
```
ab
d
-

```

### Verificação da Correção
✅ **Consulta 1→3**: 
- Empresa 'a': 1→2→3 (custo 2)
- Empresa 'b': 1→3 (direto)

✅ **Consulta 2→1**: 
- Empresa 'd': 2→3→1 (custo 2)

✅ **Consulta 3→2**: 
- Nenhum caminho possível com as conexões dadas

**Resultado**: Todas as consultas estão corretas! ✅