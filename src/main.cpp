#include <iostream>
#include <cmath>

using namespace std;

int getMax(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int main() {
    float a;

    cout << getMax(1, 2);

    return 0;
}