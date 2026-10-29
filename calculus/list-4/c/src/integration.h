

#ifndef CALCULUS_LIST4_INTEGRATION_H
#define CALCULUS_LIST4_INTEGRATION_H

#include <stddef.h>

typedef double (*Integrand)(double);

double trapezoidal_rule(Integrand f, double a, double b, size_t n);
double simpsons_rule(Integrand f, double a, double b, size_t n);

#endif
