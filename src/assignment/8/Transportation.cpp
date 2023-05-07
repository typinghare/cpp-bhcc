
#include "Transportation.h"
#include <iostream>

using namespace std;

std::ostream &operator<<(ostream &os, Transportation &transportation) {
    os << transportation.toString();

    return os;
}

void Transportation::setNumPassenger(int _numPassenger) {
    // Crew members (if any), as well as the driver or pilot of the vehicle,
    // are usually not considered to be passengers
    if (_numPassenger >= 0)
        numPassenger = _numPassenger;
}