
#include "Course.h"
#include <iostream>

using namespace std;

int main() {
    // create a course instance from the empty constructor
    Course course1 = Course();

    // create a course from the parameterized constructor
    Course course2 = Course("CSC-285", "Operating System", 15, Semester::SPRING, 2023);

    // test getter methods
    cout << "Course id: " << course2.getId() << endl;
    cout << "Course name: " << course2.getName() << endl;
    cout << "The number of students in the course: " << course2.getNumStudent() << endl;
    cout << "The semester of the course: " << Course::SemesterNames[course2.getSemester()] << endl;
    cout << "The year of the course: " << course2.getYear() << endl;

    // use the toString method
    cout << endl;
    cout << course2.toString() << endl;

    // test invalid arguments (all catches should be visited)
    try { // invalid numStudent
        Course course3 = Course("CSC-289", "Deep Learning", -5, Semester::FALL, 2023);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try { // invalid semester
        Course course4 = Course("CSC-301", "Machine Learning", 15, (Semester) 4, 2023);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try { // invalid year #1
        Course course5 = Course("CSC-292", "NLP", 15, Semester::WINTER_SESSION, 2010);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try { // invalid year #2
        Course course6 = Course("CSC-305", "Compiler Design", 15, Semester::SUMMER, 20234);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }
}