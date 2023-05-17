#include "Dimensions.h"
#include <string>

Dimensions::Dimensions(double width, double height) {
    if (width <= 0) {
        throw new std::invalid_argument("The width should be a positive integer!");
    }

    if (height <= 0) {
        throw new std::invalid_argument("The height should be a positive integer!");
    }

    this->width = width;
    this->height = height;
}

const std::string Dimensions::toString() const {
    return std::to_string(height) + "ft × " + std::to_string(width) + "ft";
}

std::istream &operator>>(std::istream &is, Dimensions &dimensions) {
    is >> dimensions.width >> dimensions.height;
    return is;
}

std::ostream &operator<<(std::ostream &os, Dimensions &dimensions) {
    os << dimensions.toString();
    return os;
}