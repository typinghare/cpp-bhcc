#include "Name.h"

Name::Name(std::string firstName, std::string lastName) {
    isAnonymous = false;
    this->firstName = firstName;
    this->lastName = lastName;
}

const std::string Name::toString() const {
    if (isAnonymous) {
        return "[Anonymous]";
    } else {
        return firstName + " " + lastName;
    }
}

std::istream &operator>>(std::istream &is, Name &name) {
    std::string firstName;
    is >> firstName;

    if (firstName == "[Anonymous]") {
        name.isAnonymous = true;
    } else {
        name.firstName = firstName;
        is >> name.lastName;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Name &name) {
    os << name.toString();
    return os;
}