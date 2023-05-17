#ifndef BHCC_CPP_PAINTING_H
#define BHCC_CPP_PAINTING_H

#include "Artwork.h"
#include "../common/Dimensions.h"

/**
 * A painting artwork.
 */
class Painting : public Artwork {
public:
    enum Medium {
        OIL, ACRYLIC, MIXED_MEDIA, WATERCOLOR
    };

    static int numberOfPaintings;
    static const std::string mediumString[4];
private:
    // The medium of this painting.
    Medium medium;

    // The dimensions of this painting.
    Dimensions dimensions;
public:
    /**
     * Creates a dance artwork.
     * @param artist the name of the artist of this painting.
     * @param created the date this painting was created.
     * @param acquired the date this painting was acquired from the donor.
     * @param donatedBy the name of the donor.
     * @param description the description of this painting.
     * @param medium the medium of this painting.
     * @param dimensions the dimensions of this painting.
     */
    Painting(Name artist, Date created, Date acquired, Name donatedBy, std::string description,
             Medium medium, Dimensions dimensions);

    const Medium getMedium() const { return medium; }

    const Dimensions getDimensions() const { return dimensions; }

    double value() override;

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, Painting &);

    friend std::ostream &operator<<(std::ostream &, Painting &);
};

/**
 * Convert a medium to string.
 */
std::string toMediumString(Painting::Medium medium);

/**
 * Convert a string to medium.
 */
Painting::Medium parseMediumString(std::string mediumString);

#endif