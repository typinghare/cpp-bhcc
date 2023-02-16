/**
 * @author James Chan (Zhuojian Chen)
 */


#include <iomanip>
#include "helper.h"
#include "constant.h"

using namespace std;

/**
 * Returns the number of times a specified number occurs in an integer array.
 * @param array the given array to search for
 * @param length the length of the array
 * @param number the number to find
 * @return the number of times a specified number occurs in the array
 */
int count(int array[], int length, int number) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == number) count++;
    }

    return count;
}

/**
 * Returns the maximum value of a given array of double numbers.
 * @param array the given array to search for
 * @param length the length of the array
 * @return the maximum value of the given array.
 */
double maxOfArray(double array[], int length) {
    double max = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] > max) max = array[i];
    }

    return max;
}

/**
 * Returns the maximum value of a given array of integer numbers.
 * @param array the given array to search for
 * @param length the length of the array
 * @return the maximum value of the given array.
 */
int maxOfArray(int array[], int length) {
    int max = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] > max) max = array[i];
    }

    return max;
}

/**
 * Returns the minimum value of a given array of integer numbers.
 * @param array the given array to search for
 * @param length the length of the array
 * @return the minimum value of the given array.
 */
int minOfArray(int array[], int length) {
    int min = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] < min) min = array[i];
    }

    return min;
}

/**
 * Returns the summation of an array of integer.
 * @param array the array to aggregate
 * @param length the length of the array.
 * @return
 */
int sum(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }

    return sum;
}

/**
 * Converts an integer array to a string
 * @param array the array to convert
 * @param length the length of the array
 * @return
 */
string arrayToString(int array[], int length) {
    string str = to_string(array[0]);

    for (int i = 1; i < length; ++i) {
        str += ", " + to_string(array[i]);
    }

    return str;
}

/**
 * Prints a two-dimensional array.
 * @param matrix the two-dimensional array to print
 * @param rowNum the number of row in the array
 */
void print2DArray(int matrix[][ROW_LENGTH], int rowNum, ostream &os) {
    for (int row = 0; row < rowNum; ++row) {
        string label = string("[") + to_string(row + 1) + "]";

        os << setw(5) << label;
        for (int col = 0; col < ROW_LENGTH; ++col) {
            os << setw(CELL_WIDTH_PRINT) << matrix[row][col];
        }

        os << endl;
    }
}