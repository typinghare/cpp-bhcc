#include "Dance.h"
#include "../util/helper.h"
#include <sstream>

int Dance::numberOfDanceItems = 0;

Dance::Dance(Name artist, Date created, Date acquired, Name donatedBy, std::string description,
             std::string performedBy, Time length)
    : Artwork(artist, created, acquired, donatedBy, description) {
    this->performedBy = performedBy;
    this->length = length;
}

double Dance::value() {
    // age in years * timeInHours / 60.
    return getAge() * length.getMinutes() / 60;
}

std::string Dance::toString() {
    std::stringstream ss;

    ss << "[Dance] $" << value() << std::endl
       << "Artist: " << getArtist().toString() << ";" << std::endl
       << "Created date: " << getCreated().toString() << ";" << std::endl
       << "Acquired date: " << getAcquired().toString() << ";" << std::endl
       << "Donated by: " << getDonatedBy().toString() << ";" << std::endl
       << "Description: " << getDescription() << ";" << std::endl
       << "Performed by: " << getPerformedBy() << ";" << std::endl
       << "Length: " << getLength().toString() << ";" << std::endl;

    return ss.str();
}

std::istream &operator>>(std::istream &is, Dance &dance) {
    try {
        return is >> static_cast<Artwork &>(dance) >> dance.performedBy >> dance.length;
    } catch (std::exception* e) {
        std::cout << "Fail to create dance object: " << e->what() << std::endl;
        exit(1);
    }
}

std::ostream &operator<<(std::ostream &os, Dance &dance) {
    return os << static_cast<Artwork &>(dance) << ' '
              << joinWithSpace(dance.performedBy, dance.length);
}