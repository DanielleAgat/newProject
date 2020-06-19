//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "tree.h"

pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board) {
	pathTree path;
	char** boardCopy = (char**)malloc(sizeof(char*) * N);
	checkMemoryAllocation(boardCopy);
	copyBoard(board, boardCopy, start);
	boardPosArray** toFree = validMoves(moves, board);
	freeBoardPosArrayMatrix(toFree);

	//    Declaring tree source :
	path.head = (treeNode*)malloc(sizeof(treeNode));
	checkMemoryAllocation(path.head);
	path.head->position[0] = start[0];
	path.head->position[1] = start[1];
	path.head->next_possible_positions = NULL;
	path.head = _findAllPossiblePaths(boardCopy, moves, start, path.head);

	freeBoard(boardCopy);
	return path;
}

treeNode* _findAllPossiblePaths(char** board, movesArray** moves, boardPos start, treeNode* node) {
	int startCol = start[1] - 1;
	int startRow = toNumeric(start[0]);
	int logSize = 0;
	boardPos changesInBoard[M * N];
	unsigned int numOfChild = moves[startRow][startCol].size;

	if (node == NULL && numOfChild != 0) {
		node = (treeNode*)malloc(sizeof(treeNode));
		checkMemoryAllocation(node);
		node->position[0] = start[0];
		node->position[1] = start[1];
		node->next_possible_positions = NULL;
	}

	for (unsigned int i = 0; i < numOfChild; i++) { //Runs as long as there are children to the boardPos
		int k = toNumeric(start[0]);
		int t = start[1] - 1;
		if (isValid(board, moves[startRow][startCol].moves[i], k, t)) {
			if (isEmptyList(node->next_possible_positions)) {
				node->next_possible_positions = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
				checkMemoryAllocation(node->next_possible_positions);
				node->next_possible_positions->next = NULL;
				node->next_possible_positions->node = NULL;
			}
			addCellToPath(board, start, moves[startRow][startCol].moves[i], TAKEN);
			node->next_possible_positions = insertValidPosToHead(node->next_possible_positions, start);
			changesInBoard[logSize][0] = start[0];
			changesInBoard[logSize++][1] = start[1];
			node->next_possible_positions->node = _findAllPossiblePaths(board, moves, start, node->next_possible_positions->node);

			//Return to original parameters:
			start[0] -= moves[startRow][startCol].moves[i].rows;
			start[1] -= moves[startRow][startCol].moves[i].cols;
			removeTakenPos(board, changesInBoard, logSize);
		}
	}
	return node;
}

treeNodeListCell* insertValidPosToHead(treeNodeListCell* lst, boardPos data) {
	treeNodeListCell* newListCell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	checkMemoryAllocation(newListCell);
	newListCell->node = createNode(data, NULL);
	newListCell->next = lst;
	return newListCell;
}

treeNode* createNode(boardPos data, treeNodeListCell* nextPossiblePosition) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	checkMemoryAllocation(newNode);
	newNode->position[0] = data[0];
	newNode->position[1] = data[1];
	newNode->next_possible_positions = nextPossiblePosition;
	return newNode;
}

void removeTakenPos(char** board, boardPos posToRemove[], int size) {
	for (int i = 0; i < size; i++) {
		int startCol = posToRemove[i][1] - 1;
		int startRow = toNumeric(posToRemove[i][0]);
		board[startRow][startCol] = ' ';
	}
}