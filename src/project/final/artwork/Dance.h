#ifndef BHCC_CPP_DANCE_H
#define BHCC_CPP_DANCE_H

#include <iostream>
#include "Artwork.h"
#include "../util/Time.h"

/**
 * A dance artwork. (Honestly how can a dance be substance?)
 */
class Dance : public Artwork {
public:
    // The number of dance items in the museum.
    static int numberOfDanceItems;
private:
    // The name of the team performing this dance.
    std::string performedBy;

    // The length of this dance.
    Time length;
public:
    Dance(Name artist, Date created, Date acquired, Name donatedBy, std::string performedBy,
          Time length);

    double value() override;

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, Dance &);

    friend std::ostream &operator<<(std::ostream &, Dance &);
};

#endif
