/**
 * @author James Chan
 * @date Feb 23, 2023
*/

#include <iostream>
#include <iomanip>

using namespace std;

int randBetween(int min, int max);

short getDigitsOfNumber(int number);

void printArray(int array[], int size, short maxLength);

void printArray(short array[], int size);

// constants
int PRINT_ARRAY_MAX_COLUMN = 20;

/**
* @requirement
 * Ask the user for the size of the array to create (larger than 1000)
 * Create a dynamic integer array of the size the user specifies
 * Fill the array with random numbers between -(size/2) and (size/2)
 * Create a second dynamic short array of the size the user specified.
 * Loop through the first array, determine the number of digits in each number
 * (include the - sign as a digit) in the first array, and put that number in the second array.
 * write a function that prints the 2nd array, 20 per line neatly formatted.
 * (and print the 2nd array)
*/

int main() {
    // ask the user for the size of the array to create (size > 1000)
    int size = 0;
    do {
        cout << "Please input the size of the array (> 1000): ";
        cin >> size;
        if (size < 1000) {
            cout << "The size of the array should be greater than 1000." << endl;
        }
    } while (size < 1000);

    // create a dynamic integer array of the size the user specifies
    int *intArray = new int[size];

    // fill the array with random numbers between -(size/2) and (size/2)
    int min = -size / 2, max = size / 2;
    for (int i = 0; i < size; ++i) {
        intArray[i] = randBetween(min, max);
    }

    // create a second dynamic short array of the size the user specified.
    short *shortArray = new short[size];

    // loop through the first array, determine the number of digits in each number
    // in the first array, and put that number in the second array.
    for (int i = 0; i < size; ++i) {
        shortArray[i] = getDigitsOfNumber(intArray[i]);
    }

    // determine the max length
    short maxLength = shortArray[0];
    for (int i = 1; i < size; ++i) {
        if (maxLength < shortArray[i]) {
            maxLength = shortArray[i];
        }
    }

    cout << "max length: " << maxLength << endl;

    // print the two arrays
    cout << "The integer array is as follows. " << endl;
    printArray(intArray, size, 5);
    cout << "The short array in as follows. " << endl;
    printArray(shortArray, size);

    // release memory
    delete[] intArray;
    delete[] shortArray;

    return 0;
}

/**
 * Returns a random integer between specified values.
 * @param min the lower bound; included
 * @param max the upper bound; included
 * @return a random integer between specified values.
 */
int randBetween(int min, int max) {
    return rand() % (max - min + 1) + min;
}

short getDigitsOfNumber(int number) {
    int digit = 0;

    if (number < 0) {
        digit++;
        number = -number;
    }

    while (number > 0) {
        number /= 10;
        digit++;
    }

    return digit;
}

/**
 * Prints an integer array.
 * @param array array to print
 * @param size the size of the array
 * @param maxLength the longest length of all elements in the array
 */
void printArray(int array[], int size, short maxLength) {
    for (int i = 0; i < size; ++i) {
        // question: I just don't understand how setw() works.
        // It doesn't work when the numbers in the array is pretty large
        cout << setw(maxLength + 1) << array[i] << " ";
        if ((i + 1) % PRINT_ARRAY_MAX_COLUMN == 0) cout << endl;
    }

    cout << endl;
}

/**
 * Prints a short array.
 * @param array array to print
 * @param size the size of the array
 */
void printArray(short array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(3) << array[i];
        if ((i + 1) % PRINT_ARRAY_MAX_COLUMN == 0) cout << endl;
    }

    cout << endl;
}