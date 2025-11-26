# 📝 Como Desenhar o Grafo - Passo a Passo

## 📊 Dados de Entrada
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

## 🏗️ PASSO 1: Desenhar as Cidades (Vértices)

**Primeiro, posicione as 4 cidades no papel:**

```
        CIDADE 2
        
        
CIDADE 1        CIDADE 4


        CIDADE 3
```

**💡 Dica:** Coloque a CIDADE 1 (origem) à esquerda e CIDADE 4 (destino) à direita.

---

## 🛣️ PASSO 2: Adicionar as Rotas (Arestas)

**Vamos adicionar uma rota de cada vez:**

### Rota 1: `1 4 1` (Cidade 1 → Cidade 4, custo 1)
```
        CIDADE 2
        
        
CIDADE 1 ────────► CIDADE 4
     (custo=1)
     
        CIDADE 3
```

### Rota 2: `1 3 3` (Cidade 1 → Cidade 3, custo 3)
```
        CIDADE 2
        
        
CIDADE 1 ────────► CIDADE 4
     │  (custo=1)
     │
     ▼ (custo=3)
        CIDADE 3
```

### Rota 3: `3 4 4` (Cidade 3 → Cidade 4, custo 4)
```
        CIDADE 2
        
        
CIDADE 1 ────────► CIDADE 4
     │  (custo=1)      ▲
     │                 │
     ▼ (custo=3)       │ (custo=4)
        CIDADE 3 ──────┘
```

### Rota 4: `1 2 2` (Cidade 1 → Cidade 2, custo 2)
```
        CIDADE 2
           ▲
           │ (custo=2)
           │
CIDADE 1 ────────► CIDADE 4
     │  (custo=1)      ▲
     │                 │
     ▼ (custo=3)       │ (custo=4)
        CIDADE 3 ──────┘
```

### Rota 5: `2 4 5` (Cidade 2 → Cidade 4, custo 5)
```
        CIDADE 2 ──────┐
           ▲            │ (custo=5)
           │ (custo=2)  │
           │            ▼
CIDADE 1 ────────► CIDADE 4
     │  (custo=1)      ▲
     │                 │
     ▼ (custo=3)       │ (custo=4)
        CIDADE 3 ──────┘
```

---

## 🎨 PASSO 3: Versão Final Limpa

```
        ┌─────────┐
        │CIDADE 2 │ ──────────┐
        └─────────┘           │
           ▲                  │ (custo=5)
           │                  │
           │ (custo=2)        ▼
┌─────────┐                ┌─────────┐
│CIDADE 1 │ ══════════════►│CIDADE 4 │
└─────────┘    (custo=1)   └─────────┘
     │                        ▲
     │                        │
     │ (custo=3)              │ (custo=4)
     ▼                        │
┌─────────┐                   │
│CIDADE 3 │ ──────────────────┘
└─────────┘
```

---

## 📋 PASSO 4: Adicionar Informações Extras

**Agora adicione as informações de capacidade:**

```
        ┌─────────┐
        │CIDADE 2 │ ──────────┐
        └─────────┘           │ custo=5
           ▲                  │ cap=10
           │ custo=2          ▼
           │ cap=10    ┌─────────┐
┌─────────┐            │CIDADE 4 │
│CIDADE 1 │ ══════════►│(DESTINO)│
│(ORIGEM) │ custo=1    └─────────┘
└─────────┘ cap=10        ▲
     │                    │ custo=4
     │ custo=3            │ cap=10
     │ cap=10             │
     ▼                    │
┌─────────┐               │
│CIDADE 3 │ ──────────────┘
└─────────┘
```

---

## 🔧 DICAS IMPORTANTES

### ✅ **Regras Para Desenhar:**
1. **Posição:** Origem (1) à esquerda, Destino (4) à direita
2. **Setas:** Sempre mostrar a direção das rotas
3. **Rótulos:** Custo e capacidade em cada aresta
4. **Bidirecionais:** Todas as rotas são bidirecionais (ida e volta)

### 📐 **Layout Sugerido:**
```
Posicionamento ideal:

    2
   ╱ ╲
  1───4
   ╲ ╱
    3
```

### 🎯 **Caminhos Principais:**
- **Direto:** 1 → 4 (custo 1) ⭐ MELHOR
- **Via 3:** 1 → 3 → 4 (custo 7)
- **Via 2:** 1 → 2 → 4 (custo 7)

---

## 🚀 RESULTADO ESPERADO

**Seu grafo final deve mostrar:**
✅ 4 cidades (vértices)
✅ 5 rotas bidirecionais (10 arestas totais)
✅ Custos claramente marcados
✅ Capacidades = 10 assentos em todas as rotas
✅ Caminho mais curto visível (1→4)

**Pronto!** 🎉 Agora você pode visualizar como o algoritmo escolherá primeiro o caminho direto (custo 1), depois o alternativo (custo 7).