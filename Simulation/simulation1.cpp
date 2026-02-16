#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    int totalPoints = 10000; // Total number of random points
    int pointsInsideCircle = 0;

    // Seed the random number generator
    srand(time(0));

    for (int i = 0; i < totalPoints; i++) {
        // Generate random (x, y) coordinates between -1 and 1
        double x = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

        // Check if the point is inside the unit circle
        if (x * x + y * y <= 1.0) {
            pointsInsideCircle++;
        }
    }

    // Estimate of pi using the ratio of points
    double piEstimate = 4.0 * pointsInsideCircle / totalPoints;

    cout << "Estimated value of Pi: " << piEstimate << endl;
    cout<< " Actual value of pi is : "<<M_PI<<endl;
    return 0;
}

