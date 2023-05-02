/**
 * @author Zhuojian Chen (James)
 *
 * @requirement
 * Modify the Box class (topic 6 reading assignment):
 * 1. create overloaded comparison operators (<, >, <=, >=, !=, ==).
 * 2. create an overloaded addition operator. for the addition operator to work, a side on each box
 * must be the same (l and w, l and h, or h and w).
 * 3. create an overloaded subtraction operator. for the subtraction operator to work, a side on
 * each box must be the same (l and w, l and h, or h and w), and the RHS of the subtraction must be
 * smaller than the LHS. (Think of cutting off a section of a 2x4 length of lumber).
 * 4. create overloaded stream input and output operators.
 * NOTE: in the stream input overload, do NOT use cout to get the values from the user...
 *
 * @update "stream input should validate the inputs."
 */

#include "Box.h"
#include <iostream>

using namespace std;

std::string Box::toString() {
    stringstream ss;
    ss << "SIZE=" << getLength() << "x" << getWidth() << "x" << getHeight() << "; VOLUME="
       << volume() << "; MATERIAL=\"" << material << "\".";

    return ss.str();
}

bool Box::operator<(const Box &box) {
    return this->volume() < box.volume();
}

bool Box::operator>(const Box &box) {
    return this->volume() > box.volume();
}

bool Box::operator<=(const Box &box) {
    return this->volume() <= box.volume();
}

bool Box::operator>=(const Box &box) {
    return this->volume() >= box.volume();
}

bool Box::operator!=(const Box &box) {
    return this->volume() != box.volume();
}

bool Box::operator==(const Box &box) {
    return this->volume() == box.volume();
}

/**
 * Overload plus operator.
 * Only a box with identical two sides and one different side can add.
 * @param box
 * @return
 */
Box Box::operator+(const Box &box) {
    bool isLengthEqual = length == box.length;
    bool isWidthEqual = width == box.width;
    bool isHeightEqual = height == box.height;

    if (isLengthEqual + isWidthEqual + isHeightEqual != 2) {
        throw "Only a box with identical two sides and one different side can add.";
    }

    Box newBox = *this;     // copy constructor
    if (!isLengthEqual) newBox.setLength(length + box.length);
    if (!isWidthEqual) newBox.setWidth(width + box.width);
    if (!isHeightEqual) newBox.setHeight(height + box.height);

    return newBox;
}

/**
 * Overload minus operator.
 * Only a box with identical two sides and one different side can subtract.
 * For the different side, the magnitude of this box's should be greater than the minuend (被减数).
 * @param box
 * @return
 */
Box Box::operator-(const Box &box) {
    bool isLengthEqual = length == box.length;
    bool isWidthEqual = width == box.width;
    bool isHeightEqual = height == box.height;

    if (isLengthEqual + isWidthEqual + isHeightEqual != 2) {
        throw "Only a box with identical two sides and one different side can subtract.";
    }

    if (volume() < box.volume()) {
        throw "For the different side, the magnitude of this box's should be greater than the minuend.";
    }

    Box newBox = *this;     // copy constructor
    if (!isLengthEqual) newBox.setLength(length - box.length);
    if (!isWidthEqual) newBox.setWidth(width - box.width);
    if (!isHeightEqual) newBox.setHeight(height - box.height);

    return newBox;
}

istream &operator>>(istream &in, Box &box) {
    // validate the inputs
    in >> box.length >> box.width >> box.height >> box.material;

    return in;
}

ostream &operator<<(ostream &out, Box &box) {
    out << box.toString() << endl;
    return out;
}