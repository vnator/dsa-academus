#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main() {
    char texto[100];
    char exemplos[5][20] = {"luz azul", "reviver", "rir", "rodador", "ovo"};
    
    printf("=== Exercício 5: Verificação de palíndromos ===\n\n");
    
    printf("Testando exemplos conhecidos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Texto: \"%s\" - ", exemplos[i]);
        if (eh_palindromo(exemplos[i])) {
            printf("É um palíndromo!\n");
        } else {
            printf("Não é um palíndromo.\n");
        }
    }
    
    printf("\nTeste com outros textos:\n");
    
    strcpy(texto, "esta frase não é um palíndromo");
    printf("Texto: \"%s\" - ", texto);
    if (eh_palindromo(texto)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }
    
    strcpy(texto, "Socorram-me, subi no ônibus em Marrocos!");
    printf("Texto: \"%s\" - ", texto);
    if (eh_palindromo(texto)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }
    
    strcpy(texto, "A man, a plan, a canal: Panama!");
    printf("Texto: \"%s\" - ", texto);
    if (eh_palindromo(texto)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }
    
    printf("\nDigite um texto para verificar se é palíndromo: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';
    printf("Texto digitado: \"%s\" - ", texto);
    if (eh_palindromo(texto)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }
    
    return 0;
}