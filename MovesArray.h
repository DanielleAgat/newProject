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

//TODO: Add description
void PrintMovesBoard(movesArray** moves);

//TODO: Add description
void PrintBoard(char** board);

//TODO: Add description
void initMovesArray(movesArray** moves);

//TODO: Add description
boardPosArray** validMoves(movesArray** moves, char** board);

//TODO: Add description
bool isValid(char** board, Move cellDest, int i, int j);

#endif
