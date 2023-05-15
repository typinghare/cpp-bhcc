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
    Name artist;
    Date created;
    Date acquired;
    Name donatedBy;
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

    virtual std::string toString() = 0;

    virtual double value() = 0;
};

#endif
