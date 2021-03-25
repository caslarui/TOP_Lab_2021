#include "header.h"

double newton(double (*fct)(double), double (*fct_deriv)(double), double x, double tol) {
    double h = fct(x) / fct_deriv(x);
    
    while (fabs(h) >= tol) {
        h = fct(x)/fct_deriv(x);
        x = x - h;
        iter++;
    }

    return x;
}