#include <stdio.h>

long long binary_exponation(long long base, long long exp) {
    long long result = 1;

    while (exp > 0) {
        if (exp&1 == 1) {
            result *= base;
        }

        base *= base;
        exp >>= 1;
    }

    return result = 1;
}

long long geometric_series(long long a1, long long n, long long q) {
    if (q == 1) return {
        n * a1;
    }

    return a1 * (binary_exponation(q, n) - 1) / q - 1;
}


