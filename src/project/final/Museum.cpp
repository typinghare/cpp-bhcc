/**
 * @author Zhuojian Chen (James)
 * @date May 8, 2023 ~ May 17, 2023
 *
 * @document https://docs.google.com/document/d/10v-g-SEaB8brHoszFjoMtH-h2lQMoTOvo3-GjtTGIP0
 *
 * @requirement
 * 1. Create UMLs for all the classes.
 * 2. Your classes must overload the stream output operator.
 * 3. Implement value() method for all artwork classes.
 * 4. Overload comparison operators (==, !=, <, >, <=, >=) for all artwork classes.
 * 5. Create a template to find the minimum value; test it.
 * 6. Create a template to find the maximum value; test it.
 * 7. Write a function in "museum" file (driver program) that demonstrates polymorphism.
 * 8. Classes should throw exceptions for invalid inputs, and catch and handle those exceptions.
 * 9. *Write information from "Museum" to a text file.
 *
 * @notice
 * 1. Comment extensively.
 * 2. Use self-documenting method names and variables.
 * 3. Use smart pointers where appropriate.
 * 4. Delete allocated memory out of smart pointers.
 *
 * @explanation
 * 1. The value of Dance, which is obtained by "age in years * timeInHours/60" seems to be
 * incorrect, because a dance typically lasts for only a few hours, resulting in a very small value
 * for "timeInHours/60". Therefore, I changed the "timeInHours" to "timeInMinutes" when computing.
 * 2. I placed "Date", "Dimensions", "Name", and "Time" in the "common" directory. I also made some
 * tests for them in the driver program.
 * 3. I created some helpful functions, such as "joinWithSpace", "getStreamOutput", and "expect", in
 * the "util/helper.h" to increase the reusability and readability of code. Another purpose is to
 * apply the new knowledge from the last several classes.
 *
 * @references
 * https://www.programiz.com/cpp-programming/pure-virtual-funtion
 * https://en.cppreference.com/w/cpp/language/lambda
 * https://en.cppreference.com/w/cpp/language/fold
 * https://en.cppreference.com/w/cpp/language/dynamic_cast
 * https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
*/

#include <iostream>
#include "./artwork/Artwork.h"
#include "./util/helper.h"
#include "./common/Dimensions.h"
#include "./common/Time.h"
#include "./artwork/Dance.h"
#include "./artwork/Painting.h"
#include "./artwork/WrittenWord.h"
#include <fstream>

using namespace std;

void testCommonDate();

void testCommonDimensions();

void testCommonName();

void testCommonTime();

string artworkToString(Artwork *artwork);

template<typename T>
T findMinValueArtwork(T *artworkArray, int size);

template<typename T>
T findMaxValueArtwork(T *artworkArray, int size);

void writeFile(string filepath, Artwork *artworkArray[], int size);

Artwork **readFile(string filepath, int size);

/**
 * Driver program.
 * @see https://www.name-generator.org.uk/quick/
 */
int main() {
    // Test common classes.
    testCommonDate();
    testCommonDimensions();
    testCommonName();
    testCommonTime();

    // Test museum.
    // Create 6 artworks (Dance, Painting, and WrittenWord).
    Dance dance1(
        Name("Oliwia", "Herman"),
        Date(1, 5, 1870),
        Date(4, 29, 1911),
        Name(true),
        "A graceful and energetic dance.",
        "Haygrace",
        Time(1, 27, 30)
    );

    Dance dance2(
        Name("Lauren", "Guerrero"),
        Date(4, 19, 1920),
        Date(7, 16, 2005),
        Name("Katerina", "Kelley"),
        "A dynamic and captivating dance performance.",
        "WhiteSwan",
        Time(3, 16, 0)
    );

    Painting painting1(
        Name("Will", "Barron"),
        Date(2, 1, 1938),
        Date(12, 10, 1985),
        Name("Christopher", "Zamora"),
        "An excellent pastoral painting.",
        Painting::Medium::WATERCOLOR,
        Dimensions(3.5, 2.1)
    );

    Painting painting2(
        Name("Angelo", "Moreno"),
        Date(4, 9, 1920),
        Date(3, 12, 1970),
        Name("Gertrude", "Fox"),
        "An excellent pastoral painting.",
        Painting::Medium::WATERCOLOR,
        Dimensions(2.7, 1.8)
    );

    WrittenWord writtenWord1(
        Name("Imogen", "Doyle"),
        Date(2, 1, 1765),
        Date(6, 8, 1959),
        Name("Seamus", "Burch"),
        "Mr. Doyle's research manuscript",
        WrittenWord::Genre::ANTHOLOGY,
        265
    );

    WrittenWord writtenWord2(
        Name("Colin", "Mcknight"),
        Date(10, 29, 1820),
        Date(11, 6, 1997),
        Name("Sophie", "O'Reilly"),
        "Mr. Mcknight's autobiography.",
        WrittenWord::Genre::AUTOBIOGRAPHY,
        169
    );

    Dance::numberOfDanceItems = 2;
    Painting::numberOfPaintings = 2;
    WrittenWord::numberOfWrittenWordItems = 2;

    const int NUM_ARTWORK = 6;
    Artwork *artworksInMuseum[NUM_ARTWORK] = {
        &dance1, &painting1, &writtenWord1,
        &dance2, &painting2, &writtenWord2
    };

    // Print all artwork in the museum.
    for (int i = 0; i < NUM_ARTWORK; ++i) {
        cout << artworkToString(artworksInMuseum[i]) << endl;
    }

    // Test `minValueArtwork` and `minValueArtwork`.
    Artwork *minValueArtwork = findMinValueArtwork(artworksInMuseum, NUM_ARTWORK);
    Artwork *maxValueArtwork = findMaxValueArtwork(artworksInMuseum, NUM_ARTWORK);
    cout << "The minimum value among all artworks: $" << minValueArtwork->value() << endl;
    cout << "The maximum value among all artworks: $" << maxValueArtwork->value() << endl;

    // Write the array `artworksInMuseum` to a text file.
    const string TEXT_FILE_FILEPATH = "museum.txt";
    cout << endl << "Writing artworks in the museum to the text file." << endl;
    writeFile(TEXT_FILE_FILEPATH, artworksInMuseum, NUM_ARTWORK);
    cout << "Wrote artworks in the museum to the text file successfully." << endl;

    // Reads array from the text file.
    cout << endl << "Reading artworks from the text file." << endl;
    Artwork **artworkArray = readFile(TEXT_FILE_FILEPATH, NUM_ARTWORK);
    cout << "Read artworks from the text file successfully." << endl;
    for (int i = 0; i < NUM_ARTWORK; ++i) {
        cout << (*artworkArray[i]).toString() << endl;
    }
}

/**
 * Converts an artwork to description text about it.
 * @param artwork the artwork to convert.
 * @return a description text about the artwork.
 * @remark This function is intended to demonstrate polymorphism.
 */
string artworkToString(Artwork *artwork) {
    return artwork->toString();
}

/**
 * Finds a returns the artwork with minimum value from an array of artwork.
 * @tparam T the artwork template.
 * @param artworkArray the artwork array to find.
 * @param size the size of the artwork array.
 * @return the artwork with minimum value from an array of artwork.
 */
template<typename T>
T findMinValueArtwork(T *artworkArray, int size) {
    T minValueArtwork = artworkArray[0];

    for (int i = 1; i < size; i++) {
        if (artworkArray[i]->value() < minValueArtwork->value()) {
            minValueArtwork = artworkArray[i];
        }
    }

    return minValueArtwork;
}

/**
 * Finds a returns the artwork with maximum value from an array of artwork.
 * @tparam T the artwork template.
 * @param artworkArray the artwork array to find.
 * @param length the length of the artwork array.
 * @return the artwork with maximum value from an array of artwork.
 */
template<typename T>
T findMaxValueArtwork(T *artworkArray, int size) {
    T maxValueArtwork = artworkArray[0];

    for (int i = 0; i < size; i++) {
        if (artworkArray[i]->value() > maxValueArtwork->value()) {
            maxValueArtwork = artworkArray[i];
        }
    }

    return maxValueArtwork;
}

void writeFile(string filepath, Artwork *artworkArray[], int size) {
    // create and open a text file
    ofstream fileOutputStream(filepath);

    for (int i = 0; i < size; i++) {
        Artwork *artwork = artworkArray[i];

        if (instanceof<Dance>(artwork)) {
            fileOutputStream << "Dance " << *dynamic_cast<Dance *>(artwork) << endl;
        } else if (instanceof<Painting>(artwork)) {
            fileOutputStream << "Painting " << *dynamic_cast<Painting *>(artwork) << endl;
        } else if (instanceof<WrittenWord>(artwork)) {
            fileOutputStream << "WrittenWord " << *dynamic_cast<WrittenWord *>(artwork) << endl;
        } else {
            throw runtime_error("Unknown artwork type.");
        }
    }

    fileOutputStream.close();
}

Artwork **readFile(string filepath, int size) {
    ifstream fileInputStream(filepath);

    Artwork **artworkArray = new Artwork *[size];
    for (int i = 0; i < size; i++) {
        string line;
        getline(fileInputStream, line);

        string className;
        stringstream ss(line);
        ss >> className;
        if (className == "Dance") {
            Dance *dance = new Dance();
            ss >> *dance;

            artworkArray[i] = dance;
        } else if (className == "Painting") {
            Painting *painting = new Painting();
            ss >> *painting;

            artworkArray[i] = painting;
        } else if (className == "WrittenWord") {
            WrittenWord *writtenWord = new WrittenWord();
            ss >> *writtenWord;

            artworkArray[i] = writtenWord;
        } else {
            throw runtime_error("Unknown artwork type: [ " + className + " ].");
        }
    }

    return artworkArray;
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