#ifndef BHCC_CPP_LIFEFORM_H
#define BHCC_CPP_LIFEFORM_H

#include <iostream>

class LifeForm {
protected:
    std::string name;
    std::string planet_of_origin;
public:
    LifeForm() {};

    LifeForm(std::string name, std::string planet_of_origin) {
        this->name = name;
        this->planet_of_origin = planet_of_origin;
    }

    virtual std::string toString() = 0;

    friend std::istream &operator>>(std::istream &, LifeForm &);

    friend std::ostream &operator<<(std::ostream &, LifeForm &);
};

#endif
