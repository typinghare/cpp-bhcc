#ifndef BHCC_CPP_DATE_H
#define BHCC_CPP_DATE_H

#include <iostream>

class Date {
private:
    short month;
    short day;
    short year;

    /**
     * Checks for valid day based on year and month.
     */
    void checkDay();

public:
    // Days in each month.
    constexpr static const short DAYS_IN_MONTH[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Date() {}

    Date(short month, short day, short year);

    short getMonth() { return month; }

    short getDay() { return day; }

    short getYear() { return year; }

    /**
     * Returns a date string formatting as "MM-DD-YYYY".
     */
    std::string toString();
};

/**
 * Returns the number of days from the birth date to today's date.
 * @param birthDate the birth date.
 */
int daysAfterBirth(Date birthDate);

#endif
