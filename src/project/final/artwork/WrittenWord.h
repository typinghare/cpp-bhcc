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
    int numPages;
public:
    WrittenWord(Name artist, Date created, Date acquired, Name donatedBy, int numPages);

    double value() override;

    std::string toString() override;
};


#endif
