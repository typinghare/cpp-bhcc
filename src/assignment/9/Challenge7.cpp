/**
 * @author Zhuojian Chen (James)
 * @date May 2, 2023
 *
 * @requirement
 * Write a class named TestScores. The class constructor should accept an array of test scores as
 * its argument. The class should have a member function that returns the average of the test scores.
 * If any test score in the array is negative or greater than 100, the class should throw an exception.
 * Demonstrate the class in a program.
*/

#include <iostream>
#include "TestScores.h"

using namespace std;

/**
 * Test the "TestScores" class.
 * @return
 */
int main() {
    const int numScores = 5;
    float scores[numScores] = {86.5, 90.0, 95.5, 82.0, 84.5};
    TestScores testScores(scores, numScores);

    float average = testScores.getAverage();
    cout << "The average score is: " << average << endl;
}