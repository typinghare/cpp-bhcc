#ifndef BHCC_CPP_TESTSCORES_H
#define BHCC_CPP_TESTSCORES_H

#endif

class TestScores {
private:
    int length;
//    float scores[];   // does not work.
    float *scores;  // It must be written like this.

    /**
     * Checks whether a score is legal. A score is legal if and only if it is not less than 0 and
     * not greater than 100.
     * @throw an exception if the score is not legal.
     */
    void checkScore(float score);

public:
    /**
     * Create a TestScores.
     * @param scores an array of test scores.
     * @param the length of the scores array.
     */
    TestScores(float scores[], int length);

    /**
     * Returns the average of the scores.
     * @return the average of the scores.
     */
    float getAverage();
};