#include <math.h>
#include <time.h>
#include "root_methods.h"

static double calculate_time_ms(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
}

Result bisection(double a, double b, FunctionType f, double epsilon, double sigma, int max_iter, int use_interval_stop) {
    Result res = {NAN, 0, 0.0};
    struct timespec start, end;
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0.0) {
        return res;
    }

    timespec_get(&start, TIME_UTC);

    while (res.iterations < max_iter) {
        double xk = (a + b) / 2.0;
        double fx = f(xk);

        res.iterations++;
        res.root = xk;

        if (fa * fx < 0.0) {
            b = xk;
            fb = fx;
        } else {
            a = xk;
            fa = fx;
        }

        if (fabs(fx) <= epsilon) {
            break;
        }

        if (use_interval_stop && fabs(b - a) <= sigma) {
            break;
        }
    }

    timespec_get(&end, TIME_UTC);
    res.time_ms = calculate_time_ms(start, end);
    return res;
}
