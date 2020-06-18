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
//#define twoFullPathes
//#define oneFullPath
//#define question5
//#define DanielsBoard
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

	char* fullBoard[] = {"        ",
                         "        ",
                         "  *     ",
                         "   *    ",
                         "  * *   ",
                         "   *    ",
                         "       *",
                         "**      ",};

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
	start4[0] = 'E';
	start4[1] = 4;
	
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

    movesarr[toNumeric('E')][3].size = 1;
    movesarr[toNumeric('E')][3].moves[0].rows = -1;
    movesarr[toNumeric('E')][3].moves[0].cols = 1;
    //1
    movesarr[toNumeric('D')][4].size = 1;
    movesarr[toNumeric('D')][4].moves[0].rows = -3;
    movesarr[toNumeric('D')][4].moves[0].cols = -1;
    //2
    movesarr[toNumeric('A')][3].size = 1;
    movesarr[toNumeric('A')][3].moves[0].rows = 1;
    movesarr[toNumeric('A')][3].moves[0].cols = -3;
    //3
    movesarr[toNumeric('B')][0].size = 1;
    movesarr[toNumeric('B')][0].moves[0].rows = -1;
    movesarr[toNumeric('B')][0].moves[0].cols = 7;
    //4
    movesarr[toNumeric('A')][7].size = 1;
    movesarr[toNumeric('A')][7].moves[0].rows = 6;
    movesarr[toNumeric('A')][7].moves[0].cols = -7;
    //5
    movesarr[toNumeric('G')][0].size = 1;
    movesarr[toNumeric('G')][0].moves[0].rows = -3;
    movesarr[toNumeric('G')][0].moves[0].cols = 2;
    //6
    movesarr[toNumeric('D')][2].size = 1;
    movesarr[toNumeric('D')][2].moves[0].rows = -2;
    movesarr[toNumeric('D')][2].moves[0].cols = 3;
    //7
    movesarr[toNumeric('B')][5].size = 1;
    movesarr[toNumeric('B')][5].moves[0].rows = 5;
    movesarr[toNumeric('B')][5].moves[0].cols = 1;
    //8
    movesarr[toNumeric('G')][6].size = 1;
    movesarr[toNumeric('G')][6].moves[0].rows = 1;
    movesarr[toNumeric('G')][6].moves[0].cols = -3;
    //9
    movesarr[toNumeric('H')][3].size = 1;
    movesarr[toNumeric('H')][3].moves[0].rows = -2;
    movesarr[toNumeric('H')][3].moves[0].cols = -3;
    //10
    movesarr[toNumeric('F')][0].size = 1;
    movesarr[toNumeric('F')][0].moves[0].rows = 2;
    movesarr[toNumeric('F')][0].moves[0].cols = 2;
    //11
    movesarr[toNumeric('H')][2].size = 1;
    movesarr[toNumeric('H')][2].moves[0].rows = -2;
    movesarr[toNumeric('H')][2].moves[0].cols = 2;
    //12
    movesarr[toNumeric('F')][4].size = 1;
    movesarr[toNumeric('F')][4].moves[0].rows = -2;
    movesarr[toNumeric('F')][4].moves[0].cols = 3;
    //13
    movesarr[toNumeric('D')][7].size = 1;
    movesarr[toNumeric('D')][7].moves[0].rows = -1;
    movesarr[toNumeric('D')][7].moves[0].cols = -7;
    //14
    movesarr[toNumeric('C')][0].size = 1;
    movesarr[toNumeric('C')][0].moves[0].rows = 0;
    movesarr[toNumeric('C')][0].moves[0].cols = 1;
    //15
    movesarr[toNumeric('C')][1].size = 2;
    movesarr[toNumeric('C')][1].moves[0].rows = 0;
    movesarr[toNumeric('C')][1].moves[0].cols = 2;
    movesarr[toNumeric('C')][1].moves[1].rows = 0; //INVALID
    movesarr[toNumeric('C')][1].moves[1].cols = 1; //INVALID
    //16
    movesarr[toNumeric('C')][3].size = 1;
    movesarr[toNumeric('C')][3].moves[0].rows = -1;
    movesarr[toNumeric('C')][3].moves[0].cols = 0;
    //17
    movesarr[toNumeric('B')][3].size = 1;
    movesarr[toNumeric('B')][3].moves[0].rows = 6;
    movesarr[toNumeric('B')][3].moves[0].cols = 2;
    //18
    movesarr[toNumeric('H')][5].size = 1;
    movesarr[toNumeric('H')][5].moves[0].rows = 0;
    movesarr[toNumeric('H')][5].moves[0].cols = -1;
    //19
    movesarr[toNumeric('H')][4].size = 1;
    movesarr[toNumeric('H')][4].moves[0].rows = -1;
    movesarr[toNumeric('H')][4].moves[0].cols = 0;
    //20
    movesarr[toNumeric('G')][4].size = 1;
    movesarr[toNumeric('G')][4].moves[0].rows = -2;
    movesarr[toNumeric('G')][4].moves[0].cols = 2;
    //21
    movesarr[toNumeric('E')][6].size = 1;
    movesarr[toNumeric('E')][6].moves[0].rows = -3;
    movesarr[toNumeric('E')][6].moves[0].cols = -5;
    //22
    movesarr[toNumeric('B')][1].size = 1;
    movesarr[toNumeric('B')][1].moves[0].rows = 6;
    movesarr[toNumeric('B')][1].moves[0].cols = 5;
    //23
    movesarr[toNumeric('H')][6].size = 1;
    movesarr[toNumeric('H')][6].moves[0].rows = 0;
    movesarr[toNumeric('H')][6].moves[0].cols = 1;
    //24
    movesarr[toNumeric('H')][7].size = 1;
    movesarr[toNumeric('H')][7].moves[0].rows = -5;
    movesarr[toNumeric('H')][7].moves[0].cols = -1;
    //25
    movesarr[toNumeric('C')][6].size = 1;
    movesarr[toNumeric('C')][6].moves[0].rows = 4;
    movesarr[toNumeric('C')][6].moves[0].cols = -5;
    //26
    movesarr[toNumeric('G')][1].size = 1;
    movesarr[toNumeric('G')][1].moves[0].rows = -2;
    movesarr[toNumeric('G')][1].moves[0].cols = -1;
    //27
    movesarr[toNumeric('E')][0].size = 1;
    movesarr[toNumeric('E')][0].moves[0].rows = -4;
    movesarr[toNumeric('E')][0].moves[0].cols = 5;
    //28
    movesarr[toNumeric('A')][5].size = 1;
    movesarr[toNumeric('A')][5].moves[0].rows = 0;
    movesarr[toNumeric('A')][5].moves[0].cols = -5;
    //29
    movesarr[toNumeric('A')][0].size = 1;
    movesarr[toNumeric('A')][0].moves[0].rows = 3;
    movesarr[toNumeric('A')][0].moves[0].cols = 5;
    //30
    movesarr[toNumeric('D')][5].size = 1;
    movesarr[toNumeric('D')][5].moves[0].rows = 2;
    movesarr[toNumeric('D')][5].moves[0].cols = -3;
    //31
    movesarr[toNumeric('F')][2].size = 1;
    movesarr[toNumeric('F')][2].moves[0].rows = -1;
    movesarr[toNumeric('F')][2].moves[0].cols = -1;
    //32
    movesarr[toNumeric('E')][1].size = 1;
    movesarr[toNumeric('E')][1].moves[0].rows = 1;
    movesarr[toNumeric('E')][1].moves[0].cols = 0;
    //33
    movesarr[toNumeric('F')][1].size = 1;
    movesarr[toNumeric('F')][1].moves[0].rows = 1;
    movesarr[toNumeric('F')][1].moves[0].cols = 1;
    //34
    movesarr[toNumeric('G')][2].size = 1;
    movesarr[toNumeric('G')][2].moves[0].rows = -4;
    movesarr[toNumeric('G')][2].moves[0].cols = 2;
    //35
    movesarr[toNumeric('C')][4].size = 1;
    movesarr[toNumeric('C')][4].moves[0].rows = 3;
    movesarr[toNumeric('C')][4].moves[0].cols = 2;
    //36
    movesarr[toNumeric('F')][6].size = 3;
    movesarr[toNumeric('F')][6].moves[0].rows = -1;
    movesarr[toNumeric('F')][6].moves[0].cols = -1;
    movesarr[toNumeric('F')][6].moves[1].rows = -1; //INVALID 1
    movesarr[toNumeric('F')][6].moves[1].cols = -2; //INVALID 1
    movesarr[toNumeric('F')][6].moves[2].rows = -1; //INVALID 2
    movesarr[toNumeric('F')][6].moves[2].cols = -3; //INVALID 2
    //37
    movesarr[toNumeric('E')][5].size = 1;
    movesarr[toNumeric('E')][5].moves[0].rows = 1;
    movesarr[toNumeric('E')][5].moves[0].cols = 0;
    //38
    movesarr[toNumeric('F')][5].size = 1;
    movesarr[toNumeric('F')][5].moves[0].rows = 1;
    movesarr[toNumeric('F')][5].moves[0].cols = -2;
    //39
    movesarr[toNumeric('G')][3].size = 1;
    movesarr[toNumeric('G')][3].moves[0].rows = -5;
    movesarr[toNumeric('G')][3].moves[0].cols = 3;
    //40
    movesarr[toNumeric('B')][6].size = 1;
    movesarr[toNumeric('B')][6].moves[0].rows = -1;
    movesarr[toNumeric('B')][6].moves[0].cols = 0;
    //41
    movesarr[toNumeric('A')][6].size = 1;
    movesarr[toNumeric('A')][6].moves[0].rows = 3;
    movesarr[toNumeric('A')][6].moves[0].cols = -5;
    //42
    movesarr[toNumeric('D')][1].size = 1;
    movesarr[toNumeric('D')][1].moves[0].rows = 0;
    movesarr[toNumeric('D')][1].moves[0].cols = -1;
    //43
    movesarr[toNumeric('D')][0].size = 1;
    movesarr[toNumeric('D')][0].moves[0].rows = 3;
    movesarr[toNumeric('D')][0].moves[0].cols = 5;
    //44
    movesarr[toNumeric('G')][5].size = 1;
    movesarr[toNumeric('G')][5].moves[0].rows = -1;
    movesarr[toNumeric('G')][5].moves[0].cols = 2;
    //45
    movesarr[toNumeric('F')][7].size = 1;
    movesarr[toNumeric('F')][7].moves[0].rows = -1;
    movesarr[toNumeric('F')][7].moves[0].cols = 0;
    //46
    movesarr[toNumeric('E')][7].size = 1;
    movesarr[toNumeric('E')][7].moves[0].rows = -3;
    movesarr[toNumeric('E')][7].moves[0].cols = -5;
    //47
    movesarr[toNumeric('B')][2].size = 1;
    movesarr[toNumeric('B')][2].moves[0].rows = 2;
    movesarr[toNumeric('B')][2].moves[0].cols = 4;
    //48
    movesarr[toNumeric('D')][6].size = 1;
    movesarr[toNumeric('D')][6].moves[0].rows = -1;
    movesarr[toNumeric('D')][6].moves[0].cols = -1;
    //49
    movesarr[toNumeric('C')][5].size = 1;
    movesarr[toNumeric('C')][5].moves[0].rows = 0;
    movesarr[toNumeric('C')][5].moves[0].cols = 2;
    //50
    movesarr[toNumeric('C')][7].size = 1;
    movesarr[toNumeric('C')][7].moves[0].rows = -1;
    movesarr[toNumeric('C')][7].moves[0].cols = 0;
    //51
    movesarr[toNumeric('B')][7].size = 1;
    movesarr[toNumeric('B')][7].moves[0].rows = 0;
    movesarr[toNumeric('B')][7].moves[0].cols = -3;
    //52
    movesarr[toNumeric('B')][4].size = 1;
    movesarr[toNumeric('B')][4].moves[0].rows = -1;
    movesarr[toNumeric('B')][4].moves[0].cols = 0;
    //53

    movesarr[toNumeric('A')][4].size = 1;
    movesarr[toNumeric('A')][4].moves[0].rows = 0;
    movesarr[toNumeric('A')][4].moves[0].cols = -2;
    //54
    movesarr[toNumeric('A')][2].size = 1;
    movesarr[toNumeric('A')][2].moves[0].rows = 0;
    movesarr[toNumeric('A')][2].moves[0].cols = -1;
    //55

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
	posArr.size = 56; //9
	posArr.positions = (boardPos*)malloc(sizeof(boardPos) * posArr.size);
	checkMemoryAllocation(posArr.positions);

#ifdef DanielsBoard
	posArr.positions[0][0] = 'A'; //A
	posArr.positions[0][1] = 1; //1

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
#endif

    int i, j;
    movesArray** movesarr = (movesArray**)malloc(sizeof(movesArray*) * N);
    for (i = 0; i < N; i++)
    {
        movesarr[i] = (movesArray*)malloc(sizeof(movesArray) * M);
        for (j = 0; j < M; j++)
        {
            movesarr[i][j].moves = (Move*)malloc(sizeof(Move) * 3);
            movesarr[i][j].size = 1;
        }
    }

    //start
    posArr.positions[0][0] = 'E';
    posArr.positions[0][1] = 4;
    movesarr[toNumeric('E')][3].size = 1;
    movesarr[toNumeric('E')][3].moves[0].rows = -1;
    movesarr[toNumeric('E')][3].moves[0].cols = 1;
	//1
    posArr.positions[1][0] = 'D';
    posArr.positions[1][1] = 5;
    movesarr[toNumeric('D')][4].size = 1;
    movesarr[toNumeric('D')][4].moves[0].rows = -3;
    movesarr[toNumeric('D')][4].moves[0].cols = -1;
    //2
    posArr.positions[2][0] = 'A'; //A
    posArr.positions[2][1] = 4; //1
    movesarr[toNumeric('A')][3].size = 1;
    movesarr[toNumeric('A')][3].moves[0].rows = 1;
    movesarr[toNumeric('A')][3].moves[0].cols = -3;
    //3
    posArr.positions[3][0] = 'B'; //A
    posArr.positions[3][1] = 1; //1
    movesarr[toNumeric('B')][0].size = 1;
    movesarr[toNumeric('B')][0].moves[0].rows = -1;
    movesarr[toNumeric('B')][0].moves[0].cols = 7;
    //4
    posArr.positions[4][0] = 'A'; //A
    posArr.positions[4][1] = 8; //1
    movesarr[toNumeric('A')][7].size = 1;
    movesarr[toNumeric('A')][7].moves[0].rows = 6;
    movesarr[toNumeric('A')][7].moves[0].cols = -7;
    //5
    posArr.positions[5][0] = 'G'; //A
    posArr.positions[5][1] = 1; //1
    movesarr[toNumeric('G')][0].size = 1;
    movesarr[toNumeric('G')][0].moves[0].rows = -3;
    movesarr[toNumeric('G')][0].moves[0].cols = 2;
    //6
    posArr.positions[6][0] = 'D'; //A
    posArr.positions[6][1] = 3; //1
    movesarr[toNumeric('D')][2].size = 1;
    movesarr[toNumeric('D')][2].moves[0].rows = -2;
    movesarr[toNumeric('D')][2].moves[0].cols = 3;
    //7
    posArr.positions[7][0] = 'B'; //A
    posArr.positions[7][1] = 6; //1
    movesarr[toNumeric('B')][5].size = 1;
    movesarr[toNumeric('B')][5].moves[0].rows = 5;
    movesarr[toNumeric('B')][5].moves[0].cols = 1;
    //8
    posArr.positions[8][0] = 'G'; //A
    posArr.positions[8][1] = 7; //1
    movesarr[toNumeric('G')][6].size = 1;
    movesarr[toNumeric('G')][6].moves[0].rows = 1;
    movesarr[toNumeric('G')][6].moves[0].cols = -3;
    //9
    posArr.positions[9][0] = 'H'; //A
    posArr.positions[9][1] = 4; //1
    movesarr[toNumeric('H')][3].size = 1;
    movesarr[toNumeric('H')][3].moves[0].rows = -2;
    movesarr[toNumeric('H')][3].moves[0].cols = -3;
    //10
    posArr.positions[10][0] = 'F'; //A
    posArr.positions[10][1] = 1; //1
    movesarr[toNumeric('F')][0].size = 1;
    movesarr[toNumeric('F')][0].moves[0].rows = 2;
    movesarr[toNumeric('F')][0].moves[0].cols = 2;
    //11
    posArr.positions[11][0] = 'H'; //A
    posArr.positions[11][1] = 3; //1
    movesarr[toNumeric('H')][2].size = 1;
    movesarr[toNumeric('H')][2].moves[0].rows = -2;
    movesarr[toNumeric('H')][2].moves[0].cols = 2;
    //12
    posArr.positions[12][0] = 'F'; //A
    posArr.positions[12][1] = 5; //1
    movesarr[toNumeric('F')][4].size = 1;
    movesarr[toNumeric('F')][4].moves[0].rows = -2;
    movesarr[toNumeric('F')][4].moves[0].cols = 3;
    //13
    posArr.positions[13][0] = 'D'; //A
    posArr.positions[13][1] = 8; //1
    movesarr[toNumeric('D')][7].size = 1;
    movesarr[toNumeric('D')][7].moves[0].rows = -1;
    movesarr[toNumeric('D')][7].moves[0].cols = -7;
    //14
    posArr.positions[14][0] = 'C'; //A
    posArr.positions[14][1] = 1; //1
    movesarr[toNumeric('C')][0].size = 1;
    movesarr[toNumeric('C')][0].moves[0].rows = 0;
    movesarr[toNumeric('C')][0].moves[0].cols = 1;
    //15
    posArr.positions[15][0] = 'C'; //A
    posArr.positions[15][1] = 2; //1
    movesarr[toNumeric('C')][1].size = 2;
    movesarr[toNumeric('C')][1].moves[0].rows = 0;
    movesarr[toNumeric('C')][1].moves[0].cols = 2;
    movesarr[toNumeric('C')][1].moves[1].rows = 0; //INVALID
    movesarr[toNumeric('C')][1].moves[1].cols = 1; //INVALID
    //16
    posArr.positions[16][0] = 'C'; //A
    posArr.positions[16][1] = 4; //1
    movesarr[toNumeric('C')][3].size = 1;
    movesarr[toNumeric('C')][3].moves[0].rows = -1;
    movesarr[toNumeric('C')][3].moves[0].cols = 0;
    //17
    posArr.positions[17][0] = 'B'; //A
    posArr.positions[17][1] = 4; //1
    movesarr[toNumeric('B')][3].size = 1;
    movesarr[toNumeric('B')][3].moves[0].rows = 6;
    movesarr[toNumeric('B')][3].moves[0].cols = 2;
    //18
    posArr.positions[18][0] = 'H'; //A
    posArr.positions[18][1] = 6; //1
    movesarr[toNumeric('H')][5].size = 1;
    movesarr[toNumeric('H')][5].moves[0].rows = 0;
    movesarr[toNumeric('H')][5].moves[0].cols = -1;
    //19
    posArr.positions[19][0] = 'H'; //A
    posArr.positions[19][1] = 5; //1
    movesarr[toNumeric('H')][4].size = 1;
    movesarr[toNumeric('H')][4].moves[0].rows = -1;
    movesarr[toNumeric('H')][4].moves[0].cols = 0;
    //20
    posArr.positions[20][0] = 'G'; //A
    posArr.positions[20][1] = 5; //1
    movesarr[toNumeric('G')][4].size = 1;
    movesarr[toNumeric('G')][4].moves[0].rows = -2;
    movesarr[toNumeric('G')][4].moves[0].cols = 2;
    //21
    posArr.positions[21][0] = 'E'; //A
    posArr.positions[21][1] = 7; //1
    movesarr[toNumeric('E')][6].size = 1;
    movesarr[toNumeric('E')][6].moves[0].rows = -3;
    movesarr[toNumeric('E')][6].moves[0].cols = -5;
    //22
    posArr.positions[22][0] = 'B'; //A
    posArr.positions[22][1] = 2; //1
    movesarr[toNumeric('B')][1].size = 1;
    movesarr[toNumeric('B')][1].moves[0].rows = 6;
    movesarr[toNumeric('B')][1].moves[0].cols = 5;
    //23
    posArr.positions[23][0] = 'H'; //A
    posArr.positions[23][1] = 7; //1
    movesarr[toNumeric('H')][6].size = 1;
    movesarr[toNumeric('H')][6].moves[0].rows = 0;
    movesarr[toNumeric('H')][6].moves[0].cols = 1;
    //24
    posArr.positions[24][0] = 'H'; //A
    posArr.positions[24][1] = 8; //1
    movesarr[toNumeric('H')][7].size = 1;
    movesarr[toNumeric('H')][7].moves[0].rows = -5;
    movesarr[toNumeric('H')][7].moves[0].cols = -1;
    //25
    posArr.positions[25][0] = 'C'; //A
    posArr.positions[25][1] = 7; //1
    movesarr[toNumeric('C')][6].size = 1;
    movesarr[toNumeric('C')][6].moves[0].rows = 4;
    movesarr[toNumeric('C')][6].moves[0].cols = -5;
    //26
    posArr.positions[26][0] = 'G'; //A
    posArr.positions[26][1] = 2; //1
    movesarr[toNumeric('G')][1].size = 1;
    movesarr[toNumeric('G')][1].moves[0].rows = -2;
    movesarr[toNumeric('G')][1].moves[0].cols = -1;
    //27
    posArr.positions[27][0] = 'E'; //A
    posArr.positions[27][1] = 1; //1
    movesarr[toNumeric('E')][0].size = 1;
    movesarr[toNumeric('E')][0].moves[0].rows = -4;
    movesarr[toNumeric('E')][0].moves[0].cols = 5;
    //28
    posArr.positions[28][0] = 'A'; //A
    posArr.positions[28][1] = 6; //1
    movesarr[toNumeric('A')][5].size = 1;
    movesarr[toNumeric('A')][5].moves[0].rows = 0;
    movesarr[toNumeric('A')][5].moves[0].cols = -5;
    //29
    posArr.positions[29][0] = 'A'; //A
    posArr.positions[29][1] = 1; //1
    movesarr[toNumeric('A')][0].size = 1;
    movesarr[toNumeric('A')][0].moves[0].rows = 3;
    movesarr[toNumeric('A')][0].moves[0].cols = 5;
    //30
    posArr.positions[30][0] = 'D'; //A
    posArr.positions[30][1] = 6; //1
    movesarr[toNumeric('D')][5].size = 1;
    movesarr[toNumeric('D')][5].moves[0].rows = 2;
    movesarr[toNumeric('D')][5].moves[0].cols = -3;
    //31
    posArr.positions[31][0] = 'F'; //A
    posArr.positions[31][1] = 3; //1
    movesarr[toNumeric('F')][2].size = 1;
    movesarr[toNumeric('F')][2].moves[0].rows = -1;
    movesarr[toNumeric('F')][2].moves[0].cols = -1;
    //32
    posArr.positions[32][0] = 'E'; //A
    posArr.positions[32][1] = 2; //1
    movesarr[toNumeric('E')][1].size = 1;
    movesarr[toNumeric('E')][1].moves[0].rows = 1;
    movesarr[toNumeric('E')][1].moves[0].cols = 0;
    //33
    posArr.positions[33][0] = 'F'; //A
    posArr.positions[33][1] = 2; //1
    movesarr[toNumeric('F')][1].size = 1;
    movesarr[toNumeric('F')][1].moves[0].rows = 1;
    movesarr[toNumeric('F')][1].moves[0].cols = 1;
    //34
    posArr.positions[34][0] = 'G'; //A
    posArr.positions[34][1] = 3; //1
    movesarr[toNumeric('G')][2].size = 1;
    movesarr[toNumeric('G')][2].moves[0].rows = -4;
    movesarr[toNumeric('G')][2].moves[0].cols = 2;
    //35
    posArr.positions[35][0] = 'C'; //A
    posArr.positions[35][1] = 5; //1
    movesarr[toNumeric('C')][4].size = 1;
    movesarr[toNumeric('C')][4].moves[0].rows = 3;
    movesarr[toNumeric('C')][4].moves[0].cols = 2;
    //36
    posArr.positions[36][0] = 'F'; //A
    posArr.positions[36][1] = 7; //1
    movesarr[toNumeric('F')][6].size = 3;
    movesarr[toNumeric('F')][6].moves[0].rows = -1;
    movesarr[toNumeric('F')][6].moves[0].cols = -1;
    movesarr[toNumeric('F')][6].moves[1].rows = -1; //INVALID 1
    movesarr[toNumeric('F')][6].moves[1].cols = -2; //INVALID 1
    movesarr[toNumeric('F')][6].moves[2].rows = -1; //INVALID 2
    movesarr[toNumeric('F')][6].moves[2].cols = -3; //INVALID 2
    //37
    posArr.positions[37][0] = 'E'; //A
    posArr.positions[37][1] = 6; //1
    movesarr[toNumeric('E')][5].size = 1;
    movesarr[toNumeric('E')][5].moves[0].rows = 1;
    movesarr[toNumeric('E')][5].moves[0].cols = 0;
    //38
    posArr.positions[38][0] = 'F'; //A
    posArr.positions[38][1] = 6; //1
    movesarr[toNumeric('F')][5].size = 1;
    movesarr[toNumeric('F')][5].moves[0].rows = 1;
    movesarr[toNumeric('F')][5].moves[0].cols = -2;
    //39
    posArr.positions[39][0] = 'G'; //A
    posArr.positions[39][1] = 4; //1
    movesarr[toNumeric('G')][3].size = 1;
    movesarr[toNumeric('G')][3].moves[0].rows = -5;
    movesarr[toNumeric('G')][3].moves[0].cols = 3;
    //40
    posArr.positions[40][0] = 'B'; //A
    posArr.positions[40][1] = 7; //1
    movesarr[toNumeric('B')][6].size = 1;
    movesarr[toNumeric('B')][6].moves[0].rows = -1;
    movesarr[toNumeric('B')][6].moves[0].cols = 0;
    //41
    posArr.positions[41][0] = 'A'; //A
    posArr.positions[41][1] = 7; //1
    movesarr[toNumeric('A')][6].size = 1;
    movesarr[toNumeric('A')][6].moves[0].rows = 3;
    movesarr[toNumeric('A')][6].moves[0].cols = -5;
    //42
    posArr.positions[42][0] = 'D'; //A
    posArr.positions[42][1] = 2; //1
    movesarr[toNumeric('D')][1].size = 1;
    movesarr[toNumeric('D')][1].moves[0].rows = 0;
    movesarr[toNumeric('D')][1].moves[0].cols = -1;
    //43
    posArr.positions[43][0] = 'D'; //A
    posArr.positions[43][1] = 1; //1
    movesarr[toNumeric('D')][0].size = 1;
    movesarr[toNumeric('D')][0].moves[0].rows = 3;
    movesarr[toNumeric('D')][0].moves[0].cols = 5;
    //44
    posArr.positions[44][0] = 'G'; //A
    posArr.positions[44][1] = 6; //1
    movesarr[toNumeric('G')][5].size = 1;
    movesarr[toNumeric('G')][5].moves[0].rows = -1;
    movesarr[toNumeric('G')][5].moves[0].cols = 2;
    //45
    posArr.positions[45][0] = 'F'; //A
    posArr.positions[45][1] = 8; //1
    movesarr[toNumeric('F')][7].size = 1;
    movesarr[toNumeric('F')][7].moves[0].rows = -1;
    movesarr[toNumeric('F')][7].moves[0].cols = 0;
    //46
    posArr.positions[46][0] = 'E'; //A
    posArr.positions[46][1] = 8; //1
    movesarr[toNumeric('E')][7].size = 1;
    movesarr[toNumeric('E')][7].moves[0].rows = -3;
    movesarr[toNumeric('E')][7].moves[0].cols = -5;
    //47
    posArr.positions[47][0] = 'B'; //A
    posArr.positions[47][1] = 3; //1
    movesarr[toNumeric('B')][2].size = 1;
    movesarr[toNumeric('B')][2].moves[0].rows = 2;
    movesarr[toNumeric('B')][2].moves[0].cols = 4;
    //48
    posArr.positions[48][0] = 'D'; //A
    posArr.positions[48][1] = 7; //1
    movesarr[toNumeric('D')][6].size = 1;
    movesarr[toNumeric('D')][6].moves[0].rows = -1;
    movesarr[toNumeric('D')][6].moves[0].cols = -1;
    //49
    posArr.positions[49][0] = 'C'; //A
    posArr.positions[49][1] = 6; //1
    movesarr[toNumeric('C')][5].size = 1;
    movesarr[toNumeric('C')][5].moves[0].rows = 0;
    movesarr[toNumeric('C')][5].moves[0].cols = 2;
    //50
    posArr.positions[50][0] = 'C'; //A
    posArr.positions[50][1] = 8; //1
    movesarr[toNumeric('C')][7].size = 1;
    movesarr[toNumeric('C')][7].moves[0].rows = -1;
    movesarr[toNumeric('C')][7].moves[0].cols = 0;
    //51
    posArr.positions[51][0] = 'B'; //A
    posArr.positions[51][1] = 8; //1
    movesarr[toNumeric('B')][7].size = 1;
    movesarr[toNumeric('B')][7].moves[0].rows = 0;
    movesarr[toNumeric('B')][7].moves[0].cols = -3;
    //52
    posArr.positions[52][0] = 'B'; //A
    posArr.positions[52][1] = 5; //1
    movesarr[toNumeric('B')][4].size = 1;
    movesarr[toNumeric('B')][4].moves[0].rows = -1;
    movesarr[toNumeric('B')][4].moves[0].cols = 0;
    //53
    posArr.positions[53][0] = 'A'; //A
    posArr.positions[53][1] = 5; //1
    movesarr[toNumeric('A')][4].size = 1;
    movesarr[toNumeric('A')][4].moves[0].rows = 0;
    movesarr[toNumeric('A')][4].moves[0].cols = -2;
    //54
    posArr.positions[54][0] = 'A'; //A
    posArr.positions[54][1] = 3; //1
    movesarr[toNumeric('A')][2].size = 1;
    movesarr[toNumeric('A')][2].moves[0].rows = 0;
    movesarr[toNumeric('A')][2].moves[0].cols = -1;
    //55
    posArr.positions[55][0] = 'A'; //A
    posArr.positions[55][1] = 2; //1



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

//	int i, j;
//	movesArray** movesarr = (movesArray**)malloc(sizeof(movesArray*) * N);
//	for (i = 0; i < N; i++)
//	{
//		movesarr[i] = (movesArray*)malloc(sizeof(movesArray) * M);
//		for (j = 0; j < M; j++)
//		{
//			movesarr[i][j].moves = (Move*)malloc(sizeof(Move) * 3);
//			movesarr[i][j].size = 0;
//		}
//	}
//	movesarr[0][0].size = 1;
//	movesarr[0][0].moves[0].rows = 2;
//	movesarr[0][0].moves[0].cols = 2;
//
//	movesarr[2][2].size = 3;
//	movesarr[2][2].moves[0].rows = 0;
//	movesarr[2][2].moves[0].cols = -1;
//	movesarr[2][2].moves[1].rows = -1;
//	movesarr[2][2].moves[1].cols = 0;
//	movesarr[2][2].moves[2].rows = -2;
//	movesarr[2][2].moves[2].cols = 0;
//
//	movesarr[1][2].size = 2;
//	movesarr[1][2].moves[0].rows = -1;
//	movesarr[1][2].moves[0].cols = -1;
//	movesarr[1][2].moves[1].rows = 0;
//	movesarr[1][2].moves[1].cols = -1;
//
//	movesarr[0][1].size = 2;
//	movesarr[0][1].moves[0].rows = 2;
//	movesarr[0][1].moves[0].cols = 1;
//	movesarr[0][1].moves[1].rows = 0;
//	movesarr[0][1].moves[1].cols = 1;
//
//	movesarr[0][2].size = 1;
//	movesarr[0][2].moves[0].rows = 1;
//	movesarr[0][2].moves[0].cols = -2;
//
//	movesarr[1][0].size = 1;
//	movesarr[1][0].moves[0].rows = 1;
//	movesarr[1][0].moves[0].cols = 0;
//
//	movesarr[2][0].size = 1;
//	movesarr[2][0].moves[0].rows = 0;
//	movesarr[2][0].moves[0].cols = 1;

	char* file_name = "Positions.bin";
	int res = checkAndDisplayPathFromFile(file_name, movesarr, fullBoard);
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


