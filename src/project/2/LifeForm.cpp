#include "LifeForm.h"

#include <iostream>

using namespace std;

istream &operator>>(istream &is, LifeForm &lifeForm) {
    string name, planet_of_origin;

    is >> name;
    is >> planet_of_origin;

    lifeForm.name = name;
    lifeForm.planet_of_origin = planet_of_origin;

    return is;
}

ostream &operator<<(ostream &os, LifeForm &lifeForm) {
    os << lifeForm.toString();

    return os;
}
