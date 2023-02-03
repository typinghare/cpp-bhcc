#include <fstream>
#include "generateData.h"
#include "helper.h"

using namespace std;

int generateData(const string filename) {
    // create and open a text file
    ofstream fileOutputStream(filename);

    const int ROW_LENGTH{20};
    int rowNumber = generateInt(30, 125);
    for (int i = 0; i < rowNumber; ++i) {
        int *row = generateRow();
        for (int j = 0; j < ROW_LENGTH; ++j) {
            fileOutputStream << setw(5) << row[j];
        }
        fileOutputStream << setw(5) << sum(row, ROW_LENGTH) << endl;
    }

    fileOutputStream.close();

    return rowNumber;
}

/**
 * Generates a random integer.
 * @param lowerBound the lower bound; included
 * @param upperBound the upper bound; excluded
 * @return
 */
int generateInt(int lowerBound, int upperBound) {
    return rand() % (upperBound - lowerBound) + lowerBound;
}

/**
 * Generates an integer array of length 20.
 * @return an integer array of length 20
 */
int *generateRow() {
    const int ROW_LENGTH{20};
    static int row[ROW_LENGTH];

    for (int i = 0; i < ROW_LENGTH; i++) {
        row[i] = generateInt(-50, 50);
    }

    return row;
}