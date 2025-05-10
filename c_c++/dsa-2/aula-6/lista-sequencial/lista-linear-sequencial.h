#include <stdbool.h>
#define MAX 30

typedef int TipoChave;

typedef struct registro {
  TipoChave chave;
} Registro;

typedef struct lista {
  Registro v[MAX];
  int n;
} Lista;

void lista_inicializar(Lista *lista);

int lista_tamanho(Lista *lista);

void lista_imprimir(Lista *lista);

int lista_buscar(Lista *lista, TipoChave ch);

bool lista_inserir(Lista *lista, Registro item, int i);

bool lista_inserir_sem_repeticao(Lista *lista, Registro item);

bool lista_excluir(Lista *lista, TipoChave ch);

void lista_reinicializar(Lista *lista);
