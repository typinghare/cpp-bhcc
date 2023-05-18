#include "Artwork.h"
#include "../util/helper.h"

const short Artwork::getAge() const {
    return created.getYearsFromNow();
}

Artwork::Artwork(Name artist, Date created, Date acquired, Name donatedBy,
                 std::string description) {
    this->artist = artist;
    this->created = created;
    this->acquired = acquired;
    this->donatedBy = donatedBy;
    this->description = description;
}

std::istream &operator>>(std::istream &is, Artwork &artwork) {
    return is >> artwork.artist >> artwork.created >> artwork.acquired >> artwork.donatedBy;
}

std::ostream &operator<<(std::ostream &os, Artwork &artwork) {
    return os
        << joinWithSpace(artwork.artist, artwork.created, artwork.acquired, artwork.donatedBy);
}