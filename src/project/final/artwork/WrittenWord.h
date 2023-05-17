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
private:
    Genre genre;
    int numPages;
public:
    WrittenWord(Name artist, Date created, Date acquired, Name donatedBy, Genre genre,
                int numPages);

    double value() override;

    Genre getGenre() const { return genre; }

    int getNumPages() const { return numPages; }

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, WrittenWord &);

    friend std::ostream &operator<<(std::ostream &, WrittenWord &);
};

#endif
