/**
 * @author Zhuojian Chen (James)
 * @date May 8, 2023
 *
 * @document https://docs.google.com/document/d/10v-g-SEaB8brHoszFjoMtH-h2lQMoTOvo3-GjtTGIP0
 *
 * @requirement
 * 1. *Create UMLs for all the classes.
 * 2. *Your classes must overload the stream output operator.
 * 3. *Implement value() method for all artwork classes.
 * 4. *Overload comparison operators (==, !=, <, >, <=, >=) for all artwork classes.
 * 5. *Create a template to find the minimum value; test it.
 * 6. *Create a template to find the maximum value; test it.
 * 7. *Write a function in "museum" file (driver program) that demonstrates polymorphism.
 * 8. *Classes should throw exceptions for invalid inputs, and catch and handle those exceptions.
 * 9. *Write information from "Museum" to a text file.
 *
 * @notice
 * 1. Comment extensively.
 * 2. Use self-documenting method names and variables.
 * 3. Use smart pointers where appropriate.
 * 4. Delete allocated memory out of smart pointers.
*/

#include <iostream>
#include <sstream>
#include "./artwork/Artwork.h"
#include "./util/helper.h"

using namespace std;

/**
 * Converts an artwork to description text about it.
 * @param artwork the artwork to convert.
 * @return a description text about the artwork.
 * @remark This function is intended to demonstrate polymorphism.
 */
string artworkToString(Artwork &artwork) {
    return artwork.toString();
}

void testCommonDate();

void testCommonDimensions();

void testCommonName();

void testCommonTime();

/**
 * Driver program.
 */
int main() {
    // Test common classes.
    testCommonDate();
    testCommonDimensions();
    testCommonName();
    testCommonTime();

    // Test museum.

}

void testCommonDate() {
    test("common/Date", []() {
        Date date1(3, 12, 1999);
        expect(getStreamOutput(date1), "3 12 1999");
        expect(date1.toString(), "03-12-1999");

        Date date2;
        streamInput(date2, "5 9 2005");
        expect(date2.toString(), "05-09-2005");
    });
}

void testCommonDimensions() {
    test("common/Dimensions", []() {
        Date date(3, 12, 1999);
        expect(getStreamOutput(date), "3 12 1999");
        expect(date.toString(), "03-12-1999");

        Date date2;
        streamInput(date2, "5 9 2005");
        expect(date2.toString(), "05-09-2005");
    });
}

void testCommonName() {

}

void testCommonTime() {

}