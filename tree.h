//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_TREE_H
#define PROJECT_TREE_H

#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "FreeMemory.h"

//This MACRO return true if a given list is empry ; false otherwise;
#define isEmptyList(lst) (((lst) == NULL) ? true : false)

//This function returns a tree of all the possible paths starting from a given boardPos
pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board);

//This is an inner function. it returns a treeNode of all the possible paths starting from a given boardPos
treeNode* _findAllPossiblePaths(char** board, movesArray** moves, boardPos start, treeNode* node);

//This function inserts a new treeNodeListCell with a given boardPos as its data to the head of a given treeList.
treeNodeListCell* insertValidPosToHead(treeNodeListCell* lst, boardPos data);

//This function creates a treeNode node and returns it.
treeNode* createNode(boardPos data, treeNodeListCell* nextPossiblePosition);

//This function removes given boardPosses from the board.
void removeTakenPos(char** board, boardPos* posToRemove, int size);


#endif
