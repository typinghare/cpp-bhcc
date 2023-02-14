/**
 * @author James Chan (Zhuojian Chen)
 */

#include <fstream>
#include <sstream>
#include "readData.h"
#include "helper.h"
#include "constant.h"

using namespace std;

/**
 * Reads the target file and return a data matrix.
 * @param filename filename/filepath of the target file
 * @note Not using the dynamic 2d array; use static 2d array instead
 * @return the number of line read
 */
int readData(std::string filename, int matrix[][ROW_LENGTH]) {
    ifstream fileInputStream(filename);

    string line;
    int row = 0, num, count = 0;
    while (getline(fileInputStream, line) && count < MAX_ROW_NUMBER) {
        istringstream istream(line);
        for (int col = 0; col < ROW_LENGTH; col++) {
            istream >> num;
            matrix[row][col] = num;
        }

        // check the summation
        if (istream) {
            int checkSum;
            istream >> checkSum;
            int realSum = sum(matrix[row], ROW_LENGTH);
            if (checkSum != realSum) {
                cout << "[Report] The checksum is incorrect!"
                     << "It is expected to be " << realSum << ", "
                     << checkSum << "is given." << endl;
            }
        } else {
            cout << "[Report] Missing the checksum number!" << endl;
        }

        row++;
        count++;
    }

    fileInputStream.close();

    return row;
}