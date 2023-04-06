#ifndef BHCC_CPP_COURSE_H
#define BHCC_CPP_COURSE_H

#include <iostream>

using namespace std;

// declaration of Course class
class Course {
private:
    string id;      // course id
    string name;    // course name
    int numStudent; // number of students
    int semester;   // enum(0=Spring; 1=Summer; 2=Fall, 3=WinterSession)
    int year;       // course year (>=2015)

    void setNumStudent(int _numStudent);

    void setSemester(int _semester);

    void setYear(int _year);

public:
    Course();

    Course(string id, string name, int numStudent, int semester, int year);

    const string getId() const;

    const string getName() const;

    int getNumStudent() const;

    int getSemester() const;

    int getYear() const;

    string toString();
};

#endif