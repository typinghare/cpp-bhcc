/**
 * @author James Chan (Zhuojian Chen)
 */

#ifndef BHCC_CPP_READDATA_H
#define BHCC_CPP_READDATA_H

#include <iostream>
#include "constant.h"

//int (*readData(std::string filename))[ROW_LENGTH];
void readData(std::string filename, int matrix[][ROW_LENGTH]);

#endif