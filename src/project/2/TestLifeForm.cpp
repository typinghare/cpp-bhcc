/**
 * @author Zhuojian Chen (James)
 * @date April 30, 2023
 *
 * @requirement
 * https://docs.google.com/document/d/1MwxWHA7XLbe_6qv1vD_NAV8sHeUyg6m9De93ovtn4oQ
 *
 * @question 1. It is not likely that you needed to create a destructor, copy constructor, a copy
 * assignment operator, a move constructor, or a move assignment operator. Why or why not? Explain
 * in full detail.
 * @answer In this project, the "LifeForm" is the abstract super class of "Robot" and "Person". By
 * extracting the shared properties and methods from two or more similar classes and abstract them
 * into class can make our code reusable and save out time. With this, I do not have to write the
 * assignment statements for "name" and "planet_of_origin" in the "Robot" and "Person" classes, but
 * just using "LifeForm(name, planet_of_origin)", letting the super class do the work.
 *
 * In this project, I do not need to create destructors for classes because all of these classes
 * only have member variables of type "short" or "string". Although `Person` class contains a member
 * variable of type `Date`, the `Date` class manages its own memory since it has no static variables
 * that are allocated dynamically. For these reasons, I do not need to create destructors.
 *
 * A copy constructor is a special constructor for creating new objects as a copy of an existing
 * object; a move constructor is a similar special constructor for creating a new object by moving
 * resources of an existing object into the new object; move assignment is a feature that allows
 * for the efficient of resources (e.g. memory) from one object to another object of the same class.
 * I do not need to create these structures because here I am using inheritance to implement them
 * all. It can be understood that by declaring "class Robot: public LifeForm" or
 * "class Person: public LifeForm", the C++ has done the above stuffs for us. Utilizing inheritance
 * is like creating a genealogy, where subclasses have everything of their parents excepting the
 * private members. Therefore, it frees developers from writing boring and repetitive "copying code"
 * and thus increases code reusability to some extent.
 *
 * @issue This program works without issues on my IDE, however, it encounters a compilation error on
 * GraderThan. It is said that: "undefined reference to `Person::SkillString[abi:cxx11]'", but I
 * don't understand and don't know how to solve it. I created "Skill" enums for both Robot and
 * Person class, and I also created static "SkillString" vectors in both classes for mapping between
 * indices and corresponding strings. If it is not necessary to be done, I will remove those parts
 * and submit my code again.
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
    printLifeForm(extraRobot); // it should output:
    // "[Robot] Name: Bard; Planet of origin: Earth; Inventor: Google;
    // Context: " A competitor of ChatGPT."; Skill: logic".

    SuperPerson extraSuperPerson;
    cout << "Input extra super person's information: ";
    cin >> extraSuperPerson;
    // Doraemon Earth Fujio empathy A household robot from the future
    // ** Press enter key and then continue to input: **
    // Doraemon Earth 09-03-2112 Japan empathy
    printLifeForm(extraSuperPerson); // it should output:
    // [SuperPerson] Name: Doraemon; Planet of origin: Earth; Inventor: Fujio;
    // Context: " A household robot from the future"; Birth date: 09-03-2112;
    // Birth place: Japan; Skill: empathy.
}