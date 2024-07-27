#include <stdio.h>

int main() {
    int x;

    for (;;) {
        scanf("%d", &x);

        if (x == 0)
            break;

        if (x % 2 != 0) {
            x++;
        }

        int soma = 0;
        for (int i = 0; i < 5; i++) {
            soma += x + 2 * i;
        }

        printf("%d\n", soma);
    }

    return 0;
}
