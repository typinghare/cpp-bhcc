#include "Painting.h"
#include "../util/helper.h"
#include <sstream>
#include<string>

int Painting::numberOfPaintings = 0;

const std::string Painting::mediumString[4]{"Oil", "Acrylic", "Mixed Media", "Watercolor"};

Painting::Painting(Name artist, Date created, Date acquired, Name donatedBy,
                   std::string description, Medium medium, Dimensions dimensions) :
    Artwork(artist, created, acquired, donatedBy, description) {
    this->medium = medium;
    this->dimensions = dimensions;
}

double Painting::value() {
    // age in years * area in square feet
    return getAge() * dimensions.getArea();
}

std::string Painting::toString() {
    std::stringstream ss;

    ss << "[Painting] $" << value() << std::endl
       << "Artist: " << getArtist().toString() << ";" << std::endl
       << "Created date: " << getCreated().toString() << ";" << std::endl
       << "Acquired date: " << getAcquired().toString() << ";" << std::endl
       << "Donated by: " << getDonatedBy().toString() << ";" << std::endl
       << "Description: " << getDescription() << ";" << std::endl
       << "Dimensions: " << getDimensions().toString() << ";" << std::endl
       << "Medium: " << toMediumString(getMedium()) << ";" << std::endl;

    return ss.str();
}

std::string toMediumString(Painting::Medium medium) {
    return Painting::mediumString[medium];
}

Painting::Medium parseMediumString(std::string mediumString) {
    int size = sizeof(Painting::mediumString) / sizeof(Painting::mediumString[0]);
    for (int i = 0; i < size; ++i) {
        if (Painting::mediumString[i] == mediumString) {
            return static_cast<Painting::Medium>(i);
        }
    }

    throw new std::invalid_argument("Invalid painting medium string: " + mediumString);
}

std::istream &operator>>(std::istream &is, Painting &painting) {
    try {
        is >> static_cast<Artwork &>(painting) >> painting.dimensions;

        std::string mediumString;
        is >> mediumString;
        painting.medium = parseMediumString(mediumString);

        return is;
    } catch (std::exception* e) {
        std::cout << "Fail to create painting object: " << e->what() << std::endl;
        exit(1);
    }
}

std::ostream &operator<<(std::ostream &os, Painting &painting) {
    return os << static_cast<Artwork &>(painting) << ' '
              << joinWithSpace(painting.medium, painting.dimensions);
}