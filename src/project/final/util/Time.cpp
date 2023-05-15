#include "Time.h"
#include <sstream>
#include <string>

Time::Time(int seconds) {
    if (seconds <= 0) {
        throw new std::invalid_argument("The seconds should be a positive number!");
    }
    this->seconds = seconds;
}

Time::Time(int minutes, int seconds) : Time(minutes * 60 + seconds) {
    if (minutes < 0) {
        throw new std::invalid_argument("The minutes should be a whole number!");
    }
}

Time::Time(int hours, int minutes, int seconds) : Time(hours * 60 + minutes, seconds) {
    if (hours < 0) {
        throw new std::invalid_argument("The hours should be a whole number!");
    }
}

std::string Time::toString() {
    int second = seconds % 60;
    int minute = seconds / 60;
    int hour = minute / 60;

    std::stringstream ss;
    if (hour > 0) ss << std::to_string(hour) << "h";
    if (minute > 0) ss << std::to_string(minute) << "min";
    if (second > 0) ss << std::to_string(minute) << "sec";

    return ss.str();
}