#include <iostream>

using namespace std;

class MyClass {
public:
    int num = 5;

    void setNum(int _num) {
        num = _num;
    }
};

int main() {
    shared_ptr<MyClass> myClass = make_shared<MyClass>();
    MyClass myClass2 = *new MyClass();
    MyClass* myClass3 = &myClass2;

    cout << myClass->num << endl;

    myClass->setNum(9);

    cout << myClass2.num << endl;

    myClass2.setNum(10);

    cout << myClass3->num << endl;
}