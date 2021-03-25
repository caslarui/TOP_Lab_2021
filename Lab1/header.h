#ifndef HEADER_H_
#define HEADER_H_

extern int iter;
extern int N;
typedef unsigned long long ull;

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;



double fibonnaci(double (*fct)(double), double a, double b, double tol);
double golden(double (*fct)(double), double a, double b, double tol);
double falsi(double (*fct)(double), double a, double b, double tol);
double newton(double (*fct)(double), double (*fct_deriv)(double), double x, double tol);

#endif
