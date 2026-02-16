// Runge-Kutta Method
#include<iostream>
#include<cmath>
using namespace std;

// Define the function
double f(double x, double y) {
    return x + y;
}

// RK4 function
double RK4(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);
        
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        
        cout << "At step " << i+1 << ", x = " << x << ", y = " << y << endl;
    }

    return y;
}

int main() {
    double x0, y0, xn, h;
    int n;
    
    cout << "Enter the initial values x0 and y0: ";
    cin >> x0 >> y0;
    
    cout << "Enter the point where you want the solution (xn): ";
    cin >> xn;
    
    cout << "Enter the number of steps: ";
    cin >> n;

    h = (xn - x0) / n;  // Calculate step size
    
    double result = RK4(x0, y0, h, n);
    
    cout << "Approximate value of y at x = " << xn << " is: " << result << endl;

    return 0;
}

