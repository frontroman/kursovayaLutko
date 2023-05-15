#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { 
    return pow(x, 3) - 2 * x - 5;
}

double parabolic(double x1, double x2, double x3, double eps, int max_iter) {
    double a, b, c, x, fx, fx1, fx2, fx3;
    int iter = 0;

    do {
        fx1 = f(x1);
        fx2 = f(x2);
        fx3 = f(x3);

        a = fx1 / ((x1 - x2) * (x1 - x3)) + fx2 / ((x2 - x1) * (x2 - x3)) + fx3 / ((x3 - x1) * (x3 - x2));
        b = fx1 * ((x2 + x3) / ((x1 - x2) * (x1 - x3))) + fx2 * ((x1 + x3) / ((x2 - x1) * (x2 - x3))) + fx3 * ((x1 + x2) / ((x3 - x1) * (x3 - x2)));
        c = fx1 - a * x1 * x1 - b * x1;
        x = -b / (2 * a); 

        if (x < x3) { 
            fx = f(x);
            if (fx < fx3)

                x2 = x;
            else
                x1 = x; 
        }
        else {
            fx = f(x3);
            if (fx < fx3)
                x2 = x3; 
            else
                x1 = x3; 
            x3 = x; 
        }

        iter++;
    } while (fabs(fx) > eps && iter < max_iter);

    return x;
}

int main() {
    double x1 = 1, x2 = 2, x3 = 3, eps = 0.0001;
    int max_iter = 100;

    double root = parabolic(x1, x2, x3, eps, max_iter);

    cout << "answer: " << root << endl;

    return 0;
}
