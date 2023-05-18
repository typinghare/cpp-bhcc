#ifndef BHCC_CPP_DANCE_H
#define BHCC_CPP_DANCE_H

#include <iostream>
#include "Artwork.h"
#include "../common//Time.h"

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
    /**
     * Creates a dance artwork.
     * @param artist the name of the artist of this dance.
     * @param created the date this dance was created.
     * @param acquired the date this dance was acquired from the donor.
     * @param donatedBy the name of the donor.
     * @param description the description of this dance.
     * @param performedBy the name of the team performing this dance.
     * @param length the length of this dance.
     */
    Dance(Name artist, Date created, Date acquired, Name donatedBy, std::string description,
          std::string performedBy, Time length);

    std::string getPerformedBy() const { return performedBy; }

    Time getLength() const { return length; }

    double value() override;

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, Dance &);

    friend std::ostream &operator<<(std::ostream &, Dance &);
};

#endif
