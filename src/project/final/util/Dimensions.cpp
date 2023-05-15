#include "Dimensions.h"
#include <string>

Dimensions::Dimensions(double width, double height) {
    this->width = width;
    this->height = height;
}

const std::string Dimensions::toString() const {
    return std::to_string(height) +  " ft × " + std::to_string(width) + " ft";
}