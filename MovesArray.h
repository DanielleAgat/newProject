//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef MovesArray
#define MovesArray

#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "FreeMemory.h"

//This function prints a given board.
void PrintBoard(char** board);

//This function filters the invalid moves of a given movesArray and returns a boardPosArray of all the valid positions.
boardPosArray** validMoves(movesArray** moves, char** board);

//This function returns true if a given move is valid ; false otherwise.
bool isValid(char** board, Move cellDest, int i, int j);

#endif
