//This is a trash file. Do no use it or submit it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!








//void insertValidPosToHead(treeNodeListCell* lst,boardPos data);

//moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev);

//void insertDataToEndList(movesList* lst,Move move);

//void _insertNewNodeToEnd(movesList* lst, moveCell* newNode);

//boardPosArray* readFromBinFile(char* file_name);
//void writePosToArr(boardPosArray* arr, int i, BYTE* data);

//void printBinFile();
//bool ex5Test(char file_name[], char input_board_pos[], char output_board_pos[]);
//boardPosArray* getBoardPosArrayPFromStr(char input[]);
//void printBinFile(char* file_name);
//boardPosArray* readArrayFromBin(char* file_name);

//void insertDataToTail(movesList* lst, Move move);
//moveCell* createMoveNode(Move move, moveCell* prev, moveCell* next);
//void _insertNewNodeToTail(movesList* lst, moveCell* newNode);

//void insertDataToEndList(movesList* lst, Move move);
//
//moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev);
//void _insertNewNodeToEnd(movesList* lst, moveCell* newNode);

/*void makeEmptyList(movesList* lst){
    lst->head = lst->tail = NULL;
}*/

/*void insertDataToEndList(movesList* lst,Move move){
    moveCell* newNode = createMoveNode(move,NULL,lst->tail);
    _insertNewNodeToEnd(lst,newNode);
}*/

/*moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev){
    moveCell* newNode = (moveCell*)malloc(sizeof(moveCell));
    checkMemoryAllocation(newNode);
    newNode->move = move;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}*/

/*void _insertNewNodeToEnd(movesList* lst, moveCell* newNode) {
	newNode->next = NULL;
	if (lst->tail == NULL) {
		lst->tail = lst->head = newNode;
	}
	else {
		lst->tail->next = newNode;
		lst->tail = newNode;
	}
}*/


/*moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev) {
	moveCell* newNode = (moveCell*)malloc(sizeof(moveCell));
	checkMemoryAllocation(newNode);
	newNode->move = move;
	newNode->next = next;
	newNode->prev = prev;
	return newNode;
}*/


/*void insertDataToTail(movesList* lst, Move move) {
	moveCell* newNode = createMoveNode(move, lst->tail, NULL);
	_insertNewNodeToEnd(lst, newNode);
}*/

/*void insertDataToEndList(movesList* lst,Move move){
    moveCell* newNode = createMoveNode(move,NULL,lst->tail);
    _insertNewNodeToEnd(lst,newNode);
}*/

/*moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev){
    moveCell* newNode = (moveCell*)malloc(sizeof(moveCell));
    checkMemoryAllocation(newNode);
    newNode->move = move;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}*/

/*void _insertNewNodeToEnd(movesList* lst, moveCell* newNode) {
	newNode->next = NULL;
	if (lst->tail == NULL) {
		lst->tail = lst->head = newNode;
	}
	else {
		lst->tail->next = newNode;
		lst->tail = newNode;
	}
}*/

/*void _insertNewNodeToTail(movesList* lst, moveCell* newNode) {
	if (lst->head == NULL) {
		lst->head = lst->tail= newNode;
	}
	else {
		newNode->prev = lst->tail;
		lst->tail = newNode;
	}

}*/


//Amit's function :
/*boardPos* readFromBinFile(char* file_name, int* size, bool* isExist) {
	FILE* fr = fopen(file_name, "rb");
	checkMemoryAllocation(fr);
	short int numOfPos;
	fread(&numOfPos, sizeof(short), 1, fr);
	boardPos* arr = (boardPos*)malloc(sizeof(boardPos) * numOfPos);
	BYTE tempData[3];
	int i = 0;
	for (i = 0; i < numOfPos && numOfPos-i > 3 ;i += 4) {
		fread(tempData, sizeof(char), 3, fr);
		writePosToArr(arr, i, tempData);
	}
	if (numOfPos - i < 4 && numOfPos != 0){
		BYTE data;
		if (numOfPos % 4 == 1) {
			fread(&data, sizeof(char), 1, fr);
			arr[i][0] = ((data & 0xE0) >> 5) + 'A';
			arr[i][1] = ((data & 0x1c) >> 2) + 1;
		}
		else if (numOfPos % 4 == 2) {
			BYTE data[2];
			fread(&data, sizeof(char), 2, fr);
			arr[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
			arr[i][1] = ((data[0] & 0x1c) >> 2) + 1;
			arr[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
			arr[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
		}
		else
		{
			BYTE data[3];
			fread(&data, sizeof(char), 3, fr);
			arr[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
			arr[i][1] = ((data[0] & 0x1c) >> 2) + 1;
			arr[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
			arr[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
			arr[i + 2][0] = (data[1] & 0x0E) >> 1 + 'A';
			arr[i + 2][1] = ((data[1] & 0x01) << 2 | (data[2] & 0xC0) >> 6) + 1;
		}
	}
	return arr;
}*/

/*
bool ex5Test(char file_name[], char input_board_pos[], char output_board_pos[]) {

	bool test = false;
	boardPosArray* bp_arr = getBoardPosArrayPFromStr(input_board_pos);
	saveListToBinFile(file_name, bp_arr);
	boardPosArray* result = readFromBinFile(file_name);
	boardPosArray* bp_arr_output = (output_board_pos == NULL ? bp_arr : getBoardPosArrayPFromStr(output_board_pos));

	if (result->size != bp_arr_output->size)
		test = true;
	for (int i = 0; i < result->size && !test; i++)
		if ((result->positions[i][0] != bp_arr_output->positions[i][0]) ||
			result->positions[i][1] != bp_arr_output->positions[i][1])
			test = true;

	if (test) {
		printf("mistake at comparing boardPos`s.\n");
		printBinFile(file_name);
		printf("\n");
	}

	free(bp_arr->positions);
	free(bp_arr);
	free(result->positions);
	free(result);
	return !test;
}*/


/*boardPosArray* getBoardPosArrayPFromStr(char input[]) {

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
}*/


/*void printBinFile(char* file_name) {

	boardPosArray* result = readArrayFromBin(file_name);
	printf(" // RES      - <%d>", result->size);
	for (int i = 0; i < result->size; i++)
		printf(" (%c,%d)", result->positions[i][0], result->positions[i][1]);

	free(result->positions);
	free(result);
}*/


/*boardPosArray* readArrayFromBin(char* file_name) {
	unsigned int lenName = strlen(file_name) + 5;
	char* file = (char*)malloc(sizeof(char) * lenName);
	sprintf(file, "%s%s", file_name, ".bin");
	FILE* data = fopen(file, "rb");
	checkMemoryAllocation(data);
	short int len;
	fread(&len, sizeof(short int), 1, data);

	boardPosArray* result = (boardPosArray*)calloc(1, sizeof(boardPosArray));
	checkMemoryAllocation(result);
	result->size = len;
	result->positions = (boardPos*)calloc(len, sizeof(boardPos));
	checkMemoryAllocation(result->positions);

	int type = 0;
	BYTE currByte, mask = 0x07, input, temp;
	fread(&currByte, sizeof(BYTE), 1, data);
	for (int nextEmptyBit = 0; nextEmptyBit < len * 6; nextEmptyBit += 3) {
		if (nextEmptyBit > 1 && nextEmptyBit % 8 == 0)
			fread(&currByte, sizeof(BYTE), 1, data);
		int bitIndex = 7 - (nextEmptyBit % 8), resIndex = nextEmptyBit / 6;
		if (bitIndex >= 2) {
			input = (currByte & (mask << (bitIndex - 2))) >> (bitIndex - 2);
			temp = input + (type == 0 ? 'A' : 1);
			result->positions[resIndex][type] |= temp;
		}
		else {
			input = ((currByte & (mask >> (2 - bitIndex))) << (2 - bitIndex));
			fread(&currByte, sizeof(BYTE), 1, data);
			temp = ((currByte & (mask << (6 + bitIndex))) >> (6 + bitIndex));
			input |= temp;
			result->positions[resIndex][type] |= input + (type == 0 ? 'A' : 1);
		}
		type = (type == 1 ? 0 : 1);
	}

	fclose(data);
	return result;
}*/


/*
void printBinFile() {
	FILE* data = fopen("test2.bin", "rb");
	short int numOfPos;
	fread(&numOfPos, sizeof(short int), 1, data);
	char* arr = (char*)malloc(sizeof(char) * 8);

	fread(stdout, sizeof(unsigned char), 7, data);
}
*/



/*boardPosArray* readFromBinFile(char* file_name)//, int* size, bool* isExist) {
{
		FILE* fr = fopen(file_name, "rb");
		checkMemoryAllocation(fr);
		short int numOfPos;
		fread(&numOfPos, sizeof(short), 1, fr);
		boardPosArray* arr = (boardPos*)malloc(sizeof(boardPos) * numOfPos);
		BYTE tempData[3];
		int i = 0;
		for (i = 0; i < numOfPos && numOfPos - i > 3; i += 4) {
			fread(tempData, sizeof(char), 3, fr);
			writePosToArr(arr, i, tempData);
		}
		if (numOfPos - i < 4 && numOfPos != 0) {
			BYTE data;
			if (numOfPos % 4 == 1) {
				fread(&data, sizeof(char), 1, fr);
				arr->positions[i][0] = ((data & 0xE0) >> 5) + 'A';
				arr->positions[i][1] = ((data & 0x1c) >> 2) + 1;
			}
			else if (numOfPos % 4 == 2) {
				BYTE data[2];
				fread(&data, sizeof(char), 2, fr);
				arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
				arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
				arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
				arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
			}
			else
			{
				BYTE data[3];
				fread(&data, sizeof(char), 3, fr);
				arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
				arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
				arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
				arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
				arr->positions[i + 2][0] = (data[1] & 0x0E) >> 1 + 'A';
				arr->positions[i + 2][1] = ((data[1] & 0x01) << 2 | (data[2] & 0xC0) >> 6) + 1;
			}
		}
		*size = i;
		return arr;

}*/

/*void writePosToArr(boardPosArray* arr, int i, BYTE* data) {

	arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
	arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
	arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
	arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
	arr->positions[i + 2][0] = (data[1] & 0x0E) >> 1 + 'A';
	arr->positions[i + 2][1] = ((data[1] & 0x01) << 2 | (data[2] & 0xC0) >> 6) + 1;
	arr->positions[i + 3][0] = ((data[2] & 0x38) >> 3) + 'A';
	arr->positions[i + 3][1] = (data[2] & 0x07) + 1;
}*/

/*boardPosArray* readFromBinFile(char* file_name)//, int* size, bool* isExist) {
{
	FILE* fr = fopen(file_name, "rb");
	checkMemoryAllocation(fr);
	short int numOfPos;
	fread(&numOfPos, sizeof(short), 1, fr);
	boardPosArray* arr = (boardPos*)malloc(sizeof(boardPos) * numOfPos);
	BYTE tempData[3];
	int i = 0;
	for (i = 0; i < numOfPos && numOfPos - i > 3; i += 4) {
		fread(tempData, sizeof(char), 3, fr);
		writePosToArr(arr, i, tempData);
	}
	if (numOfPos - i < 4 && numOfPos != 0) {
		BYTE data;
		if (numOfPos % 4 == 1) {
			fread(&data, sizeof(char), 1, fr);
			arr->positions[i][0] = ((data & 0xE0) >> 5) + 'A';
			arr->positions[i][1] = ((data & 0x1c) >> 2) + 1;
		}
		else if (numOfPos % 4 == 2) {
			BYTE data[2];
			fread(&data, sizeof(char), 2, fr);
			arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
			arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
			arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
			arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
		}
		else
		{
			BYTE data[3];
			fread(&data, sizeof(char), 3, fr);
			arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
			arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
			arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
			arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
			arr->positions[i + 2][0] = (data[1] & 0x0E) >> 1 + 'A';
			arr->positions[i + 2][1] = ((data[1] & 0x01) << 2 | (data[2] & 0xC0) >> 6) + 1;
		}
	}
	*size = i;
	return arr;
}

/*void writePosToArr(boardPosArray* arr, int i, BYTE* data) {

	arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
	arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
	arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
	arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
	arr->positions[i + 2][0] = (data[1] & 0x0E) >> 1 + 'A';
	arr->positions[i + 2][1] = ((data[1] & 0x01) << 2 | (data[2] & 0xC0) >> 6) + 1;
	arr->positions[i + 3][0] = ((data[2] & 0x38) >> 3) + 'A';
	arr->positions[i + 3][1] = (data[2] & 0x07) + 1;
}*/

