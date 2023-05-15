/**
 * @author Zhuojian Chen (James)
 * @date May 11, 2023
*/

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

static int ctr = 0;

/**
 * Finds the greatest common divisor of two numbers (u and v).
 */
int gcd(int u, int v) {
    ctr++;

    return v == 0 ? u : gcd(v, u % v);
//    int t = u < v ? u : v;
//
//    while (u % t != 0 || v % t != 0) t--;
//
//    return t;
}

int main() {
    // 461952 116298

    while (true) {
        int x, y;
        cout << "Please input two numbers: ";
        cin >> x >> y;

        cout << "The greatest common divisor of " << x
             << " and " << y << " is: " << gcd(x, y) << endl;

        cout << "The number of times the gcd() function executed: " << ctr << endl;
    }
}


#pragma clang diagnostic pop