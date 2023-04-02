#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
struct Date {
    short month; // 2
    short day; // 2
    short year; // 2
};
struct Temperatures {
    Date date; // 6
    double temperature; // 8
}; // 16 bytes !!

void printData(Temperatures temps[], int num);
void printData(Temperatures temps[], int num, fstream& out);

int main() {
    Temperatures* temperatures;
    string filename {"tempdata.dat"};
    fstream inFile(filename, ios::binary | ios::in);

    int sizeTemps = sizeof(Temperatures);

// find out how large the file is..
    inFile.seekg(0L,ios_base::end);
    int nbytes = inFile.tellg();
    int numStructs = nbytes/sizeTemps;
    cout << "There are " << numStructs << " structs in the file" << endl;
    
    
    temperatures = new Temperatures[numStructs];
    inFile.seekg(0L,ios::beg);
    
    for (int i =0; i < numStructs; i++) {
        inFile.read(reinterpret_cast<char*>(&temperatures[i]),
             sizeof(Temperatures));
    }
    printData(temperatures, numStructs);
    inFile.close();
    delete[] temperatures;
    return 0;

}
void printData(Temperatures temps[], int num) {
    cout << setfill('0') << fixed << setprecision(2);
    for (int i = 0; i < num; i++) {
        cout << temps[i].date.month << '/' 
            << setw(2) << temps[i].date.day  << '/' 
            << temps[i].date.year << " " << setw(5) 
            << temps[i].temperature << endl;
    }
}
void printData(Temperatures temps[], int num, fstream& out) {
    for (int i = 0; i < num; i++) {
        out.write(reinterpret_cast<char*>(&temps[i]),
             sizeof(Temperatures));
    }
}

/* the old way */
void printData(const short month[],const short day[],const  short year[],const double temperature[], int num) {
    cout << setfill('0') << fixed << setprecision(2);
    for (int i = 0; i < num; i++) {
        cout << month[i] << '/' << setw(2) 
        << day[i] << '/' << year[i] << " " 
        << setw(6) << temperature[i] << endl;
    }

}