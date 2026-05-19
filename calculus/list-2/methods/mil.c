#include "root_methods.h"
#include <math.h>
#include <time.h>

Result mil(double x0, double (*phi)(double), double (*f)(double), double tol_f, double tol_x, int max_iter) {
    Result res = {x0, 0, 0.0, 0, 0};
    struct timespec start, end;
    timespec_get(&start, TIME_UTC);

    double xk = x0;
    while (res.iterations < max_iter) {
        
        // Critério 1: Parada pelo resíduo
        if (tol_f > 0.0 && fabs(f(xk)) <= tol_f) {
            res.stopped_by_f = 1;
            res.root = xk;
            break;
        }

        double x_next = phi(xk);
        res.iterations++;

        // Critério 2: Parada pelo tamanho do passo (\Delta x)
        if (tol_x > 0.0 && fabs(x_next - xk) <= tol_x) {
            res.stopped_by_x = 1;
            res.root = x_next;
            break;
        }

        xk = x_next;
    }
    
    if (res.iterations == max_iter && !res.stopped_by_f && !res.stopped_by_x) {
        res.root = xk;
    }

    timespec_get(&end, TIME_UTC);
    res.time_ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    return res;
}