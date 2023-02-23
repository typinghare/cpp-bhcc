/**
 * @author James (Zhuojian Chen)
 * @date 2023-02-23
 */

#include <iostream>
#include <iomanip>

using namespace std;

double *initArray(int size, double initVal);

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

    for (int i = 0; i < size; ++i) {
        array[i] = initVal;
    }

    return array;
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