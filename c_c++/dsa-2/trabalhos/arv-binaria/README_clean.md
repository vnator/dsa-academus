# Árvore Binária de Busca (BST) - Implementação em C

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
├── avr_binaria.h      
├── arv_binaria.c      
├── main.c             
├── Makefile           
└── README.md          
```

## Como Compilar e Executar

### Usando o Makefile:

```bash
make

make run

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
    int chave;           
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

## Testes Implementados

O programa `main.c` inclui testes abrangentes para validar todas as funcionalidades:

### 1. **Teste de Inserção e Busca**
- Insere múltiplos valores na árvore
- Verifica se todos foram inseridos corretamente
- Testa busca de valores existentes e inexistentes

### 2. **Teste de Percursos**
- Demonstra os três tipos de percurso
- Mostra a ordem de visitação dos nós
- Valida que o percurso em ordem retorna valores ordenados

### 3. **Teste de Mínimo e Máximo**
- Encontra os valores extremos da árvore
- Valida que estão corretos

### 4. **Teste de Sucessor e Predecessor**
- Testa predecessor e sucessor para vários nós
- Valida casos especiais (primeiro e último elemento)

### 5. **Teste de Remoção**
- Remove nós folha
- Remove nós com um filho
- Remove nós com dois filhos
- Remove a raiz
- Tenta remover valores inexistentes

### 6. **Teste de Árvore Vazia**
- Valida comportamento correto quando a árvore está vazia
- Testa todas as operações em árvore vazia

## Complexidades

| Operação | Melhor Caso | Caso Médio | Pior Caso |
|----------|-------------|------------|-----------|
| Busca    | O(log n)    | O(log n)   | O(n)      |
| Inserção | O(log n)    | O(log n)   | O(n)      |
| Remoção  | O(log n)    | O(log n)   | O(n)      |
| Percurso | O(n)        | O(n)       | O(n)      |

**Nota**: O pior caso O(n) ocorre quando a árvore se torna uma lista ligada (completamente desbalanceada).

## Exemplo de Uso

```c
#include "avr_binaria.h"

int main() {
    ArvoreBinaria* arvore = criar_arvore();
    
    inserir(arvore, 50);
    inserir(arvore, 30);
    inserir(arvore, 70);
    
    No* resultado = busca_chave(arvore, 30);
    if (resultado) {
        printf("Valor 30 encontrado!\n");
    }
    
    printf("Valores em ordem: ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    destruir_arvore(arvore);
    
    return 0;
}
```

## Propriedades da BST

Uma Árvore Binária de Busca mantém as seguintes propriedades:

1. **Propriedade BST**: Para qualquer nó:
   - Todos os valores na subárvore esquerda são menores
   - Todos os valores na subárvore direita são maiores

2. **Estrutura**: Cada nó tem no máximo dois filhos

3. **Ordenação**: O percurso em ordem sempre retorna valores ordenados

4. **Unicidade**: Não permite chaves duplicadas nesta implementação

## Casos de Uso

- **Busca eficiente** em conjuntos de dados ordenados
- **Ordenação** de dados (através do percurso em ordem)
- **Dicionários** e tabelas de símbolos
- **Implementação de conjuntos** (sets)
- **Algoritmos que precisam de acesso ordenado** aos dados

**Autor**: Implementação para disciplina de Estruturas de Dados  
**Data**: Julho 2025
