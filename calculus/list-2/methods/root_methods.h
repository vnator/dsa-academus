#ifndef ROOT_METHODS_H
#define ROOT_METHODS_H

#include <math.h>

// Estrutura de retorno melhorada para identificar o motivo da parada
typedef struct {
    double root;
    int iterations;
    double time_ms;
    int stopped_by_f; // 1 se parou pelo critério de f(x), 0 caso não
    int stopped_by_x; // 1 se parou pelo critério de passo (x_k - x_k-1), 0 caso não
} Result;

// Recebe tol_f (para o resíduo) e tol_x (para o tamanho do passo)
Result newton_raphson(double x0, double (*f)(double), double (*df)(double), double tol_f, double tol_x, int max_iter);
Result mil(double x0, double (*phi)(double), double (*f)(double), double tol_f, double tol_x, int max_iter);

#endif