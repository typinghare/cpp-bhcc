#include "Car.h"
#include <iostream>
#include <sstream>

using namespace std;

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

