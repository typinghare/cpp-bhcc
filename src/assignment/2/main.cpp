#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int *createArray(int size, int initValue);

void fillArray(int array[], int size, int lowerBound, int upperBound);

void printArray(int array[], int size, ostream &os, int longestLength);

void sortArray(int array[], int size);

double *findMedian(int array[], int size);

int *findMode(int array[], int size);

int randBetween(int lowerBound, int upperBound);

int readNumber(string prompt, ostream &os, istream &in);

int readPositiveNumber(string prompt, ostream &os, istream &in);

int getLengthOfInt(int number);

const int ARRAY_PRINT_MAX_COLUMN = 10;

int main() {
    // set a random seed
    srand(time(nullptr));

    int size = readPositiveNumber("Please enter the length of the array (whole number): ", cout, cin);
    int lowerBound = readNumber("Please enter the lower bound of random numbers: ", cout, cin);
    int upperBound = readNumber("Please enter the upper bound of random numbers: ", cout, cin);

    while (upperBound < lowerBound) {
        cout << "The upper bound should be greater than the lower bound ("
             << lowerBound << ")!" << endl;
        upperBound = readNumber("Please enter the upper bound of random numbers:  ", cout, cin);
    }

    int *array = createArray(size, 0);
    cout << "The array has been created. Filling the array with random numbers between "
         << lowerBound << " and " << upperBound << "." << endl;
    fillArray(array, size, lowerBound, upperBound);

    // print the array
    int longestLength = max(getLengthOfInt(upperBound), getLengthOfInt(lowerBound));
    cout << "The array is as follows: " << endl;
    printArray(array, size, cout, longestLength);
    cout << "The size of this array is: " << size << endl;

    // test findMode()
    int *mode = findMode(array, size);
    if (mode == nullptr) {
        cout << "The mode does not exist." << endl;
    } else {
        cout << "The mode of this array is: " << *mode << endl;
    }

    // test findMedian()
    double *median = findMedian(array, size);
    cout << "The median of this array is: " << *median << endl;

    // free memory
    // supplement: use delete instead of free for the sake of safety
    delete median;
    delete[] array;
}

/**
 * Returns a dynamic integer array of specified size.
 * @param size the size of the array; should be whole number
 * @param initValue initial value
 * @return a dynamic integer array of specified size; nullptr is size is not
 * greater than 0.
 */
int *createArray(int size, int initValue) {
    if (size <= 0) return nullptr;

    int *array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = initValue;
    }

    return array;
}

/**
 * Fills an array with random values between specified values.
 * @param array the array to operate
 * @param size the size of the array.
 */
void fillArray(int array[], int size, int lowerBound, int upperBound) {
    if (array == nullptr) return;

    for (int i = 0; i < size; ++i) {
        array[i] = randBetween(lowerBound, upperBound);
    }
}

/**
 * Prints an array in a pretty way.
 * @param array the array to print
 * @param size the size of the array
 * @param os ostream
 * @param longestLength
 */
void printArray(int array[], int size, ostream &os, int longestLength) {
    if (array == nullptr) {
        os << "[null]";
        return;
    }

    for (int i = 0; i < size; ++i) {
        os << setw(longestLength) << array[i] << " ";
        if (i % ARRAY_PRINT_MAX_COLUMN == ARRAY_PRINT_MAX_COLUMN - 1) os << endl;
    }

    os << endl;
}

/**
 * Sorts an array in ascending order.
 * @param array the array to sort
 * @param size the size of the array
 */
void sortArray(int array[], int size) { sort(array, array + size); }

/**
 * Returns the median of an array.
 * @param array the array to find the median
 * @param size the size of the array
 * @return the pointer of a double variable.
 */
double *findMedian(int array[], int size) {
    if (array == nullptr) return nullptr;

    sortArray(array, size);

    double *median = new double;
    int half = size / 2;

    if (size % 2 == 1) {
        // the size is an odd number
        *median = array[half];
    } else {
        // the size is an even number
        *median = ((double) array[half] + array[half - 1]) / 2;
    }

    return median;
}

/**
 * Returns the mode of an array.
 * @param array array to find the mode
 * @param size the size of the array
 * @return the mode of an array; null if the mode does not exist.
 */
int *findMode(int array[], int size) {
    if (array == nullptr) return nullptr;

    sortArray(array, size);

    int *num = new int[size];
    int *frequency = new int[size];
    int pos = 0;
    num[0] = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] == num[pos]) {
            frequency[pos]++;
        } else {
            num[++pos] = array[i];
            frequency[pos] = 1;
        }
    }

    // find the max frequency and the number of modes
    int mode = num[0], maxFrequency = frequency[0];
    for (int i = 1; i < pos; ++i) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mode = num[i];
        }
    }

    int *modePointer = new int;
    if (maxFrequency == 1) {
        modePointer = nullptr;
    } else {
        *modePointer = mode;
    }

    delete[] num;
    delete[] frequency;

    return modePointer;
}

/**
 * Returns a random integer between specified values.
 * @param lowerBound the lower bound; included
 * @param upperBound the upper bound; included
 * @return a random integer between specified values.
 */
int randBetween(int lowerBound, int upperBound) {
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}

/**
 * Reads a number.
 * @return a number read
 */
int readNumber(string prompt, ostream &os, istream &in) {
    int number;
    os << prompt;
    in >> number;

    return number;
}

/**
 * Reads a positive number.
 * @return a whole number read
 */
int readPositiveNumber(string prompt, ostream &os, istream &in) {
    int number = readNumber(prompt, os, in);

    while (number <= 0) {
        os << "You should enter a positive number. ";
        number = readNumber(prompt, os, in);
    }

    return number;
}

/**
 * Returns the length of an integer; the negative sign counts.
 * @param number
 * @return the length of an integer; the negative sign counts.
 */
int getLengthOfInt(int number) {
    int len = 0;

    if (number < 0) {
        len++;
        number = -number;
    }

    while (number > 0) {
        number /= 10;
        len++;
    }

    return len;
}