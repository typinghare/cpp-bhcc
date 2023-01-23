//
// Created by James Chan on 1/18/23.
//

#include <iostream>

using namespace std;

int study_read() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Your name is " << name;

    return 0;
}