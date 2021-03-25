#include "header.h"


double golden(double (*fct)(double), double a, double b, double tol) {
    
    double c = b - (b - a) * 0.618;
    double d = a + (b - a) * 0.618;

    while(fabs(b - a) > tol) {
        if (fct(c) > fct(d)){   
            a = c;
        } else {
            b = d; 
        }
        c = b - (b - a) * 0.618;
        d = a + (b - a) * 0.618;
        ++iter;
    }
    return (a + b) / 2;
}