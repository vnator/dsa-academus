#include <stdio.h>

long long binary_exponation(long long base, unsigned int exp) {
    long long result = 1;

    while (exp > 0) {
        if (exp & 1) {
            result = result*base;
        }
        
        base = base * base;
        exp >>= 1;
    }

    return result;
}