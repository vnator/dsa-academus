#include "root_methods.h"
#include <math.h>
#include <time.h>

Result newton_raphson(double x0, double (*f)(double), double (*df)(double), double tol_f, double tol_x, int max_iter) {
    Result res = {x0, 0, 0.0, 0, 0};
    struct timespec start, end;
    timespec_get(&start, TIME_UTC);

    double xk = x0;
    while (res.iterations < max_iter) {
        double fx = f(xk);
        
        // Critério 1: Parada pelo resíduo (f(x) próximo de zero)
        if (tol_f > 0.0 && fabs(fx) <= tol_f) {
            res.stopped_by_f = 1;
            res.root = xk;
            break;
        }

        double dfx = df(xk);
        if (fabs(dfx) < 1e-15) { // Proteção contra divisão por zero
            break;
        }

        double x_next = xk - (fx / dfx);
        res.iterations++;

        // Critério 2: Parada pelo tamanho do passo (diferença entre iterações)
        if (tol_x > 0.0 && fabs(x_next - xk) <= tol_x) {
            res.stopped_by_x = 1;
            res.root = x_next;
            break;
        }

        xk = x_next;
    }
    
    res.root = xk;
    timespec_get(&end, TIME_UTC);
    res.time_ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    return res;
}