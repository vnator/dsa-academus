# Árvore Binária de Busca (BST)```
arv-binaria/
├──### Usando o Makefile:

```bash
make

m### Estrutura do Nó (`No`)
```c
typed#### `ArvoreBinaria* criar_arvore()`
- **Descrição**: Cria uma nova árvore binária vazia
- **Retorno**: Ponteiro para a estrutura da árvore
- **Complexidade**: O(1)

#### `No* criar_no(int chave)`
- **Descrição**: Cria um novo nó com a chave especificada
- **Parâmetros**: `chave` - valor a ser armazenado no nó
- **Retorno**: Ponteiro para o novo nó criado
- **Complexidade**: O(1)

#### `void destruir_arvore(ArvoreBinaria* arvore)`
- **Descrição**: Libera toda a memória da árvore recursivamente
- **Parâmetros**: `arvore` - ponteiro para a árvore a ser destruída
- **Complexidade**: O(n)

### Operações Principaisint chave;           
    struct No* esquerda; 
    struct No* direita;  
    struct No* pai;      
} No;
```

### Estrutura da Árvore (`ArvoreBinaria`)
```c
typedef struct {
    No* raiz;           
} ArvoreBinaria;
```

## Métodos Implementados

### Funções Básicas de Gerenciamento```

### Compilação manual:
```bash
gcc -Wall -Wextra -g -o main main.c arv_binaria.c
./main
```

## Estrutura da Árvore
├── arv_binaria.c      
├── main.c             
├── Makefile           
└── README.md          
```

## Como Compilar e Executarntação em C

Este projeto implementa uma **Árvore Binária de Busca** completa em linguagem C, incluindo todas as operações fundamentais e funções auxiliares.

## Pré-requisitos

Antes de compilar e executar o projeto, certifique-se de ter:

- **Compilador GCC** instalado no sistema
- **Make** instalado (para usar o Makefile)
- Sistema operacional **Linux** ou **macOS** (ou WSL no Windows)

### Instalação dos pré-requisitos no Ubuntu/Debian:
```bash
sudo apt update
sudo apt install gcc make
```

### Instalação dos pré-requisitos no Fedora/CentOS:
```bash
sudo dnf install gcc make
```

### Verificar se estão instalados:
```bash
gcc --version
make --version
```

## Estrutura do Projeto

```
arv-binaria/
├── avr_binaria.h      # Header com definições e protótipos
├── arv_binaria.c      # Implementação das funções
├── main.c             # Programa principal com testes
├── Makefile           # Script de compilação
└── README.md          # Este arquivo
```

## Como Compilar e Executar

### Usando o Makefile:

```bash
# Compilar o projeto
make

# Compilar e executar os testes
make run

# Limpar arquivos compilados
make clean
```

### Compilação manual:
```bash
gcc -Wall -Wextra -g -o main main.c arv_binaria.c
./main
```

## Estrutura da Árvore

A árvore é implementada usando duas estruturas principais:

### Estrutura do Nó (`No`)
```c
typedef struct No {
    int chave;           // Valor armazenado no nó
    struct No* esquerda; // Ponteiro para subárvore esquerda
    struct No* direita;  // Ponteiro para subárvore direita
    struct No* pai;      // Ponteiro para o nó pai
} No;
```

### Estrutura da Árvore (`ArvoreBinaria`)
```c
typedef struct {
    No* raiz;           // Ponteiro para o nó raiz
} ArvoreBinaria;
```

## Métodos Implementados

### Funções Básicas de Gerenciamento

#### `ArvoreBinaria* criar_arvore()`
- **Descrição**: Cria uma nova árvore binária vazia
- **Retorno**: Ponteiro para a estrutura da árvore
- **Complexidade**: O(1)

#### `No* criar_no(int chave)`
- **Descrição**: Cria um novo nó com a chave especificada
- **Parâmetros**: `chave` - valor a ser armazenado no nó
- **Retorno**: Ponteiro para o novo nó criado
- **Complexidade**: O(1)

#### `void destruir_arvore(ArvoreBinaria* arvore)`
- **Descrição**: Libera toda a memória da árvore recursivamente
- **Parâmetros**: `arvore` - ponteiro para a árvore a ser destruída
- **Complexidade**: O(n)

---

### Operações Principais

#### `void inserir(ArvoreBinaria* arvore, int chave)`
- **Descrição**: Insere uma nova chave na árvore mantendo a propriedade BST
- **Parâmetros**: 
  - `arvore` - ponteiro para a árvore
  - `chave` - valor a ser inserido
- **Regra**: Valores menores vão para a esquerda, maiores para a direita
- **Complexidade**: O(h) onde h é a altura da árvore
- **Comportamento**: Não insere chaves duplicadas

#### `No* busca_chave(ArvoreBinaria* arvore, int chave)`
- **Descrição**: Busca uma chave específica na árvore
- **Parâmetros**: 
  - `arvore` - ponteiro para a árvore
  - `chave` - valor a ser buscado
- **Retorno**: Ponteiro para o nó encontrado ou NULL se não existir
- **Complexidade**: O(h) onde h é a altura da árvore
- **Algoritmo**: Busca binária recursiva

#### `void remover(ArvoreBinaria* arvore, int chave)`
- **Descrição**: Remove uma chave da árvore mantendo a propriedade BST
- **Parâmetros**: 
  - `arvore` - ponteiro para a árvore
  - `chave` - valor a ser removido
- **Complexidade**: O(h) onde h é a altura da árvore
- **Casos tratados**:
  1. **Nó folha**: Remove diretamente
  2. **Nó com um filho**: Substitui pelo filho
  3. **Nó com dois filhos**: Substitui pelo sucessor in-order

---

### Percursos da Árvore

#### `void pre_ordem(No* no)`
- **Descrição**: Percorre a árvore em pré-ordem
- **Ordem**: **Raiz → Esquerda → Direita**
- **Uso**: Útil para copiar ou serializar a árvore
- **Complexidade**: O(n)
- **Exemplo**: Para árvore com raiz 50, filhos 30 e 70: `50 30 70`

#### `void em_ordem(No* no)`
- **Descrição**: Percorre a árvore em ordem (in-order)
- **Ordem**: **Esquerda → Raiz → Direita**
- **Uso**: Imprime valores em ordem crescente
- **Complexidade**: O(n)
- **Exemplo**: Para uma BST: sempre imprime em ordem crescente

#### `void pos_ordem(No* no)`
- **Descrição**: Percorre a árvore em pós-ordem
- **Ordem**: **Esquerda → Direita → Raiz**
- **Uso**: Útil para liberar memória ou calcular altura
- **Complexidade**: O(n)
- **Exemplo**: Para árvore com raiz 50, filhos 30 e 70: `30 70 50`

---

### Funções de Busca Especiais

#### `No* minimo(No* no)`
- **Descrição**: Encontra o nó com menor valor numa subárvore
- **Parâmetros**: `no` - raiz da subárvore
- **Retorno**: Ponteiro para o nó com menor valor
- **Algoritmo**: Sempre vai para a esquerda até encontrar NULL
- **Complexidade**: O(h)
- **Uso**: Encontrar o menor elemento ou o sucessor

#### `No* maximo(No* no)`
- **Descrição**: Encontra o nó com maior valor numa subárvore
- **Parâmetros**: `no` - raiz da subárvore
- **Retorno**: Ponteiro para o nó com maior valor
- **Algoritmo**: Sempre vai para a direita até encontrar NULL
- **Complexidade**: O(h)
- **Uso**: Encontrar o maior elemento ou o predecessor

#### `No* sucessor(No* no)`
- **Descrição**: Encontra o sucessor de um nó (próximo maior valor)
- **Parâmetros**: `no` - nó para encontrar o sucessor
- **Retorno**: Ponteiro para o sucessor ou NULL se não existir
- **Complexidade**: O(h)
- **Algoritmo**:
  1. Se tem subárvore direita: retorna o mínimo da subárvore direita
  2. Senão: sobe até encontrar um ancestral que seja filho esquerdo

#### `No* predecessor(No* no)`
- **Descrição**: Encontra o predecessor de um nó (próximo menor valor)
- **Parâmetros**: `no` - nó para encontrar o predecessor
- **Retorno**: Ponteiro para o predecessor ou NULL se não existir
- **Complexidade**: O(h)
- **Algoritmo**:
  1. Se tem subárvore esquerda: retorna o máximo da subárvore esquerda
  2. Senão: sobe até encontrar um ancestral que seja filho direito

---
