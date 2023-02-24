/**
 * @author James Chan
 * @date Feb 16, 2023
*/

/**
 * Answers to questions.
 *
 * 1. The functions append and concatenate take inputs with a data type of
 * int*& (integer pointer reference). Why?
 * @answer The "int*" refers to an array of integer. The ampersand character means passing parameters
 * by reference. In this case, if we create an array in the main function, and then pass this array to
 * a function, in which the parameter is reassigned, the value of the variable in the main function
 * will also be updated. That's because in this situation the address of the variable, instead of a
 * copy of it, is passed to the function, and when the assignment statement is executed in the
 * function, the program will update the value of the given address.
 *
 * 2. The function concatenates second input parameter has a data type of const
 * int* (constant integer pointer). Why?
 * @answer The "int*" refers to an array of integer. The "const" specified that the function will
 * not modify this argument. This is a good practices to avoid accidental modifications to the array.
 *
 * 3. Under what circumstances (if any) do you need to print error messages in your functions?
 * @answer (1) the array (int* or int[]) given is `nullptr`. (2) the number of element specified is
 * a negative number of zero. (3) the `startIndex` is a negative number. (4) the sum of `startIndex`
 * and `numElements` is greater than the number of all elements.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *create(int numElements);

void fill(int *array, int numElements);

void fill(int *array, int startIndex, int numElements);

void fillRandom(int *array, int numElements, int min, int max);

void append(int *&array, int value);

void concatenate(int *&array1, const int *array2);

int elementAt(int *array, int index);

int sum(int *array);

void print(int *array);

// self-defined functions
void updateSum(int *array);

int randBetween(int min, int max);

int getLengthOfInt(int number);

int main() {
    int *pArray;
    int numElements = 3;
    int numEl = 7;
    int *pArr2;

    pArray = create(numElements);
    pArr2 = create(numEl);
    print(pArray);

    fill(pArray, numElements);
    print(pArray);

    cout << "Append 42..." << endl;
    append(pArray, 42);
    print(pArray);

    cout << "Create another array..." << endl;
    fill(pArr2, numEl);
    cout << "Print array2: " << endl;
    print(pArr2);

    cout << "Concatenate array2 onto array" << endl;
    concatenate(pArray, pArr2);
    print(pArray);

    cout << "sum of array: " << sum(pArray) << endl;
    for (int i = 0; i < 8; i++)
        cout << "element [" << i << "] of array: " << elementAt(pArray, i) << endl;
    delete[] pArray;
    delete[] pArr2;
    pArray = nullptr;
    pArr2 = nullptr;
    return 0;
}

/**
 * Creates an array with specified number of elements. The array will be initialized with zeros.
 * @param numElements the number of elements in the array
 * @return an array with specified number of elements; null if the numElements is not positive.
 */
int *create(int numElements) {
    if (numElements <= 0) {
        cout << "The number of elements should be a positive number." << endl;
        return nullptr;
    }

    int *array = new int[numElements + 2];

    // set the number of elements
    array[0] = numElements;

    // fill the array with zeros; set the sum as zero
    for (int i = 1; i < numElements + 2; ++i) {
        array[i] = 0;
    }

    return array;
}

/**
 * Fills the given array.
 * @param array the array to fill
 * @param numElements the number of elements
 */
void fill(int *array, int numElements) {
    if (array == nullptr) {
        cout << "Fail to fill the array because the given array is null." << endl;
        return;
    }

    fill(array, 0, numElements);
}

/**
 * Fills the given array.
 * @param array
 * @param startIndex
 * @param numElements
 */
void fill(int *array, int startIndex, int numElements) {
    if (array == nullptr) {
        cout << "Fail to fill the array because the given array is null." << endl;
        return;
    } else if (numElements < 0) {
        cout << "The number of elements should be a positive number." << endl;
        return;
    } else if (startIndex < 0 || startIndex + numElements > array[0]) {
        cout << "Fail to fill the array because index is out of bounds." << endl;
        return;
    }

    for (int i = startIndex + 1; i < startIndex + numElements + 1; ++i) {
        int num;
        cout << "Please enter a number for element [" << i - 1 << "]: ";
        cin >> num;
        array[i] = num;
    }

    updateSum(array);
}

/**
 * Fills the given array with random numbers.
 * @param array
 * @param numElements
 * @param min
 * @param max
 */
void fillRandom(int *array, int numElements, int min, int max) {
    if (array == nullptr) {
        cout << "Fail to fill the array because the given array is null." << endl;
        return;
    } else if (numElements < 0) {
        cout << "The number of elements should be a positive number." << endl;
        return;
    } else if (numElements > array[0]) {
        cout << "Fail to fill the array because index is out of bounds." << endl;
        return;
    }

    for (int i = 1; i < numElements + 1; ++i) {
        array[i] = randBetween(min, max);
    }

    updateSum(array);
}

/**
 * Concatenates two arrays.
 */
void concatenate(int *&array1, const int *array2) {
    const int numElements1 = array1[0], numElements2 = array2[0];
    int *newArray = new int[numElements1 + numElements2 + 2];
    newArray[0] = numElements1 + numElements2;

    // copy elements from array1
    for (int i = 1; i < numElements1 + 1; ++i) {
        newArray[i] = array1[i];
    }

    // copy elements from array2
    for (int i = numElements1 + 1; i <= numElements1 + numElements2 + 1; ++i) {
        newArray[i] = array2[i - numElements1];
    }

    // update the sum
    newArray[numElements1 + numElements2 + 1] = sum(array1) + array2[numElements2 + 1];

    delete[] array1;
    array1 = newArray;
}

/**
 * Appends a value to the given array.
 * @param array the array to append value to
 * @param numElements value to append
 */
void append(int *&array, int value) {
    if (array == nullptr) {
        cout << "Fail to fill the array because the given array is null." << endl;
        return;
    }

    const int newNumElements = array[0] + 1;
    int *newArray = new int[newNumElements + 2];
    newArray[0] = newNumElements;

    // copy elements from the old array to the new one
    for (int i = 1; i < newNumElements; ++i) {
        newArray[i] = array[i];
    }

    // append the new element to the end of the new array
    newArray[newNumElements] = value;

    // update the sum
    newArray[newNumElements + 1] = array[newNumElements] + value;

    delete[] array;
    array = newArray;
}

/**
 * Returns the element at a specified index.
 * @param array the given array
 * @param index index of the element to find
 * @return the element at a specified index.
 */
int elementAt(int *array, int index) {
    return array[index + 1];
}

/**
 * Returns the sum of the given array.
 * @param array the array to find the sum
 * @return the sum of the given array.
 */
int sum(int *array) {
    return array[array[0] + 1];
}

/**
 * Prints an array.
 * @param array array to print
 */
void print(int *array) {
    if (array == nullptr) {
        cout << "[null]";
        return;
    }

    // find minimum and maximum numbers in the array
    int min = array[1], max = array[2];
    for (int i = 2; i <= array[0]; ++i) {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }

    // determine the longest length to set.
    int longestLength = std::max(getLengthOfInt(min), getLengthOfInt(max));

    const int size = array[0];
    cout << "[Array]SIZE=" << size << "; SUM=" << sum(array) << "; DETAIL:" << endl;

    for (int i = 1; i < size + 1; ++i) {
        cout << setw(longestLength) << array[i] << " ";
        if (i % 10 == 0) cout << endl;
    }

    cout << endl;
}

/**
 * Updates the sum of an array.
 * @param array array to update; should not be null
 */
void updateSum(int *array) {
    const int totalNumElements = array[0];
    int sum = 0;
    for (int i = 1; i <= totalNumElements; ++i) {
        sum += array[i];
    }
    array[totalNumElements + 1] += sum;
}

/**
 * Returns a random integer between specified values.
 * @param min the lower bound; included
 * @param max the upper bound; included
 * @return a random integer between specified values.
 */
int randBetween(int min, int max) {
    return rand() % (max - min + 1) + min;
}


/**
 * Returns the length of an integer; the negative sign counts.
 * @param number
 * @return the length of an integer; the negative sign counts.
 */
int getLengthOfInt(int number) {
    int len = 0;

    if (number < 0) {
        len++;
        number = -number;
    }

    while (number > 0) {
        number /= 10;
        len++;
    }

    return len;
}