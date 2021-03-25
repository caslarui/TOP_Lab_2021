#include "header.h"


double falsi(double (*fct)(double), double a, double b, double tol) {
    
    double c = (a * fct(b) - b * fct(a)) / (fct(b) - fct(a));
    while(fabs(c) > tol) {
        if (fct(a) * fct(c) < 0.0f){   
            b = c;
        } else if (fct(a) * fct(c) > 0.0f) {
            a = c;
        } else {
            return c;
        }
        c = (a * fct(b) - b * fct(a)) / (fct(b) - fct(a));
        ++iter;
    }
    return (a + b) / 2;
}