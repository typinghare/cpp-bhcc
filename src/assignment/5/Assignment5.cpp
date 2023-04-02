/**
* @author Zhuojian Chen (James)
*/

/**
 * @requirement
 * Create a program that implements a checkbook structure:
 * [Checkbook]                          [Comment]
 * date: Date
 * depositOrWithdrawAmount: double      amount deposited(+) or withdrawn(-)
 * currentBalance: double               balance after withdrawal or deposit
 *
 * 1. Start with a deposit of 10.00, then create 10 random deposit and withdrawal amounts.
 * 2. Create a function that deposits money, and a function that withdraws money.
 *    Make sure you do not withdraw more money than you have in the checkbook.
 *    Each time, write the structure to a text file and to a binary file.
 * 3. When done, close both files.
 * 4. Read the data back from the binary file to the console from a function.
 * 5. Check for errors reading and writing the files.
 * 6. Open the files again to add 10 more random deposits and withdrawals. Again, close both files.
 *    Read the binary file in reverse and print it to the console.
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Date structure.
 */
struct Date {
    short year;     // format: YYYY
    short month;    // format: mm
    short day;      // format: dd
};

/**
 * Checkbook structure.
 */
struct Checkbook {
    Date date;                      // transfer date
    double depositOrWithdrawAmount; // amount deposited(+) or withdrawn(-)
    double currentBalance;          // balance after withdrawal or deposit
};

Checkbook deposit(double &balance, Date date, double moneyToDeposit);

Checkbook withdraw(double &balance, Date date, double moneyToWithdraw);

void writeToTextFile(Checkbook checkbook, string filepath);

void writeToBinaryFile(Checkbook checkbook, string filepath);

Checkbook *readCheckbooksFromBinaryFile(string filepath, int size);

void printCheckbook(Checkbook checkbook, ostream &os);

// custom functions
int randInt(int lower, int upper);

double randDouble(double lower, double upper);

Date randDate(Date lower);

int main() {
    srand(time(nullptr));

//    string textFilepath = "../resource/checkbook.txt";
//    string binaryFilepath = "../resource/checkbook.dat";
    string textFilepath = "";
    string binaryFilepath = "";

    while (textFilepath == "") {
        cout << "Please input the filepath of the text file: ";
        cin >> textFilepath;
        if (!filesystem::exists(textFilepath)) {
            cout << "The file does not exist." << endl;
            textFilepath = "";
        }
    }

    while (binaryFilepath == "") {
        cout << "Please input the filepath of the binary file: ";
        cin >> binaryFilepath;
        if (!filesystem::exists(binaryFilepath)) {
            cout << "The file does not exist." << endl;
            binaryFilepath = "";
        }
    }

    double balance = 0.0;
    Date date = {2023, 3, 12};

    // Part I: start with a deposit of 10.00
    Checkbook checkbook = deposit(balance, date, 10.00);
    writeToTextFile(checkbook, textFilepath);
    writeToBinaryFile(checkbook, binaryFilepath);
    Checkbook *checkbooks = readCheckbooksFromBinaryFile(binaryFilepath, 1);
    printCheckbook(checkbooks[0], cout);

    // Part II: create 10 random deposit and withdrawal amounts.
    for (int i = 0; i < 10; ++i) {
        date = randDate(date);
        double moneyChange = randDouble(0.00, 10.0);

        Checkbook _checkbook =
                randInt(0, 1) == 0 ?
                deposit(balance, date, moneyChange) :
                withdraw(balance, date, moneyChange);

        if (_checkbook.currentBalance != -1) {
            writeToTextFile(_checkbook, textFilepath);
            writeToBinaryFile(_checkbook, binaryFilepath);
        }
    }

    Checkbook *checkbooks2 = readCheckbooksFromBinaryFile(binaryFilepath, 11);
    for (int i = 1; i < 11; ++i) {
        printCheckbook(checkbooks2[i], cout);
    }

    // release
    delete[] checkbooks;
    delete[] checkbooks2;
}

/**
 * Deposits money.
 * @param balance balance
 * @param date the date to deposit
 * @param moneyToDeposit money to deposit
 * @return
 */
Checkbook deposit(double &balance, Date date, double moneyToDeposit) {
    Checkbook checkbook = Checkbook();

    checkbook.date = date;
    checkbook.depositOrWithdrawAmount = moneyToDeposit;
    checkbook.currentBalance = balance = balance + moneyToDeposit;

    return checkbook;
}

/**
 * Withdraws money.
 * @param balance
 * @param date
 * @param moneyToWithdraw
 */
Checkbook withdraw(double &balance, Date date, double moneyToWithdraw) {
    Checkbook checkbook = Checkbook();

    if (moneyToWithdraw > balance) {
        cout << "Insufficient balance." << endl;
        return {{}, 0, -1};
    }

    checkbook.date = date;
    checkbook.depositOrWithdrawAmount = -moneyToWithdraw;
    checkbook.currentBalance = balance = balance - moneyToWithdraw;

    return checkbook;
}

/**
 * Write a checkbook to the specified text file.
 * @param checkbook
 * @param filepath
 */
void writeToTextFile(Checkbook checkbook, string filepath) {
    stringstream ss;
    ss << checkbook.date.year << ","
       << checkbook.date.month << ","
       << checkbook.date.day << ","
       << checkbook.depositOrWithdrawAmount << ","
       << checkbook.currentBalance << endl;

    ofstream file(filepath, ios_base::app);

    file << ss.str();
    file.close();   // close file when done
}

/**
 * Write a checkbook to the specified binary file.
 * @param checkbook
 * @param filepath
 */
void writeToBinaryFile(Checkbook checkbook, string filepath) {
    ofstream file(filepath, ios::binary | ios_base::app);

    file.write(reinterpret_cast<char *>(&checkbook), sizeof(checkbook));
    file.close();   // close file when done
}

/**
 * Reads checkbooks from a specified binary file and returns an array of checkbook.
 * @param filepath
 * @param size
 * @return
 */
Checkbook *readCheckbooksFromBinaryFile(string filepath, int size) {
    Checkbook *checkbooks = new Checkbook[size];

    ifstream file(filepath);

    int numCheckbooks = 0;
    while (file.read(reinterpret_cast<char *>(&checkbooks[numCheckbooks]), sizeof(Checkbook))) {
        if (numCheckbooks > size) {
            cerr << "Not enough checkbook to read." << endl;
            break;
        }

        ++numCheckbooks;
    }

    return checkbooks;
}

/**
 * Prints a checkbook.
 * @param checkbook
 * @param os
 */
void printCheckbook(Checkbook checkbook, ostream &os) {
    const double mc = checkbook.depositOrWithdrawAmount;

    const int day = checkbook.date.day, month = checkbook.date.month;
    const string dayStr = day > 10 ? to_string(day) : "0" + to_string(day);
    const string monthStr = month > 10 ? to_string(month) : "0" + to_string(month);

    os << "[" << checkbook.date.year << "." << monthStr << "." << dayStr << "] "
       << (mc > 0 ? "Deposit=" : "Withdraw=") << abs(mc) << "; Balance="
       << checkbook.currentBalance << "." << endl;
}

/**
 * Returns a random integer between specified values.
 * @param lower the lower bound; included
 * @param upper the upper bound; included
 * @return a random integer between specified values.
 */
int randInt(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

/**
 * Returns a random double number between specified bounds.
 * @param lower the lower bound; included
 * @param upper the upper bound; excluded
 * @return a random double number between specified values; the value keeps 2 decimal places.
 */
double randDouble(double lower, double upper) {
    return (double) randInt(lower * 100, upper * 100) / 100;
}

/**
 * Returns a random date after the given date.
 * @param lower a given date
 * @return a random date after the given date.
 */
Date randDate(Date lower) {
    static const int dayInMonths[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    const int dayNum = randInt(0, 10);  // number of days to add on the `lower`
    int day = lower.day + dayNum;
    int month = lower.month;
    int year = lower.year;
    int dayInMonth = dayInMonths[lower.month - 1];

    if (day > dayInMonth) {
        day = day % dayInMonth;
        month++;
    }

    if (month > 12) {
        month = 1;
        year++;
    }

    Date date = Date();
    date.year = year;
    date.month = month;
    date.day = day;

    return date;
}