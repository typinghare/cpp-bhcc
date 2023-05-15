#ifndef BHCC_CPP_DIMENSIONS_H
#define BHCC_CPP_DIMENSIONS_H

#include <iostream>

class Dimensions {
private:
    /**
     * Width in feet.
     */
    double width;

    /**
     * Height in feet.
     */
    double height;
public:
    Dimensions() {};

    Dimensions(double width, double height);

    const double getWidth() const { return width; }

    const double getHeight() const { return height; }

    /**
     * Returns the area in feet.
     * @return
     */
    const double getArea() const { return width * height; }

    const std::string toString() const;
};

#endif