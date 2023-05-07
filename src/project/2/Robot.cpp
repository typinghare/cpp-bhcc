#include "Robot.h"
#include <iostream>

#include <sstream>

using namespace std;

string Robot::toString() {
    stringstream ss;

    ss << "[Robot] Name: " << name
       << "; Planet of origin: " << planet_of_origin
       << "; Inventor: " << inventor
       << "; Context: \"" << context << "\""
       << "; Skill: " << SkillString.at(skill) << ".";

    return ss.str();
}

/**
 * @reference https://favtutor.com/blogs/split-string-cpp
 */
istream &operator>>(istream &is, Robot &robot) {
    is >> static_cast<LifeForm &>(robot);
    is >> robot.inventor;

    // Robot's skill.
    string skillStr;
    is >> skillStr;
    for (int i = 0; i < (int) Robot::SkillString.size(); ++i) {
        if (skillStr == Robot::SkillString[i]) {
            robot.setSkill(static_cast<Robot::Skill>(i));
        }
    }

    getline(is, robot.context);

    return is;
}

ostream &operator<<(ostream &os, Robot &robot) {
    os << robot.toString();

    return os;
}

const std::array<std::string, 3> Robot::SkillString = {"strength", "logic", "speed"};