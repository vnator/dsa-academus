
mod integration;

use integration::{simpsons_rule, trapezoidal_rule};

use std::f64::consts::PI;
use std::fmt::Write as _;
use std::fs;
use std::io;
use std::path::Path;

// ---------------------------------------------------------
// Numerical methods
// ---------------------------------------------------------

#[derive(Clone, Copy)]
enum Method {
    Trapezoidal,
    Simpson,
}

fn markdown_table(
    f: fn(f64) -> f64,
    a: f64,
    b: f64,
    intervals: &[usize],
    exact: f64,
    method: Method,
) -> String {
    let mut output = String::from(
        "| n | h | Aproximação | Erro absoluto |\n\
         |---:|---:|---:|---:|\n",
    );

    for &n in intervals {
        let h = (b - a) / n as f64;

        let approximation = match method {
            Method::Trapezoidal => trapezoidal_rule(f, a, b, n),
            Method::Simpson => simpsons_rule(f, a, b, n),
        };

        let error = (exact - approximation).abs();

        writeln!(
            output,
            "| {n} | {h:.8} | {approximation:.10} | {error:.10} |"
        )
        .expect("Failed to format Markdown table");
    }

    output
}

// ---------------------------------------------------------
// Exercise 1 — Vehicle displacement
// ---------------------------------------------------------

fn velocity(t: f64) -> f64 {
    4.0 + 3.0 * t + 0.2 * t * t
}

fn exercise_1() -> String {
    let exact = 770.0 / 3.0;

    let mut output = format!(
        "# Exercício 1 — Deslocamento\n\n\
         **Função:** `v(t) = 4 + 3t + 0.2t²`\n\n\
         **Intervalo:** `[0, 10]` segundos\n\n\
         **Valor exato:** `{exact:.10} m` (`770/3`)\n\n\
         ## Regra dos Trapézios Repetida\n\n"
    );

    output.push_str(&markdown_table(
        velocity,
        0.0,
        10.0,
        &[10, 100],
        exact,
        Method::Trapezoidal,
    ));

    output
}

// ---------------------------------------------------------
// Exercise 2 — Pollutant transport
// ---------------------------------------------------------

fn pollutant_mass_rate(t: f64) -> f64 {
    const Q: f64 = 2000.0;

    let concentration = 8.0 + 4.0 * (PI * t / 12.0).sin();

    Q * concentration
}

fn exercise_2() -> String {
    let exact = 192_000.0 + 192_000.0 / PI;

    let mut output = format!(
        "# Exercício 2 — Transporte de Poluente\n\n\
         **Concentração:** `C(t) = 8 + 4sin(πt/12)`\n\n\
         **Vazão:** `2000 L/h`\n\n\
         **Intervalo:** `[0, 12]` horas\n\n\
         **Valor exato:** `{exact:.10} mg` \
         (`192000 + 192000/π`)\n\n\
         ## Regra de Simpson 1/3 Repetida\n\n"
    );

    output.push_str(&markdown_table(
        pollutant_mass_rate,
        0.0,
        12.0,
        &[24, 240],
        exact,
        Method::Simpson,
    ));

    output
}

// ---------------------------------------------------------
// Exercise 3 — Processor energy consumption
// ---------------------------------------------------------

fn processor_power(t: f64) -> f64 {
    40.0 + 15.0 * (-0.1 * t).exp() + 0.02 * t * t
}

fn exercise_3() -> String {
    let exact = 3990.0 - 150.0 * (-6.0_f64).exp();

    let mut output = format!(
        "# Exercício 3 — Consumo de Energia\n\n\
         **Função:** `P(t) = 40 + 15e^(-0.1t) + 0.02t²`\n\n\
         **Intervalo:** `[0, 60]` segundos\n\n\
         **Valor exato:** `{exact:.10} J` \
         (`3990 - 150e⁻⁶`)\n\n\
         ## Regra dos Trapézios Repetida\n\n"
    );

    output.push_str(&markdown_table(
        processor_power,
        0.0,
        60.0,
        &[60, 600],
        exact,
        Method::Trapezoidal,
    ));

    output.push_str("\n## Regra de Simpson 1/3 Repetida\n\n");

    output.push_str(&markdown_table(
        processor_power,
        0.0,
        60.0,
        &[60, 600],
        exact,
        Method::Simpson,
    ));

    output
}

// ---------------------------------------------------------
// Markdown output
// ---------------------------------------------------------

fn write_report(filename: &str, content: &str) -> io::Result<()> {
    let directory = Path::new(env!("CARGO_MANIFEST_DIR")).join("results");

    fs::create_dir_all(&directory)?;
    fs::write(directory.join(filename), content)?;

    println!("{content}\n");

    Ok(())
}

fn main() -> io::Result<()> {
    write_report("exercise-1.md", &exercise_1())?;
    write_report("exercise-2.md", &exercise_2())?;
    write_report("exercise-3.md", &exercise_3())?;

    Ok(())
}
