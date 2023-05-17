#include "Dance.h"
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
    return getAge() * length.getHours() / 60;
}

std::string Dance::toString() {
    std::stringstream ss;

    ss << "[Dance] "
       << "Artist: " << artist.toString() << ";" << std::endl
       << "Created date: " << created.toString() << ";" << std::endl
       << "Acquired date: " << acquired.toString() << ";" << std::endl
       << "Donated by: " << donatedBy.toString() << ";" << std::endl
       << "Performed by: " << performedBy << ";" << std::endl
       << "Length: " << length.toString() << ";" << std::endl;

    return ss.str();
}

std::istream &operator>>(std::istream &is, Dance &dance) {
    is >> static_cast<Artwork &>(dance);
    is >> dance.performedBy >> dance.length;

    return is;
}

std::ostream &operator<<(std::ostream &os, Dance &dance) {
    os << static_cast<Artwork&>(dance);
    os << dance.performedBy << dance.length;

    return os;
}