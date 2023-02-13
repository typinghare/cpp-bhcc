#include <iostream>
#include <fstream>

using namespace std;

int *createArray(int size);

int *createArray(int size);

void fillArray(int *array, int size, int lowerBound, int upperBound);

void printArray(int *array, int size, ostream &os);

void sortArray(int *array, int size);

double *findMedian(int *array, int size);

int findMode(int *array, int size);

int randBetween(int lowerBound, int upperBound);

void readWholeNumber(string prompt, ostream &os, istream &in, int &number);

int main() {
    // set a random seed
    srand(time(nullptr));

    int size, lowerBound, upperBound;
    readWholeNumber("Please enter the length of the array: ", cout, cin, size);
    readWholeNumber("Please enter the lower bound of random numbers (whole number): ", cout, cin, lowerBound);
    readWholeNumber("Please enter the upper bound of random numbers (whole number): ", cout, cin, upperBound);

    while (upperBound < lowerBound) {
        cout << "The upper bound should be greater than the lower bound (" << lowerBound << ")!" << endl;
        readWholeNumber("Please enter the upper bound of random numbers (whole number): ", cout, cin, upperBound);
    }

    int *array = createArray(size);
    cout << "The array has been created. Filling the array with random numbers between "
         << lowerBound << " and " << upperBound << "." << endl;
    fillArray(array, size, lowerBound, upperBound);

    // print the array
    cout << "The array is as follows: " << endl;
    printArray(array, size, cout);
    cout << "The size of this array is: " << size << endl;

    // test findMode()
    int mode = findMode(array, size);
    if (mode == -1) {
        cout << "The mode does not exist." << endl;
    } else {
        cout << "The mode of this array is: " << mode << endl;
    }

    // test findMedian()
    double *median = findMedian(array, size);
    cout << "The median of this array is: " << *median << endl;

    // free memory
    free(median);
    delete[] array;
}

/**
 * Returns a dynamic integer array of specified size.
 * @param size the size of the array; should be whole number
 * @return a dynamic integer array of specified size.
 */
int *createArray(int size) {
    if (size < 0) {
        cout << "The size of the array should be a whole number.";
        // 1: indicates abnormal termination of a program perhaps as a result a minor problem in the code
        exit(1);
    }

    return new int[size];
}

/**
 * Fills an array with random values between specified values.
 * @param array the array to operate
 * @param size the size of the array.
 */
void fillArray(int *array, int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        array[i] = randBetween(lowerBound, upperBound);
    }
}

/**
 * Prints an array in a pretty way.
 * @param array
 * @param size
 * @param os
 */
void printArray(int *array, int size, ostream &os) {
    // improvement: the width of cells is determined by the longest number
    int longestLength = 0;
    for (int i = 0; i < size; ++i) {
        int length = to_string(array[i]).length();
        if (length > longestLength) longestLength = length;
    }

    int column = 0;
    for (int i = 0; i < size; ++i) {
        os << setw(longestLength + 1) << array[i];
        if (++column >= 10) {
            column = 0;
            os << endl;
        }
    }

    os << endl;
}

/**
 * Sorts an array in ascending order.
 * @param array the array to sort
 * @param size the size of the array
 */
void sortArray(int *array, int size) {
    sort(array, array + size);
}

/**
 * Returns the median of an array.
 * @param array the array to find the median
 * @param size the size of the array
 * @return the pointer of a double variable.
 */
double *findMedian(int *array, int size) {
    // first sort the array
    sortArray(array, size);

    double *median = (double *) (malloc(sizeof(double)));

    if (size % 2 == 1) {
        // the size is an odd number
        *median = array[size / 2];
    } else {
        // the size is an even number
        *median = ((double) array[size / 2] + array[size / 2 - 1]) / 2;
    }

    return median;
}

/**
 * Returns the mode of an array.
 * @param array array to find the mode
 * @param size the size of the array.
 * @return the mode of an array.
 */
int findMode(int *array, int size) {
    // first sort the array
    sortArray(array, size);

    int num[size], frequency[size], pos = 0;
    num[0] = array[0];
    frequency[0] = 1;
    for (int i = 1; i < size; ++i) {
        if (array[i] == num[pos]) {
            frequency[pos]++;
        } else {
            pos++;
            num[pos] = array[i];
            frequency[pos] = 1;
        }
    }

    int mode = num[0], maxFrequency = frequency[0];
    for (int i = 1; i < pos; ++i) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mode = num[i];
        }

    }

    return maxFrequency == 1 ? -1 : mode;
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
 * Reads a whole number.
 */
void readWholeNumber(string prompt, ostream &os, istream &in, int &number) {
    os << prompt;
    in >> number;

    while (number < 0) {
        os << "You should enter a whole number. " << prompt;
        in >> number;
    }
}