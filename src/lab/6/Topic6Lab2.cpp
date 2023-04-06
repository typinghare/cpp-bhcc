/**
 * @author Zhuojian Chen (James)
 * @requirement
 * Creates a Course from the empty constructor
 * Creates a Course from the parameterized constructor
 * uses the getters you created
 * uses the toString you created
*/

int main() {
    // create a course instance from the empty constructor
    Course course1 = Course();

    // create a course from the parameterized constructor
    Course course2 = Course(123456, "Machine Learning", 15, 1, 2023);

    // use the getter methods
    cout << "Course id: " << course2.getId() << endl;
    cout << "Course name: " << course2.getName() << endl;
    cout << "The number of students in the course: " << course2.getNumStudent() << endl;
    cout << "The semester of the course: " << course2.getSemester() << endl;
    cout << "The year of the course:" << course2.getYear() << endl;

    // use the toString method
    cout << course2.toString() << endl;
}