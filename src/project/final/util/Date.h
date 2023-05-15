#ifndef BHCC_CPP_DATE_H
#define BHCC_CPP_DATE_H

#include <iostream>

const short CURRENT_YEAR = 2023;

class Date {
private:
    short month;
    short day;
    short year;

    /**
     * Checks for valid date based on year and month.
     */
    void checkDay();
public:
    Date();

    Date(short month, short day, short year);

    short getMonth() const { return month; }

    short getDay() const { return day; }

    short getYear() const { return year; }

    /**
     * Returns a date string formatting as "MM-DD-YYYY".
     */
    std::string toString();

    /**
     * Returns the number of years between the year provided by this date and the current year;
     * @return
     */
    short getYearsFromNow() const;
};

#endif
