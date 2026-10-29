pub fn trapezoidal_rule<F>(f: F, a: f64, b: f64, n: usize) -> f64
where
    F: Fn(f64) -> f64,
{
    assert!(n >= 1, "n must be positive");

    let h = (b - a) / n as f64;
    let mut sum = (f(a) + f(b)) / 2.0;

    for i in 1..n {
        let x = a + i as f64 * h;
        sum += f(x);
    }

    h * sum
}

pub fn simpsons_rule<F>(f: F, a: f64, b: f64, n: usize) -> f64
where
    F: Fn(f64) -> f64,
{
    assert!(n >= 2 && n.is_multiple_of(2), "n must be even and >= 2");

    let h = (b - a) / n as f64;
    let mut sum = f(a) + f(b);

    for i in 1..n {
        let x = a + i as f64 * h;
        let weight = if i.is_multiple_of(2) { 2.0 } else { 4.0 };

        sum += weight * f(x);
    }

    (h / 3.0) * sum
}
