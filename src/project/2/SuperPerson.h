#ifndef BHCC_CPP_SUPERPERSON_H
#define BHCC_CPP_SUPERPERSON_H

#include <iostream>
#include "Date.h"
#include "LifeForm.h"
#include "Person.h"
#include "Robot.h"


/**
 * A super-person inherits from both person and robot, but always inherits skill from person.
 */
class SuperPerson : public Person, virtual Robot {
public:
    SuperPerson():LifeForm(), Robot(), Person() {};

    SuperPerson(
        std::string name,
        std::string planet_of_origin,
        std::string inventor,
        std::string context,
        Date birthDate,
        std::string birthPlace
    ) : LifeForm(name, planet_of_origin),
        Robot(name, planet_of_origin, inventor, context),
        Person(name, planet_of_origin, birthDate, birthPlace) {
    }

    void setSkill(Person::Skill _skill) override { Person::setSkill(_skill); }

    Person::Skill getSkill() override { return Person::getSkill(); }

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, SuperPerson &);

    friend std::ostream &operator<<(std::ostream &, SuperPerson &);
};

#endif
