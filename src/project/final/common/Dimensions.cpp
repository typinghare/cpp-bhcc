#include "Dimensions.h"
#include <string>
#include "../util/helper.h"

void Dimensions::checkMemberVariables() {
    if (width <= 0) {
        throw new std::invalid_argument("The width should be a positive integer!");
    }

    if (height <= 0) {
        throw new std::invalid_argument("The height should be a positive integer!");
    }
}

Dimensions::Dimensions(double width, double height) {
    this->width = width;
    this->height = height;

    checkMemberVariables();
}

const std::string Dimensions::toString() const {
    return std::to_string(height) + "ft × " + std::to_string(width) + "ft";
}

std::istream &operator>>(std::istream &is, Dimensions &dimensions) {
    is >> dimensions.width >> dimensions.height;

    dimensions.checkMemberVariables();

    return is;
}

std::ostream &operator<<(std::ostream &os, Dimensions &dimensions) {
    return os << joinWithSpace(dimensions.width, dimensions.height);
}