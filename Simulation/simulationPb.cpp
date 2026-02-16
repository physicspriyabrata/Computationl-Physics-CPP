#include <iostream>
#include <cmath>
#include <random>

using namespace std;

const int A = 208;             // Nucleons per lead nucleus
const double R = 7.1;          // Nucleus radius in fm
const double d = 1.5;          // Max distance for a nucleon-nucleon collision in fm
const int N_EVENTS = 1000;     // Number of Monte Carlo events

struct Nucleon {
    double x, y, z;
};

// Fill a nucleus with nucleons randomly distributed inside a sphere
void generate_nucleus(Nucleon nucleus[], mt19937 &gen) {
    uniform_real_distribution<> dist(-R, R);
    int i = 0;
    while (i < A) {
        double x = dist(gen);
        double y = dist(gen);
        double z = dist(gen);
        if (x*x + y*y + z*z <= R*R) {
            nucleus[i] = {x, y, z};
            ++i;
        }
    }
}

// Count nucleon-nucleon collisions (within d)
int count_collisions(Nucleon nucleus1[], Nucleon nucleus2[]) {
    int count = 0;
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            double dx = nucleus1[i].x - nucleus2[j].x;
            double dy = nucleus1[i].y - nucleus2[j].y;
            double dz = nucleus1[i].z - nucleus2[j].z;
            double r2 = dx*dx + dy*dy + dz*dz;
            if (r2 <= d*d) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> impact_dist(0.0, 14.0); // Impact parameter b

    Nucleon nucleus1[A];
    Nucleon nucleus2[A];

    int total_collisions = 0;

    for (int event = 0; event < N_EVENTS; ++event) {
        double b = impact_dist(gen);

        generate_nucleus(nucleus1, gen);
        generate_nucleus(nucleus2, gen);

        // Shift nucleus2 by b along x-axis
        for (int i = 0; i < A; ++i) {
            nucleus2[i].x += b;
        }

        int collisions = count_collisions(nucleus1, nucleus2);
        total_collisions += collisions;

        cout << "Event " << event + 1 << ": " << collisions << " collisions" << endl;
    }

    double avg = static_cast<double>(total_collisions) / N_EVENTS;
    cout << "Average collisions per event: " << avg << endl;

    return 0;
}
