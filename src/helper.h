/**
 * @author James Chan (Zhuojian Chen)
 */

#ifndef BHCC_CPP_HELPER_H
#define BHCC_CPP_HELPER_H

#include <iostream>
#include "constant.h"

int count(int array[], int length, int number);

double maxOfArray(double array[], int length);

int maxOfArray(int array[], int length);

int minOfArray(int array[], int length);

int sum(int array[], int length);

std::string arrayToString(int array[], int length);

void print2DArray(int array[][ROW_LENGTH], int rowNum, std::ostream &os);

#endif
