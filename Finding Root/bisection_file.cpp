#include<iostream>
#include<cmath>
#include<fstream>  // Include for file operations

using namespace std;

float bisection(float x)
{
   float fn =x*x*x - x*x - x -5; 
    return fn;
}

int main(){
    int i = 0; 
    float a, b , c, fmean, y0, y1, e;
    e = 0.00001;
    cin >> a >> b;

    y0 = bisection(a);
    y1 = bisection(b);
    
    // Open the file for writing
    ofstream outfile("output.txt");
    
    if (!outfile) {
        cout << "Error opening file!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    do {
        c = (a + b) / 2;
        fmean = bisection(c);

        if (y0 * y1 > 0) {
            cout << "Wrong the guess value" << endl;
            break;
        }
        else {
            if (y0 * fmean < 0) {
                b = c;
            }
            if (y1 * fmean < 0) {
                a = c;
            }
        }

        // Save iteration and root to the file
        outfile << "Iteration: " << i << "   Root: " << c << endl;
        i++;     

    } while (fabs(b - a) > e);

    // Close the file
    outfile.close();

    return 0;
}

