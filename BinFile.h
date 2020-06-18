//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_BINFILE_H
#define PROJECT_BINFILE_H

#define _CRT_SECURE_NO_WARNINGS
#include "Types.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

//TODO: Add description
void saveListToBinFile(char* file_name, boardPosArray* pos_arr);

//TODO: Add description
boardPosArray* readFromBinFile(char* file_name, bool* isExist);

//TODO: Add description
void setBits(boardPosArray* pos_arr, BYTE res[], int j, int numOfPos);

//TODO: Add description
void writePosToArr(boardPosArray* arr, int i, BYTE* data, int numOfPos);

#endif