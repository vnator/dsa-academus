typedef struct matriz Matriz;

Matriz *matriz_criar(int l, int c);
void matriz_libera(Matriz *m);
float matriz_le(Matriz *m, int l, int c);
void matriz_add(Matriz *m, float v);
void matriz_atualiza(Matriz *m, int l, int c, float v);
int matriz_linhas(Matriz *m);
int matriz_colunas(Matriz *m);
void matriz_print(Matriz *m);
