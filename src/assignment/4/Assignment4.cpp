/**
 * @author James (Zhuojian Chen)
 * @date Mar 16, 2022
*/

/**
 * @requirement
 * 1. Create 2 accounts for Selena Gomes, a Savings account with $50 in it with an interest rate of
 * 0.1%, and a checking account with $500 in it and 0% interest rate. Savings interest is calculated
 * as simple interest - Simple Interest for n months = (P × n × R)/ (12 × 100) assuming the P = amount,
 * n = numbers of months, R is rate as percent. Create a single function in your program that deposits
 * to a savings or a checking account.
 * 2. Create a single function in your program to withdraw from a savings or a checking account.
 * A customer must not be able to withdraw more than the balance of their account.
 * If they try to withdraw more than in the account, the function should return -1, otherwise it
 * should return the current balance in the account.
 * 3. Create a single function in your program to update the interest in an account - one parameter
 * is the number of months.
 * 4. Create a function to print the account
 * 5. Create an array of 3 savings accounts. They should have a random starting balance between
 * $75 and $200. They should all have the same interest rate, but different account numbers.
 * Add $10 to each account and withdraw $150 from each account.
 * Print out the accounts using your print function.
 */

#include <iostream>

using namespace std;

struct Account {
    string accountNumber;   // 6 digits, can start with 0
    string ownerName;       // the name of the owen of this account
    char accountType;       // S = savings, C = checking
    double rate;            // (annual) interest rate
    double balance;         // unit: dollar
};

double deposit(Account *account, double money);

double withdraw(Account *account, double money);

void updateAccountInterest(Account *account, int numMonths);

void printAccount(Account *account, ostream &os);

int randBetween(int lowerBound, int upperBound);

string generateAccountNumber();

int main() {
    srand(time(nullptr));

    // create a savings account and checking account for Selena Gomes
    Account savingsAccount = Account();
    savingsAccount.accountType = 'S';
    savingsAccount.balance = 50;
    savingsAccount.rate = 0.001;

    Account checkingAccount = Account();
    checkingAccount.accountType = 'C';
    checkingAccount.balance = 500;
    checkingAccount.rate = 0.0;

    // create an array of three savings accounts
    const int NUM_ACCOUNT = 3;
    const double ACCOUNT_BALANCE_MIN = 75.0;
    const double ACCOUNT_BALANCE_MAX = 200.0;
    const double INTEREST_RATE = 0.004; // 4%
    Account **accountArray = new Account *[NUM_ACCOUNT];

    for (int i = 0; i < NUM_ACCOUNT; ++i) {
        Account *account = new Account();
        account->accountNumber = "";
        account->accountType = 'S';
        account->rate = INTEREST_RATE;
        account->balance = randBetween(ACCOUNT_BALANCE_MIN, ACCOUNT_BALANCE_MAX);
        accountArray[i] = account;
    }

    accountArray[0]->ownerName = "Jackson";
    accountArray[1]->ownerName = "Emma";
    accountArray[2]->ownerName = "Noah";

    // print all the savings accounts
    cout << "Before deposit and withdrawal:" << endl;
    for (int i = 0; i < NUM_ACCOUNT; ++i) {
        cout << "[Account " << i + 1 << " information]" << endl;
        printAccount(accountArray[i], cout);
        cout << endl;
    }

    // deposit $10 to and withdraw $150 from each account
    for (int i = 0; i < NUM_ACCOUNT; ++i) {
        deposit(accountArray[i], 10);
        withdraw(accountArray[i], 150);
    }

    // print all the savings accounts
    cout << "After deposit and withdrawal:" << endl;
    for (int i = 0; i < NUM_ACCOUNT; ++i) {
        cout << "[Account " << i + 1 << " information]" << endl;
        printAccount(accountArray[i], cout);
        cout << endl;
    }

    // release
    for (int i = 0; i < NUM_ACCOUNT; ++i) delete[] accountArray[i];
    delete[] accountArray;
}

/**
 * Allows a user to deposit.
 * @param account user's account
 * @param money the money to deposit
 * @return the balance of the account after deposit; -1 if the money given is a non-positive number.
 */
double deposit(Account *account, double money) {
    if (money <= 0) {
        cout << "The money to deposit should be a positive number." << endl;
        return -1;
    }

    account->balance += money;
    return account->balance;
}

/**
 * Allows a user to withdraw money.
 * @param account user's account
 * @param money money to withdraw
 * @return the balance of the account after withdrawal; -1 if the money to withdraw is
 * greater than the balance.
 */
double withdraw(Account *account, double money) {
    if (money > account->balance) return -1;

    account->balance -= money;
    return account->balance;
}

/**
 * Updates the interest of an account.
 * @param account the account to update interest
 * @param numMonths the number of months
 */
void updateAccountInterest(Account *account, int numMonths) {
    double interest = (account->balance * numMonths * account->rate) / 12000;

    account->balance += interest;
}

/**
 * Print the information of an account.
 * @param account account to print
 */
void printAccount(Account *account, ostream &os) {
    // we assume that the type of the account it either 'S' or 'C'
    string accountType = account->accountType == 'S' ? "Savings Account" : "Checking Account";

    os << "Account number: " << account->accountNumber << endl
       << "Owner name: " << account->ownerName << endl
       << "Account type: " << accountType << endl
       << "Interest rate: " << account->rate << endl
       << "Balance: " << account->balance << endl;
}

/**
 * Returns a random integer between specified values.
 * @param lowerBound the lower bound; included
 * @param upperBound the upper bound; included
 * @return a random integer between specified values.
 */
int randBetween(int lowerBound, int upperBound) {
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}