/**
 * @author Zhuojian Chen (James)
 * @date May 2, 2023
 *
 * @requirement
 * Write a template for a function called total. The function should keep a running total of values
 * entered by the user, then return the total. The argument sent into the function should be the
 * number of values the function is to read. Test the template in a simple driver program that sends
 * values of various types as arguments and displays the results.
*/

#include <iostream>

using namespace std;

/**
 * Prompts users to input a series of number, and returns the summation of the numbers.
 * @tparam T the type of the numbers (int, float, double, ...).
 * @param count the number of numbers to prompt the user to input.
 */
template<typename T>
T total(int count) {
    T sum = 0;
    for (int i = 0; i < count; ++i) {
        T num;
        cout << "Please input the number " << (i + 1) << ": ";
        cin >> num;
        sum += num;
    }

    return sum;
}

/**
 * Test.
 */
int main() {
    int intSum = total<int>(2);
    cout << "The total of two integers: " << intSum << endl;

    float floatSum = total<float>(3);
    cout << "The total of three float numbers: " << floatSum << endl;

    double doubleSum = total<double>(4);
    cout << "The total of four double numbers: " << doubleSum << endl;

    return 0;
}