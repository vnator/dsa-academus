

#include "integration.h"

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <sys/stat.h>

typedef enum { TRAPEZOIDAL, SIMPSON } IntegrationMethod;

// ---------------------------------------------------------
// Exercise functions
// ---------------------------------------------------------

static double velocity(double t) { return 4.0 + 3.0 * t + 0.2 * t * t; }

static double pollutant_mass_rate(double t) {
  const double pi = acos(-1.0);
  const double concentration = 8.0 + 4.0 * sin(pi * t / 12.0);

  return 2000.0 * concentration;
}

static double processor_power(double t) {
  return 40.0 + 15.0 * exp(-0.1 * t) + 0.02 * t * t;
}

// ---------------------------------------------------------
// Markdown table
// ---------------------------------------------------------

static void markdown_table(FILE *out, Integrand f, double a, double b,
                           const size_t *intervals, size_t count, double exact,
                           IntegrationMethod method) {
  fprintf(out, "| n | h | Aproximação | Erro absoluto |\n"
               "|---:|---:|---:|---:|\n");

  for (size_t i = 0; i < count; ++i) {
    const size_t n = intervals[i];
    const double h = (b - a) / (double)n;

    const double approximation = method == TRAPEZOIDAL
                                     ? trapezoidal_rule(f, a, b, n)
                                     : simpsons_rule(f, a, b, n);

    const double error = fabs(exact - approximation);

    fprintf(out, "| %zu | %.8f | %.12f | %.12f |\n", n, h, approximation,
            error);
  }
}

// ---------------------------------------------------------
// Exercise 1 — Vehicle displacement
// ---------------------------------------------------------

static void exercise_1(FILE *out) {
  const double exact = 770.0 / 3.0;
  const size_t intervals[] = {10, 100};

  fprintf(out,
          "# Exercício 1 — Deslocamento\n\n"
          "**Função:** `v(t) = 4 + 3t + 0.2t²`\n\n"
          "**Intervalo:** `[0, 10]` segundos\n\n"
          "**Valor exato:** `%.12f m` (`770/3`)\n\n"
          "## Regra dos Trapézios Repetida\n\n",
          exact);

  markdown_table(out, velocity, 0.0, 10.0, intervals, 2, exact, TRAPEZOIDAL);
}

// ---------------------------------------------------------
// Exercise 2 — Pollutant transport
// ---------------------------------------------------------

static void exercise_2(FILE *out) {
  const double pi = acos(-1.0);
  const double exact = 192000.0 + 192000.0 / pi;
  const size_t intervals[] = {24, 240};

  fprintf(out,
          "# Exercício 2 — Transporte de Poluente\n\n"
          "**Concentração:** `C(t) = 8 + 4sin(πt/12)`\n\n"
          "**Vazão:** `2000 L/h`\n\n"
          "**Intervalo:** `[0, 12]` horas\n\n"
          "**Valor exato:** `%.12f mg` (`192000 + 192000/π`)\n\n"
          "## Regra de Simpson 1/3 Repetida\n\n",
          exact);

  markdown_table(out, pollutant_mass_rate, 0.0, 12.0, intervals, 2, exact,
                 SIMPSON);
}

// ---------------------------------------------------------
// Exercise 3 — Processor energy consumption
// ---------------------------------------------------------

static void exercise_3(FILE *out) {
  const double exact = 3990.0 - 150.0 * exp(-6.0);
  const size_t intervals[] = {60, 600};

  fprintf(out,
          "# Exercício 3 — Consumo de Energia\n\n"
          "**Função:** `P(t) = 40 + 15e^(-0.1t) + 0.02t²`\n\n"
          "**Intervalo:** `[0, 60]` segundos\n\n"
          "**Valor exato:** `%.12f J` (`3990 - 150e⁻⁶`)\n\n"
          "## Regra dos Trapézios Repetida\n\n",
          exact);

  markdown_table(out, processor_power, 0.0, 60.0, intervals, 2, exact,
                 TRAPEZOIDAL);

  fprintf(out, "\n## Regra de Simpson 1/3 Repetida\n\n");

  markdown_table(out, processor_power, 0.0, 60.0, intervals, 2, exact, SIMPSON);
}

// ---------------------------------------------------------
// Markdown output
// ---------------------------------------------------------

typedef void (*Report)(FILE *);

static int write_report(const char *file_name, Report report) {
  char path[256];

  const int written = snprintf(path, sizeof(path), "results/%s", file_name);

  if (written < 0 || (size_t)written >= sizeof(path)) {
    fprintf(stderr, "Invalid report path\n");
    return 1;
  }

  FILE *file = fopen(path, "w");

  if (file == NULL) {
    perror(path);
    return 1;
  }

  report(file);

  const int write_error = ferror(file);
  const int close_error = fclose(file);

  if (write_error || close_error != 0) {
    fprintf(stderr, "Could not write %s\n", path);
    return 1;
  }

  report(stdout);
  fputs("\n", stdout);

  return ferror(stdout) ? 1 : 0;
}

int main(void) {
  if (mkdir("results", 0755) != 0 && errno != EEXIST) {
    perror("results");
    return 1;
  }

  if (write_report("exercise-1.md", exercise_1) ||
      write_report("exercise-2.md", exercise_2) ||
      write_report("exercise-3.md", exercise_3)) {
    return 1;
  }

  return 0;
}
