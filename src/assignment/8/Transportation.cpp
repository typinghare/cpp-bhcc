
#include "Transportation.h"
#include <iostream>
#include <sstream>

using namespace std;


std::ostream &operator<<(ostream &os, Transportation &transportation) {
    os << transportation.toString();

    return os;
}

string Car::toString() {
    stringstream ss;

    ss << "[" << getType() << "] "
       << "NumberOfPassenger = " << getNumPassenger()
       << "; Make = " << getMake()
       << "; Model = " << getModel()
       << "; Speed = " << getSpeed() << "mph"
       << "." << endl;

    return ss.str();
}

string Bicycle::toString() {
    stringstream ss;

    ss << "[" << getType() << "] "
       << "NumberOfPassenger = " << getNumPassenger()
       << "; Make = " << getMake()
       << "; Model = " << getModel()
       << "; Speed = " << getSpeed() << "mph"
       << "." << endl;

    return ss.str();
}