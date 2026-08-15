export function arithmetic_series(n: bigint, a1:  bigint, an: bigint): bingint {
    let an_serie = a1 + an;
 
    if (n & 1n === 0n) {
        return (n >> 1n) * an_serie;
    } else {
        return n * (an_serie >> 1n);
    }
}