//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#define _CRT_SECURE_NO_WARNINGS

#ifndef PROJECT_LIST_TESTS_H
#define PROJECT_LIST_TESTS_H

#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "FreeMemory.h"

movesList getListFromUser();

void makeEmptyList(movesList* lst);

void printList(movesList lst);

void _print_list(moveCell* node);

//TODO: Add description
void initMovesArray(movesArray** moves);

void PrintMovesBoard(movesArray** moves);

#endif
