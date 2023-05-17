#include "Name.h"
#include "../util/helper.h"

const std::string Name::ANONYMOUS_LABEL = "[Anonymous]";

Name::Name(std::string firstName, std::string lastName) {
    isAnonymous = false;
    this->firstName = firstName;
    this->lastName = lastName;
}

const std::string Name::toString() const {
    if (isAnonymous) {
        return Name::ANONYMOUS_LABEL;
    } else {
        return firstName + " " + lastName;
    }
}

std::istream &operator>>(std::istream &is, Name &name) {
    std::string firstName;
    is >> firstName;

    if (firstName == Name::ANONYMOUS_LABEL) {
        name.isAnonymous = true;
    } else {
        name.firstName = firstName;
        is >> name.lastName;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Name &name) {
    return os << name.toString();
}