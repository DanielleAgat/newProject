#include "Amitest.h"


bool ex6Test(char file_name[], char input_moves_str[], char* input_board) {

	bool test1 = false;
	movesArray** inputMoves = getMovesArrayFromStr(input_moves_str);
	char** boardTemp = getBoardFromStr(input_board);
	int result = checkAndDisplayPathFromFile(file_name, inputMoves, boardTemp);

	if (result == -1) {
		test1 = true;
		printf("File does not exist");
	}
	else if (result == 1) {
		test1 = true;
		printf("Failed at locating legal path in Bin file");
	}
	else
		printf("Function returned: %d ", result);

	return !test1;
}

void test_ex_6_main() {

	char inputBoard6[] = "(A,2,3,4,5,6,7,8)(B,1,2,3,4,5,6,7,8)(C,1,3,4,5,6,7,8)(D,1,2,3,4,5,6,7,8)(E,1,2,3,4,6,7,8)(F,1,2,3,4,5,6,7,8)(G,1,2,3,4,5,6,7,8)(H,1,2,3,4,5,6,7,8)";
	char input_moves_str_6[] = "[<A,1>(2,1)][<C,2>(2,3)]";

	char boardPos_array_str6[] = "<3> (A,1) (C,2) (E,5)";
	boardPosArray* bp_arr = getBoardPosArrayPFromStr(boardPos_array_str6);
	saveListToBinFile("test1", bp_arr);

	//check if legal course in bin, expected 2
	printf(" // Ex 6 Test 1 # EXPECTED ->Function returned:2 GOOD	\n                 # RESULT   -> ");
	printf(ex6Test("test1", input_moves_str_6, inputBoard6) ? "GOOD\n\n" : "\n\n");

	char boardPos_array_str6_1[] = "<2> (A,1) (C,2) ";
	boardPosArray* bp_arr1 = getBoardPosArrayPFromStr(boardPos_array_str6_1);
	saveListToBinFile("test2", bp_arr1);

	//check if legal course in bin, expected 3
	printf(" // Ex 6 Test 2 # EXPECTED -> Function returned: 3 GOOD	\n                 # RESULT   -> ");
	printf(ex6Test("test2", input_moves_str_6, inputBoard6) ? "GOOD\n\n" : "\n\n");

	//bin.file does not exist
	printf(" // Ex 6 Test 3 # EXPECTED -> File does not exist\n                # RESULT   -> ");
	printf(ex6Test("does_not_exist.bin", input_moves_str_6, inputBoard6) ? "GOOD\n\n" : "\n\n");

	char input_moves_str_6_1[] = "[<A,1>(3,1)][<C,2>(2,3)]";
	saveListToBinFile("test4", bp_arr1);

	//no legal course in bin file
	printf(" // Ex 6 Test 4 # EXPECTED -> Failed at locating legal path in Bin file\n                # RESULT   -> ");
	printf(ex6Test("test4", input_moves_str_6_1, inputBoard6) ? "GOOD\n\n" : "\n\n");
}
bool compareBoardPosPP(boardPosArray** arr1, boardPosArray** arr2) {

	bool flag = false;
	for (int i = 0; i < N && !flag; i++)
		for (int j = 0; j < M && !flag; j++) {
			if (arr1[i][j].size != arr2[i][j].size) {
				flag = true;
				printf("Failed at boardPosArray compare.");
			}
			for (int k = 0; k < arr1[i][j].size && !flag; k++) {
				if (arr1[i][j].positions[k][0] != arr2[i][j].positions[k][0] ||
					arr1[i][j].positions[k][1] != arr2[i][j].positions[k][1]) {
					flag = true;
					printf("Failed at boardPosArray compare.");
				}
			}
		}

	return !flag;
}

bool compareMovesArrayPP(movesArray** inputMoves, movesArray** outputMoves) {

	bool flag = false;
	for (int i = 0; i < N && !flag; i++)
		for (int j = 0; j < M && !flag; j++) {
			if (inputMoves[i][j].size != outputMoves[i][j].size) {
				flag = true;
				printf("Failed at moveArray compare. ");
			}
			for (int k = 0; k < inputMoves[i][j].size && !flag; k++) {
				if (inputMoves[i][j].moves[k].rows != outputMoves[i][j].moves[k].rows ||
					inputMoves[i][j].moves[k].cols != outputMoves[i][j].moves[k].cols) {
					flag = true;
					printf("Failed at moveArray compare. ");
				}
			}
		}

	return !flag;
}
movesArray** getMovesArrayFromStr(char input[]) {
// char input1[] = "[<A,2>(1,0)(0,3)][<B,2>(-1,0)(-1,3)(8,2)][<A,5>(6,0)(6,-1)(6,-2)(7,0)][<G,8>(0,-2)(0,1)(1,0)(1,-5)]";
movesArray** pMovesArray = (movesArray**)malloc(N * sizeof(movesArray*));
checkMemoryAllocation(pMovesArray);
for (int i = 0; i < N; i++) {
	pMovesArray[i] = (movesArray*)malloc(M * sizeof(movesArray));
	checkMemoryAllocation(pMovesArray[i]);
	for (int j = 0; j < M; j++)
		pMovesArray[i][j] = create_movesArray();
}

int col, tempRow, tempCol;
char row;
for (int i = 0; i < strlen(input); i++)
	if (input[i] == '[') {
		sscanf(&input[++i], "<%c,%d>", &row, &col);
		while (input[i] != ']') {
			if (input[i] == '(') {
				sscanf(&input[i], "(%d,%d)", &tempRow, &tempCol);
				Move move = { tempRow, tempCol };
				insertNodeToArr_movesArray(&pMovesArray[toNumeric(row)][col - 1], move);
			}
			i++;
		}
	}

return pMovesArray;
}

boardPosArray** getBoardPosArrayPPFromStr(char input[]) {

	// "[<A,2>(B,2)(A,5)][<B,2>(A,2)(A,5)][<A,5>(G,5)(G,4)][<G,8>(G,6)(H,3)]";
	boardPosArray** result = (boardPosArray**)malloc(N * sizeof(boardPosArray*));
	checkMemoryAllocation(result);
	for (int i = 0; i < M; i++) {
		result[i] = (boardPosArray*)calloc(M, sizeof(boardPosArray));
		checkMemoryAllocation(result[i]);
	}

	int col, tempCol;
	char row, tempRow;
	for (int i = 0; i < strlen(input); i++)
		if (input[i] == '[') {
			sscanf(&input[++i], "<%c,%d>", &row, &col);
			while (input[i] != ']') {
				if (input[i] == '(') {
					sscanf(&input[i], "(%c,%d)", &tempRow, &tempCol);
					insertTo_boardPosArray(&result[toNumeric(row)][col - 1], tempRow, tempCol);
				}
				i++;
			}
		}

	return result;
}

boardPosArray* getBoardPosArrayPFromStr(char input[]) {

	// "<3> (A,1) (C,2) (E,3)"
	boardPosArray* result = (boardPosArray*)malloc(sizeof(boardPosArray));
	checkMemoryAllocation(result);
	sscanf(input, "<%d>", &result->size);
	input += 4;
	result->positions = (boardPos*)calloc(result->size, sizeof(boardPos));
	checkMemoryAllocation(result->positions);

	char row;
	int col, counter = 0;
	for (int i = 0; i < strlen(input); i++)
		if (input[i] == '(') {
			sscanf(&input[i], "(%c,%d)", &row, &col);
			result->positions[counter][0] = row;
			result->positions[counter++][1] = col;
		}

	return result;
}

void printPositions(boardPosArray** arr) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("|| [%d,%d] ", i, j);
			for (int k = 0; k < arr[i][j].size; k++)
				printf("(%d,%d) ", arr[i][j].positions[k][0], arr[i][j].positions[k][1]);
		}
		printf("\n");
	}
}

void printMovesArray(movesArray** arr) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("|| [%d,%d] ", i, j);
			for (int k = 0; k < arr[i][j].size; k++)
				printf("(%d,%d) ", arr[i][j].moves[k].rows, arr[i][j].moves[k].cols);
		}
		printf("\n");
	}
}

movesList* getMovesListFromStr(char input[]) {

	int rows, cols;
	movesList* pMovesList = makePEmptyList_movesList();

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '(') {
			sscanf(&input[i], "(%d,%d)", &rows, &cols);
			insertDataToEnd_movesList(pMovesList, rows, cols);
		}
	}

	return pMovesList;
}

char** getBoardFromStr(char* input) {

	char** inputBoard = (char**)calloc(N, sizeof(char*));
	checkMemoryAllocation(inputBoard);
	for (int i = 0; i < N; i++) {
		inputBoard[i] = (char*)calloc(M, sizeof(char));
		checkMemoryAllocation(inputBoard[i]);
		for (int j = 0; j < M; j++)
			inputBoard[i][j] = ' ';
	}

	for (int i = 0; i < strlen(input); i++)
		if (input[i] == '(') {
			int row = toNumeric(input[i + 1]);
			i += 2;
			while (input[i] != ')') {
				int col = input[++i] - '1';
				inputBoard[row][col] = '*';
				i++;
			}
		}

	return inputBoard;
}

char** getBoard_FILLED_FromStr(char** input_board, char* input_str) {

	// "<A,2>(B,2)(A,5)(G,5)(H,1)(H,3)(H,4)(G,4)(G,6)(G,7)(G,8)(B,8)";
	char** board = getBoardCopy(input_board);

	char row, counter = '1';
	int col;
	sscanf(input_str, "<%c,%d>", &row, &col);
	board[toNumeric(row)][col - 1] = '#';

	for (int i = 5; i < strlen(input_str); i += 5) {
		sscanf(&input_str[i], "(%c,%d)", &row, &col);
		board[toNumeric(row)][col - 1] = counter++;
	}

	return board;
}
movesArray create_movesArray() {

	movesArray result;

	result.size = 0;
	result.moves = NULL;

	return result;
}

char** getBoardCopy(char** board) {

	char** dest = (char**)calloc(N, sizeof(char*));
	checkMemoryAllocation(dest);
	for (int i = 0; i < N; i++) {
		dest[i] = (char*)calloc(M, sizeof(char));
		checkMemoryAllocation(dest[i]);
		for (int j = 0; j < M; j++)
			dest[i][j] = board[i][j];
	}

	return dest;
}
movesList * makePEmptyList_movesList() {

	movesList* list = (movesList*)calloc(1, sizeof(movesList));
	checkMemoryAllocation(list);
	*list = makeEmptyList_movesList();

	return list;
}
void insertDataToEnd_movesList(movesList* list, char rows, char cols) {

	if (isEmptyList_movesList(*list)) {
		list->head = list->tail = createCell_movesList(rows, cols);
		return;
	}

	list->tail->next = createCell_movesList(rows, cols);
	list->tail->next->prev = list->tail;
	list->tail = list->tail->next;
}
movesList makeEmptyList_movesList() {

	movesList result;
	result.head = result.tail = NULL;

	return result;
}
moveCell* createCell_movesList(char rows, char cols) {
	
	moveCell* result = (moveCell*)calloc(1, sizeof(moveCell));
	checkMemoryAllocation(result);

	result->next = result->prev = NULL;
	result->move = create_Move(rows, cols);

	return result;
}
bool isEmptyList_movesList(movesList list) {

	return (list.head == NULL ? true : false);
}
Move create_Move(int row, int col) {

	Move result;

	result.cols = col;
	result.rows = row;

	return result;
}

void insertNodeToArr_movesArray(movesArray* array, Move move) {

	if (array->size == 0 || array->moves == NULL) {
		array->size = 1;
		array->moves = (Move*)calloc(1, sizeof(Move));
		checkMemoryAllocation(array->moves);

		array->moves[0] = move;
		return;
	}

	array->moves = (Move*)realloc(array->moves, ++array->size * sizeof(Move));
	checkMemoryAllocation(array->moves);

	array->moves[array->size - 1] = move;
}
void insertTo_boardPosArray(boardPosArray* array, char row, char col) {

	if (array->size == 0 || array->positions == NULL) {
		array->size = 1;
		array->positions = (boardPos*)calloc(1, sizeof(boardPos));
		checkMemoryAllocation(array->positions);

		array->positions[0][0] = row;
		array->positions[0][1] = col;
		return;
	}

	array->positions = (boardPos*)realloc(array->positions, ++array->size * sizeof(boardPos));
	checkMemoryAllocation(array->positions);

	array->positions[array->size - 1][0] = row;
	array->positions[array->size - 1][1] = col;
}

void printBinFile(char* file_name) {
	bool isExist;
	boardPosArray* result = readFromBinFile(file_name,&isExist);
	printf(" // RES      - <%d>", result->size);
	for (int i = 0; i < result->size; i++)
		printf(" (%c,%d)", result->positions[i][0], result->positions[i][1]);

	free(result->positions);
	free(result);
}