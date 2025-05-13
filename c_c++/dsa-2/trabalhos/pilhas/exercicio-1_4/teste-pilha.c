#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha p1, p2;
    
    // Inicialização das pilhas
    inicializa_pilha(&p1);
    inicializa_pilha(&p2);
    
    // Teste do Exercício 1: Transfere elementos
    printf("=== Exercício 1: Transfere elementos ===\n");
    empilha(&p1, 10);
    empilha(&p1, 20);
    empilha(&p1, 30);
    
    printf("Pilha P1 antes: ");
    imprime_pilha(&p1);
    printf("Pilha P2 antes: ");
    imprime_pilha(&p2);
    
    transfere_pilha(&p1, &p2);
    
    printf("Pilha P1 depois: ");
    imprime_pilha(&p1);
    printf("Pilha P2 depois: ");
    imprime_pilha(&p2);
    printf("\n");
    
    // Teste do Exercício 2: Testa se tem mais elementos
    printf("=== Exercício 2: Testa se tem mais elementos ===\n");
    inicializa_pilha(&p1);
    empilha(&p1, 10);
    empilha(&p1, 20);
    
    printf("Pilha P1: ");
    imprime_pilha(&p1);
    printf("Pilha P2: ");
    imprime_pilha(&p2);
    
    printf("P1 tem mais elementos que P2? %s\n", tem_mais_elementos(&p1, &p2) ? "Sim" : "Não");
    
    empilha(&p2, 100);
    empilha(&p2, 200);
    empilha(&p2, 300);
    empilha(&p2, 400);
    
    printf("Pilha P1 após: ");
    imprime_pilha(&p1);
    printf("Pilha P2 após: ");
    imprime_pilha(&p2);
    
    printf("P1 tem mais elementos que P2? %s\n\n", tem_mais_elementos(&p1, &p2) ? "Sim" : "Não");
    
    // Teste do Exercício 3: Inverte pilha
    printf("=== Exercício 3: Inverte pilha ===\n");
    inicializa_pilha(&p1);
    empilha(&p1, 10);
    empilha(&p1, 20);
    empilha(&p1, 30);
    empilha(&p1, 40);
    
    printf("Pilha antes da inversão: ");
    imprime_pilha(&p1);
    
    inverte_pilha(&p1);
    
    printf("Pilha depois da inversão: ");
    imprime_pilha(&p1);
    printf("\n");
    
    // Teste do Exercício 4: Pilhas iguais
    printf("=== Exercício 4: Testa pilhas iguais ===\n");
    inicializa_pilha(&p1);
    inicializa_pilha(&p2);
    
    empilha(&p1, 10);
    empilha(&p1, 20);
    empilha(&p1, 30);
    
    empilha(&p2, 10);
    empilha(&p2, 20);
    empilha(&p2, 30);
    
    printf("Pilha P1: ");
    imprime_pilha(&p1);
    printf("Pilha P2: ");
    imprime_pilha(&p2);
    
    printf("P1 é igual a P2? %s\n", pilhas_iguais(&p1, &p2) ? "Sim" : "Não");
    
    inicializa_pilha(&p2);
    empilha(&p2, 10);
    empilha(&p2, 20);
    empilha(&p2, 40);
    
    printf("Pilha P1: ");
    imprime_pilha(&p1);
    printf("Pilha P2 modificada: ");
    imprime_pilha(&p2);
    
    printf("P1 é igual a P2? %s\n", pilhas_iguais(&p1, &p2) ? "Sim" : "Não");
    
    return 0;
}