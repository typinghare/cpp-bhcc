#ifndef BHCC_CPP_ASSIGNMENT7_H
#define BHCC_CPP_ASSIGNMENT7_H
#endif

#include <iostream>
#include <sstream>

class Box {
private:
    double length;
    double width;
    double height;
    std::string material;
public:
    double getLength() const { return length; }

    double getWidth() const { return width; }

    double getHeight() const { return height; }

    void setLength(double _length) { length = _length > 0 ? _length : 1; }

    void setWidth(double _width) { width = _width > 0 ? _width : 1; }

    void setHeight(double _height) { height = _height ? _height : 1; }

    void setMaterial(std::string _material) { material = _material; }

    double volume() const { return length * width * height; }

    std::string toString();

    // operators overload
    bool operator<(const Box &);

    bool operator>(const Box &);

    bool operator<=(const Box &);

    bool operator>=(const Box &);

    bool operator!=(const Box &);

    bool operator==(const Box &);

    Box operator+(const Box &);

    Box operator-(const Box &);

    friend std::istream &operator>>(std::istream &, Box &);

    friend std::ostream &operator<<(std::ostream &, Box &);
};



