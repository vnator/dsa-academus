#include <stdio.h>
#include "avr_binaria.h"

void print_separador() {
    printf("\n========================================\n");
}

void test_inserir_buscar() {
    printf("TESTE: Inserção e Busca\n");
    print_separador();
    
    ArvoreBinaria* arvore = criar_arvore();
    
    // Inserindo valores
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    printf("Inserindo valores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        inserir(arvore, valores[i]);
    }
    printf("\n");
    
    // Testando busca
    printf("\nTeste de busca:\n");
    for (int i = 0; i < n; i++) {
        No* resultado = busca_chave(arvore, valores[i]);
        printf("Busca %d: %s\n", valores[i], resultado ? "ENCONTRADO" : "NÃO ENCONTRADO");
    }
    
    // Testando busca de valor não existente
    No* resultado = busca_chave(arvore, 99);
    printf("Busca 99: %s\n", resultado ? "ENCONTRADO" : "NÃO ENCONTRADO");
    
    destruir_arvore(arvore);
}

void test_percursos() {
    printf("\n\nTESTE: Percursos\n");
    print_separador();
    
    ArvoreBinaria* arvore = criar_arvore();
    
    // Inserindo valores para formar uma árvore interessante
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        inserir(arvore, valores[i]);
    }
    
    printf("Árvore criada com valores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n\n");
    
    printf("Pré-ordem (raiz, esquerda, direita): ");
    pre_ordem(arvore->raiz);
    printf("\n");
    
    printf("Em ordem (esquerda, raiz, direita): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    printf("Pós-ordem (esquerda, direita, raiz): ");
    pos_ordem(arvore->raiz);
    printf("\n");
    
    destruir_arvore(arvore);
}

void test_minimo_maximo() {
    printf("\n\nTESTE: Mínimo e Máximo\n");
    print_separador();
    
    ArvoreBinaria* arvore = criar_arvore();
    
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        inserir(arvore, valores[i]);
    }
    
    No* min = minimo(arvore->raiz);
    No* max = maximo(arvore->raiz);
    
    printf("Valores inseridos: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");
    
    printf("Mínimo da árvore: %d\n", min ? min->chave : -1);
    printf("Máximo da árvore: %d\n", max ? max->chave : -1);
    
    destruir_arvore(arvore);
}

void test_sucessor_predecessor_simples() {
    printf("\n\nTESTE: Sucessor e Predecessor\n");
    print_separador();
    
    ArvoreBinaria* arvore = criar_arvore();
    
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        inserir(arvore, valores[i]);
    }
    
    printf("Testando sucessor e predecessor para alguns nós:\n");
    
    int testes[] = {30, 50, 70, 10, 80};
    int n_testes = sizeof(testes) / sizeof(testes[0]);
    
    for (int i = 0; i < n_testes; i++) {
        No* no = busca_chave(arvore, testes[i]);
        if (no) {
            No* succ = sucessor(no);
            No* pred = predecessor(no);
            
            printf("Nó %d: ", testes[i]);
            if (pred) {
                printf("Predecessor = %d, ", pred->chave);
            } else {
                printf("Predecessor = NULL, ");
            }
            if (succ) {
                printf("Sucessor = %d\n", succ->chave);
            } else {
                printf("Sucessor = NULL\n");
            }
        }
    }
    
    destruir_arvore(arvore);
}

void test_remocao() {
    printf("\n\nTESTE: Remoção\n");
    print_separador();
    
    ArvoreBinaria* arvore = criar_arvore();
    
    // Inserindo valores
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        inserir(arvore, valores[i]);
    }
    
    printf("Árvore inicial (em ordem): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    // Teste 1: Remover nó folha
    printf("\nRemoção de nó folha (10):\n");
    remover(arvore, 10);
    printf("Após remoção (em ordem): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    // Teste 2: Remover nó com um filho
    printf("\nRemoção de nó com um filho (25):\n");
    remover(arvore, 25);
    printf("Após remoção (em ordem): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    // Teste 3: Remover nó com dois filhos
    printf("\nRemoção de nó com dois filhos (30):\n");
    remover(arvore, 30);
    printf("Após remoção (em ordem): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    // Teste 4: Remover raiz
    printf("\nRemoção da raiz (50):\n");
    remover(arvore, 50);
    printf("Após remoção (em ordem): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    // Teste 5: Tentar remover nó inexistente
    printf("\nTentativa de remoção de nó inexistente (99):\n");
    remover(arvore, 99);
    printf("Após tentativa (em ordem): ");
    em_ordem(arvore->raiz);
    printf("\n");
    
    destruir_arvore(arvore);
}

void test_arvore_vazia() {
    printf("\n\nTESTE: Operações em árvore vazia\n");
    print_separador();
    
    ArvoreBinaria* arvore = criar_arvore();
    
    printf("Busca em árvore vazia (chave 10): %s\n", 
           busca_chave(arvore, 10) ? "ENCONTRADO" : "NÃO ENCONTRADO");
    
    printf("Mínimo em árvore vazia: %s\n", 
           minimo(arvore->raiz) ? "EXISTE" : "NULL");
    
    printf("Máximo em árvore vazia: %s\n", 
           maximo(arvore->raiz) ? "EXISTE" : "NULL");
    
    printf("Percurso em ordem de árvore vazia: ");
    em_ordem(arvore->raiz);
    printf("(vazio)\n");
    
    printf("Remoção em árvore vazia (chave 10): ");
    remover(arvore, 10);
    printf("OK\n");
    
    destruir_arvore(arvore);
}

int main() {
    printf("=== TESTE COMPLETO DA ÁRVORE BINÁRIA DE BUSCA ===\n");
    
    test_inserir_buscar();
    test_percursos();
    test_minimo_maximo();
    test_sucessor_predecessor_simples();
    test_remocao();
    test_arvore_vazia();
    
    printf("\n\n=== TODOS OS TESTES CONCLUÍDOS ===\n");
    
    return 0;
}