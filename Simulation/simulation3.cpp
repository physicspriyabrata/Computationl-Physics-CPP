#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;
const int NUM_EVENTS = 10000;
const int A = 208; // Pb nucleus has 208 nucleons
const double MAX_IMPACT = 15.0; // Max impact parameter in fm

// Simple random float between min and max
double randUniform(double min, double max) {
    return min + (max - min) * (rand() / (double)RAND_MAX);
}

// Estimate number of participant nucleons based on impact parameter
int estimateParticipants(double b) {
    // Very simplified model: more central -> more participants
    double centralityFactor = std::max(0.0, 1.0 - (b / MAX_IMPACT));
    return static_cast<int>(2 * A * centralityFactor); // two nuclei
}

// Estimate number of charged particles produced
int estimateChargedParticles(int N_part) {
    // Simplified linear model with fluctuations
    double avg = N_part * 1.5;
    return static_cast<int>(randUniform(avg * 0.8, avg * 1.2));
}

int main() {
ofstream file("simulation0.txt");
    srand(time(0));

    cout << "ImpactParameter, N_part, N_ch" <<endl;

    for (int i = 0; i < NUM_EVENTS; ++i) {
        double b = randUniform(0.0, MAX_IMPACT);
        int N_part = estimateParticipants(b);
        int N_ch = estimateChargedParticles(N_part);
        
        cout << b << "          " << N_part << "	 " << N_ch << endl;
        file << b << "		 " << N_part << "	 " << N_ch <<endl;
    }

    return 0;
}

