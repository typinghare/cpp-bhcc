/**
 * @author Zhuojian Chen (James)
 * @update (Apr 11, 2023)
 * 1. Removes "using namespace std;" statement from the header file.
 * 2. The test code is now placed in another file named "TestCourse.cpp".
 * 3. The "SemesterNames" variable is now a public static property in Course class.
 */

#include "Course.h"
#include <iostream>
#include <sstream>

using namespace std;

void Course::setNumStudent(int _numStudent) {
    if (_numStudent < 0) {
        throw invalid_argument(
                "The number of students should be a whole number, but " +
                to_string(_numStudent) + " is given.");
    }

    numStudent = _numStudent;
}

void Course::setSemester(Semester _semester) {
    if (_semester > Semester::WINTER_SESSION) {
        throw invalid_argument(
                "The semester should be between 0 and 3, but " + to_string(_semester) +
                " is given.");
    }

    semester = _semester;
}

void Course::setYear(int _year) {
    if (_year <= 2015 || _year > 9999) {
        throw invalid_argument(
                "The year should be a 4 digits number and greater than 2015, but "
                + to_string(_year) + " is given.");
    }

    year = _year;
}

Course::Course() : Course("CSC-265", "Operating System", 10, Semester::SUMMER, 2023) {}

Course::Course(std::string id, std::string name, int numStudent, Semester semester, int year) {
    this->id = id;
    this->name = name;

    setNumStudent(numStudent);
    setSemester(semester);
    setYear(year);
}

string Course::toString() {
    stringstream ss;
    ss << "Course id: " << id << endl;
    ss << "Course name: " << name << endl;
    ss << "Number of students: " << numStudent << endl;
    ss << "Semester: " << semester << endl;
    ss << "Year: " << year << endl;

    return ss.str();
}

const std::string Course::SemesterNames[4] = {"Spring", "Summer", "Fall", "WinterSession"};
