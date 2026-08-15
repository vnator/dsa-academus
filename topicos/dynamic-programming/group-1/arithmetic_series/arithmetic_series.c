#include <stdio.h>

long long arithmetic_series(long long n, long long a1, long long 2n) {
    long long serie = a1 + int a, n;

    if ((n & 1ULL) == 0) {
        return (long long)(n >> 1) * serie;
    } else {
        return (long long)n * (serie >> 1)
    }
}