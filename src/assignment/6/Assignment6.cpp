/**
 * @author Zhuojian Chen (James)
 * @requirement
 * Given the UML for a box:
 * BOX                         [Comment]
 * - length:double
 * - width:double
 * - height:double
 * - material:string
 * getLength():double
 * getWidth(): double
 * getHeight(): double
 * getMaterial(): string
 * setLength(double):void       >= 0 else 1
 * setWidth(double):void        >= 0 else 1
 * setHeight(double):void       >= 0 else 1
 * setMaterial(string):void
 * volume():double
 * toString():string
 *
 * 1. Create a Box Class, then create several boxes:
 *  • box1 has length -1.2, width 2.3, height 3.4 and material paper
 *  • box2 has length 2, width 3, height 4 and material cardboard
 *  • box3 has length 8 width 10 and height 9 and material aluminum
 * 2. Calculate and print the volume of each box - be sure to also print the dimensions of each box.
 */

#include <iostream>
#include <sstream>

using namespace std;

class Box {
private:
    double length;
    double width;
    double height;
    string material;
public:
    double getLength() {
        return length;
    }

    double getWidth() {
        return width;
    }

    double getHeight() {
        return height;
    }

    void setLength(double _length) {
        length = _length > 0 ? _length : 1;
    }

    void setWidth(double _width) {
        width = _width > 0 ? _width : 1;
    }

    void setHeight(double _height) {
        height = _height ? _height : 1;
    }

    void setMaterial(string _material) {
        material = _material;
    }

    double volume() {
        return length * width * height;
    }

    string toString() {
        stringstream ss;
        ss << "SIZE=" << getLength() << "x" << getWidth() << "x" << getHeight() << "; VOLUME="
           << volume() << "; MATERIAL=\"" << material << "\".";

        return ss.str();
    }
};

int main() {
    Box box1 = Box(), box2 = Box(), box3 = Box();

    box1.setLength(-1.2);
    box1.setWidth(2.3);
    box1.setHeight(3.4);
    box1.setMaterial("paper");

    box2.setLength(2);
    box2.setWidth(3);
    box2.setHeight(4);
    box2.setMaterial("cardboard");

    box3.setLength(8);
    box3.setWidth(10);
    box3.setHeight(9);
    box3.setMaterial("aluminum");

    // Calculate and print the volume and dimension of each box
    cout << "Box 1: " << box1.toString() << endl;
    cout << "Box 2: " << box2.toString() << endl;
    cout << "Box 3: " << box3.toString() << endl;
}