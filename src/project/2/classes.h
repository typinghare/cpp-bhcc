#ifndef BHCC_CPP_CLASSES_H
#define BHCC_CPP_CLASSES_H

#endif

#include <iostream>

class Date {
private:
    short month;
    short day;
    short year;

    /**
     * Checks for valid day based on year and month.
     */
    void checkDay();

public:
    // Days in each month.
    constexpr static const short DAYS_IN_MONTH[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Date() {}

    Date(short month, short day, short year);

    short getMonth() { return month; }

    short getDay() { return day; }

    short getYear() { return year; }

    /**
     * Returns a date string formatting as "MM-DD-YYYY".
     */
    std::string toString();
};

class LifeForm {
protected:
    std::string name;
    std::string planet_of_origin;
public:
    LifeForm() {}

    LifeForm(std::string name, std::string planet_of_origin) {
        this->name = name;
        this->planet_of_origin = planet_of_origin;
    }

    virtual std::string toString() = 0;

//    virtual std::ostream &operator<<(std::ostream &) = 0;

    virtual std::istream &operator>>(std::istream &) = 0;
};


class Robot : public LifeForm {
private:
    std::string inventor;
    std::string context;
public:
    enum Skill {
        STRENGTH, LOGIC, SPEED
    };
    Skill skill;

    Robot(
        std::string name,
        std::string planet_of_origin,
        std::string inventor,
        std::string context
    ) : LifeForm(name, planet_of_origin) {
        this->inventor = inventor;
        this->context = context;
    }

    void setSkill(Skill _skill) { skill = _skill; }

    Skill getSkill() { return skill; }

    std::string toString() override;

//    std::ostream &operator<<(std::ostream &) override;

    std::istream &operator>>(std::istream &) override;

    friend std::ostream &operator<<(std::ostream &os, Robot robot);
};

class Person : public LifeForm {
private:
    Date birthDate;
    std::string birthPlace;
public:
    enum Skill {
        INTELLIGENCE, EMPATHY
    };

    Skill skill;

    Person(
        std::string name,
        std::string planet_of_origin,
        Date birthDate,
        std::string birthPlace
    ) : LifeForm(name, planet_of_origin) {
        this->birthDate = birthDate;
        this->birthPlace = birthPlace;
    }

    virtual void setSkill(Skill _skill) { skill = _skill; }

    virtual Skill getSkill() { return skill; }

    std::string toString() override;

//    std::ostream &operator<<(std::ostream &) override;

    std::istream &operator>>(std::istream &) override;

    // overload all comparison operators (based on the age of persons)
    bool operator<(const Person &);

    bool operator>(const Person &);

    bool operator<=(const Person &);

    bool operator>=(const Person &);

    bool operator!=(const Person &);

    bool operator==(const Person &);
};

/**
 * A super-person inherits from both person and robot, but always inherits skill from person.
 */
class SuperPerson : public Person, virtual Robot {
public:
    SuperPerson(
        std::string name,
        std::string planet_of_origin,
        std::string inventor,
        std::string context,
        Date birthDate,
        std::string birthPlace
    ) : Person(name, planet_of_origin, birthDate, birthPlace),
        Robot(name, planet_of_origin, inventor, context) {
    }

    void setSkill(Person::Skill _skill) override { setSkill(_skill); }

    Person::Skill getSkill() override { return getSkill(); }

    std::string toString() override;

//    std::ostream &operator<<(std::ostream &) override;

    std::istream &operator>>(std::istream &) override;
};

// custom
bool isLeapYear(short year);

int daysAfterBirth(Date birthDate);