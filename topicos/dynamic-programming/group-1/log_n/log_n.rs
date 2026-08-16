fn custom_abs(n: f64) -> {
    if n < 0.0 { -n } else { n }
}

pub fn log_n(x: f64) -> f64 {
    if x < 0.0 { return f64::NAN; }
    if x == 0.0 { return f64::NEGATIVE_INFINITY; }
    if x == 1.0 { return 0.0; }

    let z = (x - 1) / (x + 1);
    let z_square = z * z;

    let mut serie: f64 = 0.0;
    let mut base = z;
    let mut dominator: f64 = 1.0;

    const E: f64 = 1e-15;

    while custom_abs(base/dominator) > E {
        serie += base / dominator;
        base *= z_square;
        dominator += 2.0;
    }

    return 2 * serie
}