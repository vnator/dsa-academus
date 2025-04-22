// A. Faça uma solução para decidir se um código informado pelo usuário é
// masculino ou feminino, digitando M ou m para masculino e F ou f para
// feminino
#include <stdio.h>
#include <stdbool.h>

int main (void) {
    char sexo;

    printf('Digite seu sexo: ');
    scanf('%c', &sexo);

    if (sexo == 'm' || sexo = 'M') {
        printf('masculino')
    } else {
        printf('feminino')
    }

    return 0;
}