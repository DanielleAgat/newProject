//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "FreeMemory.h"

void freeBoardPosArrayMatrix(boardPosArray** matrix){
    for(int i=0 ;i < N ; i++)
        freeBoardPosArr(matrix[i]);
}

void freeBoardPosArr(boardPosArray* arr){
    free(arr->positions);
    free(arr);
}

void freeMovesList(movesList* moves_list) {
    _freeMovesList(moves_list->head);
}

void _freeMovesList(moveCell* moveNode) {
    moveCell* temp;
    while (moveNode != NULL) {
        temp = moveNode;
        moveNode = moveNode->next;
        free(temp);
    }
}

void freeBoard(char** board) {
    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
}