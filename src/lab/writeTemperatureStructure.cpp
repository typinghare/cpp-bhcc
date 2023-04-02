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
    Temperatures todaysTemp = { {3, 7, 2023}, 45};
    Temperatures* temperatures;
    temperatures = &todaysTemp;
    string filename {"tempdata.dat"};
    fstream outFile(filename, ios::binary | ios::out);

    cout << "The size of the Temps struct: " << sizeof(Temperatures) << endl;

    cout << temperatures->temperature << endl; // dereference
    cout << (* temperatures).temperature << endl; // other deref
    
    int nValues;
    cout << "Enter the number of dates and high temperatures you want to record: ";
    cin >> nValues;
    temperatures = new Temperatures[nValues];
    for (int i =0; i < nValues; i++) {
        cout << "Enter date (month, day, year) and high temp: ";
        cin >> temperatures[i].date.month 
        >> temperatures[i].date.day
        >> temperatures[i].date.year
        >> temperatures[i].temperature;
    }
    printData(temperatures, nValues);
    printData(temperatures, nValues, outFile);
    outFile.close();
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