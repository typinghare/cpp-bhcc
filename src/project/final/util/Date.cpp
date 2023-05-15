#include "Date.h"
#include <string>

using namespace std;

/**
 * @return a date string formatting as "MM-DD-YYYY".
 */
std::string Date::toString() {
    string monthString = month >= 10 ? to_string(month) : '0' + to_string(month);
    string dayString = day >= 10 ? to_string(day) : '0' + to_string(day);

    return monthString + "-" + dayString + "-" + to_string(year);
}

Date::Date(short month, short day, short year) {
    this->month = month;
    this->day = day;
    this->year = year;

    checkDay();
}

void Date::checkDay() {
    // validate month
    if (month < 1 || month > 12) {
        throw new invalid_argument(
            "Month should be between 1 and 12, but " + to_string(month) + " is given."
        );
    }

    // validate year
    if (year < 100 || year > 3000) {
        throw new invalid_argument(
            "Year should be between 100 and 3000, but " + to_string(year) + " is given."
        );
    }

    // validate date
    short correctDay = DAYS_IN_MONTH[month - 1];
    if (day < 1 || day > correctDay) {
        throw new invalid_argument(
            "The day in " + to_string(month) + "should be " + to_string(correctDay)
            + ", but" + to_string(day) + " is given."
        );
    }
}

short Date::getYearsFromNow() const {
    return CURRENT_YEAR - year;
}