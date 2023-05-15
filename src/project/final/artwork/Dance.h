#ifndef BHCC_CPP_DANCE_H
#define BHCC_CPP_DANCE_H

#include <iostream>
#include "Artwork.h"
#include "../util/Time.h"

class Dance : public Artwork {
public:
    static int numberOfDanceItems;
private:
    std::string performedBy;
    Time length;
public:
    Dance();
};


#endif
