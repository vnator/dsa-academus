fn custom_abs(n: f64) -> f64 {
    if n < 0.0 { -n } else { n }
}

fn log_n(x: f64) -> f64 {
    if x < 0 { return f64::NAN; }
    if x == 0.0 { return f64:NEGATIVE_INFINITY; }
    if x == 1 { return 0; }

    let z = (x-1) / (x+1);
    let z_square = z*z;

    let mut serie: f64 = 0.0;
    let mut base = z;
    let mut denominator: f64 = 1.0;
    const E: f64 = 1e-15;

    while custom_abs(base/denominator) > E {
        serie += base/denominator;
        base *= z_square;
        denominator += 2;
    }

    2.0*serie
}

pub fn log(x: f64, base: f64) -> f64 {
    if x <= 0.0 || base <= 0.0 || base == 1.0 {
        return f64::NAN;
    }

    let numerator = log_n(x);
    let denominator = log_n(base);

    numerator/denominator
}
