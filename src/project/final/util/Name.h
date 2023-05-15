#ifndef BHCC_CPP_NAME_H
#define BHCC_CPP_NAME_H

#include <iostream>

class Name {
private:
    /**
     * Whether the person is anonymous.
     */
    bool isAnonymous;
    std::string firstName;
    std::string lastName;
public:
    /**
     * Creates an anonymous person.
     */
    Name() { isAnonymous = true; }

    /**
     * Creates a non-anonymous person.
     * @param firstName
     * @param lastName
     */
    Name(std::string firstName, std::string lastName);

    bool getIsAnonymous() const { return isAnonymous; }

    const std::string getFirstName() const { return firstName; }

    const std::string getLastName() const { return lastName; }

    const std::string toString() const;
};

#endif
