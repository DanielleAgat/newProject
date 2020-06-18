//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "ErrorsHandlings.h"

void checkMemoryAllocation(void* ptr) {
	if (ptr == NULL) {
		printf("ERROR: Memery allocation failed!");
		exit(1);
	}
}

void isFileOpeningSuccessful(FILE* file){
    if(file == NULL){
        printf("ERROR: File couldn't be open!");
        exit(1);
    }
}

void closeFileWithValidation(FILE* file){
    if(fclose(file) != 0){
        printf("ERROR: File couldn't be closed!");
        exit(1);
    }
}