#ifndef BHCC_CPP_TIME_H
#define BHCC_CPP_TIME_H

#include <iostream>

class Time {
private:
    int seconds;
public:
    Time(int seconds);

    Time(int minutes, int seconds);

    Time(int hours, int minutes, int seconds);

    std::string toString();
};

#endif
