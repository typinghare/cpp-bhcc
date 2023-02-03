#include <fstream>
#include <sstream>
#include "readData.h"
#include "helper.h"

using namespace std;

int **readData(string filename) {
    const int MAX_ROW{125}, ROW_LENGTH{20};

    // create a 125x20 2D array
    int **matrix = new int *[MAX_ROW];
    for (int i = 0; i < MAX_ROW; ++i) matrix[i] = new int[ROW_LENGTH];

    ifstream fileInputStream(filename);

    string line;
    int row = 0, num, count = 0;
    while (getline(fileInputStream, line) && count < MAX_ROW) {
        istringstream istream(line);
        for (int col = 0; col < ROW_LENGTH; col++) {
            istream >> num;
            matrix[row][col] = num;
        }

        // check the summation
        if (istream) {
            int originalSum;
            istream >> originalSum;
            if (originalSum != sum(matrix[row], ROW_LENGTH)) {
                cout << "The summation is incorrect!" << endl;
                throw exception();
            }
        } else {
            cout << "" << endl;
            throw exception();
        }

        row++;
        count++;
    }

    fileInputStream.close();

    return matrix;
}