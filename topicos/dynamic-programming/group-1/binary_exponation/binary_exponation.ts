export function binaryExponation(base: bigint, exp: bigint): bigint {
    let result: bigint = 1n;

    while (exp > 0n) {
        if ((exp & 1n) === 1n) {
            result *= base;
        }

        base *= base;
        exp >>= 1n;
    }

    return result;
}