#ifndef BHCC_CPP_CAR_H
#define BHCC_CPP_CAR_H

#include "Transportation.h"

/**
 * Car extends Transportation.
 */
class Car : public Transportation {
public:
    std::string toString() override;

    std::string getType() override { return "Car"; }
};

#endif