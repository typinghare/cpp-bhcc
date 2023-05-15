#include "Name.h"

Name::Name(std::string firstName, std::string lastName) {
    isAnonymous = false;
    this->firstName = firstName;
    this->lastName = lastName;
}

const std::string Name::toString() const {
    if (isAnonymous) {
        return "Anonymous person";
    } else {
        return firstName + " " + lastName;
    }
}