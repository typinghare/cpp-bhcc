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
 * @return
 */
void readData(std::string filename, int matrix[][ROW_LENGTH]) {
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
            if (checkSum != sum(matrix[row], ROW_LENGTH)) {
                cout << "The summation is incorrect!" << endl;
                throw exception();
            }
        } else {
            cout << "Missing the check sum number!" << endl;
            throw exception();
        }

        row++;
        count++;
    }

    fileInputStream.close();
}