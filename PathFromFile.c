//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#define _CRT_SECURE_NO_WARNINGS
#include "PathFromFile.h"

int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board) {
	int result = 0;
	bool isExist;
	boardPosArray* arr = readFromBinFile(file_name, &isExist);
	if (!isExist)
		return -1;

	boardPosArray** validPositions = validMoves(moves, board);
	movesList* list=(movesList*)malloc(sizeof(movesList));
	checkMemoryAllocation(list);
	makeEmptyList(list);
    bool found = true;

    for (int i = 0; i < arr->size-1 && found; i++) {
        //Get current boardPos's coordinates
		char row = arr->positions[i][0]-'A';
		char col = arr->positions[i][1]-1;

		//Search for the next boardPos in the array inside the
		// nextPossiblePositions array in order to see if the path is valid:
		int j = 0;
		bool flag = false;
		while (j < validPositions[row][col].size && !flag){
			if (isValidPos((arr->positions[i + 1]), (validPositions[row][col].positions[j]))) { //if the next boardPos appears inside the validPositions->positions array
				Move move = getLastMove(arr->positions[i], arr->positions[i + 1]);
				insertDataToEndList(list, move);
				flag = true;// get out of the loop
			}
			j++;
		}
		if (!flag) //There is a boardPos that makes the path inValid.
			found = false;
	}
	if (!found){
		result = 1;
	}
	else{ //the path is valid
		int removedMoves = display(list, arr->positions[0], board);
		if (arr->size - removedMoves == getCountOfEmptyCells(board))
			result = 2;
		else{
			result = 3;
		}
	}

    freeMovesList(list);
    freeBoardPosArr(arr);
    freeBoardPosArrayMatrix(validPositions);
    return result;
}

bool isValidPos(boardPos next, boardPos valid){
	if (next[0]==valid[0] && next[1]==valid[1])
		return true;
	return false;
}

void freeBoardPosArrayMatrix(boardPosArray** matrix){
    for(int i=0 ;i < N ; i++)
        freeBoardPosArr(matrix[i]);
}


void freeBoardPosArr(boardPosArray* arr){
    free(arr->positions);
    free(arr);
}





