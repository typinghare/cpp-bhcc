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
 *
 * @notice This program works without issues on my IDE, however, it encounters a compilation error on
 * GraderThan. It is said that: "undefined reference to `Person::SkillString[abi:cxx11]'", but I
 * don't understand and I do not know how to solve it.
 */

#include "Robot.h"
#include "Person.h"
#include "SuperPerson.h"

using namespace std;

void printLifeForm(LifeForm &lifeForm) {
    cout << lifeForm << endl;
}

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

    // Test polymorphic function.
    printLifeForm(robot);
    printLifeForm(person);
    printLifeForm(superPerson);

    // Test person comparison operations.
    Person child("Jim", "Earth", Date(4, 30, 2003), "Italy");
    Person mother("Mary", "Earth", Date(3, 17, 1973), "German");
    cout << "child < mother = " << (child < mother) << endl;      // 1
    cout << "child > mother = " << (child > mother) << endl;      // 0
    cout << "child <= mother = " << (child <= mother) << endl;    // 1
    cout << "child >= mother = " << (child >= mother) << endl;    // 0
    cout << "child == mother = " << (child == mother) << endl;    // 0
    cout << "child != mother = " << (child != mother) << endl;    // 1

    // Test >> operator overload.
    Robot extraRobot;
    cout << "Input extra robot's information: ";
    cin >> extraRobot;  // Bard Earth Google logic A competitor of ChatGPT.
    printLifeForm(extraRobot); // it should be:
    // "[Robot] Name: Bard; Planet of origin: Earth; Inventor: Google;
    // Context: " A competitor of ChatGPT."; Skill: logic".

    SuperPerson extraSuperPerson;
    cout << "Input extra super person's information: ";
    cin >> extraSuperPerson;
    // Doraemon Earth Fujio empathy A household robot from the future
    // ** Press enter key and then continue to input: **
    // Doraemon Earth 09-03-2112 Japan empathy
    printLifeForm(extraSuperPerson); // it should be:
    // [SuperPerson] Name: Doraemon; Planet of origin: Earth; Inventor: Fujio;
    // Context: " A household robot from the future"; Birth date: 09-03-2112;
    // Birth place: Japan; Skill: empathy.
}