pub fn custom_ln(x: f64) -> f64 {
    if x < 0.0 {
        return f64::NAN;
    }
    if x == 0.0 {
        return f64::NEG_INFINITY;
    }
    if x == 1.0 {
        return 0.0;
    }

    let z = (x - 1.0) / (x + 1.0);
    let z_squared = z * z;
    
    let mut sum: f64 = 0.0;
    let mut current_power = z;
    let mut denominator: f64 = 1.0;
    
    let epsilon: f64 = 1e-15;

    while (current_power / denominator).abs() > epsilon {
        sum += current_power / denominator;
        current_power *= z_squared;
        denominator += 2.0;
    }

    2.0 * sum
}