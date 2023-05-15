#include "Artwork.h"

const short Artwork::getAge() const {
    return created.getYearsFromNow();
}

Artwork::Artwork(Name artist, Date created, Date acquired, Name donatedBy) {
    this->artist = artist;
    this->created = created;
    this->acquired = acquired;
    this->donatedBy = donatedBy;
}