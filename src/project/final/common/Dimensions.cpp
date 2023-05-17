#include "Dimensions.h"
#include <string>
#include <iomanip>
#include <sstream>

void Dimensions::checkMemberVariables() {
    if (width <= 0) {
        throw std::invalid_argument("The width should be a positive integer!");
    }

    if (height <= 0) {
        throw std::invalid_argument("The height should be a positive integer!");
    }
}

Dimensions::Dimensions(double width, double height) {
    this->width = width;
    this->height = height;

    checkMemberVariables();
}

const std::string Dimensions::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << width << "ft × " << height << "ft";

    return ss.str();
}

std::istream &operator>>(std::istream &is, Dimensions &dimensions) {
    is >> dimensions.width >> dimensions.height;

    dimensions.checkMemberVariables();

    return is;
}

std::ostream &operator<<(std::ostream &os, Dimensions &dimensions) {
    return os << std::fixed << std::setprecision(2) << dimensions.width << ' ' << dimensions.height;
}