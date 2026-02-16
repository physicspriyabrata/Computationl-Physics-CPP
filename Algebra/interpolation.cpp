#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    float x, u, u1, y;
    int i, j, n, fact;
    vector<double> X, Y;

  

    // Open file
    ifstream file("nfi-input.dat");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Read values from the file
    double tempX, tempY;
    while (file >> tempX >> tempY) {
        X.push_back(tempX);
        Y.push_back(tempY);
    }
    file.close();

    n = X.size();  // Number of data points
    if (n == 0) {
        cerr << "File is empty or invalid format!" << endl;
        return 1;
    }

    cout << "Enter value of x for which you want y: ";
    cin >> x;

    // Construct the Difference Table
    vector<vector<double>> a(n, vector<double>(n, 0));
    for (i = 0; i < n; i++) {
        a[i][0] = Y[i];  // First column is Y values
    }

    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];

    // Print the Difference Table
    cout << "\nThe Difference Table is as follows:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n - i - 1; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    // Choose forward or backward interpolation
    if (fabs(x - X[0]) < fabs(x - X[n - 1])) {
        // Forward Interpolation
        cout << "\nUsing Forward Interpolation:\n";
        u = (x - X[0]) / (X[1] - X[0]);
        y = a[0][0];
        u1 = u;
        fact = 1;

        for (i = 1; i < n; i++) {
            y += (u1 * a[0][i]) / fact;
            fact *= (i + 1);
            u1 *= (u - i);
        }
    } else {
        // Backward Interpolation
        cout << "\nUsing Backward Interpolation:\n";
        u = (x - X[n - 1]) / (X[1] - X[0]);
        y = a[n - 1][0];
        u1 = u;
        fact = 1;

        for (i = 1; i < n; i++) {
            y += (u1 * a[n - i - 1][i]) / fact;
            fact *= (i + 1);
            u1 *= (u + i);
        }
    }

    cout << "\nValue at X = " << x << " is = " << y << endl;
    return 0;
}
