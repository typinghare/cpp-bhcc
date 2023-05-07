#include "SuperPerson.h"
#include <iostream>
#include <sstream>

using namespace std;

std::string SuperPerson::toString() {
    stringstream ss;

    ss << "[SuperPerson] Name: " << Person::name
       << "; Planet of origin: " << Person::planet_of_origin
        << "; Inventor: " << Robot::getInventor()
        << "; Context: \"" << Robot::getContext() << "\""
       << "; Birth date: " << Person::getBirthDate().toString()
       << "; Birth place: " << Person::getBirthPlace()
       << "; Skill: " << Person::SkillString.at(getSkill()) << ".";

    return ss.str();
}

std::istream &operator>>(std::istream &is, SuperPerson &superPerson) {
    is >> static_cast<Robot &>(superPerson);
    is >> static_cast<Person &>(superPerson);

    return is;
}

std::ostream &operator<<(std::ostream &os, SuperPerson &superPerson) {
    os << superPerson.toString();

    return os;
}