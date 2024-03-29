/**
 * @author James Chan (Zhuojian Chen)
 */

#include <iostream>
#include <filesystem>
#include "helper.h"
#include "generateData.h"
#include "readData.h"
#include "constant.h"

using namespace std;

int main() {
    srand(time(nullptr));   // set the global random seed
    string filename = NAME + ".txt";    // filename of the data file

    // generate data
    int rowNumWrote = generateData(filename);
    cout << "Generated file \"" << filename << "\" and randomly wrote "
         << rowNumWrote << " lines. "
         << "(" << filesystem::absolute(filesystem::path(filename)) << ")" << endl;

    // read data
    int matrix[MAX_ROW_NUMBER][ROW_LENGTH];
    int rowNum = readData(filename, matrix);

    // find the maximum and minimum value of each row
    int maxArray[MAX_ROW_NUMBER], minArray[MAX_ROW_NUMBER];
    for (int row = 0; row < rowNum; ++row) {
        maxArray[row] = maxOfArray(matrix[row], ROW_LENGTH);
        minArray[row] = minOfArray(matrix[row], ROW_LENGTH);
    }
    cout << "The maximum value of each row of the array: " << arrayToString(maxArray, rowNum) << endl;
    cout << "The minimum value of each row of the array: " << arrayToString(minArray, rowNum) << endl;

    // find the maximum and minimum value of the whole data file
    cout << "The maximum value of the data file: " << maxOfArray(maxArray, rowNum) << endl;
    cout << "The minimum value of the data file: " << minOfArray(minArray, rowNum) << endl;

    // find the number of zeros in the file
    int numberOfZero = 0;
    for (int row = 0; row < rowNum; ++row) {
        numberOfZero += count(matrix[row], ROW_LENGTH, 0);
    }
    cout << "There are " << numberOfZero << " zeros in the file." << endl;

    // print data
    cout << "The following is the generated two dimensional array:" << endl;
    print2DArray(matrix, rowNum, cout);
}