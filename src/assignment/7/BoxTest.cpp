#include "Box.h"

#include <iostream>

using namespace std;

void overloadOperatorTest() {
    cout << "[Overload Operator Test]" << endl;

    Box box1, box2;

    box1.setLength(2);
    box1.setWidth(3);
    box1.setHeight(4);

    box2.setLength(3);
    box2.setWidth(4);
    box2.setHeight(5);

    cout << (box1 < box2) << endl;      // it should be: true = 1
    cout << (box1 > box2) << endl;      // it should be: false = 0
    cout << (box1 <= box2) << endl;     // it should be: true = 1
    cout << (box1 >= box2) << endl;     // it should be: false = 0
    cout << (box1 != box2) << endl;     // it should be: true = 1
    cout << (box1 == box2) << endl;     // it should be: false = 0
}

void overloadAddTest() {
    cout << endl << "[Overload Add Test]" << endl;

    Box box1, box2, box3;

    box1.setLength(2);
    box1.setWidth(3);
    box1.setHeight(4);

    box2.setLength(3);
    box2.setWidth(4);
    box2.setHeight(5);

    box3.setLength(2);
    box3.setWidth(1);
    box3.setHeight(4);

    try {
        Box box4 = box1 + box2;
    } catch (const char *errorMsg) {
        // it should be `Only a box with identical two sides and one different side can add.`
        cout << errorMsg << endl;
    }

    Box box5 = box1 + box3;
    cout << box5.toString() << endl;    // it should be `SIZE=2x4x4; VOLUME=32; MATERIAL="".`
}

void overloadSubtractTest() {
    cout << endl << "[Overload Subtract Test]" << endl;

    Box box1, box2, box3;

    box1.setLength(5);
    box1.setWidth(6);
    box1.setHeight(7);

    box2.setLength(5);
    box2.setWidth(6);
    box2.setHeight(11);

    box3.setLength(5);
    box3.setWidth(6);
    box3.setHeight(2);

    try {
        Box box4 = box1 - box2;
    } catch (const char *errorMsg) {
        // it should be `For the different side, the magnitude of this box's should be greater than the minuend.`
        cout << errorMsg << endl;
    }

    Box box5 = box1 - box3;
    cout << box5.toString() << endl;    // it should be `SIZE=5x6x5; VOLUME=150; MATERIAL="".
}

void overloadOutStreamTest() {
    cout << endl << "[Overload Output Stream Test]" << endl;

    Box box;
    box.setLength(3);
    box.setWidth(4);
    box.setHeight(5);
    box.setMaterial("Cardboard");

    cout << box;    // it should be: `SIZE=3x4x5; VOLUME=60; MATERIAL="Cardboard."`
}

void overloadInStreamTest() {
    cout << endl << "[Overload Input Stream Test]" << endl;

    Box box;
    cin >> box; // Input "5 6 7 Copper"
    cout << box << endl;    // it should be: `SIZE=5x6x7; VOLUME=210; MATERIAL="Copper".`
}

int main() {
    overloadOperatorTest();
    overloadAddTest();
    overloadSubtractTest();
    overloadOutStreamTest();
    overloadInStreamTest();
}