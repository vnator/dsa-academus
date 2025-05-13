#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_CARROS 10

typedef struct {
    int placa;
    int manobras;
} Carro;

typedef struct {
    Carro carros[MAX_CARROS];
    int topo;
} Estacionamento;

void inicializa_estacionamento(Estacionamento *e);
bool estacionamento_vazio(Estacionamento *e);
bool estacionamento_cheio(Estacionamento *e);
bool estacionar_carro(Estacionamento *e, int placa);
bool retirar_carro(Estacionamento *e, int placa, int *manobras);
void imprimir_estacionamento(Estacionamento *e);
void processar_operacoes(Estacionamento *e, char operacao, int placa);

#endif