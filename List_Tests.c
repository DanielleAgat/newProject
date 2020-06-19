//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "List_Tests.h"

movesList getListFromUser(){
    movesList res;
    int size,i;
    Move move;
    int rows, cols;

    makeEmptyList(&res);

    printf("Please enter the number of items to be entered:\n");
    scanf("%d", &size);

    printf("Please enter the numbers:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &rows);
        scanf("%d", &cols);
        move.rows = (char)rows;
        move.cols = (char)cols;
        insertDataToEndList(&res, move);
    }
    return res;
}

movesList getList(){
    movesList res;
    int size = 5,i;
    Move move;

    makeEmptyList(&res);

    for(i = 0; i < size; i++){
        move.rows = (char)((random() % 2 * 127) - 127);
        scanf("%c", &move.rows);
        scanf("%c", &move.cols);
        insertDataToEndList(&res, move);
    }
    return res;
}


void printList(movesList lst) {
	_print_list(lst.head);
}

void _print_list(moveCell* node) {
	while (node != NULL) {
		printf("row:%d col:%d\n", node->move.rows, node->move.cols);
		node = node->next;
	}
}


void initMovesArray(movesArray** moves) {
    int i, j;
//#define basicTest
#define coverAllBoard

#ifdef basicTest/*
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 && j == 0)
				moves[i][j].size = 5;
			else
				moves[i][j].size = 4;
			moves[i][j].moves = (Move*)malloc(sizeof(Move) * moves[i][j].size);
			moves[i][j].moves[0].rows = 2;
			moves[i][j].moves[0].cols = -2;
			moves[i][j].moves[1].rows = -2;
			moves[i][j].moves[1].cols = -2;
			moves[i][j].moves[2].rows = 2;
			moves[i][j].moves[2].cols = 2;
			moves[i][j].moves[3].rows = -2;
			moves[i][j].moves[3].cols = 2;
		}
	}

	//moves[0][0].moves[4].rows = 2;
	//moves[0][0].moves[4].cols = 1;
	*/
#endif

#ifdef coverAllBoard
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            moves[i][j].size = 1;
            moves[i][j].moves = (Move*)malloc(sizeof(Move) * moves[i][j].size);
            moves[i][j].moves[0].rows = 1;
            moves[i][j].moves[0].cols = 1;
        }
    }

    //    All board path
    moves[0][1].moves[0].rows = 0; //A2
    moves[0][1].moves[0].cols = 2;
    moves[0][3].moves[0].rows = 0; //A4
    moves[0][3].moves[0].cols = -3;
    moves[0][0].moves[0].rows = 1; //A1
    moves[0][0].moves[0].cols = 1;
    moves[1][1].moves[0].rows = 0; //B2
    moves[1][1].moves[0].cols = 2;
    moves[1][3].moves[0].rows = 0; //B4
    moves[1][3].moves[0].cols = -1;
    //Last = B3
#endif

}


void PrintMovesBoard(movesArray** moves) {
    char row_letter = 65;

    printf(" \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < moves[i][j].size; k++) {
                printf("row: %d col: %d \n", moves[i][j].moves[k].rows, moves[i][j].moves[k].cols);
            }
            printf("\n");
        }
        row_letter++;
        printf("\n");
    }
}