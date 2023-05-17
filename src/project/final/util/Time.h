#ifndef BHCC_CPP_TIME_H
#define BHCC_CPP_TIME_H

#include <iostream>

/**
 * A time representing the length of a music, video of something else. The hour, minute, and second
 * are counted
 */
class Time {
private:
    int seconds = 0, minutes = 0, hours = 0;
public:
    Time() : Time(0, 0, 0) {};

    Time(int hours, int minutes, int seconds);

    // The "hours" is zero.
    Time(int minutes, int seconds);

    // The "hours" and "minutes" are zero.
    Time(int seconds);

    int getSeconds() const { return seconds; }

    int getMinutes() const { return minutes; }

    int getHours() const { return hours; }

    /**
     * Returns a string of time.
     * @example "3:05:23"
     * @example "40:23"
     * @example "00:29"
     */
    std::string toString();

    // The order: hours, minutes, seconds.
    friend std::istream &operator>>(std::istream &, Time &);

    friend std::ostream &operator<<(std::ostream &, Time &);
};

#endif
