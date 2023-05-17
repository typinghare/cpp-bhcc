#include "Time.h"
#include <sstream>
#include <string>

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
    if (hours < 0) {
        throw new invalid_argument("The hours should be a whole number!");
    }
    if (minutes < 0) {
        throw new invalid_argument("The minutes should be a whole number!");
    }
    if (seconds < 0) {
        throw new invalid_argument("The seconds should be a whole number!");
    }

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

Time::Time(int minutes, int seconds) : Time(0, minutes, seconds) {}

Time::Time(int seconds) : Time(0, 0, seconds) {}

string Time::toString() {
    string minutesStr = minutes >= 10 ? to_string(minutes) : "0" + to_string(minutes);
    string secondsStr = seconds >= 10 ? to_string(seconds) : "0" + to_string(seconds);

    stringstream ss;
    if (hours > 0) ss << to_string(hours) << ":";
    ss << to_string(minutes) << ":" << to_string(seconds);

    return ss.str();
}

std::istream &operator>>(std::istream &is, Time &time) {
    is >> time.hours >> time.minutes >> time.seconds;

    return is;
}

std::ostream &operator<<(std::ostream &os,  Time &time) {
    os << time.toString();
    return os;
}