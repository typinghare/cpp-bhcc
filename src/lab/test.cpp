#include <iostream>

using namespace std;

//class Person {
//private:
//    string *name;
//public:
//    Person(string *_name) {
//        name = _name;
//    }
//
//    string *getName() { return name; }
//};
//
//
//int main() {
//    string name = "James";
//    Person person[1] = {&name};
//
//    cout << *(person[0].getName()) << endl;
//}

class FeetInch {
private:
    int feet, inch;
public:
    FeetInch(int feet = 0, int inch = 0) {
        this->feet = feet;
        this->inch = inch;
    }

    FeetInch operator++(int);
};

FeetInch FeetInch::operator++(int) {
//    FeetInch feetInch(feet, inch);
    FeetInch feetInch = *this;

    return feetInch
}