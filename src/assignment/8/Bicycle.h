#ifndef BHCC_CPP_BICYCLE_H
#define BHCC_CPP_BICYCLE_H

#include "Transportation.h"

/**
 * Bicycle extends Transportation.
 */
class Bicycle : public Transportation {
public:
    std::string toString() override;

    std::string getType() override { return "Bicycle"; }

    // Because the bicycle cannot go backward, here we should override this method.
    void backward() override {
        std::cout << getType() << " cannot go backward." << std::endl;
    }
};

#endif