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
#include "FreeMemory.h"


//This function reads a boardPoses' binary file and returns:
//(-1) If the file doesn't exist.
//(1) If the boardPoses doesn't represent a valid path.
//(2) If the boardPoses represent a valid path covering all board.
//(3) If the boardPoses represent a valid path that doesn't cover all board.
int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board);

//This function gets 2 boardPoss and return true if equal ; false otherwise;
bool isValidPos(boardPos next, boardPos valid);



#endif