#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function: sin(x)/x with handling for x = 0
double f(double x) {
    if (x == 0.0)
        return 1.0;
    return sin(x) / x;
}

// Romberg Integration with step size control
double romberg(double a, double b, int initial_intervals) {
    const int N = 4; // Number of Romberg levels
    double R[N][N];
    int n = initial_intervals;
    double h = (b - a) / n;

    // First trapezoidal approximation
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i)
        sum += f(a + i * h);
    R[0][0] = h * sum;

    for (int k = 1; k < N; ++k) {
        n *= 2;
        h = (b - a) / n;

        double midsum = 0.0;
        for (int i = 1; i <= n; i += 2)
            midsum += f(a + i * h);

        R[k][0] = 0.5 * R[k - 1][0] + h * midsum;

        for (int j = 1; j <= k; ++j)
            R[k][j] = R[k][j - 1] + (R[k][j - 1] - R[k - 1][j - 1]) / (pow(4, j) - 1);
    }

    // Print Romberg table
    cout << fixed << setprecision(10);
    cout << "Romberg Table:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << R[i][j] << "\t";
        cout << "\n";
    }

    return R[N - 1][N - 1];
}

int main() {
    double a = 0.0, b = 1.0;
    int intervals;

    cout << "Enter number of initial trapezoidal intervals (e.g., 2, 4, 8): ";
    cin >> intervals;

    double result = romberg(a, b, intervals);
    cout << "\nEstimated integral of sin(x)/x from 0 to 1: " << result << endl;

    return 0;
}


