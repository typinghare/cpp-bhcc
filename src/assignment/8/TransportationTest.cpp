/**
 * @author Zhuojian Chen (James)
 * @requirement
 * 1. Create a Transportation abstract class with the abstract method toString().
 * 2. Create subclasses of Car and Bicycle. All transportation should go forward, backward, left,
 * right, stop, go, accelerate, decelerate. Bicycles cannot go backwards.
 * (Use "cout << [thing] <<" goes forward" << endl;" for forward, etc. All transportation has a
 * speed, which increases with acceleration, and decreases with deceleration. toString() should
 * display the number of passengers, and the make, the model of the transportation, and the current
 * speed. Overload the stream output operator and demonstrate with a polymorphic print function that
 * can print to either cout or to a file.
 *
 * @update May 3, 2023
 * 1. Separates Car and Bicycle in different files.
 * 2. Adds a straightforward speed check within the decelerate method.
 * 3. Adds a validation within the numPassenger setter.
 * 4. Move "#endif" to the end of the file in header files.
*/

#include "Car.h"
#include "Bicycle.h"
#include <iostream>

using namespace std;

/**
 * Prints a transportation.
 * @param transportation transportation to print.
 */
void printTransportation(Transportation &transportation) {
    cout << transportation;
}

/**
 * Tests.
 */
int main() {
    Car car;
    car.setNumPassenger(3);
    car.setMake("Tesla");
    car.setModel("S");
    car.decelerate();   // this should not work
    for (int i = 0; i < 40; ++i) car.accelerate();
    car.decelerate();
    car.decelerate();

    car.left();
    car.right();
    car.forward();
    car.backward();

    Bicycle bicycle;
    bicycle.setNumPassenger(0);
    bicycle.setNumPassenger(-1);    // this should not work
    bicycle.setMake("Trek");
    bicycle.setModel("Domane+");
    for (int i = 0; i < 12; ++i) bicycle.accelerate();

    bicycle.left();
    bicycle.right();
    bicycle.forward();
    bicycle.backward();

    // polymorphic print function test
    printTransportation(car);
    printTransportation(bicycle);
}