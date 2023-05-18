#include <iostream>
#include "Date.h"

using namespace std;

// Today's date.
// Since I don't know how to get today's date in C++, I can only define it here.
Date today = Date(5, 7, 2023);

/**
 * Whether a given year is a leap year. In a leap year, there are 29 days in February.
 * @reference: https://en.wikipedia.org/wiki/Leap_year.
 */
bool isLeapYear(short year) {
    if (year % 4 != 0) return false;

    if (year % 100 != 0) return true;

    if (year % 400 == 0) return true;

    return false;
}

/**
 * Returns the number of days from the birth date to today's date. It should be ensured that the
 * birthdate is at before today's date.
 * Tested by: https://www.timeanddate.com/date/durationresult.html
 * @param birthDate the birth date.
 */
int daysAfterBirth(Date birthDate) {
    short bMonth = birthDate.getMonth(), bDay = birthDate.getDay(), bYear = birthDate.getYear();
    short tMonth = today.getMonth(), tDay = today.getDay(), tYear = today.getYear();

    int ans = 0;

    // Compute days in full years.
    for (int year = bYear + 1; year < tYear; ++year) {
        ans += isLeapYear(year) ? 366 : 365;
    }

    // Compute days in full months.
    if (bYear == tYear) {
        // In the same year.
        for (int month = bMonth + 1; month < tMonth; ++month) {
            ans += Date::DAYS_IN_MONTH[month - 1];
        }
        if (bMonth == 1 && tMonth > 2 && isLeapYear(bYear)) ans++;
    } else {
        // Not in the same year.
        for (int month = bMonth + 1; month <= 12; ++month) {
            ans += Date::DAYS_IN_MONTH[month - 1];
        }
        if (bMonth == 1 && isLeapYear(bYear)) ans++;

        for (int month = 1; month < tMonth; ++month) {
            ans += Date::DAYS_IN_MONTH[month - 1];
        }
        if (tMonth > 2 && isLeapYear(tYear)) ans++;
    }

    // Compute the rest days.
    if (bYear == tYear && bMonth == tMonth) {
        // In the same month.
        ans += tDay - bDay;
    } else {
        // Not in the same month.
        ans += Date::DAYS_IN_MONTH[bMonth - 1] - bDay + tDay;
        if (bMonth == 2 && isLeapYear(bYear)) ans++;
    }

    return ans;
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