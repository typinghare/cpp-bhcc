#ifndef BHCC_CPP_ARTWORK_H
#define BHCC_CPP_ARTWORK_H

#include <iostream>
#include "../util/Date.h"
#include "../util/Name.h"

/**
 * An abstract class.
 */
class Artwork {
protected:
    // The name of the artist of this artwork.
    Name artist;

    // The date this artwork was created.
    Date created;

    // The date this artwork was acquired from the donor.
    Date acquired;

    // The name of the donor.
    Name donatedBy;

    // The description of this artwork.
    std::string description;
public:
    Artwork(Name artist, Date created, Date acquired, Name donatedBy);

    const Name getArtist() const { return artist; }

    const Date getCreated() const { return created; }

    const Date getAcquired() const { return acquired; }

    const std::string getDescription() const { return description; }

    /**
     * Returns the age of this artwork.
     * @return
     */
    const short getAge() const;

    /**
     * Returns the string of this artwork.
     * @abstract
     */
    virtual std::string toString() = 0;

    /**
     * Returns the value of this artwork in American dollars ($).
     * @abstract
     */
    virtual double value() = 0;

    friend std::istream &operator>>(std::istream &, Artwork &);

    friend std::ostream &operator<<(std::ostream &, Artwork &);
};



#endif
