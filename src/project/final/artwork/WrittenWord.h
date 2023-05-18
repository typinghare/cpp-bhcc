#ifndef BHCC_CPP_WRITTENWORD_H
#define BHCC_CPP_WRITTENWORD_H

#include <iostream>
#include "Artwork.h"

class WrittenWord : public Artwork {
public:
    enum Genre {
        NOVEL, BIOGRAPHY, ANTHOLOGY, ILLUSTRATED, AUTOBIOGRAPHY, NONFICTION, POETRY
    };

    static int numberOfWrittenWordItems;
    static const std::string genreString[7];
private:
    // The genre of this written word.
    Genre genre;

    // The number of pages of this written word.
    int numPages;
public:
    WrittenWord() {};

    /**
     * Creates a dance artwork.
     * @param artist the name of the artist of this written word.
     * @param created the date this written word was created.
     * @param acquired the written word this dance was acquired from the donor.
     * @param donatedBy the name of the donor.
     * @param description the description of this written word.
     * @param genre the genre of this written word.
     * @param numPages the number of pages of this written word.
     */
    WrittenWord(Name artist, Date created, Date acquired, Name donatedBy, std::string description,
                Genre genre, int numPages);

    double value() override;

    Genre getGenre() const { return genre; }

    int getNumPages() const { return numPages; }

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, WrittenWord &);

    friend std::ostream &operator<<(std::ostream &, WrittenWord &);
};

/**
 * Convert a genre to string.
 */
std::string toGenreString(WrittenWord::Genre genre);

/**
 * Convert a string to genre.
 */
WrittenWord::Genre parseGenreString(std::string genreString);

#endif
