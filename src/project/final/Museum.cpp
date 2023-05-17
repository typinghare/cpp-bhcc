/**
 * @author Zhuojian Chen (James)
 * @date May 8, 2023
 *
 * @document https://docs.google.com/document/d/10v-g-SEaB8brHoszFjoMtH-h2lQMoTOvo3-GjtTGIP0
 *
 * @requirement
 * 1. *Create UMLs for all the classes.
 * 2. Your classes must overload the stream output operator.
 * 3. Implement value() method for all artwork classes.
 * 4. Overload comparison operators (==, !=, <, >, <=, >=) for all artwork classes.
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
#include "./artwork/Artwork.h"
#include "./util/helper.h"
#include "./common/Dimensions.h"
#include "./common/Time.h"
#include "./artwork/Dance.h"
#include "./artwork/Painting.h"
#include "./artwork/WrittenWord.h"

using namespace std;

string artworkToString(Artwork &artwork);

template<typename T>
T findMinValueArtwork(T *artworkArray, int length);

template<typename T>
T findMaxValueArtwork(T *artworkArray, int length);

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
    Painting painting1(
        Name("Will", "Barron"),
        Date(4, 9, 1920),
        Date(7, 16, 2005),
        Name("Christopher", "Zamora"),
        "An excellent pastoral painting.",
        Painting::Medium::WATERCOLOR,
        Dimensions(3.5, 2.1)
    );

    Painting painting2(
        Name("Will", "Barron"),
        Date(4, 9, 1920),
        Date(7, 16, 2005),
        Name("Christopher", "Zamora"),
        "An excellent pastoral painting.",
        Painting::Medium::WATERCOLOR,
        Dimensions(3.7, 2.1)
    );

    cout << (painting1 > painting2) << endl;
}

/**
 * Converts an artwork to description text about it.
 * @param artwork the artwork to convert.
 * @return a description text about the artwork.
 * @remark This function is intended to demonstrate polymorphism.
 */
string artworkToString(Artwork &artwork) {
    return artwork.toString();
}

template<typename T>
T findMinValueArtwork(T *artworkArray, int length) {
    T minValueArtwork = artworkArray[0];

    for (int i = 1; i < length; i++) {
        if (artworkArray[i].value() < minValueArtwork.value()) {
            minValueArtwork = artworkArray[i];
        }
    }

    return minValueArtwork;
}

template<typename T>
T findMaxValueArtwork(T *artworkArray, int length) {
    T maxValueArtwork = artworkArray[0];

    for (int i = 1; i < length; i++) {
        if (artworkArray[i].value() < maxValueArtwork.value()) {
            maxValueArtwork = artworkArray[i];
        }
    }

    return maxValueArtwork;
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
        Dimensions dimensions1(5.6, 6.32);
        expect(getStreamOutput(dimensions1), "5.60 6.32");
        expect(dimensions1.toString(), "5.60ft × 6.32ft");

        Dimensions dimensions2;
        streamInput(dimensions2, "2.84 3.00");
        expect(dimensions2.toString(), "2.84ft × 3.00ft");
    });
}

void testCommonName() {
    test("common/name", []() {
        Name name1("John", "Cena");
        expect(getStreamOutput(name1), "John Cena");
        expect(name1.toString(), "John Cena");

        Name name2(true);
        expect(getStreamOutput(name2), "[Anonymous]");
        expect(name2.toString(), "[Anonymous]");

        Name name3(false);
        streamInput(name3, "James Chan");
        expect(name3.toString(), "James Chan");

        Name name4(false);
        streamInput(name4, "[Anonymous]");
        expect(name4.getIsAnonymous(), true);
    });
}

void testCommonTime() {
    test("common/time", []() {
        Time time1(5);
        expect(getStreamOutput(time1), "0 0 5");
        expect(time1.toString(), "0:05");

        Time time2(6, 12);
        expect(getStreamOutput(time2), "0 6 12");
        expect(time2.toString(), "6:12");

        Time time3(2, 7, 3);
        expect(getStreamOutput(time3), "2 7 3");
        expect(time3.toString(), "2:07:03");

        Time time4;
        streamInput(time4, "1 7 14");
        expect(time4.toString(), "1:07:14");
    });
}