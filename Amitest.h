//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef Amitest
#define Amitest
#define _CRT_SECURE_NO_WARNINGS
#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "tree.h"


bool ex6Test(char file_name[], char input_moves_str[], char* input_board);
void test_ex_6_main();
bool compareBoardPosPP(boardPosArray** arr1, boardPosArray** arr2);

bool compareMovesArrayPP(movesArray** inputMoves, movesArray** outputMoves);

bool ex1Test(char* input_board, char* input_moves, char* output_moves, char* output_pos);

movesArray** getMovesArrayFromStr(char input[]);

boardPosArray** getBoardPosArrayPPFromStr(char input[]);

boardPosArray* getBoardPosArrayPFromStr(char input[]);

void printPositions(boardPosArray** arr);

void printMovesArray(movesArray** arr);

movesList* getMovesListFromStr(char input[]);

char** getBoardFromStr(char* input);

movesArray create_movesArray();

char** getBoardCopy(char** board);

movesList* makePEmptyList_movesList();

movesList makeEmptyList_movesList();

void insertDataToEnd_movesList(movesList* list, char rows, char cols);

bool isEmptyList_movesList(movesList list);

void insertNodeToArr_movesArray(movesArray* array, Move move);

moveCell* createCell_movesList(char rows, char cols);

Move create_Move(int row, int col);

void printBinFile(char file_name[]);

void insertTo_boardPosArray(boardPosArray* array, char row, char col);

/*bool ex2Test(char* input_board, char* output_board, char* input_moves, int expectToRemove, boardPos start);

bool ex4Test(char* input_board, char input_moves_str[], boardPos start, char output_moveList_str[]);



bool ex5Test(char file_name[], char input_board_pos[], char output_board_pos[]);

bool ex6Test(char file_name[], char input_moves_str[], char* input_board);
*/


#endif

