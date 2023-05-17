#ifndef BHCC_CPP_DATE_H
#define BHCC_CPP_DATE_H

#include <iostream>

/**
 * Current year.
 */
const short CURRENT_YEAR = 2023;

/**
 * A date including month, day, and year.
 */
class Date {
public:
    /**
     * The number of days in every month.
     */
    constexpr static const short DAYS_IN_MONTH[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
     */
    short getYearsFromNow() const;

    // The order : month, day, year.
    friend std::istream &operator>>(std::istream &, Date &);

    friend std::ostream &operator<<(std::ostream &, Date &);
};

#endif
