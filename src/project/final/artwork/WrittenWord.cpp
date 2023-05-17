#include "WrittenWord.h"
#include <sstream>

int WrittenWord::numberOfWrittenWordItems = 0;

const std::string WrittenWord::genreString[7]{
    "novel", "biography", "anthology", "illustrated",
    "autobiography", "nonfiction", "poetry"
};

WrittenWord::WrittenWord(Name artist, Date created, Date acquired, Name donatedBy,
                         std::string description, Genre genre, int numPages)
    : Artwork(artist, created, acquired, donatedBy, description) {
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

    ss << "[Written word] $" << value() << std::endl
       << "Artist: " << artist.toString() << ";" << std::endl
       << "Created date: " << created.toString() << ";" << std::endl
       << "Acquired date: " << acquired.toString() << ";" << std::endl
       << "Donated by: " << donatedBy.toString() << ";" << std::endl
       << "Genre: " << toGenreString(genre) << ";" << std::endl
       << "Number of pages: " << numPages << ";" << std::endl;

    return ss.str();
}

std::string toGenreString(WrittenWord::Genre genre) {
    return WrittenWord::genreString[genre];
}

WrittenWord::Genre parseGenreString(std::string genreString) {
    int size = sizeof(WrittenWord::genreString) / sizeof(WrittenWord::genreString[0]);
    for (int i = 0; i < size; ++i) {
        if (WrittenWord::genreString[i] == genreString) {
            return static_cast<WrittenWord::Genre>(i);
        }
    }

    throw new std::invalid_argument("Invalid writing word genre string: " + genreString);
}

std::istream &operator>>(std::istream &is, WrittenWord &writtenWord) {
    is >> static_cast<Artwork &>(writtenWord);

    is >> writtenWord.numPages;

    return is;
}

std::ostream &operator<<(std::ostream &os, WrittenWord &writtenWord) {
    os << writtenWord.toString();

    return os;
}

