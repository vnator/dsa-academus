// C. Faça uma solução tal que o usuário informe uma letra em seguida exiba
// uma mensagem que diga se a letra é vogal ou consoante

#include <ctype.h>

int main() {
    char letter = '', l;

    printf("Digite uma letra: ");
    scanf("%c", &letter);

    while (!isalpha(letter)) {
        printf("Digite uma letra, entre A e Z: ");
        scanf("%c", &letter);
    }

    l = tolower(letter);

    l == 'a'
    || l == 'e'
    || l == 'i'
    || l == 'o'
    || l == 'u'
        ? printf('Vogal')
        : printf('Consoante');
}