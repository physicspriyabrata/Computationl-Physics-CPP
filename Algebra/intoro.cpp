#include <iostream>
using namespace std;

int main() {
    int n; // Matrix size
    cout << "Enter the size of the matrix (n): ";
    cin >> n;

    float a[n][n + 1];

    cout << "Enter the values of x in the matrix[n][n+1]:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
    }

    cout << "Enter the values of y in the matrix[n][n+1]:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i][1];
    }

    // Display the matrix for verification
    cout << "\nMatrix Values:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

