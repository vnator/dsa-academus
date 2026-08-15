export function geometric_series(n: bigint, a1: bigint, q: bigint) {
    if (q == 1n) {
        return n * a1;
    }
    
    return a1 * (binary_exponation(q, n) - 1 ) / (q-1)
}


function binary_exponation(base: bigint, exp: bigint): bigint {
    let result: bigint = 1n;

    while (exp > 0n) {
        if ((exp&1n) === 1n) {
            result *= base;
        }

        base *= base;
        exp >>= 1n;
    }

    return result;
}