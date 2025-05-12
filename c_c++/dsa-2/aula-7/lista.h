#include <stdbool.h>

#define MAX 50
#define INV -1

typedef struct no {
  int v;
  int prox;
} No;

typedef struct listaLkd {
  No no[MAX];
  int inicio;
  int livre;
} ListaLkd;

ListaLkd listaLkd_criar();
int listaLkd_tamanho(ListaLkd *l);
int listaLkd_buscar(ListaLkd *l, int v);
bool listaLkd_inserir_asc(ListaLkd *l, int v);
bool listaLkd_remover(ListaLkd *l, int v);
void listaLkd_imprimir(ListaLkd *l);
void listaLkd_reinicializar(ListaLkd *l);
