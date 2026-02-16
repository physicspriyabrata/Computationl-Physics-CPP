#include <iostream>
using namespace std;

int main() {
    int n, m;
    
    cout << "Enter the no of rows: ";
    cin >> n;
    cout << "Enter the no of columns: ";
    cin >> m;

   
    int mat[n][m];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Matrix elements are:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
 

    return 0;
}

