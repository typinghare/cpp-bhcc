#include "Date.h"
#include <string>
#include "../util/helper.h"

using namespace std;

void Date::checkMemberVariables() {
    // Validate month.
    if (month < 1 || month > 12) {
        throw invalid_argument(
            "Month should be between 1 and 12, but " + to_string(month) + " is given."
        );
    }

    // Validate year.
    if (year < 100 || year > CURRENT_YEAR) {
        throw invalid_argument(
            "Year should be between 100 and " + to_string(CURRENT_YEAR) + ", but "
            + to_string(year) + " is given."
        );
    }

    // Validate day.
    short correctDay = DAYS_IN_MONTH[month - 1];
    if (day < 1 || day > correctDay) {
        throw invalid_argument(
            "The day in " + to_string(month) + "should be " + to_string(correctDay)
            + ", but" + to_string(day) + " is given."
        );
    }
}

std::string Date::toString() const {
    string monthString = month >= 10 ? to_string(month) : '0' + to_string(month);
    string dayString = day >= 10 ? to_string(day) : '0' + to_string(day);

    return monthString + "-" + dayString + "-" + to_string(year);
}

Date::Date(short month, short day, short year) {
    this->month = month;
    this->day = day;
    this->year = year;

    checkMemberVariables();
}

short Date::getYearsFromNow() const {
    return CURRENT_YEAR - year;
}

std::istream &operator>>(std::istream &is, Date &date) {
    is >> date.month >> date.day >> date.year;

    date.checkMemberVariables();

    return is;
}

std::ostream &operator<<(std::ostream &os, Date &date) {
    return os << joinWithSpace(date.getMonth(), date.getDay(), date.getYear());
}