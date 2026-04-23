#ifndef ROOT_METHODS_H
#define ROOT_METHODS_H

typedef double (*FunctionType)(double);

typedef struct {
    double root;
    int iterations;
    double time_ms;
} Result;

Result bisection(double a, double b, FunctionType f, double epsilon, double sigma, int max_iter, int use_interval_stop);
Result false_position(double a, double b, FunctionType f, double epsilon, double sigma, int max_iter, int use_interval_stop);

#endif
