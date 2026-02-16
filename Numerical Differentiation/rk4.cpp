#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


ofstream file_rk1("rk1.txt");
ofstream file_rk2("rk2.txt");
ofstream file_rk4("rk4.txt");
ofstream file_true("true.txt");


double f(double x, double y) {
    return x + y;  
}


double trueSolution(double x) {
    return 2 * exp(x) - x - 1;
}


void rk1(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    cout << "\nRK-1 (Euler’s Method)\nx\ty" << endl;

    while (x <= xn ) {
        cout << x << "\t" << y << endl;
        file_rk1 << x << "\t" << y << endl;
        file_true << x << "\t" << trueSolution(x) << endl;

        y = y + h * f(x, y);
        x = x + h;
    }
}


void rk2(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    cout << "\nRK-2 Method\nx\ty" << endl;

    while (x <= xn ) {
        cout << x << "\t" << y << endl;
        file_rk2 << x << "\t" << y << endl;

        double k1 = f(x, y);
        double k2 = f(x + h, y + h * k1);
        y = y + (h / 2.0) * (k1 + k2);
        x = x + h;
    }
}


void rk4(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    cout << "\nRK-4 Method\nx\ty" << endl;

    while (x <= xn ) {
        cout << x << "\t" << y << endl;
        file_rk4 << x << "\t" << y << endl;

        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + h * k1 / 2);
        double k3 = f(x + h / 2, y + h * k2 / 2);
        double k4 = f(x + h, y + h * k3);
        y = y + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;
    }
}

int main() {
    double x0 = 0, y0 = 1;   
    double h = 0.1;          
    double xn = 1;           

    rk1(x0, y0, h, xn);
    rk2(x0, y0, h, xn);
    rk4(x0, y0, h, xn);

    

    return 0;
}
