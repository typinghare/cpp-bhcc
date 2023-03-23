#include <iostream>

using namespace std;

struct Time {
    int hour;
    int minute;
    int second;
};

struct Date {
    int year;
    int month;
    int day;
};

struct DateTime {
    Date *date;
    Time *time;
};

int main() {
    Time time;
    Date date;
    DateTime dateTime;

    time.hour = 10;
    time.minute = 10;
    time.second = 10;

    date.year = 2023;
    date.month = 3;
    date.day = 15;

    dateTime.date = &date;
    dateTime.time = &time;

    dateTime.time->hour = 12;
    cout << time.hour << endl;

    return 0;
}