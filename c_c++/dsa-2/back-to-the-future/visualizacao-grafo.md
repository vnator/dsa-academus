# Visualização do Grafo - Back to the Future

## Grafo de Entrada (Instância 1)

### Dados da Entrada
```
4 5        // 4 cidades, 5 rotas
1 4 1      // Rota: 1→4, custo=1
1 3 3      // Rota: 1→3, custo=3  
3 4 4      // Rota: 3→4, custo=4
1 2 2      // Rota: 1→2, custo=2
2 4 5      // Rota: 2→4, custo=5
20 10      // 20 amigos, 10 assentos por voo
```

---

## 🎯 GRAFO INICIAL (Estado Original)

```
                        ┌─────────────────┐
                        │                 │
                        │    CIDADE 2     │
                        │                 │
                        │                 │
                        └─────────────────┘
                                 │
                                 │ CUSTO = 2
                                 │ CAPACIDADE = 10
                                 ▼
┌─────────────────┐                           ┌─────────────────┐
│                 │                           │                 │
│    CIDADE 1     │ ═════════════════════════►│    CIDADE 4     │
│   (ORIGEM)      │    CUSTO = 1              │   (DESTINO)     │
│                 │  CAPACIDADE = 10          │                 │
└─────────────────┘                           └─────────────────┘
         │                                             ▲
         │                                             │
         │ CUSTO = 3                                   │ CUSTO = 4
         │ CAPACIDADE = 10                             │ CAPACIDADE = 10
         ▼                                             │
┌─────────────────┐                                    │
│                 │                                    │
│    CIDADE 3     │────────────────────────────────────┘
│                 │          CUSTO = 4
│                 │        CAPACIDADE = 10
└─────────────────┘
         ▲
         │
         │ CONEXÃO BIDIRECIONAL 
         │ (todas as rotas são bidirecionais)


CONEXÕES ADICIONAIS:
┌─────────────────┐     CUSTO = 2     ┌─────────────────┐     CUSTO = 5     ┌─────────────────┐
│    CIDADE 1     │ ◄────────────────►│    CIDADE 2     │ ◄────────────────►│    CIDADE 4     │
└─────────────────┘  CAPACIDADE = 10  └─────────────────┘  CAPACIDADE = 10  └─────────────────┘

LEGENDA:
═══► Rota principal (menor custo)
───► Rota alternativa
◄──► Rota bidirecional
```

---

## 📊 REPRESENTAÇÃO MATRICIAL DAS ROTAS

```
          CIDADE 1    CIDADE 2    CIDADE 3    CIDADE 4
        ┌───────────┬───────────┬───────────┬───────────┐
CIDADE 1│     -     │  2 (10)   │  3 (10)   │  1 (10)   │
        ├───────────┼───────────┼───────────┼───────────┤
CIDADE 2│  2 (10)   │     -     │     -     │  5 (10)   │
        ├───────────┼───────────┼───────────┼───────────┤
CIDADE 3│  3 (10)   │     -     │     -     │  4 (10)   │
        ├───────────┼───────────┼───────────┼───────────┤
CIDADE 4│  1 (10)   │  5 (10)   │  4 (10)   │     -     │
        └───────────┴───────────┴───────────┴───────────┘

Legenda: CUSTO (CAPACIDADE)
```

---

## 🛣️ CAMINHOS POSSÍVEIS (Cidade 1 → Cidade 4)

```
CAMINHO 1: DIRETO
┌─────────┐    CUSTO=1      ┌─────────┐
│CIDADE 1 │ ═══════════════►│CIDADE 4 │
└─────────┘  CAPACIDADE=10  └─────────┘
CUSTO TOTAL: 1


CAMINHO 2: VIA CIDADE 3
┌─────────┐   CUSTO=3    ┌─────────┐   CUSTO=4    ┌─────────┐
│CIDADE 1 │ ───────────► │CIDADE 3 │ ───────────► │CIDADE 4 │
└─────────┘ CAPACIDADE=10 └─────────┘ CAPACIDADE=10 └─────────┘
CUSTO TOTAL: 3 + 4 = 7


CAMINHO 3: VIA CIDADE 2  
┌─────────┐   CUSTO=2    ┌─────────┐   CUSTO=5    ┌─────────┐
│CIDADE 1 │ ───────────► │CIDADE 2 │ ───────────► │CIDADE 4 │
└─────────┘ CAPACIDADE=10 └─────────┘ CAPACIDADE=10 └─────────┘
CUSTO TOTAL: 2 + 5 = 7
```

---

## ⚡ EXECUÇÃO DO ALGORITMO (Min-Cost Max-Flow)

### ITERAÇÃO 1: Transportar 10 amigos
```
ANTES:
         [1]                           [4]
    ┌─────────┐      1 (10/10)      ┌─────────┐
    │CIDADE 1 │ ═══════════════════► │CIDADE 4 │
    └─────────┘                     └─────────┘
                   ▲ ESCOLHIDO!
                   │ (Caminho mais barato)
                   
FLUXO ENVIADO: 10 amigos
CUSTO: 10 × 1 = 10


DEPOIS:
         [1]                           [4]  
    ┌─────────┐      1 (0/10)       ┌─────────┐
    │CIDADE 1 │ ═══════════════════► │CIDADE 4 │
    └─────────┘    [SATURADA!]      └─────────┘
```

### ITERAÇÃO 2: Transportar mais 10 amigos
```
ANTES (Caminho direto bloqueado):
         [1]                           [4]
    ┌─────────┐      1 (0/10)       ┌─────────┐
    │CIDADE 1 │ ═══════════════════► │CIDADE 4 │
    └─────────┘     SATURADA        └─────────┘
         │                             ▲
         │3 (10/10)                    │4 (10/10)
         ▼              ▲ ESCOLHIDO!   │
    ┌─────────┐         │ Custo=7      │
    │CIDADE 3 │ ────────────────────────┘
    └─────────┘
    
FLUXO ENVIADO: 10 amigos
CUSTO: 10 × (3+4) = 70


DEPOIS:
         [1]                           [4]
    ┌─────────┐      1 (0/10)       ┌─────────┐
    │CIDADE 1 │ ═══════════════════► │CIDADE 4 │
    └─────────┘                     └─────────┘
         │                             ▲
         │3 (0/10)                     │4 (0/10)
         ▼         [AMBAS SATURADAS!]  │
    ┌─────────┐                       │
    │CIDADE 3 │ ──────────────────────┘
    └─────────┘
```

---

## 🎯 RESULTADO FINAL

```
╔═══════════════════════════════════════════════════════════╗
║                    RESUMO DA EXECUÇÃO                    ║
╠═══════════════════════════════════════════════════════════╣
║  ITERAÇÃO 1: 10 amigos × Caminho 1→4 (custo 1) = 10     ║
║  ITERAÇÃO 2: 10 amigos × Caminho 1→3→4 (custo 7) = 70   ║
║                                                           ║
║  TOTAL: 20 amigos transportados                          ║
║  CUSTO TOTAL: 10 + 70 = 80                              ║
╚═══════════════════════════════════════════════════════════╝
```

---

## 📈 FLUXOS FINAIS NO GRAFO

```
                        ┌─────────────────┐
                        │                 │
                        │    CIDADE 2     │
                        │    0 amigos     │
                        │   (NÃO USADA)   │
                        └─────────────────┘
                                 │
                                 │ ROTA LIVRE
                                 │ FLUXO: 0/10 amigos
                                 │ CUSTO: 2
                                 ▼
┌─────────────────┐                           ┌─────────────────┐
│                 │         ROTA SATURADA     │                 │
│    CIDADE 1     │ ═══════════════════════► │    CIDADE 4     │
│   (ORIGEM)      │   FLUXO: 10/10 amigos    │   (DESTINO)     │
│   20 amigos     │     CUSTO: 1             │  20 amigos ✓    │
└─────────────────┘                           └─────────────────┘
         │                                             ▲
         │ ROTA SATURADA                              │ ROTA SATURADA
         │ FLUXO: 10/10 amigos                        │ FLUXO: 10/10 amigos
         │ CUSTO: 3                                   │ CUSTO: 4
         ▼                                             │
┌─────────────────┐                                    │
│                 │                                    │
│    CIDADE 3     │────────────────────────────────────┘
│   10 amigos     │        ROTA SATURADA
│                 │     FLUXO: 10/10 amigos
└─────────────────┘       CUSTO: 4


ROTAS NÃO UTILIZADAS:
┌─────────────────┐     ROTA LIVRE     ┌─────────────────┐
│    CIDADE 2     │ ◄────────────────► │    CIDADE 4     │
│    0 amigos     │  FLUXO: 0/10       │                 │
│   (NÃO USADA)   │    CUSTO: 5        │                 │
└─────────────────┘                    └─────────────────┘

STATUS FINAL:
✅ CIDADE 1 → CIDADE 4 (direto): 10 amigos transportados
✅ CIDADE 1 → CIDADE 3 → CIDADE 4: 10 amigos transportados
❌ CIDADE 1 → CIDADE 2: rota não utilizada
❌ CIDADE 2 → CIDADE 4: rota não utilizada
```

---

## 🔍 ANÁLISE DAS ROTAS

| ROTA | CUSTO UNITÁRIO | CAPACIDADE | FLUXO USADO | STATUS | CUSTO TOTAL |
|------|----------------|------------|-------------|---------|-------------|
| 1→4  | 1              | 10         | 10          | ✅ USADA | 10          |
| 1→3  | 3              | 10         | 10          | ✅ USADA | 30          |
| 3→4  | 4              | 10         | 10          | ✅ USADA | 40          |
| 1→2  | 2              | 10         | 0           | ❌ LIVRE | 0           |
| 2→4  | 5              | 10         | 0           | ❌ LIVRE | 0           |

**CUSTO TOTAL:** 10 + 30 + 40 = **80**