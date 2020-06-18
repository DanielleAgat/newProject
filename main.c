//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601


#define _CRT_SECURE_NO_WARNINGS
#include "Types.h"
#include "BinFile.h"
#include "ErrorsHandlings.h"
#include "MovesArray.h"
#include "MovesList.h"
#include "PathCalculation.h"
#include "PathFromFile.h"
#include "tree.h"

//// Test Libraries !!! ///
#include "List_Tests.h"
//#include "Amitest.h"


//#define question1
//#define question2
//#define question3
#define question4
#define twoFullPathes
#define oneFullPath
//#define question5
//#define question5Amit
//#define question6

int main() {

	/*char* board[] = { "  *  ",
					  "*    ",
					  "    *",
					  "  * *" };*/
	char* board1[] = { "   ",
					   " * ",
					   "   " };
		         
	char* boardMini[] = { "  * ","*   " };

	char* emptyBoard[] = { "     ",
						   "     ",
						   "     ",
						   "     " };

	///////////////    Question 1 tests:    ///////////////
#ifdef question1
	movesArray** moves;
	boardPosArray** positionsArray;
	int i, j;
	moves = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	initMovesArray(moves);
	PrintBoard(board);
	printf("\n");
	PrintMovesBoard(moves);
	printf("\n");
	positionsArray = validMoves(moves, board);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int indexPos = 0;
			while (indexPos < positionsArray[i][j].size) {
				printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray[i][j].positions[indexPos][0], positionsArray[i][j].positions[indexPos][1]);
				printf("\n");
				indexPos++;
			}
		}
	}
#endif

	///////////////    Question 2 tests:    ///////////////
#ifdef question2
	boardPos start = { 'A',2 };
	movesList list = getListFromUser();
	printList(list);

	int removedCells = display(&list, start, board);
	printf("Number of invalid moves that were removed: %d", removedCells);

#endif question2

	///////////////    Question 3 tests:    ///////////////
#ifdef question3
	movesArray** moves3;
	pathTree tree;
	boardPos start;
	boardPosArray** positionsArray3;
	int i, j;
	moves3 = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves3[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	start[0] = 'C';
	start[1] = 3;

	initMovesArray(moves3);
	//    positionsArray3 = validMoves(moves3,board);
	//    PrintMovesBoard(moves3);

	//    for (i = 0; i < N; i++){
	//        for (j = 0; j < M; j++){
	//            int indexPos = 0;
	//            while (indexPos < positionsArray3[i][j].size){
	//                printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray3[i][j].positions[indexPos][0], positionsArray3[i][j].positions[indexPos][1]);
	//                printf("\n");
	//                indexPos++;
	//            }
	//        }
	//    }

	tree = findAllPossiblePaths(start, moves3, board);
#endif question3

	///////////////    Question 4 tests:    ///////////////
#ifdef question4
	int i, j;
	boardPos start4;
	movesList* list;
	start4[0] = 'A';
	start4[1] = 1;	
	
	movesArray** movesarr = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++)
	{
		movesarr[i] = (movesArray*)malloc(sizeof(movesArray) * M);
		for (j = 0; j < M; j++)
		{
			movesarr[i][j].moves = (Move*)malloc(sizeof(Move) * 3);
			movesarr[i][j].size = 0;
		}
	}

#ifdef twoFullPaths
	movesarr[0][0].size = 1;
	movesarr[0][0].moves[0].rows = 2;
	movesarr[0][0].moves[0].cols = 2;

	movesarr[2][2].size = 3;
	movesarr[2][2].moves[0].rows = 0;
	movesarr[2][2].moves[0].cols = -1;
	movesarr[2][2].moves[1].rows = -1;
	movesarr[2][2].moves[1].cols = 0;
	movesarr[2][2].moves[2].rows = -2;
	movesarr[2][2].moves[2].cols = 0;

	movesarr[1][2].size = 2;
	movesarr[1][2].moves[0].rows = -1;
	movesarr[1][2].moves[0].cols = -1;
	movesarr[1][2].moves[1].rows = 0;
	movesarr[1][2].moves[1].cols = -1;

	movesarr[0][1].size = 2;
	movesarr[0][1].moves[0].rows = 2;
	movesarr[0][1].moves[0].cols = 1;
	movesarr[0][1].moves[1].rows = 0;
	movesarr[0][1].moves[1].cols = 1;

	movesarr[0][2].size = 1;
	movesarr[0][2].moves[0].rows = 1;
	movesarr[0][2].moves[0].cols = -2;

	movesarr[1][0].size = 2;
	movesarr[1][0].moves[0].rows = 1;
	movesarr[1][0].moves[0].cols = 0;
	movesarr[1][0].moves[1].rows = 1;
	movesarr[1][0].moves[1].cols = 1;

	movesarr[2][0].size = 1;
	movesarr[2][0].moves[0].rows = 0;
	movesarr[2][0].moves[0].cols = 1;

	movesarr[2][1].size = 1;
	movesarr[2][1].moves[0].rows = 0;
	movesarr[2][1].moves[0].cols = -1;
#endif

#ifdef oneFullPath
    movesarr[0][0].size = 1;  //A1
    movesarr[0][0].moves[0].rows = 2;
    movesarr[0][0].moves[0].cols = 2;

    movesarr[2][2].size = 1;  //C3
    movesarr[2][2].moves[0].rows = -1;
    movesarr[2][2].moves[0].cols = 0;

    movesarr[1][2].size = 1;  //B3
    movesarr[1][2].moves[0].rows = -1;
    movesarr[1][2].moves[0].cols = -1;

    movesarr[0][1].size = 1;  //A2
    movesarr[0][1].moves[0].rows = 0;
    movesarr[0][1].moves[0].cols = 1;

    movesarr[0][2].size = 1;  //A3
    movesarr[0][2].moves[0].rows = 1;
    movesarr[0][2].moves[0].cols = -2;

    movesarr[1][0].size = 1;  //B1
    movesarr[1][0].moves[0].rows = 1;
    movesarr[1][0].moves[0].cols = 0;

    movesarr[2][0].size = 1; //C1
    movesarr[2][0].moves[0].rows = 0;
    movesarr[2][0].moves[0].cols = 1; //C2

#endif

    list = findPathCoveringAllBoard(start4, movesarr, board1);
	if (list == NULL)
		printf("There is no path!");
	else
		printList(*list); 

	/*movesArray** moves4;
	boardPos start4;
	movesList* list;
	int i, j;
	moves4 = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves4[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	start4[0] = 'A';
	start4[1] = 2;

	initMovesArray(moves4);
	list = findPathCoveringAllBoard(start4, moves4, boardMini);

	if (list == NULL)
		printf("There is no path!");
	else
		printList(*list);*/
#endif

	///////////////    Question 5 tests:    ///////////////
#ifdef question5
	boardPosArray posArr;
	posArr.size = 9;
	posArr.positions = (boardPos*)malloc(sizeof(boardPos) * 9);
	boardPos pos;

	posArr.positions[0][0] = 'A';
	posArr.positions[0][1] = 1;

	posArr.positions[1][0] = 'C';
	posArr.positions[1][1] = 3;

	posArr.positions[2][0] = 'B';
	posArr.positions[2][1] = 3;


	posArr.positions[3][0] = 'A';
	posArr.positions[3][1] = 2;

	posArr.positions[4][0] = 'C';
	posArr.positions[4][1] = 3;

	posArr.positions[5][0] = 'A';
	posArr.positions[5][1] = 3;

	posArr.positions[6][0] = 'B';
	posArr.positions[6][1] = 1;

	posArr.positions[7][0] = 'C';
	posArr.positions[7][1] = 1;

	posArr.positions[8][0] = 'C';
	posArr.positions[8][1] = 2;

	saveListToBinFile("Positions", &posArr);

	/*boardPosArray* arr = (boardPosArray*)malloc(sizeof(boardPosArray));
	arr->size = 11;
	arr->positions = (boardPos*)malloc(sizeof(boardPos) * arr->size);
	arr->positions[0][0] = 'A';
	arr->positions[0][1] = 2;
	arr->positions[0][0] = 'C';
	arr->positions[0][1] = 4;
	arr->positions[0][0] = 'B';
	arr->positions[0][1] = 3;

	saveListToBinFile("TalEliptital", arr);*/

#endif


	///////////////    Question 5Amit tests:    ///////////////
#ifdef question5Amit
	char boardPos_array_str[] = "<3> (A,1) (C,2) (E,5)";


	//printf(" // Ex 5 Test 1 # EXPECTED -> GOOD\n                # RESULT   -> ");
	//printf(ex5Test("test1", boardPos_array_str, NULL) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str);
	char boardPos_array_str1[] = "<9> (A,1) (C,2) (E,5) (A,2) (A,3) (B,8) (H,8) (H,1) (F,7)";

	printf(" // Ex 5 Test 2 # EXPECTED -> GOOD\n                # RESULT   -> ");
	printf(ex5Test("test2", boardPos_array_str1, NULL) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str1);

	//printf(" // Ex 5 Test 3 # EXPECTED -> mistake at comparing boardPos`s.\n                # RESULT   -> ");
	//printf(ex5Test("test3", boardPos_array_str1, boardPos_array_str) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str);

	//printf(" // Ex 5 Test 4 # EXPECTED -> mistake at comparing boardPos`s.\n                # RESULT   -> ");
	//printf(ex5Test("test4", boardPos_array_str, boardPos_array_str1) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str1);

#endif

	///////////////    Question 6 tests:    ///////////////
#ifdef question6

	int i, j;
	movesArray** movesarr = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++)
	{
		movesarr[i] = (movesArray*)malloc(sizeof(movesArray) * M);
		for (j = 0; j < M; j++)
		{
			movesarr[i][j].moves = (Move*)malloc(sizeof(Move) * 3);
			movesarr[i][j].size = 0;
		}
	}
	movesarr[0][0].size = 1;
	movesarr[0][0].moves[0].rows = 2;
	movesarr[0][0].moves[0].cols = 2;

	movesarr[2][2].size = 3;
	movesarr[2][2].moves[0].rows = 0;
	movesarr[2][2].moves[0].cols = -1;
	movesarr[2][2].moves[1].rows = -1;
	movesarr[2][2].moves[1].cols = 0;
	movesarr[2][2].moves[2].rows = -2;
	movesarr[2][2].moves[2].cols = 0;

	movesarr[1][2].size = 2;
	movesarr[1][2].moves[0].rows = -1;
	movesarr[1][2].moves[0].cols = -1;
	movesarr[1][2].moves[1].rows = 0;
	movesarr[1][2].moves[1].cols = -1;
	
	movesarr[0][1].size = 2;
	movesarr[0][1].moves[0].rows = 2;
	movesarr[0][1].moves[0].cols = 1;
	movesarr[0][1].moves[1].rows = 0;
	movesarr[0][1].moves[1].cols = 1;

	movesarr[0][2].size = 1;
	movesarr[0][2].moves[0].rows = 1;
	movesarr[0][2].moves[0].cols = -2;

	movesarr[1][0].size = 1;
	movesarr[1][0].moves[0].rows = 1;
	movesarr[1][0].moves[0].cols = 0;
	
	movesarr[2][0].size = 1;
	movesarr[2][0].moves[0].rows = 0;
	movesarr[2][0].moves[0].cols = 1;

	char* file_name = "Positions.bin";
	int res = checkAndDisplayPathFromFile(file_name, movesarr, board1);
	printf("%d", res);
	//move.cols = 1;
	//move.rows = 0;
	//movesarr[2][0].moves[0] = move;
	//test_ex_6_main();
	/*movesArray** moves6;
	int i;
	moves6 = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves6[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	
	initMovesArray(moves6);
	char* file_name = "test2.bin";
	int res=checkAndDisplayPathFromFile(file_name, moves6, board);
	printf("%d", res);
	*/
#endif

	exit(0);
}


