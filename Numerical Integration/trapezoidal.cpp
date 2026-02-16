#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 1 / (pow(x, 2) + 1);
}

int main() {
    double a, b;
    cout << "Lower bound of integration, a = ";
    cin >> a;
    cout << "Upper bound of integration, b = ";
    cin >> b;
double fun=atan(b)-atan(a);
    for (int n = 1; n < 100; n++) {
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            sum += 2 * f(x);
        }
        double error= fabs((sum*h/2)-fun)*100/fun;
        cout << n << "\t" << (h * sum / 2) <<"error is "<<error<< endl;
    }
    
    return 0;
}

