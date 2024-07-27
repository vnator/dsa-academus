#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);

    int count0 = 0;
    for (int i = 0; i < Q; i++) {
        int voto;
        scanf("%d", &voto);
        if (voto == 0) {
            count0++;
        }
    }

    if (count0 > Q / 2) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}
