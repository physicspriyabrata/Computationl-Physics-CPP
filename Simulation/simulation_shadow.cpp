#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double objectHeight; 
    double sunAngleDeg;  

    cout << "Enter height of object (meters): ";
    cin >> objectHeight;

    cout << "Enter sun angle above horizon (degrees): ";
    cin >> sunAngleDeg;

   
    double sunAngleRad = sunAngleDeg * M_PI / 180.0;

    
    if (sunAngleRad <= 0) {
    cout << "Sun is at or below the horizon. No shadow visible.\n";
        return 0;
    }

  
    double shadowLength = objectHeight / tan(sunAngleRad);

cout << "Shadow length: " << shadowLength << " meters\n";

    return 0;
}
