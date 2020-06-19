//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef NEWPROJECT1_FREEMEMORY_H
#define NEWPROJECT1_FREEMEMORY_H

#include "stdlib.h"
#include "Types.h"

//This function frees the memory of a given boardPosArray matrix.
void freeBoardPosArrayMatrix(boardPosArray** matrix);

//This function frees the memory of a given boardPosArray struct.
void freeBoardPosArr(boardPosArray* arr);

//This function frees a movesList list
void freeMovesList(movesList* moves_list);

//This is an inner function. It frees a movesList list
void _freeMovesList(moveCell* move);

//This function frees a board
void freeBoard(char** board);


#endif
