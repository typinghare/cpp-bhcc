/**
 * @author James (Zhuojian Chen)
 * @date 2023-02-23
 *
 * @requirement
 * 1. Create a function that takes an integer (size) and a double (initValue) as input and returns
 * a dynamically allocated array of doubles of that size with all values set to initValue.
 * 2. Create a function initArray that initializes an array with a double value (initValue)
 * 3. Create a function that prints an array of doubles with 2 decimal places.
 * 4. In the main function of your program, ask the user for the size of the array to create, and
 * the default value to initialize the array to set. then create the array. then print the array.
 */

#include <iostream>
#include <iomanip>

using namespace std;

double *initArray(int size, double initValue);

void initArray(int size, double *array, double initValue);

void printArray(double *array, int size);

int main() {
    int size;
    cout << "Please input the size of the array: ";
    cin >> size;

    double initVal;
    cout << "Please input the initial value of the array: ";
    cin >> initVal;

    double *array = initArray(size, initVal);
    printArray(array, size);

    // release memory
    delete[] array;

    return 0;
}

/**
 * Returns a double array filling with a specified initial value.
 * @param size the size of the array
 * @param initVal initial value to fill
 * @return a double array filling with a specified initial value.
 */
double *initArray(int size, double initVal) {
    double *array = new double[size];

    initArray(size, array, initVal);

    return array;
}

/**
 * Initializes an array with a double value.
 * @param size the size of the array
 * @param array the array to fill
 * @param initValue initial value to fill
 */
void initArray(int size, double *array, double initValue) {
    for (int i = 0; i < size; ++i) {
        array[i] = initValue;
    }
}

/**
 * Prints an array.
 * @param array array to print
 */
void printArray(double *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << fixed << setprecision(2) << array[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
}