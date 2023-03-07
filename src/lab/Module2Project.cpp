#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int *create(int numValues);

void fill(int *array, int numElements);

void fill(int *array, int startIndex, int numElements);

void fillRandom(int *array, int numElements, int min, int max);

int randBetween(int min, int max);

void append(int *&array, int value);

void concatenate(int *&array1, const int *array2);

int elementAt(int *array, int index);

int sum(int *array);

void print(int *array);

int *create(int numValues) {
    int *array = new int[numValues + 2]; // create the array

    cout << "array[0]" << numValues << endl;
    array[0] = numValues;

    for (int i = 1; i < numValues + 2; i++) {
        array[i] = 0;
        cout << i << ":" << array[i] << '\n';
    }


    return array;
}

void fill(int *array, int numElements) {
    fill(array, 0, numElements);
}

void fill(int *array, int startIndex, int numElements) {
    /// check size
    startIndex = 0;
    array[startIndex] = numElements;

    /*** for (int i = startIndex+1; i < numElements+1; i++) {
        cout << i << ": ";
        cin >> array[i];
    }
    ***/

    fillRandom(array, numElements, -50, 50);
    for (int i = 0; i < numElements + 2; i++) {
        cout << i << ":qq " << array[i];
        cout << endl;
        //cin >> array[i];
    }
}

void fillRandom(int *array, int numElements, int min, int max) {
    int sum = 0;
    array[0] = numElements;
    for (int i = 1; i < numElements + 1; i++) {
        array[i] = randBetween(min, max);
        cout << "i randon" << i << "line:" << array[i] << "\n";
        sum = sum + array[i];
        cout << "isum:" << sum;
        cout << endl;
    }
    cout << "ssum:" << sum;
    array[numElements + 1] = sum;
}

void append(int *&array, int value) {
    int size = array[0]; //length calculation
    int newSize = size + 3;
    int *newArray = new int[newSize];

    newArray[0] = array[0] + 1;
    cout << "new array size:" << newArray[0] << endl;
    for (int i = 1; i < size + 1; i++) {
        newArray[i] = array[i];
        cout << "new  size:" << newArray[i] << endl;
    }

    newArray[newSize - 2] = value;
    newArray[newSize] = array[size + 1] + value;

    //size = newSize;
    for (int j = 0; j < newSize + 1; j++) {
        cout << "For newArray[j]" << j << ":" << newArray[j] << endl;
    }
    delete[] array;
    array = newArray;

}

void concatenate(int *&array1, const int *array2) {
    int size_1 = array1[0];
    int size_2 = array2[0];
    int Size = size_1 + size_2 + 2;
    cout << "consize:" << Size << endl;

    int *newArray = new int[Size];
    newArray[0] = size_1 + size_2;
    cout << "newArray[0]:" << newArray[0] << endl;

    for (int i = 1; i <= size_1; i++) {
        newArray[i] = array1[i];
    }

    //the second part from 
    //for(int k=Size-size_2-1;k<Size-1;k--){
    //newArray[k]= array2[k-size_1];
    //}

    for (int i = 1; i <= size_2; i++)
        newArray[i + size_1] = array2[i];

    newArray[Size] = array1[size_1] + array2[size_2];

    for (int j = 0; j < Size; j++) {
        cout << "newArray" << newArray[j] << endl;
    }
    delete[] array1;
    array1 = newArray;
}

int randBetween(int min, int max) {
    if (min > max) swap(min, max);
    return (rand() % (max - min + 1) + min);
}

int elementAt(int *array, int index) {
    int size = array[0];
    int value;//query_value for index
    int count = 0;
    for (int i = 1; i < size - 1; i++) {
        value = array[i];
        if (value == index) {
            count = i + count;
        }
    }

    return count;
}

int sum(int *array) {
    int sum_array = 0;
    int size = array[0];

    for (int i = 1; i < size + 1; i++) {
        sum_array = sum_array + array[i];
    }
    return sum_array;
}

void print(int *array) {
    int size = array[0];
    int sum_value;


    for (int i = 0; i < size + 2; i++) {
        cout << "print array" << array[i] << "\n";

    }
    sum_value = array[size + 1];
    cout << "sum value:" << sum_value << endl;
}


int main() {
    int *pArray;
    int numElements = 3;
    int numEl = 7;
    int *pArr2;
    srand(time(0));

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