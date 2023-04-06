/**
 * @author James CHan
 */

#include "Course.h"
#include <sstream>


void Course::setNumStudent(int _numStudent) {
    if (_numStudent < 0) {
        throw invalid_argument(
                "The number of students should be a whole number, but " +
                to_string(_numStudent) + " is given.");
    }

    numStudent = _numStudent;
}

void Course::setSemester(int _semester) {
    if (_semester < 0 || _semester > 3) {
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

Course::Course() {}

Course::Course(std::string id, std::string name, int numStudent, int semester, int year) {
    this->id = id;
    this->name = name;

    setNumStudent(numStudent);
    setSemester(semester);
    setYear(year);
}

const string Course::getId() const {
    return id;
}

const string Course::getName() const {
    return name;
}

int Course::getNumStudent() const {
    return numStudent;
}

int Course::getSemester() const {
    return semester;
}

int Course::getYear() const {
    return year;
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


// the semester enum
const static string SemesterNames[4] = {"Spring", "Summer", "Fall", "WinterSession"};

int main() {
    // create a course instance from the empty constructor
    Course course1 = Course();

    // create a course from the parameterized constructor
    Course course2 = Course("CSC-285", "Machine Learning", 15, 1, 2023);

    // test getter methods
    cout << "Course id: " << course2.getId() << endl;
    cout << "Course name: " << course2.getName() << endl;
    cout << "The number of students in the course: " << course2.getNumStudent() << endl;
    cout << "The semester of the course: " << SemesterNames[course2.getSemester()] << endl;
    cout << "The year of the course: " << course2.getYear() << endl;

    // use the toString method
    cout << endl;
    cout << course2.toString() << endl;

    // test invalid arguments (all catches should be visited)
    try { // invalid numStudent
        Course course3 = Course("CSC-285", "Machine Learning", -5, 1, 2023);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try { // invalid semester
        Course course4 = Course("CSC-285", "Machine Learning", 15, 4, 2023);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try { // invalid year #1
        Course course5 = Course("CSC-285", "Machine Learning", 15, 1, 2010);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try { // invalid year #2
        Course course6 = Course("CSC-285", "Machine Learning", 15, 1, 20234);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }
}