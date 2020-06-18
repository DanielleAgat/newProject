//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#define _CRT_SECURE_NO_WARNINGS
#include "BinFile.h"

void saveListToBinFile(char* file_name, boardPosArray* pos_arr) {
	unsigned int j = 0;
	BYTE c[3]; 
	unsigned int lenName = strlen(file_name) + 5;
	char* file = (char*)malloc(sizeof(char) * lenName);
	checkMemoryAllocation(file);
	sprintf(file, "%s%s", file_name, ".bin");
	FILE* fb;
	fb = fopen(file, "wb");
	free(file);

	fwrite(&pos_arr->size, sizeof(short), 1, fb);
	int index = pos_arr->size;
	while (j < pos_arr->size) {
		if (index < 4){
			setBits(pos_arr, c, j, index%4);
			fwrite(c, sizeof(BYTE), index%4, fb);
			j += pos_arr->size;
		}
		else {
			setBits(pos_arr, c, j,4);
			fwrite(c, sizeof(BYTE), 3, fb);
			index -= 4;
			j += 4;
		}
	}

	fclose(fb);
}

boardPosArray* readFromBinFile(char* file_name ,bool* isExist){
    //Open file with validation:
    FILE* fr = fopen(file_name, "rb");
    if (fr == NULL){
        *isExist = false;
        return NULL;
    }
    *isExist = true;
    short int numOfPos;

    //Allocate memory for the array:
    fread(&numOfPos, sizeof(short), 1, fr);
    boardPosArray* arr = (boardPosArray*)malloc(sizeof(boardPosArray));
    checkMemoryAllocation(arr);
    arr->size = numOfPos;
    arr->positions = (boardPos*)malloc(sizeof(boardPos) * numOfPos);
    checkMemoryAllocation(arr->positions);

    //Get data and insert to array:
    BYTE tempData[3];
    int j = 0;
    int index = numOfPos;
    while (j < numOfPos) {
        if (index < 4) {
            fread(tempData, sizeof(BYTE), index % 4,fr);
            writePosToArr(arr, j, tempData, index % 4);
            j += numOfPos;
        }
        else {
            fread(tempData, sizeof(BYTE), 3, fr);
            writePosToArr(arr, j, tempData, 4);
            index -= 4;
            j += 4;
        }
    }
    closeFileWithValidation(fr);
    return arr;
}


void setBits(boardPosArray* pos_arr, BYTE* res, int j,int numOfPos) {
	res[0] = ((pos_arr->positions[j][0] - 'A') << 5) | ((pos_arr->positions[j][1] - 1) << 2);
	if (numOfPos > 1) {
		res[0] |= (pos_arr->positions[j + 1][0] - 'A' >> 1);
		res[1] = (pos_arr->positions[j + 1][0] - 'A' << 7) | (pos_arr->positions[j + 1][1] - 1 << 4);
	}
	if (numOfPos > 2) {
		res[1] |= (pos_arr->positions[j + 2][0] - 'A' << 1) | (pos_arr->positions[j + 2][1] - 1 >> 2);
		res[2] = (pos_arr->positions[j + 2][1] - 1 << 6);
	}
	if (numOfPos > 3) {
		res[2] |= (pos_arr->positions[j + 3][0] - 'A' << 3) | (pos_arr->positions[j + 3][1] - 1);
	}
}

void writePosToArr(boardPosArray* arr, int i, BYTE * data, int numOfPos){
    arr->positions[i][0] = ((data[0] & 0xE0) >> 5) + 'A';
    arr->positions[i][1] = ((data[0] & 0x1c) >> 2) + 1;
    if (numOfPos > 1) {
        arr->positions[i + 1][0] = (((data[0] & 0x03) << 1) | ((data[1] & 0x80) >> 7)) + 'A';
        arr->positions[i + 1][1] = ((data[1] & 0x70) >> 4) + 1;
    }
    if (numOfPos > 2) {
        arr->positions[i + 2][0] = ((data[1] & 0x0E) >> 1) + 'A';
        arr->positions[i + 2][1] = ((data[1] & 0x01) << 2 | (data[2] & 0xC0) >> 6) + 1;
    }
    if (numOfPos > 3) {
        arr->positions[i + 3][0] = ((data[2] & 0x38) >> 3) + 'A';
        arr->positions[i + 3][1] = (data[2] & 0x07) + 1;
    }
}

