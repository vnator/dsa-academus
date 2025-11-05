#include <stdbool.h>

#define MAX 10

typedef struct listaDesc {
  int v[MAX];
  int n;
} ListaDesc;

ListaDesc lista_criar();
bool lista_inserir(ListaDesc *lista, int val);
bool lista_remover(ListaDesc *lista, int val);
void lista_imprimir(ListaDesc *lista);
int lista_buscar(ListaDesc *lista, int val);
