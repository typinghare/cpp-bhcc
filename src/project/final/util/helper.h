#ifndef BHCC_CPP_HELPER_H
#define BHCC_CPP_HELPER_H

#include <iostream>
#include <functional>
#include <sstream>

/**
 * Joins values with space character as delimiter.
 * @tparam V template value.
 * @param values values to join.
 * @return joined string.
 * @reference https://en.cppreference.com/w/cpp/language/fold
 */
template<typename ...V>
std::string joinWithSpace(V... values) {
    std::stringstream ss;
    // If two values, "a" and 5, are given, the `((ss << values << ' '), ...)` can be seen as being
    // expanded to two statements as follows:
    // ss << "a" << ' ';  ss << 5 << ' ';
    ((ss << values << ' '), ...);
    std::string res = ss.str();

    // Remove the space character at the end of the string.
    if (!res.empty() && res.back() == ' ') {
        res.pop_back();
    }

    return res;
}

// ChatGPT:
// By adding the inline keyword to the function definitions of test and expect, you inform the
// compiler that these functions can be defined multiple times in different translation units, as
// long as they have the same definition. This avoids the multiple definition error during the
// linking phase. After making this change, you should be able to include helper.h in multiple
// source files without encountering the duplicate symbol error.

/**
 * Returns the string representation of an object from its stream output.
 * @tparam T template type of the object.
 * @param object the object to retrieve the stream output from.
 * @return the string representation of the object's stream output.
 */
template<typename T>
inline std::string getStreamOutput(T object) {
    std::stringstream ss;
    ss << object;

    return ss.str();
}

/**
 * Reads an object from a string stream.
 * @tparam T template type of the object.
 * @param object the object to store the input value.
 * @param streamString the string containing the input value.
 */
template<typename T>
inline void streamInput(T &object, std::string streamString) {
    std::stringstream ss(streamString);
    ss >> object;
}

/**
 * Perform a test.
 * @param testName the name of the test case.
 * @param testFunction test anonymous function.
 */
inline void test(std::string testName, const std::function<void()> &testFunction) {
    std::cout << "TestBegin [" << testName << "]" << std::endl;

    try {
        testFunction();
    } catch (const std::exception &e) {
        std::cout << "Test failed due to an encountered exception: " << std::endl;
        std::cout << e.what() << std::endl;

        exit(1);
    }

    std::cout << "TestEnd [" << testName << "]" << std::endl << std::endl;
}

/**
 * Program exits if the given value is not equal to the expected value.
 * @tParam T template type of the value and expected value.
 * @param value the real/given value.
 * @param expectedValue the expected value.
 */
template<typename T>
inline void expect(T value, T expectedValue) {
    if (value == expectedValue) {
        std::cout << "TEST PASS: [ " << value << " ]" << std::endl;
    } else {
        std::cout << "TEST FAIL: " << std::endl;
        std::cout << "Expected value: [ " << expectedValue << " ]" << std::endl;
        std::cout << "Given value:    [ " << value << " ]" << std::endl;
        exit(1);
    }
}

/**
 * Program exits if the given value is not equal to the expected value.
 * @tParam T template type of the value and expected value.
 * @param value the real/given value.
 * @param expectedValue the expected value.
 */
inline void expect(const std::string value, const std::string expectedValue) {
    if (value == expectedValue) {
        std::cout << "TEST PASS: [ \"" << value << "\" ]" << std::endl;
    } else {
        std::cout << "TEST FAIL: " << std::endl;
        std::cout << "Expected value: [ \"" << expectedValue << "\" ]" << std::endl;
        std::cout << "Given value:    [ \"" << value << "\" ]" << std::endl;
        exit(1);
    }
}

/**
 * Equivalent instanceof in Java.
 * @tparam Base base class.
 * @tparam T template.
 * @param ptr class to check.
 * @return true if *ptr instanceof Base
 * @reference https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
 */
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

#endif
