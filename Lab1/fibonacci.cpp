#include <iostream>
#include "header.h"

ull fib(int n) {
    ull a = 0, b = 1, c;
    if( n == 0)
        return a;
    for(int i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}


double fibonacci(double (*fct)(double), double a, double b, double tol) {

    double L_term = b - a;
    double c = - a;
    double d = b;

    while(fabs(b - a) > tol) {
        if (fct(c) > fct(d)){
            a = c;
        } else {
            b = d;
        }
        iter++;
        if (iter == N)
            break;
        L_term *= ((double)fib(N - iter) / (double)fib(N - iter + 1));

        c = b - L_term;
        d = a + L_term;
    }
    return (a + b) / 2;
}