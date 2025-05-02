typedef struct set Set;

Set *set_criar(int n);
void set_add(Set *s, int v);
void set_remove(Set *s, int v);
int set_tamanho(Set *s);
void set_atribui(Set *s_origin, Set *s_destino);
bool set_contem(Set *s, int v);
int set_min(Set *s);
int set_max(Set *s);
Set *set_uniao(Set *s1, Set *s2);
Set *set_interseccao(Set *s1, Set *s2);
Set *set_diferenca(Set *s1, Set *s2);
bool set_igual(Set *s1, Set *s2);
