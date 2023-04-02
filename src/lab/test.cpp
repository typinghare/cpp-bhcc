#include <iostream>
#include <fstream>

using namespace std;

struct Date {
    short year;     // format: YYYY
    short month;    // format: mm
    short day;      // format: dd
};

Date randDate() {
    Date date = {1,2,3};

    return date;
}

int main() {
    // sequential reading and writing
    ofstream file1("sequential.dat", std::ios::binary);
    char data[] = {'o', 'p', 'e', 'n', 'a', 'i'};
    file1.write(data, sizeof(data));
    file1.close();

    // random access reading and writing
    fstream file2("random_access.dat", std::ios::in | std::ios::out | std::ios::binary);
    file2.seekp(3, ios::beg);	// skips three bytes from the beginning
    file2.write(data, sizeof(data));
    file2.close();
}