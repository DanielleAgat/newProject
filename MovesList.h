//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_MOVESLIST_H
#define PROJECT_MOVESLIST_H
#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

//////////////////////// Logic functions: ////////////////////////

//This function displays a given route on the board, after removing the invalid move nodes from the given list.
//returns the number of removed nodes from the list.
int display(movesList* moves_list, boardPos start, char** board);

//This function copies a given board and adds a start point
void copyBoard(char** orig, char** dest, boardPos start);

//This function board position and an index and adds it to the given board
void addCellToPath(char** board, boardPos currCell, Move move, char index);

///////////////////// General List functions: /////////////////////

//This function creates an empty movesList
void makeEmptyList(movesList* lst);

//This function gets a move and inserts it to the tail of a given list.
void insertDataToEndList(movesList* lst, Move move);

//This function returns a new move's node with a given move as its data.
moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev);

//This function inserts a given node to a given list's tail.
void insertNewNodeToEnd(movesList* lst, moveCell* newNode);

//This function gets a move and inserts it to the head of a given list.
void insertDataToHead(movesList* lst, Move move);

//This function inserts a given node to a given list's head.
void insertNewNodeHead(movesList* lst, moveCell* newNode);

//This function removes a move node from a given list
void removeMoveFromList(movesList* moves_List, moveCell** toRemove);

//////////////// Free memory allocation functions: ////////////////

//This function frees a movesList list
void freeMovesList(movesList* moves_list);

//This is an inner function. It frees a movesList list
void _freeMovesList(moveCell* move);

//This function frees a board
void freeBoard(char** board);

#endif