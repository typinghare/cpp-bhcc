#ifndef BHCC_CPP_TRANSPORTATION_H
#define BHCC_CPP_TRANSPORTATION_H

#include <iostream>

/**
 * Transportation class.
 * @note A class with at least one pure virtual method contained is regarded as an abstract class.
 * @note Virtual methods can be overrode by subclasses.
 */
class Transportation {
protected:
    int speed = 0;
    int numPassenger = 0;
    std::string make;
    std::string model;

    // the type of the transportation.
    virtual std::string getType() = 0;

public:
    virtual std::string toString() = 0; // pure virtual method

    virtual void forward() { std::cout << getType() << " goes forward." << std::endl; }

    virtual void backward() { std::cout << getType() << " goes backward." << std::endl; }

    virtual void left() { std::cout << getType() << " goes left." << std::endl; }

    virtual void right() { std::cout << getType() << " goes right." << std::endl; }

    virtual void stop() { std::cout << getType() << " stops." << std::endl; }

    virtual void go() { std::cout << getType() << " goes." << std::endl; }

    virtual void accelerate() { speed++; }

    virtual void decelerate() { if (speed > 0) speed--; }

    int getSpeed() { return speed; }

    void setNumPassenger(int _numPassenger);

    int getNumPassenger() { return numPassenger; }

    const std::string getMake() const { return make; }

    void setMake(const std::string _make) { make = _make; }

    const std::string &getModel() const { return model; }

    void setModel(const std::string _model) { model = _model; }

    friend std::ostream &operator<<(std::ostream &, Transportation &);
};

#endif