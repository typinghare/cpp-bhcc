#include "Painting.h"
#include <sstream>

int Painting::numberOfPaintings = 0;

const std::string Painting::mediumString[4]{"Oil", "Acrylic", "Mixed Media", "Watercolor"};

Painting::Painting(Name artist, Date created, Date acquired, Name donatedBy, Medium medium,
                   Dimensions dimensions) :
    Artwork(artist, created, acquired, donatedBy) {
    this->medium = medium;
    this->dimensions = dimensions;
}

double Painting::value() {
    return getAge() * dimensions.getArea();
}

std::string Painting::toString() {
    std::stringstream ss;

    ss << "[Painting] "
       << "Artist: " << artist.toString() << ";" << std::endl
       << "Created date: " << created.toString() << ";" << std::endl
       << "Acquired date: " << acquired.toString() << ";" << std::endl
       << "Donated by: " << donatedBy.toString() << ";" << std::endl
       << "Dimensions: " << dimensions.toString() << ";" << std::endl
       << "Medium: " << toMediumString(medium) << ";" << std::endl;

    return ss.str();
}

std::string toMediumString(Painting::Medium medium) {
    return Painting::mediumString[medium];
}