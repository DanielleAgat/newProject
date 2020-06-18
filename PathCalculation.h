//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_PATHCALCULATION_H
#define PROJECT_PATHCALCULATION_H
#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathFromFile.h"
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

//TODO: Add description
movesList* findPathCoveringAllBoard(boardPos start, movesArray** moves, char** board);

//This function returns the amount of empty cells is a given board.
int getCountOfEmptyCells(char** board);

//TODO: Add description
bool getAllBoardPath(treeNode* root, movesList* list, int levelCounter, int emptyCells);

//This function returns the move between 2 given boardPoss.
Move getLastMove(boardPos curr, boardPos next);


#endif
