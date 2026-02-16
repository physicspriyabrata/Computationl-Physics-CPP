#include <iostream>
#include <cmath>

using namespace std;

// Function representing dy/dx = x + y
double f(double x, double y) {
    return x + y;
}

// Euler's method function
void euler(double x0, double y0, double x, int iterations) {
    double y = y0;
    double h = (x - x0) / iterations;
    cout << "Euler Method:\n";
    cout << "x\ty\n";
    for (int i = 0; i <= iterations; i++) {
        cout << x0 << "\t" << y << endl;
        y += h * f(x0, y);
        x0 += h;
    }
    cout << "Final Approximation: " << y << "\n\n";
}

// Improved Euler's method function
void improved_euler(double x0, double y0, double x, int iterations) {
    double y = y0;
    double h = (x - x0) / iterations;
    cout << "Improved Euler Method:\n";
    cout << "x\ty\n";
    for (int i = 0; i <= iterations; i++) {
        cout << x0 << "\t" << y << endl;
        double y_predictor = y + h * f(x0, y); // Predictor step
        double y_corrector = y + (h / 2) * (f(x0, y) + f(x0 + h, y_predictor)); // Corrector step
        y = y_corrector;
        x0 += h;
    }
    cout << "Final Approximation: " << y << "\n\n";
}

// Modified Euler's method function
void modified_euler(double x0, double y0, double x, int iterations) {
    double y = y0;
    double h = (x - x0) / iterations;
    cout << "Modified Euler Method:\n";
    cout << "x\ty\n";
    for (int i = 0; i <= iterations; i++) {
        cout << x0 << "\t" << y << endl;
        double y_predictor = y + h * f(x0, y); // Predictor step
        double y_corrector = y + (h / 2) * (f(x0, y) + f(x0, y_predictor)); // Corrector step
        y = y_corrector;
        x0 += h;
    }
    cout << "Final Approximation: " << y << "\n\n";
}

int main() {
    double x0 =1.0;  // Initial x value
    double y0 = 2.0;   // Initial condition: y(1) = 2
    double x = 1.5;    // Point where we need to find y(x)
    int iterations;
    cin>>iterations; // Fixed number of iterations

    euler(x0, y0, x, iterations);
    improved_euler(x0, y0, x, iterations);
    modified_euler(x0, y0, x, iterations);

    return 0;
}

