#ifndef BHCC_CPP_NAME_H
#define BHCC_CPP_NAME_H

#include <iostream>

/**
 * The name of a person, including first name and last name. It can also be anonymous.
 */
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

    /**
     * Returns the name. Particularly, it returns "[Anonymous]" if it is anonymous.
     * @return
     */
    const std::string toString() const;

    // The order: first name, last name;
    // If the first argument is "[Anonymous]", the name is seen as anonymous and does not
    // receive the second argument.
    friend std::istream &operator>>(std::istream &, Name &);

    friend std::ostream &operator<<(std::ostream &, Name &);
};

#endif
