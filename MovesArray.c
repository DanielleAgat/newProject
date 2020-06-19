//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "MovesArray.h"

void PrintBoard(char** board) {
	int i, j;
	char rowLetter = 'A';

	//	Print cols row:
	printf(" ");
	for (j = 1; j < (M + 1); j++) {
		printf("%*d", 4, j);
	}
	printf("\n");

	//    Print board:
	for (i = 0; i < N; i++) {
		printf("%c", rowLetter++); //print rows col
		for (j = 0; j < M; j++) {
			if (board[i][j] == TAKEN || board[i][j] == BLOCKED || board[i][j] == ' ')
				printf("%*c", 4, board[i][j]);
			else{
                if(board[i][j] == 100)
                    printf("%*d",4,32);
                else if(board[i][j] == 101)
                    printf("%*d",4,35);
                else if(board[i][j] == 102)
                    printf("%*d",4,42);
                else
                    printf("%*d", 4, board[i][j]);
			}
		}
		printf("\n");
	}
}


boardPosArray** validMoves(movesArray** moves, char** board) {
	boardPosArray** res = (boardPosArray**)malloc(sizeof(boardPosArray*) * N);
	checkMemoryAllocation(res);
	
	for (int i = 0; i < N; i++) {
		res[i] = (boardPosArray*)malloc(sizeof(boardPosArray) * M);
		checkMemoryAllocation(res[i]);
		for (int j = 0; j < M; j++) {
			int logsize = 0;
			Move* temp = (Move*)malloc(sizeof(Move) * moves[i][j].size);
			checkMemoryAllocation(temp);
			res[i][j].positions = (boardPos*)malloc(sizeof(boardPos) * moves[i][j].size);
            checkMemoryAllocation(res[i][j].positions);

			int indexMoves = 0;
			while (indexMoves < moves[i][j].size) {
				if (isValid(board, moves[i][j].moves[indexMoves], i, j)) {
					temp[logsize].rows = moves[i][j].moves[indexMoves].rows;
					temp[logsize].cols = moves[i][j].moves[indexMoves].cols;
					res[i][j].positions[logsize][0] = i + moves[i][j].moves[indexMoves].rows + 'A';
					res[i][j].positions[logsize][1] = j + moves[i][j].moves[indexMoves].cols + 1;
					logsize++;
				}
				indexMoves++;
			}
			if (logsize < indexMoves) {
				temp = (Move*)realloc(temp, (sizeof(Move)) * logsize);
				checkMemoryAllocation(temp);
				res[i][j].positions = (boardPos*)realloc(res[i][j].positions, (sizeof(boardPos)) * logsize);
				checkMemoryAllocation(res[i][j].positions);
			}

			moves[i][j].size = res[i][j].size = logsize;
			free(moves[i][j].moves);
			moves[i][j].moves = temp;
		}
	}
	return res;
}


bool isValid(char** board, Move cellDest, int i, int j) {
	char rowDest = cellDest.rows;
	char colDest = cellDest.cols;

	if (i + rowDest >= N || i + rowDest < 0 || j + colDest >= M || j + colDest < 0)
		return false;
	else if (board[i + rowDest][j + colDest] != ' ') 
		return false;
	else
		return true;
}