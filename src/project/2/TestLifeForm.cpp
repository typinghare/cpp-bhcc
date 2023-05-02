/**
 * @author Zhuojian Chen (James)
 *
 * @requirement
 * https://docs.google.com/document/d/1MwxWHA7XLbe_6qv1vD_NAV8sHeUyg6m9De93ovtn4oQ
 *
 * @question 1. It is not likely that you needed to create a destructor, copy constructor, a copy
 * assignment operator, a move constructor, or a move assignment operator. Why or why not? Explain
 * in full detail.
 * @answer This
 */

#include "classes.h"
#include <iostream>

using namespace std;

/**
 * Tests.
 */
int main() {
    Robot robot("ChatGPT", "Earth", "OpenAI", "A milestone in the field of AI.");
    Person person("James", "Earth", Date(3, 12, 1999), "China");
    SuperPerson superPerson("Doraemon", "Earth", "Fujiko F. Fujio",
                            "A household robot from the future", Date(9, 3, 2112), "Japan");

    robot.setSkill(Robot::Skill::LOGIC);
    person.setSkill(Person::Skill::INTELLIGENCE);
    superPerson.setSkill(Person::Skill::EMPATHY);

//    cout << "robot" << endl;
//    cout << robot << endl;
}