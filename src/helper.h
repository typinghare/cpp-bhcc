/**
 * @author James Chan (Zhuojian Chen)
 */

#ifndef BHCC_CPP_HELPER_H
#define BHCC_CPP_HELPER_H

#include <iostream>

int count(const int array[], int length, int number);

double maxOfArray(const double array[], int length);

int maxOfArray(const int array[], int length);

int minOfArray(const int array[], int length);

int sum(int array[], int length);

std::string arrayToString(int *array, int length);

void print2DArray(int **array, int rowNum, int colNum);

#endif
