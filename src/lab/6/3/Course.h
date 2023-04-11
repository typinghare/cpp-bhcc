#ifndef BHCC_CPP_COURSE_H
#define BHCC_CPP_COURSE_H

#include <iostream>

enum Semester {
    SPRING,
    SUMMER,
    FALL,
    WINTER_SESSION
};

// declaration of Course class
class Course {
private:
    std::string id;         // course id
    std::string name;       // course name
    int numStudent;         // number of students
    Semester semester;      // enum(0=Spring; 1=Summer; 2=Fall, 3=WinterSession)
    int year;               // course year (>=2015)

    void setNumStudent(int _numStudent);

    void setSemester(Semester _semester);

    void setYear(int _year);

public:
    static const std::string SemesterNames[4];

    Course();

    Course(std::string id, std::string name, int numStudent, Semester semester, int year);

    const std::string getId() const { return id; }

    const std::string getName() const { return name; }

    int getNumStudent() const { return numStudent; }

    int getSemester() const { return semester; }

    int getYear() const { return year; }

    std::string toString();
};

#endif