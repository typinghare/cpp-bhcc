#include <iostream>

using namespace std;

int main() {
    int myVariable = 3;
    int *myPointer = nullptr;
    myPointer = &myVariable;

    cout << &myVariable << endl;
    cout << myPointer << endl;
}