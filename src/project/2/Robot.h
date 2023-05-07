#ifndef BHCC_CPP_ROBOT_H
#define BHCC_CPP_ROBOT_H

#include "LifeForm.h"
#include <iostream>
#include <array>

class Robot : public virtual LifeForm {
private:
    std::string inventor;
    std::string context;
public:
    static const std::array<std::string, 3> SkillString;
    enum Skill {
        STRENGTH, LOGIC, SPEED
    };

    Skill skill = Skill::STRENGTH;

    Robot() {};

    Robot(
        std::string name,
        std::string planet_of_origin,
        std::string inventor,
        std::string context
    ) : LifeForm(name, planet_of_origin) {
        this->inventor = inventor;
        this->context = context;
    }

    void setSkill(Skill _skill) { if (skill >= 0 && skill <= 2) skill = _skill; }

    Skill getSkill() { return skill; }

    std::string getInventor() { return inventor; }

    std::string getContext() { return context; }

    std::string toString() override;

    friend std::istream &operator>>(std::istream &, Robot &);

    friend std::ostream &operator<<(std::ostream &, Robot &);
};

#endif