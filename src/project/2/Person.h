#ifndef BHCC_CPP_PERSON_H
#define BHCC_CPP_PERSON_H

#include <iostream>
#include <array>
#include "Date.h"
#include "LifeForm.h"

class Person : public virtual LifeForm {
private:
    Date birthDate;
    std::string birthPlace;
public:
    static const std::array<std::string, 2> SkillString;
    enum Skill {
        INTELLIGENCE, EMPATHY
    };

    Skill skill = Skill::INTELLIGENCE;

    Person() {};

    Person(
        std::string name,
        std::string planet_of_origin,
        Date birthDate,
        std::string birthPlace
    ) : LifeForm(name, planet_of_origin) {
        this->birthDate = birthDate;
        this->birthPlace = birthPlace;
    }

    virtual void setSkill(Skill _skill) { if (skill >= 0 && skill < 2) skill = _skill; }

    virtual Skill getSkill() { return skill; }

    Date getBirthDate() { return birthDate; }

    std::string getBirthPlace() { return birthPlace; }

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, Person &);

    friend std::ostream &operator<<(std::ostream &, Person &);

    // overload all comparison operators (based on the age of persons)
    bool operator<(const Person &);

    bool operator>(const Person &);

    bool operator<=(const Person &);

    bool operator>=(const Person &);

    bool operator!=(const Person &);

    bool operator==(const Person &);
};

#endif

