/**
 * @author James Chan (Zhuojian Chen)
 */

#include "generateData.h"
#include <fstream>
#include <iomanip>
#include "constant.h"
#include "helper.h"

using namespace std;

/**
 * Generates random data and output them into the target file.
 * @param filename filename/filepath of the target file
 * @return
 */
int generateData(string filename) {
    // create and open a text file
    ofstream fileOutputStream(filename);

    int rowNumber = generateInt(MIN_ROW_NUMBER, MAX_ROW_NUMBER);
    for (int i = 0; i < rowNumber; ++i) {
        int *row = generateRow();
        for (int j = 0; j < ROW_LENGTH; ++j) {
            fileOutputStream << setw(CELL_WIDTH_FILE) << row[j];
        }
        fileOutputStream << setw(CELL_WIDTH_FILE) << sum(row, ROW_LENGTH) << endl;
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
 * Generates a row.
 * @return a row
 */
int *generateRow() {
    static int row[ROW_LENGTH];

    for (int i = 0; i < ROW_LENGTH; i++) {
        row[i] = generateInt(RAND_NUMBER_LOWER_BOUND, RAND_NUMBER_UPPER_BOUND + 1);
    }

    return row;
}