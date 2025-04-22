#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        int soma = 0;
        for (int j = 1; j <= x / 2; j++) {
            if (x % j == 0) {
                soma += j;
            }
        }

        soma == x
          ? printf("%d eh perfeito\n", x)
          : printf("%d nao eh perfeito\n", x);
    }

    return 0;
}

