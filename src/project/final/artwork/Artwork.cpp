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

std::istream &operator>>(std::istream &is, Artwork &artwork) {
    is >> artwork.artist >> artwork.created >> artwork.acquired >> artwork.donatedBy;

    return is;
}

std::ostream &operator<<(std::ostream &os, Artwork &artwork) {
    os << artwork.toString();
    return os;
}