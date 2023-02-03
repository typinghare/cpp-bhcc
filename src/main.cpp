#include <iostream>
#include <filesystem>
#include "assignment/1/helper.h"
#include "assignment/1/generateData.h"
#include "assignment/1/readData.h"

using namespace std;

int main() {
    srand(time(nullptr));   // set the global random seed

    const string NAME = "JamesChan";    // my preferred name (my legal name is "ZhuojianChen")
    const int ROW_LENGTH = 20;

    string filename = NAME + ".txt";    // filename of the data file

    // generate data
    int rowNum = generateData(filename);
    cout << "Generated file \"" << filename << "\" and randomly wrote "
         << rowNum << " lines. "
         << "(" << filesystem::absolute(filesystem::path(filename)) << ")" << endl;

    // read data
    int **matrix = readData(filename);

    // find the maximum and minimum value in the array
//    int maxNum = matrix[0][0], minNum = matrix[0][0];
//    for (int row = 0; row < rowNum; ++row) {
//        for (int col = 0; col < ROW_LENGTH; ++col) {
//            int num = matrix[row][col];
//            if (num > maxNum) maxNum = num;
//            if (num < minNum) minNum = num;
//        }
//    }
//    cout << "The maximum value of the array is: " << maxNum << "." << endl;
//    cout << "The minimum value of the array is: " << minNum << "." << endl;

    // find the maximum and minimum value of each row
    int maxArray[125], minArray[125];
    for (int row = 0; row < rowNum; ++row) {
        maxArray[row] = maxOfArray(matrix[row], ROW_LENGTH);
        minArray[row] = minOfArray(matrix[row], ROW_LENGTH);
    }
    cout << "The maximum values of each row of the array: " << arrayToString(maxArray, ROW_LENGTH) << endl;
    cout << "The minimum values of each row of the array: " << arrayToString(minArray, ROW_LENGTH) << endl;

    // find the number of zeros in the file
    int numberOfZero = 0;
    for (int row = 0; row < rowNum; ++row) {
        for (int col = 0; col < ROW_LENGTH; ++col) {
            if (matrix[row][col] == 0) numberOfZero++;
        }
    }
    cout << "There are " << numberOfZero << " zeros in the file." << endl;

    // print data
    cout << "The following is the generated two dimensional array:" << endl;
    print2DArray(matrix, rowNum, ROW_LENGTH);
}