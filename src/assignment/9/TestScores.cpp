
#include <iostream>
#include "TestScores.h"

using namespace std;

TestScores::TestScores(float scores[], int length) {
    this->scores = new float[length];
    for (int i = 0; i < length; ++i) {
        checkScore(scores[i]);
        this->scores[i] = scores[i];
    }

    this->length = length;
}

void TestScores::checkScore(float score) {
    if (score < 0 || score > 100) {
        throw new exception();
    }
}

float TestScores::getAverage() {
    float sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += scores[i];
    }

    return sum / length;
}