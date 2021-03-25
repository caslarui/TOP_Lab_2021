#include "header.h"

int iter = 0;
int N = 20;

double funct(double x) {
    return x*x*x*x - 3*x*x*x + 2;
}

double fct_d(double x) {
    return 4*x*x*x - 9*x*x;
}

double fct_ex3(double x) {
    return -log2(x) / (1 + 25* powf(x, 3));
}

double fct_ex3_deriv(double x) {
    return -(1 + 25 * powf(x, 3) + 75 * powf(x, 3) * log(x)) / (log(2) * x);
}

int main() {
    
    double a = -10, b = 10, tol = 0.1;
    cout.precision(10);
    cout << fixed << setfill('0') << setw(10);
    cout << "Solution search starts in interval[ " << a << " : " << b << " ]" << endl;
    cout << "Golden\t\t|\tIterations\t|\tFibonacci\t\t|\tIterations\t|\tTolerance"<< endl;
    for (int i = 0; i < 10; i++) {
        cout << golden(funct, a, b, tol) <<"\t|\t"<< iter <<"\t\t|\t"; iter = 0;
        cout << fibonacci(funct, a, b, tol) <<"\t\t|\t"<< iter <<"\t\t|\t" << tol<< endl; iter = 0;
        N += 10;
        tol /= 10;
    }
    tol = 0.1;
    cout << "\n\nFalsi\t\t|\tIterations\t|\tNewton\t\t\t|\tIterations\t|\tTolerance"<< endl;
    for (int i = 0; i < 10; i++) {
        cout << falsi(fct_d, -3, 5, tol) <<"\t|\t"<< iter <<"\t\t|\t"; iter = 0;
        cout << newton(funct, fct_d, 50, tol) <<"\t\t|\t"<< iter <<"\t\t|\t" << tol<< endl; iter = 0;
        tol /= 10;
    }

    tol = 0.1;
    N = 20;
    a = 0;
    b = 5;
    cout << "\n\nSolution search starts in interval[ " << a << " : " << b << " ]" << endl;
    cout << "Golden\t\t|Nr|\tFibonacci\t|Nr|\t";
    cout << "Falsi\t\t|Nr|\tNewton\t\t|Nr|\tTolerance"<< endl;
    for (int i = 0; i < 10; i++) {
        cout << golden(fct_ex3, a, b, tol) <<"\t|"<< iter <<"|\t"; iter = 0;
        cout << fibonacci(fct_ex3, a, b, tol) <<"\t|"<< iter <<"|\t"; iter = 0;
        cout << falsi(fct_ex3_deriv, -0.3, 0.7, tol) <<"\t|"<< iter <<"|\t"; iter = 0;
        cout << newton(fct_ex3, fct_ex3_deriv, 6, tol) <<"\t|"<< iter <<"|\t" << tol<< endl; iter = 0;
        N += 10;
        tol /= 10;
    }

    return 0;
}