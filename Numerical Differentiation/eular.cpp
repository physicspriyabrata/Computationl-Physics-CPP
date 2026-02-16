#include <iostream>
#include <cmath>

using namespace std;

// Function representing dy/dx = x + y
double f(double x, double y) {
    return x + y;
}

// Euler's method function
double euler(double x0, double y0, double x, double h, int &iterations) {
    double y = y0;
    iterations = 0;
    for (double xi = x0; xi < x; xi += h) {
        y += h * f(xi, y);
        iterations++;
    }
    return y;
}

// Improved Euler's method function
double improved_euler(double x0, double y0, double x, double h, int &iterations) {
    double y = y0;
    iterations = 0;
    for (double xi = x0; xi < x; xi += h) {
        double y_predictor = y + h * f(xi, y); // Predictor step
        double y_corrector = y + (h / 2) * (f(xi, y) + f(xi + h, y_predictor)); // Corrector step
        y = y_corrector;
        iterations++;
    }
    return y;
}

// Modified Euler's method function
double modified_euler(double x0, double y0, double x, double h, int &iterations) {
    double y = y0;
    iterations = 0;
    for (double xi = x0; xi < x; xi += h) {
        double y_predictor = y + h * f(xi, y); // Predictor step
        double y_corrector = y + (h / 2) * (f(xi, y) + f(xi, y_predictor)); // Corrector step
        y = y_corrector;
        iterations++;
    }
    return y;
}

int main() {
    double x0 = 1.0;   // Initial x value
    double y0 = 2.0;   // Initial condition: y(1) = 2
    double x = 1.5;    // Point where we need to find y(x)
    double h = 0.1;    // Step size
    int iterations = 0;

    double euler_result = euler(x0, y0, x, h, iterations);
    cout << "Euler Method: Approximate solution at x = " << x << " is " << euler_result << endl;
    cout << "Number of iterations: " << iterations << endl;

    double improved_result = improved_euler(x0, y0, x, h, iterations);
    cout << "Improved Euler Method: Approximate solution at x = " << x << " is " << improved_result << endl;
    cout << "Number of iterations: " << iterations << endl;

    double modified_result = modified_euler(x0, y0, x, h, iterations);
    cout << "Modified Euler Method: Approximate solution at x = " << x << " is " << modified_result << endl;
    cout << "Number of iterations: " << iterations << endl;

    return 0;
}
