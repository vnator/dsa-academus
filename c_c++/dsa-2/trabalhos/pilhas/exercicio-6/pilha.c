#include "pilha.h"
#include <stdio.h>

void inicializa_estacionamento(Estacionamento *e) {
    e->topo = -1;
}

bool estacionamento_vazio(Estacionamento *e) {
    return (e->topo == -1);
}

bool estacionamento_cheio(Estacionamento *e) {
    return (e->topo == MAX_CARROS - 1);
}

bool estacionar_carro(Estacionamento *e, int placa) {
    if (estacionamento_cheio(e)) {
        return false;
    }
    
    e->topo++;
    e->carros[e->topo].placa = placa;
    e->carros[e->topo].manobras = 0;
    
    return true;
}

bool retirar_carro(Estacionamento *e, int placa, int *manobras) {
    if (estacionamento_vazio(e)) {
        return false;
    }
    
    int posicao = -1;
    
    for (int i = 0; i <= e->topo; i++) {
        if (e->carros[i].placa == placa) {
            posicao = i;
            break;
        }
    }
    
    if (posicao == -1) {
        return false;
    }
    
    if (posicao == e->topo) {
        *manobras = e->carros[e->topo].manobras;
        e->topo--;
        return true;
    }
    
    Estacionamento temp;
    inicializa_estacionamento(&temp);
    int carros_manobrados = 0;
    
    while (e->topo > posicao) {
        temp.topo++;
        temp.carros[temp.topo] = e->carros[e->topo];
        temp.carros[temp.topo].manobras++; /* Incrementa o número de manobras */
        e->topo--;
        carros_manobrados++;
    }
    
    *manobras = e->carros[e->topo].manobras;
    e->topo--;
    
    while (!estacionamento_vazio(&temp)) {
        e->topo++;
        e->carros[e->topo] = temp.carros[temp.topo];
        temp.topo--;
    }
    
    return true;
}

void imprimir_estacionamento(Estacionamento *e) {
    printf("Estado atual do estacionamento (saída <-- entrada):\n");
    printf("[ ");
    
    for (int i = 0; i <= e->topo; i++) {
        printf("%d", e->carros[i].placa);
        if (i < e->topo) {
            printf(", ");
        }
    }
    
    printf(" ]\n");
}

void processar_operacoes(Estacionamento *e, char operacao, int placa) {
    if (operacao == 'E') {
        if (estacionar_carro(e, placa)) {
            printf("Carro %d estacionou com sucesso.\n", placa);
        } else {
            printf("Não há vaga no estacionamento para o carro %d.\n", placa);
        }
    } else if (operacao == 'S') {
        int manobras = 0;
        if (retirar_carro(e, placa, &manobras)) {
            printf("Carro %d saiu do estacionamento. Manobras: %d\n", placa, manobras);
        } else {
            printf("Carro %d não está no estacionamento.\n", placa);
        }
    }
    
    imprimir_estacionamento(e);
}