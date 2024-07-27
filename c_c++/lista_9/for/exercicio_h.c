#include <stdio.h>

int main() {
    int a, n;
    scanf("%d", &a);
    scanf("%d", &n);

    int stars = 0;
    for (int i = 0; i < n; i++) {
        int f;
        scanf("%d", &f);

        long long fotons = (long long) a * f;
        
        if (fotons >= 40000000) {
            stars++;
        }
    }

    printf("%d\n", stars);

    return 0;
}
