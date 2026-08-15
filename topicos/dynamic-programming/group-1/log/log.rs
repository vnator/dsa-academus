fn custom_abs(n: f64) -> f64 {
    if n < 0.0 { -n } else { n }
}

pub fn custom_ln(x: f64) -> Result<f64, &'static str> {
    if x < 0.0 {
        return Err("x deve ser maior que 0");
    }
    if x == 0.0 {
        return Err("Limites em 0 tendem ao menos infinito");
    }
    if x == 1.0 {
        return Ok(0.0);
    }

    let z = (x - 1.0) / (x + 1.0);
    let z_squared = z * z;
    
    let mut sum: f64 = 0.0;
    let mut current_power = z;
    let mut denominator: f64 = 1.0;
    let epsilon: f64 = 1e-15;

    while custom_abs(current_power / denominator) > epsilon {
        sum += current_power / denominator;
        current_power *= z_squared;
        denominator += 2.0;
    }

    Ok(2.0 * sum)
}

pub fn custom_log_base(x: f64, base: f64) -> Result<f64, &'static str> {
    if x <= 0.0 || base <= 0.0 || base == 1.0 {
        return Err("Parâmetros fora do domínio válido (x > 0, base > 0, base != 1)");
    }

    let ln_x = custom_ln(x)?;
    let ln_base = custom_ln(base)?;

    Ok(ln_x / ln_base)
}
