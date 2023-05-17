#ifndef BHCC_CPP_DIMENSIONS_H
#define BHCC_CPP_DIMENSIONS_H

#include <iostream>

/**
 * A two-dimensional size including width and height.
 */
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

    /**
     * Checks whether width and height are positive numbers.
     */
    void checkMemberVariables();
public:
    Dimensions() {};

    Dimensions(double width, double height);

    const double getWidth() const { return width; }

    const double getHeight() const { return height; }

    /**
     * Returns the area of this dimensions in feet.
     */
    const double getArea() const { return width * height; }

    /**
     * Returns a string of this dimensions in the format of "<height>ft × <width>ft".
     */
    const std::string toString() const;

    // The order: width, height.
    friend std::istream &operator>>(std::istream &, Dimensions &);

    friend std::ostream &operator<<(std::ostream &, Dimensions &);
};

#endif