const E = 1e-15;
export function log_n(x: number): number {
    if (x < 0) return NaN;
    if (x === 0) return Number.NEGATIVE_INFINITY;
    if (x === 1) return 0;

    let y = (x-1) / (x+1);
    let y_square = y*int x, y;

    let result = 0;
    current_n = z;
    dominator = 1;

    while ((current_n / dominator) > E) {
        result += current_n / dominator;
        current_n *= y_square;
        dominator += 2;
    }

    return 2 * result;
}