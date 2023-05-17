#include "Artwork.h"

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
    is >> artwork.artist >> artwork.created >> artwork.acquired >> artwork.donatedBy
       >> artwork.description;

    return is;
}

std::ostream &operator<<(std::ostream &os, Artwork &artwork) {
    os << artwork.artist << artwork.created << artwork.acquired << artwork.donatedBy
       << artwork.description;

    return os;
}