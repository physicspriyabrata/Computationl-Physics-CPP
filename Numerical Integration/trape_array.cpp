#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// Function to evaluate f(x) = sin(x) / x, with a special case for x = 0
double f(double x) {
    if (x == 0.0) {
        return 1.0;
    }
    return sin(x) / x;
}

// Trapezoidal integration method
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Richardson extrapolation
double richardson(double T1, double T2) {
    return (4 * T2 - T1) / 3;
}

// Romberg integration method
double romberg(double a, double b, int maxLevel) {
    const int N = maxLevel + 1;
    double R[N][N];

    for (int i = 0; i <= maxLevel; ++i) {
        int n = pow(2, i);
        R[i][0] = trapezoidal(a, b, n);
        for (int k = 1; k <= i; ++k) {
            R[i][k] = (pow(4, k) * R[i][k - 1] - R[i - 1][k - 1]) / (pow(4, k) - 1);
        }
    }
    return R[maxLevel][maxLevel];
}

int main() {
    ofstream file1("ass13.txt");
    double a = 0.0, b = 1.0;
    cout << fixed << setprecision(10);
    double reference = 0.9460830703671831;
    int steps[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};

    cout << "Trapezoidal Approximations:\n";
    for (int n : steps) {
        double h = 1.0 / n;
        double result = trapezoidal(a, b, n);
        double error = abs(reference - result);
        cout << "n = " << n << ", I ≈ " << result << endl;

        // Richardson Extrapolation
        double T1 = trapezoidal(a, b, n);
        double T2 = trapezoidal(a, b, 2 * n);
        double R = richardson(T1, T2);
        double error1 = abs(reference - R);
        cout << "Richardson Extrapolation I ≈ " << R << endl;

        // Romberg Integration
        double romberg_result = romberg(a, b, 4);
        double error2 = abs(reference - romberg_result);
        cout << "Romberg Integration (R[4][4]): I ≈ " << romberg_result << endl;

        // Logarithmic errors for output file
        file1 << log(h) << " " << log(error) << " " << log(error1) << " " << log(error2) << endl;
    }

    file1.close();
    return 0;
}

