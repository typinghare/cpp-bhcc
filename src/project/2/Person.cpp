#include "Person.h"
#include "Date.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

std::string Person::toString() {
    stringstream ss;

    ss << "[Robot] Name: " << name
       << "; Planet of origin: " << planet_of_origin
       << "; Birth date: " << birthDate.toString()
       << "; Birth place: " << birthPlace
       << "; Skill: " << Person::SkillString.at(skill) << ".";

    return ss.str();
}

bool Person::operator<(const Person &person) {
    return daysAfterBirth(birthDate) < daysAfterBirth(person.birthDate);
}

bool Person::operator>(const Person &person) {
    return daysAfterBirth(birthDate) > daysAfterBirth(person.birthDate);
}

bool Person::operator<=(const Person &person) {
    return daysAfterBirth(birthDate) <= daysAfterBirth(person.birthDate);
}

bool Person::operator>=(const Person &person) {
    return daysAfterBirth(birthDate) >= daysAfterBirth(person.birthDate);
}

bool Person::operator!=(const Person &person) {
    return daysAfterBirth(birthDate) != daysAfterBirth(person.birthDate);
}

bool Person::operator==(const Person &person) {
    return daysAfterBirth(birthDate) == daysAfterBirth(person.birthDate);
}

/**
 * @reference https://favtutor.com/blogs/split-string-cpp
 */
std::istream &operator>>(istream &is, Person &person) {
    is >> static_cast<LifeForm &>(person);

    // Get date string.
    string dateString;
    is >> dateString;

    // Split the date string.
    stringstream ss(dateString);
    vector<string> tokens;
    string token;
    while (getline(ss, token, '-')) tokens.push_back(token);

    string monthStr = tokens[0], dayStr = tokens[1], yearStr = tokens[2];
    person.birthDate = Date(stoi(monthStr), stoi(dayStr), stoi(yearStr));

    is >> person.birthPlace;

    // Person's skill.
    string skillStr;
    is >> skillStr;
    for (int i = 0; i < Person::SkillString.size(); ++i) {
        if (skillStr == Person::SkillString[i]) {
            person.setSkill(static_cast<Person::Skill>(i));
        }
    }

    return is;
}

std::ostream &operator<<(ostream &os, Person &person) {
    os << person.toString();

    return os;
}

const std::array<std::string, 2> Person::SkillString = {"intelligence", "empathy"};