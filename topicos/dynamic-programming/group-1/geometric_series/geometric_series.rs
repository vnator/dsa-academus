pub fn binary_exponation(base: i64, exp: i64) -> i64 {
    let mut result: i64 = 1;

    while exp > 0 {
        if exp&1 == 1 {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }

    result
}

pub fn geometric_series(n: i64, a1: i64, q: i64) -> i64 {
    if q == 1 { return a1 * n };

    a1 * (binary_exponation(q, a) - 1) / (q - 1)
}