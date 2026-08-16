export function logN(x: number): number {
    if (x < 0) return NaN;
    if (x === 0) return Number.NEGATIVE_INFINITY;
    if (x === 1) return 0;

    const z = (x - 1) / (x + 1);
    const powerOdd = z * z;
    
    let serie = 0;
    let base = z;
    let denominator = 1;
    
    const E = 1e-15;

    while (Math.abs(base / denominator) > E) {
        serie += base / denominator;
        base *= powerOdd;
        denominator += 2;
    }

    return 2 * serie;
}