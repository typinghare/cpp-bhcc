#include "WrittenWord.h"
#include <sstream>

WrittenWord::WrittenWord(Name artist, Date created, Date acquired, Name donatedBy, Genre genre, int numPages)
    : Artwork(artist, created, acquired, donatedBy) {
    if (numPages <= 0) {
        throw new std::invalid_argument("The number of pages should be a positive integer!");
    }

    this->genre = genre;
    this->numPages = numPages;
}

/**
 * The value of this written word: age in years * number of pages/100.
 * @return
 */
double WrittenWord::value() {
    return getAge() * numPages / 100;
}

std::string WrittenWord::toString() {
    std::stringstream ss;

    ss << "[Dance] "
       << "Artist: " << artist.toString() << ";" << std::endl
       << "Created date: " << created.toString() << ";" << std::endl
       << "Acquired date: " << acquired.toString() << ";" << std::endl
       << "Donated by: " << donatedBy.toString() << ";" << std::endl
       << "Number of pages: " << numPages << ";" << std::endl;

    return ss.str();
}

int WrittenWord::numberOfWrittenWordItems = 0;

std::istream &operator>>(std::istream &is, WrittenWord &writtenWord) {
    is >> static_cast<Artwork &>(writtenWord);



    is >> writtenWord.numPages;

    return is;
}

std::ostream &operator<<(std::ostream &os, WrittenWord &writtenWord) {
    os << writtenWord.toString();

    return os;
}