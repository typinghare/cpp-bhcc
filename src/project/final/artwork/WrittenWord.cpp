#include "WrittenWord.h"

WrittenWord::WrittenWord(Name artist, Date created, Date acquired, Name donatedBy, int numPages)
    : Artwork(artist, created, acquired, donatedBy) {
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
    return "";
}

int WrittenWord::numberOfWrittenWordItems = 0;