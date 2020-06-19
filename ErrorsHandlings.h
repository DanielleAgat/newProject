//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#define _CRT_SECURE_NO_WARNINGS
#ifndef ERRORSHANDLING_H
#define ERRORSHANDLING_H

#include "stdio.h"
#include "stdlib.h"
#include "FreeMemory.h"

//This function checks that memory allocation didn't went wrong, and stops the program if it did.
void checkMemoryAllocation(void* ptr);

//This function checks that file opening didn't went wrong, and stops the program if it did.
void isFileOpeningSuccessfull(FILE* file);

//This function checks that file closing didn't went wrong, and stops the program if it did.
void closeFileWithValidation(FILE* file);

#endif