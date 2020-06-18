//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PATHFROMFILE_H
#define PATHFROMFILE_H

#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


//#define IsValidPos(next,valid)  ((((next)[0])==((valid)[0])) && (((next)[1])==((valid)[1]))) ? (true:false) TODO: Remove before submission if not being used!

//Todo: Add description
int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board);

//This function gets 2 boardPoss and return true if equal ; false otherwise;
bool isValidPos(boardPos next, boardPos valid);

//TODO: Find the right place foir this function
//This function frees the memory of a given boardPosArray matrix.
void freeBoardPosArrayMatrix(boardPosArray** matrix);

//TODO: Find the right place foir this function
//This function frees the memory of a given boardPosArray struct.
void freeBoardPosArr(boardPosArray* arr);

#endif